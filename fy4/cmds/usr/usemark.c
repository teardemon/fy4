#include <ansi.h>
inherit SSERVER; 
int main(object me, string arg)
{
        string roomname;
        object room;
        int skill,atman;
        if( (skill=me->query_skill("incarnation",1)) < 160 )
                return notify_fail("需要１６０级修仙术才能使用时空转换！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用仙法！\n");
        if( (atman=me->query("atman")) < 50 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用仙法！\n");     
        if( !(roomname=me->query_temp("timespacemark")))
                return notify_fail("你没有设定道标。\n");
        if( time()>me->query_temp("timespacemark_time"))
                return notify_fail("你设定的道标已经失效了。\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("此地不能使用时空转换。\n");
        if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly"))
                return notify_fail("此地不能使用时空转换。\n");
        
        me->add("atman", -50);
        me->receive_damage("gin", 100);
        if( random(atman/5+(skill-90)/2+180) <100)      {
                 message_vision( HIY "$N手指掐诀，口中默念，但什么事也没发生。\n" NOR, me);
                 return notify_fail("你的［时空转换］失败了。\n");      
                }
        message_vision( HIY "$N手指掐诀，口中默念，忽然化作一股青烟消失了 ....\n" NOR, me);
        room = load_object(roomname);
        me->move(room);
        message( "vision", HIY "\n忽然一股青烟从地上冒出，"+me->query("name")+"从烟雾中出现！\n\n" NOR,
                room, ({ me }) );
        return 1;
} 
