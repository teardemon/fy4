 // 被丁鹏的魔刀击中后。。。
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{ 
        me->apply_condition("moon-blade", duration - 1);
        if( duration < 1 )
        {
                message_vision(HIG "$N忽然由顶自踵，分为两半，向两边倒去。\n" NOR ,me);
                me->receive_wound("kee",me->query("max_kee")+1000);
                return 0;
        }
         
        return 1;
}  
int condition_type()
{
// in condition.h
/* 
#define NO_CURE                 10
#define NON_POISON              9
#define BLOOD_POISON            8
#define NERVE_POISON            7
#define BRAIN_POISON            6
#define OBSCENE_POISON          5
#define GENERIC                 0 
*/ 
        return NO_CURE;
}
