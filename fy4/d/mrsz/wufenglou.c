 inherit ROOM;
void create()
{
        set("short", "舞凤楼");
        set("long", @LONG
原来这里便是山庄大小姐的绣楼闺房。窗口一盆小小盆景，绿意盎然。靠窗边
的是一张梳张台，转过屏风，迎面只见一幅写意山水，笔势纵横。旁边就是卧榻，
垂着水红纱帐，绣了些花鸟。自从大小姐离家出走以后，这里已经没人住了，但每
天都有仆人来打扫，房间里一尘不染。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"liangting",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
