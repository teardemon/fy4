 // Room: stonestair1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "绿松石阶"); 
        set("long", @LONG
这是一块空地，目前什么都还没有修。
LONG);
        set("long_night", @LONG
这是一块空地，到了晚上就更不要指望看见什么。
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "west":__DIR__"stonecave",
        "south":__DIR__"stonestair2",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}       
