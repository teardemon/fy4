 inherit NPC;
void create()
{
        set_name("������", ({ "yellowman", "man"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�������µ�������\n");
        set("combat_exp", 150000);
        set("bellicosity", 30000 );
        set("attitude", "aggressive");
        set_skill("flying-dragon", 90);
        set_skill("dodge", 100);
        set_skill("unarmed", 20);
        set_skill("iron-cloth", 100);
        map_skill("unarmed", "flying-dragon");
                
        setup();
        add_money("coin", 50);
        carry_object("/obj/armor/cloth")->wear();
}       