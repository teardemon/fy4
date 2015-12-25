 inherit ROOM;
void create()
{
        set("short", "大院");
        set("long", @LONG
站在院中，凉风徐徐，墙外桃柳成林，红绿如霞，只觉得春意昂然。院内有一
棵老槐树，郁郁葱葱，遮盖了大半个院子，青砖铺成的地上飘落着几片树叶。院子
的西面是一个不大的练武场，东面是一间厢房，北面则是山庄的正堂了。
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"xiangfang",
        "south" : __DIR__"mrsz",
        "west" : __DIR__"wuchang",
        "north" : __DIR__"zhengtang",            
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}       
