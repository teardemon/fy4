#include <ansi.h>
inherit SMART_NPC;
inherit F_PAWNOWNER;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title","昆仑四鹫");
        set("nickname","天光，地光，人也光");
        set("long", "一条丈八的汉子坐在柜台后面闭目养神，两腿搁在桌上。这双腿黝黑如铁，
上面还长满了黑茸茸的毛，裤管直卷到膝盖。\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren");
                        
        set("max_atman",1000);
        set("atman",1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,180,0,"/d/eren2/npc/obj/","fighter_u","dragonstrike");
        set_name("轩辕三光",({"sanguang","san guang"}));
        set("age",40);
        set("gender","男性");
   set("str",50);
        set("force_factor",100);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem"); 
}    
