 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
������û�б����ɫ��ֻ�кڣ���Ϧ���ս����������һ�ֲ����������ɫ��
һ��Ů�˹��ں�ɫ������ǰ����ɫ�������ϡ���ɫ����ᣵʹ���û�����ܿ��ü���
�湩�����ʲô���磬Ҳû�����ܿ��ü������������������ź�ɴ����ɫ�ĳ�����
�ư�ɢ���ڵ��ϣ�ֻ¶��һ˫�ɱ񡢲��ϡ���צ����֡���˫�ֺ�ʲ���૵��У�
��ȴ�����������ϲԴ���ร�����������䡣�������ϲԣ����������ˣ���������
�ؼ���������
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"hole",
        ]));
        set("objects", ([
        
                __DIR__"npc/huabaifeng":        1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}     