 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������¥");
        set("long", @LONG
���µ������У��������������µ����ӣ����������������ż���ǳǳ���ƣ���
��̸Ц����̨��վ�Ÿ��������֣�Ц��ԲԲ���������ƵľƵ��ƹ����Ƶļ��ˣ�
����������̸Ц���ݡ�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"vroad2",
                "east" : __DIR__"hahalou2",
        ]));
        set("objects", ([
                __DIR__"npc/haha": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
