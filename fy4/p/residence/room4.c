 inherit ROOM;
void create ()
{
  set ("short", "̩���㳡");
  set ("long", @LONG
�������������ܵ��������е��徻����ɫʯ���̳ɵĴ�����ķ����ӡ��㳡
�����Σ�����������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ����㳡���и���
ˮ�أ�������Ϻ��浹Ҳ���˲��٣������ļ��紺�������£��ɻ�˯���ޱ���次�
LONG);
        set("exits", ([
"down" : __DIR__"kxin1032739838",
"up" : __DIR__"coldhan1029438380",
"west" : __DIR__"nfy1025472485",
"westup" : __DIR__"sunlx1020433536",
"east" : __DIR__"yiyi1017016543",
"north" : __DIR__"recall1014842649",
  "south" : __DIR__"room3",
  "northeast" : __DIR__"room6",
  "northwest" : __DIR__"room5",
]));
        set("coor/x",10);
        set("coor/y",2030);
        set("coor/z",30);
        set("owner","public");
        setup();
  replace_program(ROOM); 
} 
      