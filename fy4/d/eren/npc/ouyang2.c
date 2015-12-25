#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title","昆仑四鹫");
        set("long", "此人又高又胖。园脸，肥颈，笑眯得起来的眼睛，慢条斯理的说话。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren"); 
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "小烟" : "村里的小孩，昨天还在这儿买豆腐来着。",
                 "欧阳豆腐铺" : "嘿嘿，咱兄弟开的豆腐铺。",
                 "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，他现在不行喽。",
                 "哈哈儿": "哈哈酒楼当然是哈哈儿开的喽，他现在不行喽。",
                "娇娇客栈": "娇娇客栈是屠娇娇的女儿开的。",
                "屠小娇": "娇娇客栈是屠娇娇的女儿屠小娇开的。",
                "恶人谷": "这恶人谷三字早已没人提了。",
                "燕南天": "燕大侠的名字谁人不晓，村里还有他的铁像呢。",
                "万春流": "万神医有起死回生之能。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "欧阳当笑了笑：什么陈婆豆腐麻辣豆腐，不上我的眼。\n",
                
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","fighter_u","all");
        set_name("欧阳当",({"ouyang dang"}));
        setup();
        carry_object("/obj/armor/cloth")->wear();
        
}   
