 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "碑楼");
        set("long", @LONG
一座砖石构筑的小楼，从这里东行，便是钟楼，碑楼中立碑两通，
一通为“李世民碑”，为唐王所立，一通为“小山禅师行实碑”，南边
山墙还嵌有白居易的诗碑和乾隆的御碑。里面两句“心依六禅静，寺据
万山巅”端的妙到巅峰。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yeeast",
  "east" : __DIR__"zhonglou",
  "west" : __DIR__"dianjiao",
]));
        set("outdoors", "shaolin");
        set("coor/x",-200);
        set("coor/y",200);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
} 
