 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "jian kuang","jian" }) );
    set("long", "�򽣶���Ϊ������\n");
        set("attitude", "friendly");
    set("age", 62);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",4);
    set("combat_exp", 3000000);
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
