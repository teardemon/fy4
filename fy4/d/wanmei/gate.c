 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "风铃梅枝门");
        set("long", @LONG
一扇用干枯的梅枝扎结的庄门虚掩着。门上扎着一个紫铜风铃。
门随风开合，风铃发出断断续续的叮咚之声。门上隶书一行：
                无剑为上
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"village",
  "east" : __DIR__"frontyard",
]));
        set("outdoors", "wanmei");
        set("coor/x",140);
        set("coor/y",-400);
        set("coor/z",30);
        setup(); 
}
int valid_leave(object me, string dir)
{
        if(dir == "east"){
    if( me->query_temp("played_qin") &&(int) me->query("combat_exp")>5000)
                return 1;               
        else
                        return notify_fail("一股强劲的罡气挡住了你。\n");
        }
        return 1;
}  
