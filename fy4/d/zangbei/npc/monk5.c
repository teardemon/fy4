#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
int talkshow(); 
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("long", "这是直共寺打扫寺院的喇嘛。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
 
        ]));
                
        set("chat_chance", 1);
        set("chat_msg", ({
                (: talkshow() :), 
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
        
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        set_name("直共寺的喇嘛",({"zhigong lama","lama"}));
        set("force_factor",40);
        setup();
   carry_object(__DIR__"obj/lamacloth")->wear();
        
} 
int talkshow() {
        object room,*env,ob;
        int i;
        
        ob = this_object();
        env = all_inventory(environment(ob));
        for (i=0;i<sizeof(env);i++) {
                if (userp(env[i])) {
                        message_vision("$N往香炉里插了一炷香，低头合手，嘴里不知道在嘟囔些什么。\n",ob);
                        return 1;
                }
        }
        
        room=find_object(AREA_ZANGBEI"pine1");
        if (!objectp(room)) room= load_object(AREA_ZANGBEI"pine1");
        message("vision","直共寺的喇嘛走到树下，心神不宁地抬起头来，向东南角的树顶上看了一眼。\n",room);
        env=all_inventory(room);
        for (i=0;i<sizeof(env);i++)
                if(userp(env[i])) env[i]->set_temp("zangbei/树顶",1);
        return 1;
}  
