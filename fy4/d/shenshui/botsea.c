 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "海底");
    set("long", @LONG
这里是一片宁静的深蓝，那种深蓝很容易令人联想到夏日的夜空。海底铺满了
一层洁白的沙，几块长满珊瑚的礁石散布在沙地上，柔长的海草微微的摇摆着，偶
尔有几条小鱼游过，却不能打破这里的幽寂。
LONG
        );
        set("exits", ([
                "up" : __DIR__"midsea", 
        ]) );
        set("item_desc",([
                "sand" : "洁白的细沙铺在海底，下面似乎有什么东西。\n", 
                "沙" : "洁白的细沙铺在海底，下面似乎有什么东西。\n", 
        ]) );
        set("no_fly",1);
        set("count",1);
        set("coor/x",190);
        set("coor/y",12310);
        set("coor/z",-70);
        setup();
} 
void init(){
        object me;
        me = this_player();
        if(userp(me) && !me->query_temp("apply/use_under_water")){
                call_out("airing", 5, this_player());
        }
        add_action("do_search", "search");
        if(!random(20)){
                call_out("see_light", 3, this_player());
        }
} 
int do_search(){
        object me;
        me = this_player();
    
        if(me->is_busy()) {
                return notify_fail("你正在忙。\n");
        }
        if(me->is_fighting()){
                return notify_fail("还是先打完再说吧。\n");
        }
        message_vision("$N在海底仔细搜寻。\n", me);
        me->start_busy(2);
        call_out("result", 4, me);
        return 1;
} 
int result(object me) {
        object seashell;
        if(environment(me) == this_object()){
                if(!random(5) && !present("sea shell", this_object()) && query("count")) {
                        tell_object(me, "\n你忽然摸到一个大海蚌。\n");
                        message_vision(HIC"\n你只觉得一丝蓝莹莹的光从眼前一闪而逝。\n"NOR, me);
                        message_vision("海蚌微微动了一下，蚌壳紧紧闭上了。\n", me);
                        seashell = new(__DIR__"obj/seashell");
                        seashell->move(this_object());
                        set("count",0);
                        return 1;
                }
                tell_object(me, "你什么也没有发现。\n");
        }
    return 1;
} 
int see_light(object me){
        if(environment(me) == this_object()) {
                message("vision", HIC"\n一道蓝莹莹的微光一闪而逝。\n"NOR, environment(me));
        }
} 
int valid_leave(string dir){
        object me;
        me = this_player();
        if(dir == "up" && me->query_temp("marks/水时")) {
                me->delete_temp("marks/水时");
        }
        message_vision("$N蹬了蹬腿向上游去。\n", me);
           return 1;
} 
int airing(object ob)
{
        int i, htime, ntime;
    
        if(ob->query_temp("apply/use_under_water")) {
                return 1;
        }
        if(environment(ob) == this_object()){
                htime = (int)ob->query_str() + (int)ob->query_kar();
        if(!(ntime = (int)ob->query_temp("marks/水时"))) {  
                ntime = 5;
        } else {
                ntime = ntime + 5;
        }
        ob->set_temp("marks/水时", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/水时", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N已经憋得成半昏迷状态，再不出赶快出水，就会憋死在这儿。\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N已经憋得面红耳赤，半分中之内再不出水，恐怕会憋死在这儿。\n"NOR, ob);
        else 
            message_vision(HIB "$N觉得胸口越来越闷，大概在水里已呆不了很久。\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
}  
void reset(){
        ::reset();
        set("count",1);
}   
