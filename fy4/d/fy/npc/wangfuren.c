 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC;
object ob; 
void create()
{
        set_name("樊夫人", ({ "furen" }) );
        set("gender", "男性" );
        set("title", HIR "祭剑师"NOR);
        set("age", 52);
        set("long",
                "樊夫人本是三清宫的一个老道士，人到老年无所事事，
在这里给人祭剑。\n");
        set("combat_exp", 50000);
    set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
        add_action("do_ji","ji");
        add_action("do_answer", "answer");
        //if (!objectp(environment(this_object())->query("processing"))
        //      environment(this_object())->set("processing", ob);
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob)) {
                if (ob->query("宿命A") || ob->query("宿命B")){
                   if(ob->query("stone_mark/pstone")){
                                message_vision("\n$N微阖双眼看了看$n的幽冥紫灵剑，沉吟半晌道：幽冥紫灵剑向来只有一把，这一把定为赝品。\n",
                                                this_object(), ob);
                                return;
                        }
                        message_vision(HIY"\n$N人眼中透出热切的光，看着幽冥紫灵剑，喃喃地说：“这可是用千古难求\n"NOR, this_object());
                        message_vision(HIY"的幽冥紫晶炼成的啊。可惜冶剑之人不得其法，空误了地府之珍。”\n"NOR, this_object());
                        message_vision("\n$N说：“如果" + RANK_D->query_respect(ob) 
+ "愿意以百金相赠，我可以把幽冥紫晶提炼还原。”\n" +
"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ ）\n", this_object()); 
                        ob->set_temp("furen_yes_no", 1);
                } else {        
                        message_vision(YEL"$N的眼光扫过$n的幽冥紫灵剑，眼光让人琢磨不透。\n"NOR, this_object(), ob);
                }
        } else {
                switch( random(5) ) {
                        case 0:
                                say( "樊夫人笑道：这位" + RANK_D->query_respect(ob)
                                        + "，你的宝刃看起来好象要血祭一下了。\n");
                                break;
                        case 1:
                                say( "樊夫人说道：这位" + RANK_D->query_respect(ob)
                                        + "，你的宝刃杀气不足，来血祭一下宝刃吧。\n");
                                break;
                }
        }
}
int do_answer(string arg) {
        object me, stone, gold;
        
        me = this_player();
        gold = present("gold_money", me);
        if (!me->query_temp("furen_yes_no")) {
                return 0;
        }
        if (!arg || arg == "no") {
                message_vision("\n$N说道：“可惜了这幽冥紫晶呀！”\n", this_object());
                return 1;
        }
        if (arg == "yes") {
           me->set("marks/提幽冥紫晶", 1); 
                message_vision("$N说道：“好！”\n", me);
                return 1;
        }
} 
int accept_object(object who, object ob) {
        object me, sword;
        
        me = this_player();
        sword = present("hell sword", me);
        if (!me->query("marks/提幽冥紫晶")) {
                return 0;
        }
        if (ob->query("money_id") != "gold") {
                        return 0;
        } else {
                if (ob->query_amount() < 100 ) {
                        return 0;
                } else {
                        if (this_object()->query("busy")) {
                                return 0;
                        } else if (present("hell sword", me)) {
                                message_vision("\n$N从$n手中取过幽冥紫灵剑，放入冶剑炉中。\n", this_object(), me); 
                                destruct(sword);
                                message_vision(HIC"炉火渐渐从红色转成青白之色。\n"NOR, this_object());
                                set("busy", 1);
                                call_out("ext_stone", 3, me);
                        } else {
                                return 0;
                        }
                }
        }       
        return 1;
} 
int ext_stone(object me){
        object stone;
        if (environment(me) == environment(this_object())) {
                message_vision(MAG"\n忽然间，紫光闪耀，映彻天地。\n"NOR, this_object()); 
                message_vision(HIR"$N忽然用刀在自己的手臂上一划，一股血箭射入冶剑炉。\n"NOR, this_object()); 
                message_vision(MAG"\n紫光大盛之下，你不由得闭上眼睛。\n"NOR, this_object());
           message_vision("睁眼看时，樊夫人已将一块幽光闪闪的紫石托在手中。\n", this_object()); 
                me->delete("marks/提幽冥紫晶"); 
                stone = new("/obj/specials/stone/pstone");
                stone->move(this_object());
                if(!me->query("stone_mark/pstone")){
                me->set("stone_mark/pstone",1);
                me->add("score",3000);
                }
                command("give amethist to " + me->query("id"));
        } 
        set("busy", 0);
        return 1;
}
int  do_ji(string arg)
{
        object me;
        
        int gold;
        int cost =1;
        int i,j,base,current;
        string id,name,broken;  
        string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("你要祭什麽武器？\n"); 
//      gold = present("gold_money", this_player());
//      if( !gold) return notify_fail("你身上没有金子。\n"); 
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( !ob->query("weapon_prop") )
        return notify_fail("你只能祭可当作武器的东西。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("owner") )
        return notify_fail("你只可祭自己打造的武器。\n");
        sscanf(ob->query("name"),"%s的",broken);
        if(broken=="断掉")
        return notify_fail("你不可祭损坏了的武器，请去张铁匠那修理好武器再来祭。\n");
   base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage"); 
/*      for(j=1;j<=100;j++)
        {
                base = base + j;
                if(base >= current) break;
        }*/
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }
        if (j>=15) 
                return notify_fail("樊夫人摇了摇头说：“凭我的能力，已经无法再祭这把武器了！”\n");
        for(i=1; i<=j;i++)
                        cost = cost * 2;
        tell_object(me, HIY"祭武器将会使用"+chinese_number(cost)+"两黄金，是否要继续？(continue yes/no)\n"NOR);
        environment(this_object())->set("processing", me);
        add_action("do_continue","continue");
        return 1;
} 
int do_continue(string arg) {
        int i, j, cost = 1;
        object me = this_player();
        object ji_person;
        int gold = me->query("deposit")/10000;
        ji_person = environment(this_object())->query("processing");
        if ( !objectp(ji_person) || environment()!=environment(ji_person))
                environment(this_object())->set("processing", me);
        if (me != ji_person ) return notify_fail("有人正在祭武器，请稍后。\n"); 
        if ( arg != "yes" ) { 
                write ("樊夫人笑容可掬地说：欢迎下次再来！\n");
                environment()->delete("processing");
                remove_action("do_continue","continue");
                return 1; 
        }
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
   }
        for(i=1; i<=j;i++)
                        cost = cost * 2;         
        if( gold < cost)
                { 
                        environment()->delete("processing");
                        return  notify_fail("你银行里存款不够" + sprintf("%d",cost)+ "两金子。\n");
                }
        me->add("deposit", -cost*10000);
        me->start_busy(1);
        me->save();
        me->add("bellicosity",cost);
        seteuid(ROOT_UID);
// need to update 3 things: damage, rigidity, and weight, base_damage is to keep track
// damage on weapon so we can xiu weapon later on.
        ob->add("weapon_prop/damage",j);
    ob->add("base_damage", j);
        ob->set("weight",(int)ob->query("weight")+j*100);
        ob->add("rigidity",j*10);
        ob->add("ji_times", 1);
        ob->save();
        ob->restore();
        
        if(ob->move(me))         {
        message_vision("\n$N从$n手中取过"+ob->name()+"，放入冶剑炉中。\n", this_object(), me); 
        message_vision(HIC"炉火渐渐从红色转成青白之色。\n\n\n"NOR, this_object());
        message_vision(HIR"$N忽然用刀在自己的手臂上一划，一股血箭射入冶剑炉。\n"NOR, this_object()); 
        message_vision(HIC"\n炉火暴涨之下，你不由得闭上眼睛。\n"NOR, this_object());
        message_vision("$N说道：好了！\n\n",this_object());
        message_vision("睁眼看时，樊夫人已将$n交还给你手中。\n", this_object(), ob); 
        seteuid(getuid());
        }
        environment(this_object())->delete("processing");
        remove_action("do_continue","continue");
        return 1;
}
