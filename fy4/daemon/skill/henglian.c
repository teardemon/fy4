 // jin-gang.c
inherit SKILL;
void setup() {
        set("name", "十三太保横练");
        set("usage/iron-cloth", 1);
        set("effective_level", 150);
        set("bounce_ratio", 10);
        set("learn_bonus", -500);
        set("practice_bonus", -10);
        set("black_white_ness", 30);
        set("skill_class", "fugui");
        set("absorb_msg", ({
        "$n不闪不避，竟硬接了$N这一招。\n",
        "$n神气贯通，内劲运行全身上下，对抗$N的这一招。\n",
        "$n冷然一笑，两臂一震，已将$N的出招震开。\n",
        }) );
}  
int valid_learn(object me){
        
        if( (int)me->query_skill("skyforce",1) < (int)me->query_skill("henglian",1)) {
        return notify_fail("你的碧空心法修为不够，无法领悟更高深的十三太保横练。\n");
        }
        if( (string)me->query("gender") != "男性" ) {
        return notify_fail("十三太保横练是只有男子才能练的武功。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("十三太保横练只能通过学习来提高。\n");
                
}   
