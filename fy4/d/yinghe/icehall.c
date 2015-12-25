 // FYTeam
#include <ansi.h>
inherit ROOM; 
void create(){
        set("short", "玄冰环堡");
        set("long", @LONG
这是一座环形的城堡，四周高大的墙壁透射着一种微弱而神秘的光芒。这幽光
没有给人丝毫光明的感觉，反而带来无尽的幽暗和冷寂。这里寒气如刀如剑，冷得
令人几乎血液凝固。
LONG); 
        set("objects", ([
                __DIR__"npc/water_guard" : 1,
        ]));
        set("exits",([
        "south":__DIR__"center",
        "north":__DIR__"mudpath",
        ]) ); 
        set("indoors", "yinghe");
        setup();
} 
void init(){
        object me, *inv;
        int i;
        me = this_player();
        if(userp(me)){
                inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("bigcloth") && inv[i]->query("equipped") == "worn"){
                        message_vision(HIW "\n城堡中传来森森寒气，还好，$N有白裘劲装保暖。\n\n"NOR, me);
                        return;
                } else {
                        message_vision(HIW "\n城堡中传来森森寒气透入$N身体。\n\n"NOR, me);
                        call_out("frozen", 120, me);
                        return;
                        }
        } 
        }
} 
void frozen(object me){
        if(!interactive(me) || environment(me) != this_object()){
           return;
        }
        message_vision(HIW "\n阵阵寒气忽然流遍$N的身体，$N只觉得四肢僵痹，竟然动弹不得。\n\n"NOR, me);
        me->set_temp("disable_inputs",1);
        me->set("disable_type",HIW "<冻僵中>"NOR);
    me->set_temp("is_unconcious",1);
        call_out("remove_frozen", 10, me);
        return;
} 
void remove_frozen(object me){
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
    message_vision(HIR "\n$N强运内力，冲开了麻痹肢体的玄冰寒气！！\n\n"NOR, me);
        call_out("frozen", 60, me);     
} 
int valid_leave(object ob, string dir){
        object guard;
        guard = present("water guard", this_object());
        if(dir == "north" && objectp(guard)){
                return notify_fail("冷卿元冷笑道：玄冰环堡岂是说来就来说走就走的地方？！\n");
        }
        if(dir == "south" && ob->query("attribute/mark") != "water" && objectp(guard)){
                return notify_fail("冷卿元伸手一栏：玄冰环堡岂是说来就来说走就走的地方？！\n");
        }
        return 1;
}
