#include <room.h>
#include <ansi.h>
inherit ROOM;
void create() 
{
        set("short", "ƫ��");
        set("long", @LONG
�����Ȼ��Ů�ӵĹ뷿������ĳ��貢��ʮ���ûʣ����ܷ���ׯ��������ϲ����
ǽ�Ϲ����ý�����ɫ˿����������ͼ����ᣣ����幤���������µ��ˡ�������
��һ��ͬ�������ĳ��ֵ�����Χ������ɫ�Ķ�ᣡ�����Ҳ���в�ɫ���ӣ�����һ��
�ر�ߣ�ǰ�����һ���λ��������ŵʡ���������յ���ƵĵƼܣ����Ÿߴ������
��ȫ�����յ�ͨ����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"corridor3",
        ]));
        set("objects", ([
                __DIR__"npc/sanniang":  1,
                __DIR__"npc/huzi":      1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        create_door("south","ľ��","north",DOOR_CLOSED);
} 