 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "小径");
        set("long", @LONG
一条弯弯曲曲的小路，两旁有几棵很高大的杉树，银白色的树干上，能看到凸
起的象伤疤一样和凹下去的象眼睛一样的树节，枝叶茂盛，甚至垂到了附近的院子
中。几只松鼠“吱溜溜”地在树枝上蹿着，一晃就不见了。小路两旁是村居。 
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"groad3a",
        "east" : __DIR__"groad3c",
        "north": __DIR__"vhouse2",
        ]));
        set("item_desc", ([
                "杉树": "很高大的杉树，枝叶茂盛，甚至垂到了附近的院子中。\n",
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
        if( arg!="tree" && arg!="杉树") {
                tell_object(this_player(),"你要爬什么。\n");
                return 1;
        }
        return notify_fail("树太高，你试了试，没可能爬上去。\n"); 
}   
