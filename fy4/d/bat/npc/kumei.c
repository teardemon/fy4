#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    set("nickname", HIW "铁仙姑" NOR);
    set("gender", "女性");
    create_family("华山派", 16, "掌门");
    set("student_title","弟子");
    set("age", 59);  
    set("str", 25);
    set("int", 30);
    set("con", 25);
    set("kee", 50000);
    set("max_kee", 50000);
    set("gin", 2000);
    set("max_gin", 2000);
    set("force", 9000);
    set("max_force", 9000);
    set("force_factor", 30);
    set("combat_exp", 1500000);
    set("attitude", "friendly");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "sword.pochan" :),
            (: perform_action, "sword.poqi" :),
            }) ); 
    set_skill("unarmed", 70);
    set_skill("move", 100);
    set_skill("dodge", 100);
    set_skill("parry", 90);
    set_skill("literate",100);
    set_skill("force", 90);
    set_skill("sword", 150);
    set_skill("meng-steps", 150);
    set_skill("dugu-sword", 140);
    set_skill("wuzheng-force", 220);
    map_skill("force", "wuzheng-force");
    map_skill("move", "meng-steps");
    map_skill("parry", "dugu-sword");
    map_skill("sword", "dugu-sword");
    map_skill("dodge", "meng-steps"); 
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    
    setup();
    carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "蓝缎袍" NOR,
                        "long"  :       0 ])
                )->wear();
    carry_object("/obj/weapon/sword")->wield(); 
} 
void init()
{
    object ob;
    ob=this_player();
   if ((int)ob->query("marks/killed_yuan")==1 )
       {
           ob->delete("marks/killed_yuan");
           kill_ob(ob);
       }
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("sword",1) < 100) {
         command("say  你对剑术所知甚少，竟然想来拜我！");
                return;
    }
    if ((int)ob->query_skill("move",1) < 100 ) {
        command("say 阁下的身法似乎不能学武啊！");
                return;
    }
    if( (int) ob->query("marks/杀楚留香") == 1 )
     { 
    command("smile");
    command("recruit " + ob->query("id"));
    ob->delete("marks/杀楚留香");
     }
     else   
     command("say 老身在此世上仇家倒不多，只有一人会坏我的大事...");
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}    
