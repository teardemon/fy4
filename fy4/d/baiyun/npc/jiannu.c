 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("剑奴" , ({ "swords slave","slave" }) );
    set("nickname",CYN"千载白云空悠悠"NOR);
    set("long", "当白云岛为人知晓时，他就在这里，没人知道他究竟多老，也没人知道他和叶\n孤城的关系，只知道从来没有旁门中人在剑林放肆，也没有外人能踏入白云岛\n潜龙泉一步。而他似乎只是静静的在这里清扫剑冢，日复一日，年复一年。\n");
        set("attitude", "friendly");
    set("age", 132);
        set("gender", "男性" );
        create_family("白云城",1, "剑冢守护人");
        set("chat_chance", 1);
        set("chat_msg", ({
        "剑奴驮着背，慢慢地轻轻地擦拭着剑林中的每一把剑。\n",
        }) );
    set("per",10);
    set("combat_exp", 30000000);
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianrenheyi" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}    
