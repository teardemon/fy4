 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "银屋");
        set("long", @LONG
这屋子布置得竟像是文予闺房，对旁的梳妆台上，居然还放着整套
的梳妆用具，床后面还有个马桶。掀开帐子，床上直直的躺着具骷
髅，发髻、环佩，还都完整的留在枕头上，自然是个女子。 
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"west",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
