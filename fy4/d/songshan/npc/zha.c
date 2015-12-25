 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("札木合", ({ "muhe", "zha" }) );
        set("title", "无影神刀");
        set("gender", "男性" );
        set("age", 52);
        set("agi",35);
        set("str",35);
        set("long",
                "天下有名的第一快刀\n"
                );
        set("chat_chance", 1);
        set("chat_msg", ({
                "札木合道：我死得不明不白呀！可恨呀．．\n",
                (: random_move :),
        }) );
        set("max_force",1000);
        set("force", 1000);
        set("attitude", "peaceful");
        
        set_skill("blade", 200);
        set_skill("shenji-blade", 150);
        set_skill("shenji-steps",150);
        set_skill("dragonstrike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("perception",150);
            
        map_skill("unarmed", "dragonstrike");
        map_skill("dodge","shenji-steps");
        map_skill("blade","shenji-blade");
        
        set("combat_exp", 3000000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.shenjimiaosuan" :),
                (: perform_action, "blade.jichulianhuan" :),
        }) );  
   setup();
        carry_object(__DIR__"obj/dafeng")->wield();
}  
int is_ghost() { return 1; } 
void die(){
        object *inv, ob;
        int i;
        inv = all_inventory(this_object());
        if (random(5)) {
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("id") == "windblade") {
                        message_vision("$N恨恨地看了你一眼，一扬手把大风刀扔下山崖。\n",this_object()); 
                        destruct(ob);
                }
        }
        }
        ::die();        
}
