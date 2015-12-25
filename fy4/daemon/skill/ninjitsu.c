 // ninjitsu.c
inherit SKILL; 
void setup(){
        set("name", "忍术");
        set("usage/magic", 1);
        set("skill_class", "ninja");
        set("effective_level", 180);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
}
int practice_skill(object me)
{
        return notify_fail("忍术只能用学的。\n");
} 
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("天枫十四郎未答应转授你这门武功。\n");
        if ((int)me->query("tianfeng/ninjitsu")!=1){
                return notify_fail("天枫十四郎未答应教你这门武功。\n");
        }
        return 1;
}
