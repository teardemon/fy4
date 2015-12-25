#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit SMART_NPC;
int kill_him(); 
void create()
{ 
        set_name("袁秋云",({"yuan qiuyun","yuan","qiuyun"}));
        set("title",WHT"白云山庄庄主"NOR);
        set("long", "这人当然已是个老人，是个很有威仪的老人。他穿着也极考究，态度却比柳东来还
严肃有威，\n");
        set("age",59);
        set("combat_exp", 6400000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "白天羽" : (: kill_him :),
        ]));
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
   
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("xuebin",250,180,1,"/obj/weapon/","fighter_w","taiji");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"袁秋云现在没空回答你。\n");
                return 1;
                }
        message_vision(CYN"$N的笑声突然停顿，目光中忽然露出恐惧之色，一张严肃的脸，也突然变得扭
曲变形，失色道：“你是白……白大侠的什么人？”\n",this_object());
        return 1;
}  
