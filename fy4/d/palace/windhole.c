 inherit ROOM;
void create()
{
        set("short", "风穴");
        set("long", @LONG
山窟外雾色朦胧，鬼气森森。山窟内更是阴暗，几乎是伸手难见五指.
洞内寒风如刀，呼啸不绝。深呼一口气，只觉的空气中充满了血腥，一种
不详的感觉涌上了心头。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"interroad",
  "west" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/hulu" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",170);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",170); 
        setup(); 
} 
void reset(){
        object obj;
        
        ::reset();
        if(!present("hulu", this_object())){
                obj = new(__DIR__"obj/hulu");
                if(objectp(obj)){
                        obj->move(this_object());
                }
        }       
        return;
}      
