 // silencer@fy4 workgroup 五行阵之木阵
inherit ROOM; 
void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是一间简陋的小木屋，屋内靠边放着一张木板床，中间是一张木桌，桌上放
着热腾腾的饭菜，想来是款待穿过密林的旅者。
LONG
        );
        set("no_clean_up", 0); 
        set("exits",([
        "east" : __DIR__"wood-maze/exit", 
        ])); 
        setup();
        
} 
