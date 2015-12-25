#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "蝶恋花剑法");
        set("effective_level",  230);
        set("learn_bonus", -100);
        set("practice_bonus", -50);
        set("practice_limit",170);
        set("black_white_ness", 20);
        set("skill_class", "legend");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("parry_msg",  ({
        "$n使出一招「望极春愁」，手中的$v荡开了$N的$w。\n",
        "$n使出「黯黯生天际」，将$N的$w封于丈外。\n",
        "$n使出一招「强乐还无味」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「对酒当歌」，向$N拿$w的手腕削去。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n将手中的$v舞得密不透风，一招「拟对强衣为」封住了$N的攻势。\n",
        "$n反手一招「伫望黯草无」，整个人消失在一团剑光之中。\n",
        "$n使出一招「倚极黯色言」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招「把酒乐带伊」，迫得$N连连后退。\n",
        }) );
        action = ({
                ([              "action":
        "$N使一招「伫倚危楼风细细」，手中$w如柔风一般卷向$n的$l",
                "dodge":                20,
                                "force" :               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
        "$N使出蝶恋花剑中的「草色烟光残照里」，剑光象残照般洒向$n的$l",
                "dodge":                20,
                "force":               200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
                "$N一招「无言谁会凭栏意」，手中$w默默的削向$n的$l",
                "dodge":                30,
                "force":               50,
                "damage_type":  "割伤"
        ]),             
        ([      "action":               
                "$N手中$w一式「拟把疏狂图一醉」对准$n的$l一连刺出七剑",
                "force":                90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
                "$N的$w凭空一指，一招「衣带渐宽终不悔」刺向$n的$l",
                "dodge":                20,
         "force":               300,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
                "$N手中$w向外一分，使一招「为伊消得人憔悴」反手对准$n$l一剑刺去",
                "dodge":                20,
                "force":               100,
                "damage_type":  "刺伤"
        ]),
        });
}        
int valid_learn(object me)
{
                if(!::valid_learn(me)) {
                        return 0;
                }
        if((int)me->query("max_force") < 50 ) {
                return notify_fail("你的内力不够，没有办法练蝶恋花剑法。\n");
                } 
        return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 10) {
        return notify_fail("你的内力或气不够，没有办法练习蝶恋花剑法。\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("你按著所学练了一遍蝶恋花剑法。\n");
    return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 300 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "blade")
        if(victim->query_skill_mapped("blade") == "shortsong-blade" )
        if(me->query_skill("sword") > victim->query_skill("blade")) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n因刀剑相克，$n逐渐施展不开了！" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("sword")) * 4;
        }
        return 0;
}  
