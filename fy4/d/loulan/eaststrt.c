 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ���ƻ�ͨ���ĳ��ȣ��ƺ�ԭ�ȱ��Ƿ����Ľֵ���������һЩ��Ժ��լ����
�������ռ�����¥���ĵ��������󣬱㽫���СС����լ���ݸĽ����Թ�����
��ɫ������ʹ��������ʮ�����Լ��ڶ��������˺�һ�����˾�ס��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"saintpalace",
                "east" : __DIR__"eaststrt2",
        ]));
        set("indoors", "loulan"); 
        set("coor/x",-990);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
}      