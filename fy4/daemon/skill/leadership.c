 // leadership.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "用人之技");
        set("effective_level",160);
        set("type", "knowledge");
        set("learn_bonus", 20);
}
/*
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("leadership", 1);
        if( s%10==9 && (int)me->query("per") < s/5) {
                tell_object(me, HIW "由於你的勤学用人之技，你的魅力提高了。\n" NOR);
                me->add("per", 2);
        }
} 
*/  
