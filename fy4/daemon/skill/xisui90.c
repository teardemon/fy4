 inherit SKILL;
void setup(){
        set("name", "洗髓经");
        set("usage/iron-cloth", 1);
        set("effective_level", 200);
        set("bounce_ratio", 8);
        set("learn_bonus", -70);
        set("practice_bonus", -20);
        set("black_white_ness", 30);
        set("effect",90);
        set("skill_class", "shaolin");
        
        set("absorb_msg", ({
        "$N如击败革，一股大力从$n身上反弹回来。\n",
        "$n全身似已脱胎换骨，一股弹力反击入$N。\n",
        }) );   
} 
int practice_skill(object me)
{
        return notify_fail("洗髓经只能通过学习来提高。\n");
                
} 
