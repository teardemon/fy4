#include <ansi.h>
inherit ROOM; 
void create()
{
        object          item, con; 
        set("short", "山崖边");
        set("long", @LONG
前面是一道深不见底的万丈深渊。下面白云缭绕，什么都看不见，
就连死人的幽灵都看不见。难道那幽灵山庄就在这万丈深渊之下？
LONG
        );
        set("exits", ([
                "west" : __DIR__"forest7",
                "south" : __DIR__"forest6",
        ]));
        set("objects", ([
                __DIR__"obj/rock" : 1,
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1190);
        set("coor/y",-100);
        set("coor/z",-20);
        setup();
} 
void init()
{
        object me;
        object          *inv;
        object          con, item;
        int             i;
        
        con = present("rock", this_object());
        if (!living(con)) 
        if (!present("pipe",con)) {
                 item = new(__DIR__"obj/pipe");
                 item->move(con);
        }
        
        me = this_player();
        if(me->query_temp("marks/know_ghost")){
           tell_object(me, HIG"眼前景色似乎有些熟悉，你依稀记得往北方的低处走可以出去。\n\n"NOR);
                add_action("do_northdown", "northdown");
                add_action("do_northdown", "nd");
        }
        if(this_object()->query("exits/east"))
                delete("exits/east");
} 
void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("rock", this_object());
        if (!living(con)) 
        if (!present("pipe",con)) {
                 item = new(__DIR__"obj/pipe");
                 item->move(con);
        }
        if(query("exits/east")) 
                delete("exits/east");
        
} 
void pipe_notify()
{
        object ob;
        message("vision", HIY "\n白云之间忽然出现了一个人，什么人能凌空站在白云里？\n"NOR, this_object() );
        message("vision", HIY "你走到崖边才发现，白云里有条很粗的钢索，横贯了两旁的山崖。\n"NOR, this_object() );
        set("exits/east", __DIR__"bridge" );
} 
int do_northdown(){
        object room;
        object me=this_player();
        
        if(me->query("family/family_name")=="幽灵山庄"  || me->query_temp("marks/know_ghost")) {
                message("vision", me->name()+"微一定神辨别了一下方向，身形在山林之中闪了几下就不见了。\n", 
                                environment(me), me);   
                room = find_object(__DIR__"lroad3");
                if(!objectp(room)){
                        room = load_object(__DIR__"lroad3");
           }
                me->move(room);
                message("vision", me->name()+"从丛林之中钻了出来。\n", environment(me), me);
                return 1;
        }
        return 0;
}     
