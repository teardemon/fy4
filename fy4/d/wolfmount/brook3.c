#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "浣花溪"); 
        set("long", @LONG
一道清澈见底的泉水从两旁的山中溅落下来，嘈嘈切切错杂弹地，大珠小珠似
雨打玉盘，两旁山花烂漫，溪水中各色缤纷的花瓣随着溪水静静地流淌，一切美丽
如画。泉水浅浅可行，逆流而上，可看到不远处白云深处的泉水源头有个湖泊。
LONG); 
        set("type","waterbody");
        set("exits",([
                "south":__DIR__"sunlake",
                "northeast":__DIR__"brook",
        ]) );
       set("outdoors", "wolfmount");
        set("objects",([
                __DIR__"npc/xiaoma":1,
        ]) ); 
        set("coor/x",-750);
        set("coor/y",-750);
        set("coor/z",60);
        setup(); 
} 
void init(){
        object me;
        me = this_player();
        if(!me->query("imbue/xiaoma") && me->query("marks/杀太阳使者") && present("xiao ma", this_object())) {
                if(me->query_temp("marks/wolf_xiaoma_good") ) {
                        call_out("imbue_event", 2, me, 0);
                } else if (me->query_temp("marks/wolf_xiaoma_normal")) {
                        call_out("imbue_event", 2, me, 1);
                }
        }
} 
void imbue_event(object me, int j){
        object xiaoma, weapon, obj, *inv;
        string prop;
        int i;
        if(!interactive(me) || environment(me) != this_object()){
           return 0;
        }
        xiaoma = present("xiao ma", this_object());
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        message_vision("\n$N用力拍著$n的背，一副「好小子！干的好」的表情。\n", xiaoma, me);
        message_vision("$N突然跳了起来，伤口扯动之下$N痛地哇哇直叫，豆大的汗水吧嗒吧嗒掉了下来。。。\n", xiaoma, me);
        if(!objectp(weapon)){
                if(objectp(obj)){
                        message_vision(HIR"\n掺杂着血水的汗珠掉在$N的\n" + obj->name() + HIR"上，又滚落地上。\n"NOR, me);
                } else {
                        message_vision(HIR"\n掺杂着血水的汗珠掉在了地上。\n"NOR, me);
                }
        } else {
                message_vision(HIR"\n掺杂着血水的汗珠掉在$N的" + weapon->name() + HIR"上，一转瞬，又化为水雾消逝地无影无踪。。。\n"NOR, me);      
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                        if(j == 0 ) {
                                weapon->add(prop+"strength", 5);
                                weapon->add(prop+"tolerance", 5);
                                weapon->add(prop+"rigidity", 100);
                        } else if (j == 1) {
                                weapon->add(prop+"strength", 2);
                                weapon->add(prop+"rigidity", 50);
                        }
                        weapon->wield();
                } else {
                   if(j == 0 ) {
                                weapon->add(prop+"strength", 5);
                                weapon->add(prop+"tolerance", 5);
                                weapon->add(prop+"rigidity", 100);
                        } else if (j == 1) {
                                weapon->add(prop+"strength", 2);
                                weapon->add(prop+"rigidity", 50);
                        }
                }
                weapon->save();
                me->set("imbue/xiaoma", 1);
                me->save();
                return ;
        } 
        me->set("imbue/xiaoma", 2);
        me->save();
        return;
}       
