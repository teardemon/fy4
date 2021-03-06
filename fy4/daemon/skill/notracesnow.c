 // notracesnow.c
inherit SKILL;
void setup(){
        set("name", "踏雪无痕");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 120);
        set("learn_bonus", 20);
        set("practice_bonus", 0);
        set("black_white_ness", -10);
        set("skill_class", "bonze");
        set("dodge_msg", ({
        "$n一招「夕阳残雪」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「腾云驾雾」早已避在七尺之外。\n",
        "$n使出「鱼翔蓝天」，轻轻松松地闪过。\n",
        "$n左足一点，一招「步履云端」腾空而起，避了开去。\n",
        "可是$n使一招「踏雪无痕」，身子轻轻飘了开去。\n",
        "$n身影微动，已经藉一招「龙腾万里」轻轻闪过。\n"
        }) );
} 
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 50 ) {
        return notify_fail("你的内力不够，没有办法练踏雪无痕。\n");
        }
    return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ){
        return notify_fail("你的气或内力不够，不能练踏雪无痕。\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -3);
    return 1;
}      
