// TIE@FY3
//modify by karry@fy4
#include <ansi.h>
inherit NPC;
void pay_him(object who, int amount);
void check_pointer();
int give_card();
int do_bet2(string arg, object me);
int can_end_round();
string showdice(int num);
void find_next();
void setup_card();
void end_the_round();
void create()
{
        set_name( "白姨", ({ "bai yi", "leng baiyi" }) );
        set("long", "这是朱砂帮掌门弟子冷秋魂的妹妹。\n");
        set("attitude", "friendly");
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("cards", ({}));
        set("my_percentage",2);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("gender", "女性" );
        set("age",18); 
        set("str", 35);
        set("cor", 30);
        set("cps", 25);
        set("per",5);
        set("lower_limit",10);
        set("too_late",0);
        set("whose_turn",0);
        set("last_turn",0);
        set("counter",0);
        set("max_force",400000);
        set("force_factor",250);
        set_skill("throwing",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set("combat_exp", 50000000);
        setup();
        carry_object(__DIR__"obj/nupao")->wear();
        carry_object(__DIR__"obj/gupai")->wield(); 
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_take", "take");
        add_action("do_bet", "bet");
        add_action("do_leave","leave");
        add_action("do_table","table");
        add_action("do_fold", "fold");
        add_action("do_cards","cards");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "白姨笑咪咪地向你抛了个媚说道：这位" + RANK_D->query_respect(ob)
                                + "，过来，过来，妾身陪您赌几手！\n");
                        break;
                case 1:
                        say( "白姨将台上的鹘牌切了切道：" + RANK_D->query_respect(ob)
                                + "，看您今天一定会拿到天对儿！\n");
                        break;
                case 2:
                        say( "白姨说道：这位" + RANK_D->query_respect(ob)
                                + "，别怕！进来！ 不会我可以教你！\n");
                        break;
        }   
        return; 
}   
 
string *dice = ({
"0",
"      B"+
"      B"+
"      B"+
"  ⊙  B"+
"      B"+
"      B"+
"      B", 
"  ⊙  B"+
"      B"+
"      B"+
"      B"+
"      B"+
"      B"+
"  ⊙  B", 
"    ⊙B"+
"      B"+
"      B"+
"  ⊙  B"+
"      B"+
"      B"+
"⊙    B", 
"      B"+
"⊙  ⊙B"+
"      B"+
"      B"+
"      B"+
"⊙  ⊙B"+
"      B", 
"    ⊙B"+
"  ⊙  B"+
"⊙    B"+
"      B"+
"      B"+
"⊙  ⊙B"+
"      B", 
"⊙  ⊙B"+
"      B"+
"      B"+
"⊙  ⊙B"+
"      B"+
"      B"+
"⊙  ⊙B", 
"    ⊙B"+
"  ⊙  B"+
"⊙    B"+
"      B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B", 
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B", 
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"  ⊙  B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B", 
"⊙  ⊙B"+
"  ⊙  B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"  ⊙  B"+
"⊙  ⊙B", 
"⊙  ⊙B"+
"  ⊙  B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"⊙  ⊙B"+
"⊙  ⊙B", 
"⊙  ⊙B"+
"⊙  ⊙B"+
"⊙  ⊙B"+
"      B"+
"⊙  ⊙B"+
"⊙  ⊙B"+
"⊙  ⊙B" 
                });
int do_take(string arg)
{
        string location,money_type,c_loc;
        int amount,total;
        object me, money;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你现在没空！\n");
        if(query("too_late") )
        return notify_fail("这铺来不及了，等下铺吧．\n");
//      see if thisplayer already at a location already
        if(query("north/player") == me ||
           query("south/player") == me ||
           query("east/player") == me ||
           query("west/player") == me  )
                return notify_fail("你已经入了赌局！\n");
        if(!arg || sscanf(arg, "%s %d %s",location,amount,money_type) != 3)
                return notify_fail("take <座位> <数量> <货币种类>\n");
        switch(location) {
        case "north" : 
                c_loc = "北首";
           if(objectp(query("north/player"))) return notify_fail("北位已经有人占了！\n");
                break;
        case "south" : 
                c_loc = "南首";
                if(objectp(query("south/player"))) return notify_fail("南位已经有人占了！\n");
                break;
        case "east" : 
                c_loc = "东首";
                if(objectp(query("east/player"))) return notify_fail("东位已经有人占了！\n");
                break;
        case "west" : 
                c_loc = "西首";
                if(objectp(query("west/player"))) return notify_fail("西位已经有人占了！\n");
                break;
        default :
                return notify_fail("你只可以选north、south、east 或 west。\n");
        }
        if(amount <=0)
                return notify_fail("<数量>最少也要是一吗！\n");
        money = present(money_type+"_money", me);
        if(!objectp(money)) return notify_fail("你身上没有这种货币。\n");
        if((int) money->query_amount() < amount)
        return notify_fail("你身上没有那麽多"+money->name()+"。\n");    
        total = money->value() / money->query_amount() * amount/100;
        if(query("lower_limit") > total)
        return notify_fail("这张台的最小赌注是"+chinese_number((int) query("lower_limit"))+"两银子。\n");
// we think this player will be okey to take a seat at this moment, so, record all the info and take his money!
        set(location+"/player",me);
        add(location+"/money",total);
        money->add_amount(-amount);
        message_vision("$N从身上拿出"+ chinese_number(amount)+money->query("base_unit")+
        money->name()+"放在"+c_loc+"。\n",me);
        me->start_busy(1);
        if( find_call_out("rolldice") == -1)
//                call_out("rolldice",60);
                call_out("rolldice",30);
        if( find_call_out("rolldice") >30 && find_call_out("advertise") == -1)
                call_out("advertise",random(5)+1); 
        return 1;
} 
int do_leave()
{
        object me;
        string location ="nowhere";
        me = this_player();
if( query("north/player") == me )  location = "north";
if( query("south/player") == me )  location = "south";
if( query("east/player") == me )  location = "east";
if( query("west/player") == me )  location = "west";
if(location == "nowhere") return 0;
if(query("too_late"))
        return notify_fail("赌局正在进行中，怎么可以离开？\n");
if(query(location+"/money"))
{
pay_him(me,(int)query(location+"/money")*100);
message_vision("$N将桌子上的"+chinese_number(query(location+"/money"))+"两银子"+
"揣入怀中道：后会有期！\n",me);
}
else
message_vision("$N站起来拱了拱手道：这此运气不好！都输了！后会有期！\n",me);
delete(location);
return 1;
}
int do_table()
{
        int turn;
        string output;
        turn = query("whose_turn");
        output = sprintf(
        (turn%4==0 ? HIR:NOR)+ "%40s\n%44s\n"NOR,(query("north/player")? query("north/player")->name():"空　位"),
        query("north/money")+"两银子");
        output += "                          -------------------------\n";
        output += "                          |         "+
        (query("north/fold")? HIY:NOR)+"北首"+NOR+"          |\n";
        output += sprintf( (turn%4==1 ? HIR:NOR)+"%26s" +NOR + "|"+
        (query("west/fold")? HIY:NOR)+ "西"+NOR+"                   "+
        (query("east/fold")? HIY:NOR)+"东" +NOR+"|" +
                (turn%4==3 ? HIR:NOR) + "%s\n" +NOR,
           (query("west/player")? query("west/player")->name():"空　位"), 
                (query("east/player")? query("east/player")->name():"空　位"));
        output += sprintf("                          |"+"%14d两银子" + "   |\n",(int)query("table/total"));
        output += sprintf( (turn%4==1 ? HIR:NOR)+"%26s" +NOR + "|"+
        (query("west/fold")? HIY:NOR)+ "首"+NOR+"                   "+
        (query("east/fold")? HIY:NOR)+"首"+NOR+"|" +
                (turn%4==3 ? HIR:NOR) + "%s\n" +NOR,
                query("west/money")+"两银子",   query("east/money")+"两银子");
        output += "                          |         "+
        (query("south/fold")? HIY:NOR)+"南首"+NOR+"          |\n";
        output += "                          -------------------------\n";
        output += sprintf(
        (turn%4==2 ? HIR:NOR)+ "%40s\n%44s\n"NOR,(query("south/player")? query("south/player")->name():"空　位"),
        query("south/money")+"两银子");
        write(output);
        return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$N向你媚笑道：多赌多赢！这铺你不会不赢的！\n",this_object());
                        break;
                case 1:
message_vision("$N说道：快，再不出赌注就来不及了！\n",this_object());
                        break;
                case 2:
message_vision("$N满面春风，耸恿着大家：都压上！没错！\n",this_object()); 
                        break;
        } 
        if( find_call_out("rolldice") >=30)
                call_out("advertise",random(4)+5);
return;
} 
void rolldice()
{
        int num_of_head=0;
        string sen;
        string sen2;
// we have to have at least two people to gamble, right? //
        if(objectp(query("north/player"))) num_of_head++;
        if(objectp(query("south/player"))) num_of_head++;
        if(objectp(query("east/player"))) num_of_head++;
        if(objectp(query("west/player"))) num_of_head++; 
        if(num_of_head < 2) {
        call_out("rolldice",45);
        call_out("advertise",random(30)+2);
        return;
        }
//Also  need to setup the table,
        set("table/total",0);
        set("table/round_high",(int)query("lower_limit"));
        set("table/north",0);
        set("table/south",0);
        set("table/east",0);
        set("table/west",0);
        set("table/r_north",0);
        set("table/r_south",0);
        set("table/r_east",0);
        set("table/r_west",0);
        set("table/status",0);
        set("last_turn",-1);
        set("counter",0);
        setup_card();
//setup heartbeat
        set_heart_beat(1);
// okey, let's start the game
        sen="say 好！ 大家先各出纹银"+chinese_number(query("lower_limit"))+"两，开局！";
        if(objectp(query("north/player"))) {
        sen += "北首—"+query("north/player")->name() +"，";
        (query("north/player"))->set_temp("no_quit",1);
        add("table/total",(int)query("lower_limit"));
        add("north/money",-(int)query("lower_limit"));
        add("table/north",(int)query("lower_limit"));
        if(query("north/money"))
        {
        set("whose_turn",0); 
        sen2 = "请"+query("north/player")->name()+"先下赌注！\n";}

        }
        if(objectp(query("south/player"))) {
        sen += "南首—"+query("south/player")->name() +"，";
        (query("south/player"))->set_temp("no_quit",1);
        set("whose_turn",2); 
        add("table/total",(int)query("lower_limit"));
        add("south/money",-(int)query("lower_limit"));
        add("table/south",(int)query("lower_limit"));
        if(query("south/money"))
        {
        set("whose_turn",2); 
        sen2 = "请"+query("south/player")->name()+"先下赌注！\n";}
        }
        if(objectp(query("east/player"))) {
        sen += "东首—"+query("east/player")->name() +"，";
        (query("east/player"))->set_temp("no_quit",1);
        add("table/total",(int)query("lower_limit"));
        add("east/money",-(int)query("lower_limit"));
        add("table/east",(int)query("lower_limit"));
        if(query("east/money"))
        {
        set("whose_turn",3);
        sen2 = "请"+query("east/player")->name()+"先下赌注！\n";}
        }
        set("too_late",1); 
        command(sen+"\n");
        if(stringp(sen2))command("say " + sen2);
// game might just end from here!
   check_pointer();
return;
}
int do_bet(string arg)
{
// bet means we agree to either follow to raise or throw in whatever we have
        object me;
        int mynum;
        int turn,amt,min;
        string str_amt;
        string location ="nowhere";
        if(!query("too_late"))
        return notify_fail("还没开局呢！\n");
        me = this_player();
        if(me->is_busy())
        return notify_fail("你现在没空！\n");
        return do_bet2(arg, me);
}
int do_bet2(string arg, object me)
{
        int mynum;
        int turn,amt,min;
        string str_amt;
        string location ="nowhere";
// There must be better way to find out who is doing a bet, well...
if( query("north/player") == me ){
location = "north"; mynum=0;}
if( query("south/player") == me ){
location = "south"; mynum=2;}
if( query("east/player") == me ){
location = "east"; mynum=3;}
if( query("west/player") == me ){
location = "west"; mynum=1;}
if(location == "nowhere") return 0;
// see if already fold or out of money
if(query(location+"/fold")) return notify_fail("这铺你已经弃权了！\n");
if(!query(location+"/money")) return notify_fail("你的银子已经全部用光了！\n");
turn = (int) query("whose_turn");
if(turn%4 != mynum) return notify_fail("还没有轮到你哪！\n");
// no argument means we just "follow" hehe
min = (int)query("table/round_high") - (int)query("table/r_"+location);
if(!arg || arg=="" || arg == " ")
        amt = min;
else
if (arg=="all")
        amt=(int)query(location+"/money");
else 
        if(sscanf(arg,"%d",amt) != 1 )
                return notify_fail("bet <|数量|all>\n");
if(amt < min){
// we only allow this if our leftover money is less than min
        if(query(location+"/money") < min)
        {
        if(amt < query(location+"/money"))
        return notify_fail("你要么不跟，要么得把你面前的银子都赌出去！\n");
        else
//add it to table
        add("table/total",query(location+"/money"));
// add it to your money in table
        add("table/"+location,query(location+"/money"));
// add it to this round
        add("table/r_"+location,query(location+"/money"));
// deduct it from your pocket
        message_vision("$N不动声色地把面前的"+chinese_number(query(location+"/money"))+"两银子全部推了出去。\n",me);
        set(location+"/money",0);
        }
        else return notify_fail("你最少要下"+chinese_number(min)+"两银子的赌注。\n"); 
}
else
{
        if(query(location+"/money") <= amt)
        {
//add it to table
        add("table/total",query(location+"/money"));
// add it to your money in table
        add("table/"+location,query(location+"/money"));
// add it to this round
        add("table/r_"+location,query(location+"/money"));
// deduct it from your pocket
        message_vision("$N不动声色地把面前的"+chinese_number(query(location+"/money"))+"两银子全部推了出去。\n",me);
        add("table/round_high",amt-min);
        set(location+"/money",0);
        }
        else
        {
//hopefully this is where normal people fall into
//add it to table
        add("table/total",amt);
// add it to your money in table
        add("table/"+location,amt);
// add it to this round
        add("table/r_"+location,amt);
// deduct it from your pocket
        message_vision("$N将面前的"+chinese_number(amt)+"两银子推到了桌子中间。\n",me);
        add(location+"/money",-amt);
        add("table/round_high",amt-min);
        }
}
// always have to do this, right?
add("whose_turn",1);
me->start_busy(1);
check_pointer();
return 1;
}
int do_fold()
{
// sometimes, we are just out of luck, ormaybe we are smart?!
        object me;
        int mynum;
        int turn;
        string location ="nowhere";
        if(!query("too_late"))
        return notify_fail("还没开局呢！\n");
        me = this_player();
        if(me->is_busy())
        return notify_fail("你现在没空！\n");
// There must be better way to find out who is doing a bet, well...
if( query("north/player") == me ){
location = "north"; mynum=0;}
if( query("south/player") == me ){
location = "south"; mynum=2;}
if( query("east/player") == me ){
location = "east"; mynum=3;}
if( query("west/player") == me ){
location = "west"; mynum=1;}
if(location == "nowhere") return 0;
if(query(location+"/fold")) return notify_fail("这铺你已经弃权了！\n");
if(!query(location+"/money")) return notify_fail("你的银子已经全部用光了！\n");
turn = (int) query("whose_turn");
if(turn%4 != mynum) return notify_fail("还没有轮到你哪！\n");
set(location+"/fold",1);
message_vision("$N说道：＂这铺我不跟了！＂\n",me);
add("whose_turn",1);
me->start_busy(1);
check_pointer();
return 1; 
}
void end_the_round()
{
        string *good_ones = ({});
        string *tmp = ({});
        int total;
        int percent;
        int i,j,k;
        string *locss = ({"north","south","east","west"});
        int mm;
// sometimes the highest card holder out of money first, hehe
// Let's start withe person who put out the least, hopefully he/she can get his/her share
// He is either fold or out of money before it ends;
        if(query("table/status") == -1) return;
        set("table/status",-1);
        total = (int)query("table/total");
        for(mm=0;mm<sizeof(locss);mm++)
        if(query(locss[mm]+"/first") == query(locss[mm]+"/second"))
                set("table/R_"+locss[mm],(int)query(locss[mm]+"/first") * 10000);
        else
                set("table/R_"+locss[mm], ((int)query(locss[mm]+"/first") > (int)query(locss[mm]+"/second")? 
                (int)query(locss[mm]+"/first")*100+(int)query(locss[mm]+"/second") :
                (int)query(locss[mm]+"/second")*100+(int)query(locss[mm]+"/first")));
/*
        command("say "+sprintf("north %d, south %d, east %d, west %d\n",
                query("table/R_north"),
                query("table/R_south"),
                query("table/R_east"),
                query("table/R_west")));
*/
// put them in array good_ones according to money take out! skip those 0's
if(query("table/north") != 0  && !query("north/fold")){ tmp += ({ "north" });}
if(query("table/west") != 0 && !query("west/fold"))  { tmp += ({ "west" });}
if(query("table/south") != 0 && !query("south/fold")) { tmp += ({ "south" });}
if(query("table/east") != 0 && !query("east/fold")) { tmp += ({ "east" });} 
good_ones = sort_array(tmp,"sort_it",this_object());
// let's start with the lowest
        for(i=0;i<sizeof(good_ones);i++)
        {
        int history=0;
        int num_of_share=0;
        int sum=0;
                for(j=0;j<sizeof(good_ones);j++)
                {
// we assume we are the biggest and the only one
                        if((int)query("table/R_"+good_ones[j])> (int)query("table/R_"+good_ones[i]))
// we found someone who is bigger and last longer :) well, this guy is history
                        history=1;
                        else if((int)query("table/R_"+good_ones[j])== (int)query("table/R_"+good_ones[i]))
                                num_of_share++;
                }
                if(!history)
                {
// we can get something back!
                int mylevel;
                string *locs = ({"north","south","east","west"});
                int m;
                mylevel = (int)query("table/"+good_ones[i]);
                for(m=0;m<sizeof(locs);m++)
                if(query("table/"+locs[m])>mylevel)
                        {
                                add("table/"+locs[m],-mylevel);
                                sum += mylevel; 
                        }
                        else
                        {
                                sum += query("table/"+locs[m]);
                                set("table/"+locs[m],0); 
                        }
                for(j=0;j<sizeof(good_ones);j++)
                if((int)query("table/R_"+good_ones[j])== (int)query("table/R_"+good_ones[i]))
                        add("table/output_"+good_ones[j],sum/num_of_share); 
// already got chance!
                set("table/R_"+good_ones[i],-1);
                }// !history 
        }// i loop
// now casino takes query("my_percentage")%
        percent = (int) query("my_percentage");
                add("table/output_north",-(int)query("table/output_north") * percent/100);
                add("table/output_south",-(int)query("table/output_south") * percent/100);
                add("table/output_east",-(int)query("table/output_east") * percent/100);
                add("table/output_west",-(int)query("table/output_west") * percent/100);
        {
                string *locs = ({"north","south","east","west"});
                int m;
                string msg ;
                for(m=0;m<sizeof(locs);m++)
                        if(!(int)query(locs[m]+"/fold") && objectp(query(locs[m]+"/player"))
                                && query(locs[m]+"/first") && query(locs[m]+"/second"))
                {
                                msg = "say "+(query(locs[m]+"/player"))->name()+"－－"+
                        chinese_number((int)query(locs[m]+"/first"))+"、"+
                        chinese_number((int)query(locs[m]+"/second"))+ "\n";
                        command(msg);
                }
                for(m=0;m<sizeof(locs);m++)
                        if((int)query("table/output_"+locs[m]))
                        {

                        add(locs[m]+"/money",(int)query("table/output_"+locs[m]));
                                msg = "say "+ (query(locs[m]+"/player"))->name()+
                        "赢了"+chinese_number((int)query("table/output_"+locs[m]))+"两纹银。\n"; 
                command(msg);
                        }
// kick out link dead; and kick out 0-money people
        delete("table");
        set("table/status",-1);
                for(m=0;m<sizeof(locs);m++)
                {
                        object ob;
// they can quit or leave now
                        if(objectp(ob=query(locs[m]+"/player")))
                        ob->delete_temp("no_quit");
                        delete(locs[m]+"/fold");
                        delete(locs[m]+"/first");
                        delete(locs[m]+"/second");
                        if( objectp(ob=query(locs[m]+"/player")) && (int)query(locs[m]+"/money") <= 0)
// out of money
                        {
                                message_vision("$N对$n说道：＂您都输光了，下此再来吧！＂\n",this_object(),ob);
                                delete(locs[m]);        
                        }
                        if( objectp(ob=query(locs[m]+"/player")) && ob->query_temp("netdead"))
//link dead
                        {
                                pay_him(ob, (int)query(locs[m]+"/money")*100);
                                delete(locs[m]);
                        }                        
                }         
        }
                command("say 诸位稍等片刻，让我洗洗牌，再开始！\n");
                set("too_late",0);
                call_out("rolldice",10);
return;
}
void pay_him(object who, int amount)
{
        object ob;
object cash, tencash, gold, silver, coin; 
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
        int bet_type;
        string message;
        
                if( ob->value() >= 10000) {
                        say("白姨向你道了个万福，笑道：谢赏...\n");
                        return 1;
                } else {
                    say("白姨说道：这点钱你还是自己用吧！\n");
                        return 0;
                }
        return 0;
} 
void check_pointer()
{
// 3 things to check in here:
//  a. phase of this round
//  b. phase of this hand
//  c. conclude or not?
        string location="nowhere";
        int whohasmoney=0;
        int whohasnotfold=0;
        int last_bet=0;
        if(objectp(query("north/player")) && query("north/money") && !query("north/fold")) {whohasmoney++;location="north";}
        if(objectp(query("south/player")) && query("south/money") && !query("south/fold")) {whohasmoney++;location="south";}
        if(objectp(query("east/player")) && query("east/money") && !query("east/fold")) {whohasmoney++;location="east";}
        if(objectp(query("west/player")) && query("west/money") && !query("west/fold")) {whohasmoney++;location="west";}
        if(objectp(query("north/player")) && !query("north/fold")) whohasnotfold++;
        if(objectp(query("south/player")) && !query("south/fold")) whohasnotfold++;
        if(objectp(query("east/player")) && !query("east/fold")) whohasnotfold++;
        if(objectp(query("west/player")) && !query("west/fold")) whohasnotfold++;
        if((whohasmoney<=1 && query("table/r_"+location) >= query("table/round_high")) ||
        (whohasmoney<=1 && !query("table/r_north") && !query("table/r_south") &&
         !query("table/r_east") && !query("table/r_west"))
        )
        last_bet=1;
// step1: if everyone has put in as much as round high, expcept those alrady out of money
        if( last_bet==1 || whohasnotfold <=1 ||
((int)query("table/r_north") == (int)query("table/round_high") ||
 (int)query("north/money") == 0 || (int)query("north/fold")) 
 &&
((int)query("table/r_south") == (int)query("table/round_high") ||
 (int)query("south/money") == 0 || (int)query("south/fold")) 
 &&
((int)query("table/r_east") == (int)query("table/round_high") ||
 (int)query("east/money") == 0 || (int)query("east/fold")) 
 &&
((int)query("table/r_west") == (int)query("table/round_high") ||
 (int)query("west/money") == 0 || (int)query("west/fold")) 
        )
{
// see if we can end this game at this time, we can if only one person left,right?
if(can_end_round()) end_the_round();
else
{
switch((int)query("table/status"))
{
        int number;
        case 0:
// time to give 1st card and clear round_high and r_X:
message_vision("\n\n$N熟练已极地将桌上的象牙鹘牌在手里一转，开始给大家发第一张牌。\n\n",this_object());
// anyone who did not fold deserve a card!      
if(objectp(query("north/player")) && !(int)query("north/fold"))
{
        number = give_card();
tell_object(query("north/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("north/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("north/first",number);
}
if(objectp(query("west/player")) && !(int)query("west/fold"))
{
        number = give_card();
tell_object(query("west/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("west/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("west/first",number);
}
if(objectp(query("south/player")) && !(int)query("south/fold"))
{
        number = give_card();
tell_object(query("south/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("south/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("south/first",number);
}
if(objectp(query("east/player")) && !(int)query("east/fold"))
{
        number = give_card();
tell_object(query("east/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("east/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("east/first",number);
}
//clear some parameters
        set("table/r_north",0);
        set("table/r_south",0);
        set("table/r_east",0);
        set("table/r_west",0);
        set("table/round_high",(int)query("lower_limit"));
        add("table/status",1);
        find_next();
        break;
        case 1:
// time to give 2nd card and clear round_high and r_X:
message_vision("\n\n$N将桌上剩下的象牙鹘牌推了推，开始给大家发第二张牌。\n\n",this_object());
// anyone who did not fold deserve a card!
if(objectp(query("north/player")) && !(int)query("north/fold"))
{
        number = give_card();
tell_object(query("north/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("north/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("north/second",number);
}
if(objectp(query("west/player")) && !(int)query("west/fold"))
{
        number = give_card();
tell_object(query("west/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("west/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("west/second",number);
}
if(objectp(query("south/player")) && !(int)query("south/fold"))
{
        number = give_card();
tell_object(query("south/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("south/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("south/second",number);
}
if(objectp(query("east/player")) && !(int)query("east/fold"))
{
        number = give_card();
tell_object(query("east/player"),name()+"将一张晶莹剔透的鹘牌推到你面前。\n");
tell_object(query("east/player"),"你翻开一看：\n"+showdice(number)+"\n");
        set("east/second",number);
}
//clear some parameters
        set("table/r_north",0);
        set("table/r_south",0);
        set("table/r_east",0);
        set("table/r_west",0);
        set("table/round_high",(int)query("lower_limit"));
        add("table/status",1);
        find_next();
        break; 
}  
} 
return ;
}
else
{
// this round is not done yet, just check counter or increment to next person 
find_next();
}
return ;
}
void setup_card()
{
        set("cards",({ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,
                      14,15,16,17,18,19,20,21,22,23,24,25,
                      27,28,29,30,31,32,33,34,35,36,37,38,
                      40,41,42,43,44,45,46,47,48,49,50,51
                }));     
}
int give_card()
{
// Using daniel's suggestion here, 
int output;
int *cards;
        cards = query("cards");
        output = cards[random(sizeof(cards))];
        cards -= ({ output });
        set("cards", cards);
        return output%13;       
} 
int can_end_round()
{
        int not_fold = 0;
// if we are in stage2 and reach an equibilium, then we can end this game
        if((int)query("table/status") >=2) return 1;
        if(objectp(query("north/player")) && !query("north/fold")) not_fold++;
        if(objectp(query("south/player")) && !query("south/fold")) not_fold++;
        if(objectp(query("east/player")) && !query("east/fold")) not_fold++;
        if(objectp(query("west/player")) && !query("west/fold")) not_fold++;
if(not_fold <=1) return 1;
return 0;
}
void find_next()
{
        string location="nowhere";
        int whohasmoney=0;
        int whohasnotfold=0;
        int last_bet=0;
        if(objectp(query("north/player")) && query("north/money") && !query("north/fold")) {whohasmoney++;location="north";}
        if(objectp(query("south/player")) && query("south/money") && !query("south/fold")) {whohasmoney++;location="south";}
        if(objectp(query("east/player")) && query("east/money") && !query("east/fold")) {whohasmoney++;location="east";}
        if(objectp(query("west/player")) && query("west/money") && !query("west/fold")) {whohasmoney++;location="west";}
        if(objectp(query("north/player")) && !query("north/fold")) whohasnotfold++;
        if(objectp(query("south/player")) && !query("south/fold")) whohasnotfold++;
        if(objectp(query("east/player")) && !query("east/fold")) whohasnotfold++;
        if(objectp(query("west/player")) && !query("west/fold")) whohasnotfold++;
        if((whohasmoney<=1 && query("table/r_"+location) >= query("table/round_high")) ||
        ( whohasmoney <=1 && !query("table/r_north") && !query("table/r_south") &&
         !query("table/r_east") && !query("table/r_west"))
        )
        last_bet=1; 
        if( last_bet==1 || whohasnotfold <=1 ||
((int)query("table/r_north") == (int)query("table/round_high") ||
 (int)query("north/money") == 0 || (int)query("north/fold")) 
 &&
((int)query("table/r_south") == (int)query("table/round_high") ||
 (int)query("south/money") == 0 || (int)query("south/fold")) 
 &&
((int)query("table/r_east") == (int)query("table/round_high") ||
 (int)query("east/money") == 0 || (int)query("east/fold")) 
 &&
((int)query("table/r_west") == (int)query("table/round_high") ||
 (int)query("west/money") == 0 || (int)query("west/fold")) 
        ) 
        check_pointer();
switch ((int)query("whose_turn")%4)
{
        case 0: 
                if(objectp(query("north/player")) &&
                (int)query("north/money") > 0 &&
                !(int)query("north/fold")) 
tell_object(query("north/player"),name()+"对着"+
"你说道：＂这位"+ RANK_D->query_respect(query("north/player"))+
"轮到您说话了。＂\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 1: 
                if(objectp(query("west/player")) &&
                (int)query("west/money") > 0 &&
                !(int)query("west/fold")) 
tell_object(query("west/player"),name()+"对着"+
"你说道：＂这位"+ RANK_D->query_respect(query("west/player"))+
"轮到您说话了。＂\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 2: 
                if(objectp(query("south/player")) &&
                (int)query("south/money") > 0 &&
                !(int)query("south/fold")) 
tell_object(query("south/player"),name()+"对着"+
"你说道：＂这位"+ RANK_D->query_respect(query("south/player"))+
"轮到您说话了。＂\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return;
        case 3: 
                if(objectp(query("east/player")) &&
                (int)query("east/money") > 0 &&
                !(int)query("east/fold")) 
tell_object(query("east/player"),name()+"对着"+
"你说道：＂这位"+ RANK_D->query_respect(query("east/player"))+
"轮到您说话了。＂\n");
                else
                {
                        add("whose_turn",1);
                        check_pointer();
                }
                return; 
}
}
int sort_it(string a, string b)
{
return (int)query("table/"+a)-(int)query("table/"+b);
} 
string showdice(int num)
{
        string out;
        string *outs;
        string output="\n";
        int i;
        out = dice[num];
        outs = explode(out,"B");
        for(i=0;i<sizeof(outs);i++)
                output  += "          "+outs[i]+"\n";
        return output;
}
string showdice2(int num1, int num2)
{
        string out1,out2;
        string *outs1,*outs2;
        string output="\n";
        int i;
        out1 = dice[num1];
        out2 = dice[num2];
        
        outs1 = explode(out1,"B");
        outs2 = explode(out2,"B");
        for(i=0;i<sizeof(outs1);i++)
                output  += "          "+outs1[i]+"               "+outs2[i]+"\n";
        return output;
}  
int do_cards()
{
        object me;
        string location ="nowhere";
        me = this_player();
if( query("north/player") == me )  location = "north";
if( query("south/player") == me )  location = "south";
if( query("east/player") == me )  location = "east";
if( query("west/player") == me )  location = "west";
if(location == "nowhere") return 0;
if(query(location+"/first") && ! query(location+"/second"))
        tell_object(me,"你手里的骰牌是：\n"+showdice((int)query(location+"/first")));
else
if(query(location+"/first") &&  query(location+"/second"))
        tell_object(me,"你手里的骰牌是：\n"+showdice2((int)query(location+"/first"),(int)query(location+"/second")));
else tell_object(me,"你手里还没有牌呢！\n");
return 1;
}
void heart_beat()
{
        object player;
:: heart_beat();
// to help link-dead people
if( query("too_late") &&
        query("last_turn") == query("whose_turn") &&
        query("counter") >= 30)
{
        set("counter",0);
switch((int)query("whose_turn")%4)
{
        case 0: 
                if(objectp(player=query("north/player")))
                { 
                        message_vision("$N对$n说道：您睡着啦？那我就替您跟了吧！\n",this_object(),player);
                        do_bet2("",player);
                }
                return;
        case 1: 
                if(objectp(player=query("west/player")))
                { 
                        message_vision("$N对$n说道：您睡着啦？那我就替您跟了吧！\n",this_object(),player);
                        do_bet2("",player);
                }
                return;
        case 2: 
                if(objectp(player=query("south/player")))
                { 
                        message_vision("$N对$n说道：您睡着啦？那我就替您跟了吧！\n",this_object(),player);
                        do_bet2("",player);
                }
                return;
        case 3: 
                if(objectp(player=query("east/player")))
                { 
                        message_vision("$N对$n说道：您睡着啦？那我就替您跟了吧！\n",this_object(),player);
                        do_bet2("",player);
                }
                return;  
}
} 
else
        if(query("last_turn") == query("whose_turn"))
        add("counter",1);
else
        {
        set("last_turn",query("whose_turn"));
        set("counter",0);
        }
return;
}      
