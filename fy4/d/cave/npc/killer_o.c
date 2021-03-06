 inherit NPC;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("亢金龙", ({ "killer o" }) );
        set("title",HIC"青龙杀手"NOR);
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
        set("attitude", "friendly");
        set("combat_exp", 1600000);
        set("attitude", "friendly");
        set("class","beggar");
        set("force",1000);
        set("max_force",1000);
        set("force_factor",30);
        
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("gouyee", 150);
        set_skill("staff",150);
        set_skill("dagou-stick",130);
        set_skill("doggiesteps",150);
        set_skill("dragonstrike",130);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "gouyee");
        map_skill("staff","dagou-stick");
        map_skill("dodge","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("move","doggiesteps");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/staff")->wield();
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                this_object()->perform_action("staff.tianxiawugou");
                return;
        }       
        while(i--) {
                if(enemy[i] && living(enemy[i])&& random(100)>50 ) {
                        this_object()->perform_action("staff.banzijue");
        }
        }
        return;
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
                HIW + name() + "一闪身，在黑暗中消失了。\n" NOR, environment(),
                this_object() );
        destruct(this_object());
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
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority") ){
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
} 
