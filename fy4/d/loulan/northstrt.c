 inherit ROOM;
void create()
{
        set("short", "北天街");
        set("long", @LONG
一条灯火通明的长廊，似乎原先本是繁华的街道，两旁是一些寺院民宅，后
来快活王占据这古楼兰的地下王国后，便将大大小小的民宅修葺改建，以供手下
酒色财气四使、急风三十六骑以及众多嫔妃佳人和一干下人居住。
LONG
        ); 
        set("exits", ([ 
                "south" : __DIR__"northstrt3",
                "west" : __DIR__"prison1",
                "east" : __DIR__"kitchen",
                "north" : __DIR__"northstrt2",
        ]));
        set("objects", ([
                __DIR__"npc/guard1" : 1,
        ]) );
        set("indoors", "loulan"); 
        set("coor/x",-1000);
        set("coor/y",220);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        object *inv;
        int i;
        int j;
        int k;
        j = 0;
        if ( !userp(me) || dir=="south" || dir=="north" || dir =="east")
                return 1;
        
        inv=all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++)     {
                if (inv[i]->query("id")=="fang xinqi") j=1;
        }               
           if (j==0) return 1; 
        inv=all_inventory(me);
        for(i=0; i<sizeof(inv); i++)            {
                if(inv[i]->query("owner")=="方心骑" && (int)inv[i]->query("equipped"))
                        k = 1;
        }
        if (k==0) return notify_fail("方心骑伸手拦住你的去路。\n");
        return 1;
}      
