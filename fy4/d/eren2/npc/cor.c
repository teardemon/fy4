#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("巨鳄", ({ "gator" }) );
        set("race", "野兽");
        set("age", 400);
        set("long", "一条丈长的鳄鱼，不知在这暗河里已生活了多久。\n");
        set("limbs", ({ "头部", "身体", "尾巴", "眼睛" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set("combat_exp",1000000);
        set("gin",5000);
        set("kee",5000);
        set("sen",5000);
        set("cps",100);
        set("cor",50);
        set("str",80);
        add_temp("apply/dodge",300);
        add_temp("apply/attack",300);
        setup();
        carry_object(__DIR__"obj/gatorarmor1");
}    
