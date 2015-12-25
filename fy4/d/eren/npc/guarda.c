#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("title",YEL"恶人窟守卫"NOR);
        set("long", "这是一位恶人窟专门担任巡护之责的弟子。\n");
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        
        set("resistance/gin",40);
        set("resistance/kee",40);
        set("resistance/sen",40);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","all","all");
        setup();
        
        carry_object(__DIR__"obj/g_armor")->wear();
}         
