 inherit NPC;
int direct();
void create()
{
        set_name("曲无容", ({ "wurong" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long",
                "一个全身黑袍的女孩子．．\n");
        set("combat_exp", 1800000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "曲无容指着姬冰雁道：你．．你真的不肯走？！！\n",
                "曲无容哼道：中原一点红，他真的爱我？？\n",
        }) );
        set("inquiry", ([
                "石观音" : (: direct :),
                "master guanyin" : (: direct :) 
        ])); 
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yaozhan" :),
            }) ); 
    set_skill("unarmed", 100);
    set_skill("blade", 150);
    set_skill("force", 100);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("kongshoudao", 120);
    set_skill("ghosty-force", 150);
    set_skill("ghosty-steps", 150); 
    map_skill("unarmed", "kongshoudao");
    map_skill("blade", "wind-blade");
    map_skill("force", "ghosty-force");
    map_skill("parry", "wind-blade");
    map_skill("dodge", "ghosty-steps"); 
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth")->wear(); 
} 
int direct()
{
        object me;
        object room;
        me = this_player();
        message_vision("$N对$n冷笑一声：你想见我师父？
那我就成全你！！\n",this_object(),me);
        room = load_object(AREA_GUANYIN"mirror");
        message_vision("$N脚下一松，整个人不见了！\n",me);
        me->move(room); 
        if(!me->query("m_success/巧见石观音"))
        {
                me->set("m_success/巧见石观音",1);
                me->add("score",50); 
        } 
        return 1;
}      
