#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
void create()
{
    set_name("慕容明珠",({"murong mingzhu","murong","mingzhu" }));
//    set("title","虬髯巨汉");
    set("long","一个英俊的少年，长身玉立，神采飞扬。束金冠，紫罗衫，腰悬着长剑，剑鞘上的
宝石闪闪生光，腰上还束着紫金带，剑穗上悬着龙眼般大的一粒夜明珠。\n");
        set("gender","男性");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N满眼泪水地看了一眼屋子里的家具。。。。 \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "飞天蜘蛛道：“在下一时游戏，千万恕罪。”\n"
        }) );                   
        
           CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}
