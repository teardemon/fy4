 inherit ROOM;
void create()
{
        set("short", "赤峰路 ");
        set("long", @LONG
路往东面的山峰和西面的山脚伸展。东方的浓雾之中耸立着一座
暗红色的奇峰，直插云霄。云中有几头苍鹰在低低的盘旋遨翔，仿佛
将行人当作了猎物。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_path2",
  "west" : AREA_FY"egate",
  "northeast" : "/d/chuenyu/dustyroad0",
  "northwest" : "/d/fycycle/road6",
  "south" : "/d/fycycle/fyeast",
]));
        set("outdoors", "palace"); 
        set("coor/x",100);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
