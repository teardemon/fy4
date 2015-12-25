 // taoism.c
inherit SKILL;
void setup(){
        set("name", "天师正道");
        set("usage/literate", 1);
        set("type", "knowledge");
        set("effective_level", 200);
        set("learn_bonus", -50);
        set("practice_bonus", -25);
        set("black_white_ness", 30);
} 
int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼天师正道。\n");
        return 1;
}  
