#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                             "唤狼术");
        set("type",                             "knowledge");
        set("learn_bonus",                      -100);
        set("practice_bonus",           -100);
        set("black_white_ness",         -100);
        set("effective_level",          100); 
} 
int valid_learn(object me)
{
        if( (int)me->query_skill("animal-training",1) < (int)me->query_skill("summonwolf",1)) {
                return notify_fail("你的训兽术不够精通，无法领悟更加高深的唤狼术。\n");
        }
        return 1;
} 
void skill_improved(object me)
{
    int s;
    s = me->query_skill("summonwolf", 1);
    if (s== 150 && me->query("class")=="wolfmount") {
       tell_object(me,HIW "你对唤狼之术的了解有了一个飞跃！\n"NOR);
       tell_object(me,HIW "你唤狼的个数增加了！\n"NOR);
       } 
    if (s== 180 && me->query("class")=="wolfmount") {
       tell_object(me,HIW "你对唤狼之术的了解有了一个飞跃！\n"NOR);
       tell_object(me,HIW "你可以在室内唤狼了！\n"NOR);
       }
} 
