 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "谷地");
        set("long", @LONG
转到这里眼前豁然开朗，不知不觉中你已经爬了很高，身处云雾之中，这
里群峰环绕，然而在这群峰环绕之中有一湖泊，远远望去水呈白色，在这茫茫
雾海之中很难看到，但湖水又怎么可能是白色的呢，你心里充满了疑惑。
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
   "west" : __DIR__"tianti2",
   "east" : __DIR__"baishui", 
]));
   set("item_desc", ([
      "lake": "东方不远处有个很大的湖，湖上迷雾缭绕（ｓｗｉｍ？）。\n",
      "湖": "东方不远处有个很大的湖，湖上迷雾缭绕（ｓｗｉｍ？）。\n",
   ]) );
        set("coor/x",170);
        set("coor/y",12230);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}       
