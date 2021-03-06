 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("沈银枪", ({ "shen yinqiang" }) );
        set("gender", "男性");
        set("age", 18);
        set("long",
"这位武林名人在冷冷瞧着你，眼神中带着惊讶，也带着怜悯。\n"
);
        set("inquiry", ([
            "俞独鹤" : (: kill_him :),
             "俞放鹤" : (: fanghe :),
              "俞佩玉" : (: peiyu :),
   ]));
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "沈银枪笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
                "沈银枪道：好地方呀好地方！\n",
        }) );
          
        set("attitude", "friendly");
        set("title","宜兴");
        set("nickname", HIW"宝马银枪"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","fugui");
        
        set("combat_exp", 4500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("skyforce", 150);
        set_skill("hawk-steps",150);
        set_skill("eagle-claw",150);
        set_skill("xuezhan-spear",140);
        
        map_skill("unarmed","eagle-claw");
        map_skill("force", "skyforce");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps");
        map_skill("parry","xuezhan-spear");
        map_skill("spear","xuezhan-spear");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/spear")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int fanghe()
{
    command( "say 放鹤兄是我先天无极门的掌门人。");     
    return 1;
}  
int peiyu()
{
    command ("say 这小子是我义兄不成材的儿子。");
    return 1;
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
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        }
                }
   }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }
