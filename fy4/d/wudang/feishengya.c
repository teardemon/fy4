 inherit ROOM;
void create()
{
        set("short", "飞升崖");
        set("long", @LONG
飞升崖一峰突起，三面绝壁，山脊上有一条小路直达峰巅，跃顶
眺望。离天柱峰已然不远。
LONG
        );
        set("exits", ([
        "westup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudang");
        set("coor/x",120);
        set("coor/y",-180);
    set("coor/z",90); 
        set("objects", ([
        __DIR__"npc/yidianhong": 1,
        ]) );
        setup(); 
}    
