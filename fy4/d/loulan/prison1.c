 inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���Ǽ�ʯ�������ӣ�ʯ����Ҳ������������׾��ͼ�����е��������ף���
���������ף���״��Ȼ��񣬵��ȴ����ϸ�������ڵĳ��裬ȴ����ո�¡�����
�ģ��绨ľ�Ĳ輸���������������ӣ��񻨵Ĵ��ϣ�֧�����ս��ʡ��⵱Ȼ
�ǿ���������ġ��¾�������������������ʯ�����γ���һ��������ںϡ�
LONG
        ); 
        set("exits", ([ 
                "east" : __DIR__"northstrt",
        ]));
        set("objects", ([
                __DIR__"npc/shenlang" : 1,
                __DIR__"npc/bai" : 1,
        ]) );
        set("indoors", "loulan"); 
        set("coor/x",-1010);
        set("coor/y",220);
        set("coor/z",-100);
        setup();
}