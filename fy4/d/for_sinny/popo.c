 // keeper.c
/*inherit NPC; 
void create()
{
        set_name("婆婆", ({ "popo" }) );
        set("gender", "女性" );
        set("age", 80);
        set("long",
"这个老婆婆象天使一样保护着孩子们。\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear(); 
} 
void init()
{       
        object ob;
                add_action("do_ask_baby","ling");
                add_action("do_ask_baby","ask_baby");
                add_action("do_return_baby","return_baby");
                add_action("do_return_baby","tuo");
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "老婆婆说道：这位" + RANK_D->query_respect(ob)
                + "是来领(ling)你的孩子还是托养孩子(tuo)的的\n");
} 
int do_ask_baby(string arg)
{
        object me;
        object baby;
        me=this_player();
        if(baby=BABY_D->get_baby(me))
           if(!baby->move(me))
                        baby->move(environment(me));
        return 1;
} 
int do_return_baby(string arg)
{
        object me,baby;
        if(!arg)        return 0;
        me=this_player();
//      baby=find_object(arg)
        if(baby=present(arg,me))
        {
        BABY_D->return_home(baby);
        destruct(baby);
        return 1;
        }
        return 0;
} */      
