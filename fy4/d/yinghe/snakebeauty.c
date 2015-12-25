 // Room: snakehall.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "卧室"); 
        set("long", @LONG
这里似乎是一个卧室。室内洁净整齐，淡淡的幽香令人心情一阵轻松。一张檀
木床上粉帐低垂。一边有个梳妆台。台上明镜盈盈，一灯如豆，发着柔和的光芒，
珠帘重重，不时有流光点点浮动。
LONG); 
        set("indoors","yinghe");
        set("exits",([
                "out" : __DIR__"pearlcurtain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
