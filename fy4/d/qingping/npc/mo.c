 //XXder@fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("莫不屈" , ({ "buqu", "mo buqu", "mo" }) );
        set("long", "清平剑客的大弟子。\n");
        set("attitude", "friendly");
        set("age", 30);
        set("gender", "男性" );
        create_family("清平山庄", 1, "弟子");
        set("combat_exp", 1200000);
        set("force",500);
        set("max_force",500);
        set("force_factor",20);
        set_skill("dodge", 150);
        set_skill("sword", 160);
        set_skill("parry",120);
        set_skill("qingpingsword", 100);
        set_skill("force", 160);
        set_skill("qingpingforce", 150);
        set_skill("chaos-steps", 150);
        map_skill("parry","qingpingsword");
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}   
