 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����ô���");
        set("long", @LONG
�������룬ֻ�����Ű�ľ���������ü�ֱ��ֵ�һ�������������������ϳ�����
�������ԣ������������Ű�ľ�Ρ�����δ���������ã�����Զ�޷��������ϻ�����
ô�������ӣ���ô������ã�
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"hall4",
        "south": __DIR__"hall2",
        "west": __DIR__"hall3w",
        "east": __DIR__"hall3e",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     