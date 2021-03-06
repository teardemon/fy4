 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("吕恭", ({ "waiter" }) );
        set("gender", "男性" );
    set("title", "老板" );
        set("age", 62);
        set("long",
                "一个老头正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set_skill("iron-cloth", 2000);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 50);
        map_skill("unarmed", "bloodystrike");
        set("rank_info/respect", "老二哥");
        set("vendor_goods", ([
                __DIR__"obj/junksword":10,
                __DIR__"obj/junkblade":10,
                __DIR__"obj/junkstaff":10,
                __DIR__"obj/jade3":10,
                "/obj/item/bag":10,
        __DIR__"obj/huboots":2,
                __DIR__"obj/wineskin":10,
        __DIR__"obj/guskin":3,
                __DIR__"obj/sheep_leg":10,
                __DIR__"obj/snake_drug":10,
                __DIR__"obj/movebook":10, 
        ]) );
        setup();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
   }
        add_action("do_vendor_list", "list");
        add_action("do_rent","rent");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "店老板吕恭笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店老板吕恭用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "店老板吕恭说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅小店的酒吧，这几天才从窖子里开封的哟。\n");
                        break;
        }
} 
int do_rent(string arg)
{ 
        object ob, chefu;
        object me = this_player();
        object silver;
        if (arg != "carriage" && arg != "mache")
        {
                return notify_fail("你要租什么？\n");
        } 
        if (query("mark/rented"))
        {
                return notify_fail("马车已经租出去了 \n");
        }
        silver=present("silver_money", me);
    if(!silver) return notify_fail("你身上没有银子呀。\n");
        if (silver->query_amount()<8) return notify_fail("你的钱不够。\n");
    silver->add_amount(-8); 
        ob=new("/d/fy/npc/obj/carriage");
    ob->move(environment());
        message_vision("$N驶了过来 \n",ob); 
    chefu=new("/d/fy/npc/chefu");
    chefu->move(environment());
    chefu->get_quest("/d/guanwai/guanwaicarriageway");
    chefu->set_carriage(ob);
        message_vision("$N走了过来 \n",chefu); 
        set("mark/rented",1);
        message_vision("$N打开马车门，坐进了马车 \n",me);
        me->move(ob);
        chefu->go_now();
        
        call_out("check_rent_status",30,chefu);
        return 1;
} 
int check_rent_status(object ob)
{
        if (!ob)
        {
                set("mark/rented",0);
        }else
        {
                call_out("check_rent_status",30,ob);
        }
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/junksword":10,
                __DIR__"obj/junkblade":10,
                __DIR__"obj/junkstaff":10,
                __DIR__"obj/jade3":10,
                "/obj/item/bag":10,
        __DIR__"obj/huboots":2,
                __DIR__"obj/wineskin":10,
        __DIR__"obj/guskin":3,
                __DIR__"obj/sheep_leg":10,
                __DIR__"obj/snake_drug":10,
                __DIR__"obj/movebook":10, 
        ]) );
}       
