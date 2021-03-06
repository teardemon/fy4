 // taolord.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int marriage();
int leave();
void create()
{
    set_name( "丁白云" , ({ "master ding", "master" }) );
    set("nickname",HIB "晴空白云" NOR);
    set("gender", "女性");
    set("age", 46);
    set("long",
        "丁白云是丁乘风的师妹，也是丁乘风的亲妹妹。丁白云年轻时遭白天羽抛弃，\n"
        "伤心欲绝，于是设计杀了白天羽后到此出家。\n"); 
    set("combat_exp", 10000000);
    set("score", 200000);
    set("reward_npc", 1);
        set("difficulty", 35); 
    set("class", "taoist"); 
    set("str", 20);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("force", 2000);
    set("max_force", 1000);
    set("force_factor", 30); 
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
    set("inquiry", ([
        "谷衣心法": 
        "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
        "三清宫": 
        "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
         "leave" : (: leave :),
        ]) ); 
    set("apprentice_available", 3);
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "drainerbolt" :),
        (: cast_spell, "invocation" :),
            }) ); 
    create_family("三清宫", 6, "女主持");
    set("rank_nogen",1);
    set("ranks",({"弟子","道童","道姑","散人","仙姑",YEL"玄女"NOR,YEL"副主持"NOR,
                      HIY"主持"NOR})); 
    set_skill("literate", 140);
    set_skill("force", 180);
    set_skill("spells", 200);
    set_skill("scratching",50);
    set_skill("move", 150);
    set_skill("unarmed", 120);
    set_skill("sword", 150);
    set_skill("tenderzhi", 150);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("gouyee", 150);
    set_skill("notracesnow", 180);
    set_skill("snowshade-sword", 120);
    set_skill("taoism", 200);
    set_skill("necromancy", 200);
    set_skill("scratmancy",50);
    set_skill("perception", 100);
    
    map_skill("spells", "necromancy");
    map_skill("unarmed", "tenderzhi");
    map_skill("parry", "snowshade-sword");
    map_skill("sword", "snowshade-sword");
    map_skill("move", "notracesnow");
    map_skill("dodge", "notracesnow");
    map_skill("force","gouyee"); 
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 20); 
    setup(); 
    carry_object(__DIR__"obj/sword2")->wield();
    carry_object(__DIR__"obj/robe2")->wear();
    carry_object(__DIR__"obj/hat2")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 贫道今天已经收了三个弟子，不想再收徒了。");
    }
} 
void do_recruit(object ob)
{
    
    if( (string)ob->query("gender") != "女性" )
        {
        command("say 贫道是出家人，不便收男徒，得罪了。");
                return;
        }
    else if(ob->query("marry") || ob->query("divorced")) {
                message_vision("$N抬头看了看$n，冷冷一笑：“这位姑娘是遇上负心人了吧。你把他杀了，再来找我。”\n", 
                                this_object(), ob);
                return;
        }  
    else if (ob->query("once_menpai/sanqing") && ob->query("divorced")) {
                message_vision("$N摇了摇头道：“你既叛出三清，不遵师嘱与人成婚，纵然你现在回心转意。。。\n",this_object());
                message_vision("$N说：“我如何还会再收你？“\n",this_object());
                return;
                }
    else if (ob->query_skill("scratmancy",1)>100) {
                message_vision("$N疑惑地看了看$n道：“你既是女子，却又学了我师兄的技艺。\n",this_object(),ob);
                message_vision("$N说：“我师兄一向只收男徒，不说清缘由，我不能随便收你。“\n",this_object());
                return;
                }
             
        command("say 嗯... 想入我三清宫？也好....");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/sanqing",1);
        ob->set("once_sanqing",1);
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
    add("apprentice_availavble", -1);
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("gender");
        id=victim->query("id");
        if(id_class == "女性"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n冷笑一声：贫道最看不得的就是欺压女子之徒！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy())  player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
   if (this_player()->query("class")!="taoist") return 0;
        message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
        return 1;
}  
int marriage () {
        if (this_player()->query("once_menpai/sanqing")){
                message_vision(CYN"$N道，凡我门人，当养生修道，莫要儿女情长。\n"NOR,this_object());
                message_vision(CYN"$N又道：若你执意为此要下山我也不能勉强，只是俗念一生，回头就难，切记！\n"NOR, this_object());
                this_player()->delete("once_sanqing");
                return 1;
        }
        return 0;
}  
