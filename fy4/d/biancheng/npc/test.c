 // waiter.c
inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("试验品", ({ "afa" }) );
        set("title", "小鲁班");
        set("gender", "男性" );
        set("age", 35);
        set("long",
                "这里很暗，你看不清阿发的样子\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",5);
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        victim->receive_wound("kee",150);
        return HIR "火焰长刀喷出一股猩红的火焰，燎烤着$n的全身。\n" NOR;
}      
