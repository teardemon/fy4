 // flowerowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Oct/29/2001 
#include <ansi.h>
#include <dbase.h> 
string *delivery_list = ({
"李寻欢:/d/songshan/npc/bu_waiter",
"楚留香:/d/jinan/npc/surong",
"陆小凤:/d/yingou/npc/leng",
"方玉飞:/d/yingou/npc/fangyuxiang",
"花街大少:/d/fy/npc/bookgirl",
"诸葛小雷:/d/fugui/npc/tianxin",
"姬冰燕:/d/fugui/npc/clothlady",
"俊俏相公:/d/fugui/npc/beauty",
"楚留香:/d/jinan/npc/songtian",
"中原一点红:/d/guanyin/npc/qu",
"小方:/d/guanwai/npc/sunshine",
"小方:/d/guanwai/npc/qi",
"展梦白:/d/palace/npc/feiyu",
"花飞:/d/palace/npc/manfeng",
"胡铁花:/d/huashan/npc/jin",
"丁枫:/d/huashan/npc/linger",
"胡铁花:/d/huashan/npc/gao",
"萧十一郎:/d/huangshan/npc/feng",
"太白逸:/d/huangshan/npc/yan",
"萧十一郎:/d/huangshan/npc/bing",
"萧十一郎:/d/taishan/npc/shenbijun",
}); 
string wait_period(int timep); 
string get_flower()
{
        //get flower from the vendor list
        int i;
        mapping goods;
        string *names;
        if( !mapp(goods = query("vendor_goods")) )      return "";
        names = keys(goods);
        if (!sizeof(names))
   {
                //should we give out a default flower or don't let them deliver?
                return "";              // no more delivery
        }
        i = sizeof(names);
        return names[random(i)];
} 
mapping query_delivery()
{
        int i;
        string *delivery;
        i = sizeof(delivery_list);
        delivery = explode(delivery_list[random(i)],":");
        return (["sender": delivery[0],
                        "receiver": delivery[1],
                        ]);
}  
int assign_delivery()
{
        mapping delivery;
    string dstr;
        object who,flower,silver;
    who = this_player();
        if (who->query("combat_exp") >= 10000 )
        {
                message_vision("$N诚惶诚恐对$n道：“怎么敢劳您大驾”！\n",this_object(),who );
                return 1;
        }
        if (who->query("KILLED") >= 20 )
        {
                message_vision("$N沉吟了一会儿道：“"+RANK_D->query_respect(who)+"小小年纪，怎么印堂发黑？“\n",this_object(),who );
                message_vision("$N摇摇头说：“不吉，不吉，这送花的事你不适合干。“\n",this_object());
                return 1;
        }
        
         
        if(who->is_ghost() || who->is_zombie()) {
                tell_object(who,this_object()->name()+"道：“我们不要鬼魂送花。”\n");
                return 1;
        } 
   if((delivery =  who->query("delivery")) && (time() - who->query("delivery_time") <= 600)) {
                return 0;
        }
        //delivery unfinished and back to ask again in 10 mins
        if ((delivery =  who->query("delivery")) && (time() - who->query("delivery_time"))<= 1200)
        {
                tell_object(who,HIW"你要过" 
                                +  QUESTS_D->wait_period(1200-time()+who->query("delivery_time")) 
                                + "之后才可继续送花。\n"NOR);
                return 1;
        }
        //delivery cancled by player
        if ((!delivery =  who->query("delivery")) && ((who->query("next_delivery_time")) > time()))
        {
                tell_object(who,HIW"你要过" 
                                +  QUESTS_D->wait_period(who->query("next_delivery_time") - time()) 
                                + "之后才可继续送花。\n"NOR);
                return 1;
        } 
        silver=present("silver_money", who);
    if(!silver) 
        {
                tell_object(who,"你身上没有足够的银子付定金呀。\n");
                return 1;
        }
    if (silver->query_amount()<1)
        {
                tell_object(who,"你身上没有足够的银子付定金呀。\n");
                return 1;
        }
    silver->add_amount(-1); 
        delivery = query_delivery();
        flower = new(get_flower());
        if (!flower) {
                message_vision("$N摇摇头说：“这里的花都送光了。“\n",this_object());
                return 1;
        } 
        //flower->set("sender",delivery["sender"]);
        //flower->set("receiver",delivery["receiver"]);
        flower->set("delivery",delivery);
   flower->wither();
        if (flower->move(who))
        {
                who->set("delivery", delivery);
                flower->set("delivery_time", (int)time());      
                who->set("delivery_time", (int)time()); 
                dstr = "“这是" + delivery["sender"] + "公子送给"+  delivery["receiver"]->name(1) + "小姐的花。请速去速回。”\n";
                message_vision("$N小心翼翼递给$n一朵"+flower->name()+"道：\n" + dstr,this_object(),who); 
        }
        return 1;
} 
int cancel_delivery(string arg)
{
        object who;
        who = this_player();
        if (arg != "delivery" && arg != "送花")
        {
                return 0;
        }
        if(  who->query("delivery") && (time() - who->query("delivery_time") < 600))
        {
                who->delete("delivery");
                who->delete("delivery_time");
                tell_object(who, this_object()->name() + "说道：好吧，这个送花任务就算了吧．．\n");
                who->set("next_delivery_time", time() + random(300));
                return 1;
        }else if (!who->query("delivery"))
        {
                return notify_fail("你现在没有任何送花任务！\n");
        }else
        {
                return notify_fail("你已错过上一个任务。等下一个吧。\n");
        }
} 
int give_deposit()
{
        int amount;
        object silver,me;
        me = this_player();
        amount = me->query("delivery/success");
   if (amount>=1)
        {
                silver = new("/obj/money/silver");
                silver->set_amount(amount);
                message_vision("$N对$n道：“这是你的全部押金。”\n",this_object(),me);
                silver->move(me);
                me->set("delivery/success",0);
                return 1;
        }
        message_vision("$N对$n道：“你并没有押金在这儿。”\n",this_object(),me);
        return 1; 
} 
/* 
the code which player place reservation
not in use right now
int book_flowers(string arg)
{
        string starget,sflower;
        object target,flower,who;
        mapping goods,userdelivery;
        string *names,flowerlist;
        who = this_player();
        flowerlist = "";
        if (!arg || sscanf(arg, "%s %s", starget,sflower) != 2 ) 
        {
                return notify_fail("命令格式:book 玩家ID 花的ID\n");
        }       
        if (sizeof(user_reservation_list)>=20)
        {
                return notify_fail("本店订单已满，不在接受新的订单。\n");
        } 
        if (!target = find_player(starget))
        {
                return notify_fail("你只可预订花给在线玩家。\n");
        }
        if( mapp(goods = query("vendor_goods")) ) 
        {
                names = keys(goods);
                if (sizeof(names)) 
                {
                   for (int i=0;i<sizeof(names);i++ )
                        { 
                                flowerlist = flowerlist + names[i]->name() + "("+names[i]->query("id")+")"+"\n";
                                if ( names[i]->query("id") == sflower )
                                {
                                        userdelivery = (["sender": who->name(1),
                                                "receiver": target->query("id"),
                                                "flower":names[i],
                                        ]);
                                        user_reservation_list = user_reservation_list + ({userdelivery});
                                        message_vision("$N预订了一支"+names[i]->name()+"给"+target->name(1)+"\n",who);
                                        return 1;
                                        
                                }
                        }
                }
        } 
        if (flowerlist == "")
        {
                return notify_fail("这里的花都卖光了。\n");
        }
        tell_object(who,"你现在只可预订下列花：\n"+flowerlist);
        return 1; 
}
*/
