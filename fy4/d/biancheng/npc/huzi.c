#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
void create()
{
        set_name("小虎子",({"xiao huzi","huzi"}));
//      set("title","人如玉，玉生香");
        set("long","孩子满身红衣，头上一根冲天杵小辫子，也用条红绸带系住，身子长得虽然特别瘦
小，但眼睛却特别大，一双乌溜溜的眼珠子，不停地转来转去，显得又活泼、又机灵。。\n");
        set("gender","女性");
        set("age",32);
                
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
        
        
        set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "乐先生正色道：“洗澡最伤元气，那是万万洗不得的。”\n"
        }) );                   
        
           CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
} 
