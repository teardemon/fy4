#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 6000000);
        set("dungeon_npc","eren2");
        set("no_fly",1);
                
        set("max_atman", 1500);
        set("atman", 1500);
        set("max_mana", 1500);
        set("mana", 1500);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",70);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "小头目恨恨地说：老子在江湖上不是掌门也是个长老，在这里只能看门，真他妈的窝囊！\n",
        }) );
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,200,1,"/d/eren2/npc/obj/","all","all");
   set_name("小头目",({"lieutenant"}));
        set("title",RED"恶人窟"NOR);
        set("long", "这是一个恶人窟哨卡的小头目，两只眼睛正狐疑地看着你。\n");
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}        
