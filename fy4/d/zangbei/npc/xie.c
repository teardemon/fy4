#include <ansi.h>
#include <command.h>
inherit "/d/taiping/npc/smart_npc"; 
void throw_away(object ob); 
void create()
{ 
        set_name("谢小玉",({"xie xiaoyu","xie","xiaoyu"}));
        set("title",HIG"神剑山庄"NOR);
        set("long", "
谢小玉给人的印象绝对是尊女神。她在白纱隐约中暴露了所有的女性的特征，只不
过那是一种美感、一种神圣而庄严的美感，仿佛她全身都发着一股圣洁的光，使人
不敢逼视。使人愿意奉献一切，成为神前的牺牲。\n"); 
        set("age",20);
        set("combat_exp", 7500000);
        set("class","swordsman");               
        set("attitude","friendly");
        
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      set("death_msg",CYN"\n$N说：老二老三会为我报仇的。啊啊啊。。。 \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: auto_smart_fight(20) :),
        }) );            
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+dabei",2);
                
        setup();
        carry_object("obj/armor/cloth")->wear(); 
}  
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        string my_position;
        if( !ob || environment(ob) != environment()) return;
        command("say 你怎么会闯到这里来的？快出去！否则就没机会了。");
        call_out("throw_away",10,ob);
} 
void throw_away(object ob) {
        if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
}       
