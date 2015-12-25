 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","快意堂");
  set("long",@LONG
大厅的四壁极为辉煌，连墙纸都是镀银的，在灯火下
闪闪发光。大厅正中悬吊着一座由上千支蜡烛插在一起的
巨灯，使整个大厅没有一个黑暗的角落。门口一张黑底金
子牌子（ｓｉｇｎ）。
LONG
  );
  set("exits",([
     "west"  :__DIR__"street1",
         "northeast" : __DIR__"summer",
         "southeast" : __DIR__"spring",
         "east" : __DIR__"silver",
               ]));
        set("objects", ([
                __DIR__"npc/hun" : 1,
       ]) );
        set("item_desc", ([
                "sign": "
鹘牌玩法：
ｔａｂｌｅ      ：了解当前的赌局，红色为下注者，黄色为弃权者。
ｔａｋｅ        ：在赌局开始之前，或在一手结束之后加入赌局。 
        take <座位> <数量> <货币种类>
        <座位>可为north，south，east，west
        <数量>不限
        <货币种类>不限
ｆｏｌｄ        ：不跟这一铺
ｌｅａｖｅ      ：在一手结束之后离开赌台
ｃａｒｄｓ      ：看手里的鹘牌
ｂｅｔ          ：跟或加大赌注 
快意堂堂规：
一楼抽成百分之三。
二楼抽成百分之二。
三楼抽成百分之一。
"
        ]) );
        set("coor/x",40);
        set("coor/y",1970);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}  
