#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
int estate(); 
void create()
{
        set_name("陆漫天",({"lu mantian","lu"}));
        set("long","
这人的身材高大，很魁伟穿着件淡青色的长袍，花白的头发挽了发髻，手
里叮当作响，像是握着两枚铁胆。\n");
        
        set("gender","男性");
        
        set("age",72);          
        set("int",52);
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
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
 
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
           set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","longfenghuan",1);
        
        setup();
        carry_object(__DIR__"obj/cyancloth")->wear();
 
}       
