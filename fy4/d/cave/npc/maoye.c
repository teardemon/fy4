#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("毛野", ({"mao ye","mao"}) );
    set("gender", "男性" );
    set("nickname", BLU"奄奄一息"NOR);
    set("title", "青龙会 分舵护法");
    set("long", "毛战的双胞胎兄弟，与高立一战中身受重伤，枪挑一腿，奄奄一息，\n只好躺在这破小床上养伤。\n");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("per", 6);
        set("combat_exp", 2500000);
        set("eff_kee", 1000);
        set("kee",3000);
        set("no_heal",1);
        set("class","beggar");
        
        set("str",36);
        set("force",1000);
        set("max_force", 1000);
        set("force_factor", 70);
        set("reward_npc", 1);
        set("difficulty", 3);
        
        set_temp("apply/armor", 100);
        
        set_skill("unarmed",200);
        set_skill("dragonstrike",160);
        set_skill("blade", 200);
        set_skill("shenji-blade", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("shenji-steps",150);
        
        map_skill("blade", "shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        map_skill("unarmed","dragonstrike");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "毛野痛苦地在床上挣扎着，嘶叫着：高。。立！我作鬼也要报这断腿之仇！\n",
        "毛野的断腿不停地渗出鲜血，床上都几乎染成红色，令人触目惊心。\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/duanblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
        add_money("gold", random(3));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority")){
            message_vision("$N恨声道：拿命来！大爷送你上西天见高立！\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
   }
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->query_skill("iron-cloth")>200 
                                && this_object()->query_temp("weapon")) {
                                command("say 好硬功!待我的降龙十八掌来会你!");
                                command("unwield all");
                        } else if (enemy[i]->query_skill("iron-cloth")<200)
                                command ("wield blade");
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.shenjimiaosuan");
}  
