#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
void create()
{
        set_name("翠浓",({"cuinong"}));
//      set("title","人如玉，玉生香");
        set("long","她长得也许并不算太美，但却有双会说话的眼睛，灵巧的嘴。她虽然只是静静地坐
在那里，但却自然地有种醉人的风姿和气质。一个这样的女人，无论对任何男人来
说都已足够。\n");
        set("gender","女性");
        set("age",22);
                
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
