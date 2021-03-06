 // Copyright (C) 1995, by Sinny Shi. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "丧乱帖");
        set("usage/unarmed", 1);
        set("effective_level", 120);
        set("practice_bonus", -10);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("parry_msg", ({
        "$n笔势如飞，瞬息之间「哀毒蓋深, 奈何奈何」八字令$N不知所措。 \n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n笔势如飞，瞬息之间「哀毒蓋深, 奈何奈何」八字令$N不知所措。 \n",
        }) );   
        action = ({
        ([      "action":               
"$N清啸一声，身形飘逸，指风如刀割向$n，纵横之间「羲之顿首」四字写的清刚峭拔，
卓尔不群。",
                "dodge":                -10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N身形大开大阖，「先墓再离荼毒」一气呵成，一笔一划尽是悲愤，狂风暴雨般洒向$n。",
                "dodge":                -30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N笔意抖变，出手迟缓凝重，似有千钧之力砸向$n的$l，写的正是「追惟酷甚」四字。",
                "dodge":                -50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥洒之间在$n的$l刻下「号慕摧绝，痛贯心肝」八字，其缩也凝重，似尺蠖之屈，其
纵也险劲，如狡兔之脱。 ",
                "dodge":                -70,
                "parry":                70,
                "damage":               180,
                "damage_type":  "刺伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
    if((int)me->query_skill("chessism", 1) < 20){
        return notify_fail("你的弈道修为不够，心浮气躁不宜练习『丧乱帖』。\n");
    }
    return 1;
}  
int practice_skill(object me)
{
        if( (int)me->query("force") < 25 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
        return 1;
}    
