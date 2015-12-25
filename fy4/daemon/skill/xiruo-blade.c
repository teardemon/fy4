 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without 
// the written permission from authors. 
inherit SKILL; 
void setup(){ 
        set("name", "息若刀法"); 
        set("usage/blade", 1); 
        set("usage/parry", 1); 
        set("practice_damage", 40); 
        set("effective_level", 250); 
        set("practice_bonus", -10); 
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
                "$n慢慢地将手中的$v立于身前，强烈的刀风将$N逼得连退几步。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n手中的$v慢慢地挥出，剧烈颤动的刀锋封向$N。\n", 
        }) );    
        action = ({ 
                ([      "action":               "$N手中的$w一晃，一招[心刀]砍向$n的$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":               "$N手中的$w狂舞，袭裹向$n的$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":               "$N持$w斩似流云，忽聚忽散地砍向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":               "$N晃动手中的$w，刀光忽隐忽现，砍向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "割伤" 
                ]), 
           ([      "action":               "$N运力于手中的$w，寒风般割向$n", 
                        "force":                200, 
                        "damage":               200, 
                        "damage_type":  "割伤" 
                ]), 
        }); 
} 
int valid_learn(object me){ 
        if( (int)me->query_skill("force", 1) < 100 ) { 
            return notify_fail("你的内功心法火候不足，无法练息若刀法。\n"); 
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
        return 1; 
} 
   
