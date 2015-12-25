 // foreknowledge.c
#include <ansi.h> 
inherit SKILL; 
void setup() {
        set("name", "占卜学");
        set("type", "knowledge");
        set("effective_level",50);
        set("learn_bonus", 10);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("foreknowledge", 1);
        if( s%10==9 && (int)me->query("kar") < s/5) {
                tell_object(me, HIW "由於对占卜学的更深一步的理解，你的运气提高了。\n" NOR);
//              me->add("kar", 2);
                me->set("kar",(s+1)/5);
        }
}        
