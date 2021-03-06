 // weapon.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
#include <combat.h> 
inherit F_EQUIP;
inherit ITEM; 
mapping weapon_actions = ([
        "斩": ([        "damage_type"   : "割伤",
                        "action"                : "$N挥动$w，斩向$n的$l",
                        "parry"                 : 20    ]),
                                
        "砍": ([        "damage_type"   : "砍伤",
                        "action"                : "$N用$w往$n的$l砍去",
                        "dodge"                 : 20    ]),
        
        "劈": (["damage_type"   : "劈伤",
                        "action"                : "$N的$w朝著$n的$l劈将过去",
                        "parry"                 : -20   ]),
                        
        "刺": (["damage_type"   : "刺伤",
                        "action"                : "$N用$w往$n的$l刺去",
                        "dodge"                 : 15,
                        "parry"                 : -15   ]),
                        
        "抽": (["damage_type"   : "鞭伤",
                        "action"                : "$N将$w一扬，往$n的$l抽去",
                        "dodge"                 : -20,
                        "parry"                 : 30    ]),
                        
        "砸": (["damage_type"   : "瘀伤",
                        "action"                : "$N挥舞$w，往$n的$l用力一砸",
                        "post_action"   : "bash_weapon"         ]),
                        
        "射": (["damage_type"   : "刺伤",
                        "action"                : "$N将$w对准$n的$l射了过去",   
                        "post_action"   : "throw_weapon"        ])
]); 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
} 
void init_wield() {
        if(query("weapon_prop") 
                        && !query("weapon_prop/dodge") 
                        && (weight() >= 300000)) {
                set("weapon_prop/dodge", - weight() / 3000 );
        }
        if(!query("weapon_prop")) {
                set("weapon_prop/damage", 0);
        }
} 
mapping query_action() {
        string verb, *verbs;
        
        verbs = this_object()->query("verbs");
        
        if(!pointerp(verbs)) {
                return weapon_actions["hit"];
        } else {
                verb = verbs[random(sizeof(verbs))];
                if(!undefinedp(weapon_actions[verb])) {
                        return weapon_actions[verb];
                } else {
                        return weapon_actions["hit"];
                }
        }
} 
string throw_weapon(object me, object victim, int damage) {
        string result = "";
        object weapon = this_object();
        
        if((int)weapon->query_amount()<=2) {
                weapon->unequip();
                tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
                me->delete_temp("weapon");
   }
        weapon->add_amount(-1);
        return result;
} 
string bash_weapon(object me, object victim, int damage) {
        object ob, weapon = this_object();
        int wap, wdp, d;
        string result = "";
        
        if(!objectp(me) || !objectp(victim) || !objectp(ob = victim->query_temp("weapon"))) {
                return result;
        }
        
        if(damage==RESULT_PARRY) {
                wap = (int)weapon->weight() / 500  
                                + (int)weapon->query("rigidity") 
                                + (int)me->query_str() * 10; 
                wdp = (int)ob->weight() / 500
                                + (int)ob->query("rigidity")
                                + (int)victim->query_str() * 10;
                wap = random(wap);
                if(!random(10)&&wap > 5*(wdp/2+random(wdp))) {
                        result += HIW "只听见「啪」地一声，$n手中的" + ob->name() + "已经断为两截！\n" NOR;
                        ob->set("orig_name", ob->query("name"));
                        ob->set("name", "断掉的" + ob->query("name"));
                        d = ob->query("weapon_prop/damage") - 1;
                        ob->set("weapon_prop/damage",1);
                        ob->set("item_damaged", 1);
                        ob->set("value",0);
                        victim->add_temp("apply/damage",-d);
                        ob->save();
                } else if(!random(5) && wap > wdp/2+random(wdp/2) ) {
                        result += "$n只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR;
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > random(wdp / 2) ) {
                        result += "$n只觉得手中$v一震，险些脱手！\n";
                } else {
                        result += "$N的$w和$n的$v相击，冒出点点的火星。\n";
           }
        }
        return result;
} 
string wear_off(object me, object victim, int damage) {
        object ob, weapon = this_object();
        int wap, wdp, i;
        mapping armors;
        mixed* armor_keys;
        string result = "";
        
        if(!objectp(me) || !objectp(victim)) {
                return result;
        }
        
        ob = victim->query_temp("weapon");
        if(damage == RESULT_DODGE) {
                return result;
        }
        if(damage == RESULT_PARRY && objectp(ob)) {
                // we also use wap/(wap+wdp) formular
                wap = (int)weapon->weight() / 500 + (int)weapon->query("rigidity") 
                                + (int)me->query_str() * 10;
                wdp = (int)ob->weight() / 500 + (int)ob->query("rigidity") 
                                + (int)victim->query_str() * 10;
                // I don't think player can afford damage to their things 
                // every time two weapons hit each other
                if(!random(10) && random(wap) > random(wap+wdp)) {
                        result += HIW "$n手中的$v被磕出一个缺口！\n" NOR;
                        ob->add("weapon_prop/damage",-1);
                        if((int)ob->query("weapon_prop/damage") < 1 ) {
                                ob->set("weapon_prop/damage",1);
                        } else {
                                victim->add_temp("apply/damage",-1);
                        }
                        ob->set("item_damaged", 1);
                        ob->save();
                }
                if(!random(10) && random(wdp) > random(wap+wdp)) {
                        result += HIW "$N手中的$w被磕出一个缺口！\n" NOR;
                   weapon->add("weapon_prop/damage",-1);
                        if((int)weapon->query("weapon_prop/damage") < 1 ) {
                                weapon->set("weapon_prop/damage",1);
                        } else {
                                me->add_temp("apply/damage",-1);
                        }
                        weapon->set("item_damaged", 1);
                        weapon->save();
                }
        }
        if(damage > 20 && !random(20) && mapp(armors = victim->query_temp("armor")) && sizeof(armor_keys = keys(armors)) > 0) {
                ob = armors[armor_keys[random(sizeof(armor_keys))]];
                result += HIW "$n" + ob->query("armor_worn") + "的" +ob->name()
                                + "被弄坏了一点儿！\n" NOR;
                ob->add("armor_prop/armor",-1);
                if((int)ob->query("armor_prop/armor") < 0 ) {
                        ob->set("armor_prop/armor",0);
                } else {
                        victim->add_temp("apply/armor",-1);
                }
                ob->set("item_damaged", 1);
                ob->save();
        }
        
        return result;
}    
