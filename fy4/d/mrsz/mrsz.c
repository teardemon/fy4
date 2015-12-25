 inherit ROOM;
void create()
{
        set("short", "慕容山庄");
        set("long", @LONG
桃源的一角不知何时建起了一个庄园，两扇朱漆大门上钉着一对银白雪亭的兽
环，茶杯大小的铜钉闪闪发光。门前还踞着两只高过人的卷毛石狮，门顶匾额写着
“慕容山庄”四个大字。墙内隐约可见，崇楼高阁，画栋雕梁，一看便知绝非普通
百姓人家，可此时门前却冷冷清清，大门紧闭，四周静悄悄的。
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
//      "south" : __DIR__"road3",
        "north" : __DIR__"dayuan",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}
