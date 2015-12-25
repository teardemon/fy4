 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("文士", ({ "wen shi", "zhen zhen"}) );
    set("gender", "男性" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "他平卧在雪地上，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的。鼻息间似乎已没有气息，不知道还有没有救。\n" 
        );
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 30);
    set("eff_kee", 30);
    set("eff_sen", 30);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_force", 3000);
    set("force", 3000); 
    set("combat_exp", 9999999);
    set_skill("unarmed", 100);
    set_skill("sword", 180);
    set_skill("force", 200);
    set_skill("move", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100);
    set_skill("perception", 100);
    set_skill("yunwu-strike", 150);
    set_skill("qingfengsword", 150);
    set_skill("xianjing", 150);
    set_skill("liuquan-steps", 100);
    map_skill("unarmed", "yunwu-strike");
    map_skill("sword", "qingfeng-sword");
    map_skill("force", "xianjing");
    map_skill("dodge", "liuquan-steps");
    set("chat_chance", 1); 
    set("chat_msg", ({ 
//              "风雪交加，文士仅穿着件单薄的文士衣衫，在寒风里不住地哆嗦着。\n", 
//              "看到你文士脸上泛出一丝笑意，那笑是亲切而温暖的。\n", 
        }) ); 
        set("cured", 0); 
        set("answered", 0);
    setup();
    carry_object("/obj/armor/cloth", 
                ([      "name" : "儒服",
                        "long" : "这是一件读书人常穿的儒服。\n"]) 
                )->wear();
    carry_object("/obj/armor/hat",
                ([ "name" : "方巾" ]) 
                )->wear();
}
 
void init(){ 
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) {  
                call_out("do_leave", 120); 
        }  
        if(find_call_out("do_selfcure") == -1 && !query("cured")) { 
                call_out("do_selfcure", 30); 
        } 
} 
 
void do_selfcure(){ 
        if(query("cured")) { 
                return; 
        } 
        message_vision("$N的手臂缓缓地动了一下。\n", this_object()); 
        message_vision("$N努力地鼓着最后的精力，站立了起来。虽然站的不稳，但他是站立着的。\n", 
                        this_object()); 
        set("long",  
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n" 
   ); 
        set("cured", 1); 
} 
void do_leave(){ 
        message_vision("\n$N拖着沉重的步伐缓缓离去，雪地上留下一溜深深的足迹。\n", this_object()); 
        destruct(this_object()); 
} 
 
int Cured(object me){ 
        if(!query("cured")) { 
                message_vision("$N极为困难的挣扎着坐了起来，定定地望着$n道：“你知道我是谁吗。”  
（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ）\n",  
                                this_object(), me);      
                set("long",  
                "他人是那么的樵悴而衰弱，面孔几乎没有一丝血色，像是刚从阴暗的坟
墓里走出来似的，伫立在清晨抖峭的风和雪里，显那样地不稳定，
虽然他想挺直地站着，然而却像随时都会跌倒。 \n" 
                ); 
                add_action("do_answer", "answer"); 
                set("cured", 1); 
                remove_call_out("do_leave"); 
                call_out("do_leave", 60); 
        } 
} 
 
int do_answer(string arg) { 
        object me; 
        me = this_player(); 
        if(!arg || (arg != "yes" && arg != "no")) { 
                return 0; 
        } 
        if(query("answered")){ 
                return 0; 
        } 
        if(arg == "yes") { 
                message_vision("$N微微一笑道：“阁下就是七妙神君。”\n", me); 
                message_vision("$N道：“好！既然如此，阁下一定也知道到哪里找我。今日一别，它日必当重报。”\n", 
                                this_object()); 
                me->set("marks/梅山民", 1); 
                do_leave(); 
   } else if(arg == "no") { 
                message_vision("$N神色茫然地摇了摇头。\n", me); 
                if(me->query("title") == "普通百姓") { 
                        message_vision("$N注视着$n，笑容自嘴边漾开。$N说道：“你如愿跟随着我，可到where find me”\n", this_object(), me); 
                        me->set("marks/梅山民", 3); 
                        do_leave(); 
                } else { 
                        message_vision("$N道：“在下七妙神君，它日有缘定当重谢。”\n", this_object()); 
                        me->set("marks/梅山民", 2); 
                        do_leave(); 
                } 
        } 
        return 1; 
} 
     
