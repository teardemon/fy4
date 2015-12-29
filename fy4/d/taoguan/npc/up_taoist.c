 // tao_2.c
inherit NPC; 
void create()
{
        set_name("��ɽʹ��", ({ "taoist guard", "guard" }) );
        set("gender", "����");
        set("age", 32);
        set("long",
"��ɽʹ�������幬�Ļ�������һ����ɫ�ĵ��ۡ�\n"
);
        set("combat_exp", 50000);
        set("score", 200); 
        set("class", "taoist");
        set("fly_target",1); 
        set("gin",1400);
        set("max_gin",1400);
        set("eff_gin",1400);
        
        set("atman", 1200);
        set("max_atman", 1200); 
        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1); 
        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) ); 
        create_family("���幬", 7, "����"); 
        set_skill("literate", 50);
        set_skill("magic", 30);
        set_skill("move", 30);
        set_skill("force", 30);
        set_skill("spells", 60);
        set_skill("unarmed", 50);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 40);
        set_skill("gouyee", 60); 
        map_skill("force", "gouyee"); 
        set_skill("taoism", 70);
        set_skill("necromancy", 50);     
        map_skill("spells", "necromancy"); 
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30); 
        setup(); 
        add_money("coin", 30);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear();
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
  
int heal_up()
{
        if(environment() && !is_fighting() 
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//         command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
}      