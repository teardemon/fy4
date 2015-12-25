 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "后帐");
        set("long", @LONG
后帐很小，帐角用铁钉钉的死死的，只在顶部留一个通气的小孔，中间柱子上
绑着一个十二三岁的男童。面前放着一个铁盆，盆里是几个风干的馒头和一杯浑浊
的水。小童呆呆地看着地下，似乎没有注意到有人进来。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"camp",
                        ]));
        set("objects", ([
                __DIR__"npc/sima" : 1,
        ]));
        set("indoor","eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init() {
        
        add_action("do_loose", "loose");
} 
int do_loose(string arg){
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();
        if (!arg && arg!="司马小烟"&& arg!="sima") {
                tell_object(me,"你想解什么？\n");
                return 1;
        }
        if (!ob=present("sima",this_object())) {
                tell_object(me,"这里没有这个人。\n");
                return 1;
        }
   if (ob->query("loose")) {
                tell_object(me,"他已经被解开了。\n");
                return 1;
        }
        message_vision(YEL"$N伸手将司马小烟从柱子上解了下来。"NOR,me);
        message_vision(YEL"叹了口气对$n说：“你回村去吧。“\n"NOR,me,ob);
        message_vision(YEL"$N痴痴呆呆地，似乎没有听到$n的话。\n\n"NOR,ob,me);
        ob->set("loose",1);
        me->start_busy(4);
        switch (random(2)) {
                case 0: me->set("marks/bandit_result",1);
                        call_out("kill_self",1,me,ob);
                        break;
                case 1: if (me->query("PKS")<20) {
                                me->set("marks/bandit_result",1);
                                call_out("kill_self",1,me,ob);
                                break;
                                }
                        me->set("marks/bandit_result",2);
                        call_out("kill_me",1,me,ob);
                        break;
                }
        return 1;
} 
void kill_self(object me,object ob) {
        
        message("vision",WHT"你反身向外走去，突然听到后面传来一些异响。\n"NOR,this_object());
        message_vision(WHT"$N转身一看，$n胸口插着一把匕首倒了下去。\n\n"NOR,me,ob);
        call_out("kill_self_2",1,ob);
        return;
} 
void kill_self_2(object ob) {
        message_vision(RED"$N惨笑着说：谢谢你来救我。我一直以为我父亲是个英雄，
没想到。。就让我的血来洗清他的耻辱吧。\n"NOR,ob);
        ob->die();
} 
void kill_me(object me,object ob) {
        
        message("vision",WHT"你反身向外走去，突然听到后面传来一些异响，只觉心口一凉，低头一看，胸
口露出一截短刃。"NOR,this_object());
   message_vision(WHT"$N回头望着$n，几乎不能相信自己的眼睛。\n\n"NOR,me,ob);
        call_out("kill_me_2",1,ob,me);
        return;
} 
void kill_me_2(object ob, object me) {
        object num;
        message_vision(RED"半晌，$N惨笑着说：对不起，我不想活在我父亲的阴影里，我不能让别人
知道我的过去。$N又道：你也不必觉得委屈，你杀的"+chinese_number(me->query("PKS"))+"人中，难道就没有
一个是不该死的？\n\n"NOR,ob);
        me->receive_wound("kee",30000,ob);
        destruct(ob);
        return;
}        
