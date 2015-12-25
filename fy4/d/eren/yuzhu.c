 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "玉龙峰");
        set("long", @LONG
终于来到玉龙峰下，巨大的山影，沉重地压在过往的车马上。风在呼号，却也
吹不开那阴森凄迷的云雾。山麓阴影中，有几个客商正在歇息。向西，一条大道黄
土飞扬，通向边城。向北则是通向玉龙峰顶的山路，崎岖而蜿蜒向上。
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"kunlun3",
                "northup" : __DIR__"road0",
                "west":         AREA_ZANGBEI"wild1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
