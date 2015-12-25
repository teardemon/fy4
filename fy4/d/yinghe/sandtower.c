 // FYTeam
#include <ansi.h>
inherit ROOM;
string sand();
int monster_attack(object me);
void create(){
        set("short", "黄沙塔");
        set("long", @LONG
突兀间眼前冒出一片黄沙，无数的沙粒无一杂色，满眼的金黄色让你很容易
的联想到足色的金子。仔细看，四周的沙粒不知被何物吸引着在缓缓向前移动，
在中央形成了一座黄沙塔。
LONG); 
        set("exits",([
                "east":__DIR__"yellow_earth",
        ]) );
        set("item_desc", ([
                "sand" : (: sand :),
                "黄沙塔" : (: sand :),
                "sandtower" : (: sand :),
        ]));
        set("helsand", 1);
        set("indoors", "yinghe");
        setup();
} 
string sand(){
        object me;
        
        me = this_player();
        if(query("helsand")){
                tell_object(me, "黄沙塔的顶端似有一撮黑色的沙子。（ｇｅｔ　ｓａｎｄ）\n");
                add_action("do_get", "get");
        } else {
                tell_object(me, "黄沙塔上有着纷乱的脚印。\n");
        }
        return "";
} 
int do_get(string arg){
        object me, sand;
        me = this_player();
        if(arg == "sand"){
           if(query("monster_traped")) {
                        message_vision("$N谨慎的移近黄沙塔，从上面拿下一撮黑色的沙子。\n", me);
                        sand = new(__DIR__"obj/sand");
                        if(objectp(sand)){
                                sand->move(me);
                        }
                        delete("helsand");
                        return 1;
                } else {
                        message_vision("$N缓步向黄沙塔走去。\n", me);
                        me->start_busy(1);
                        monster_attack(me);
                        return 1;
                }
        }
        return 0;
} 
int monster_attack(object me){
        object monster, cage;
        
        cage = present("wood cage", this_object());
        if(objectp(monster = present("sand guardian", this_object()))) {
                if(objectp(cage)) {
                        message_vision("$N移步冲向$n，猛然间$N身形下落，伴随而来的是阵阵野兽的低吼。\n", monster, me);
                        set("monster_traped", 1);
                        return 1;
                }
                monster->kill_ob(me);
                return 1;
        }
        message_vision(HIY"\n猛然间，黄沙翻滚，从地下钻出了一只怪兽拦在$N身前。\n"NOR, me);
        monster = new(__DIR__"npc/sand_guard");
        if(objectp(monster)){
                monster->move(this_object());
        }
        if(objectp(cage) && cage->query("installed")) {
                message_vision("$N移步冲向$n，猛然间$N身形下落，伴随而来的是阵阵野兽的低吼。\n", monster, me);
                destruct(monster);
                set("monster_traped", 1);
                return 0;
   }
        monster->kill_ob(me);
        return 1;
} 
void reset(){
        ::reset();
        set("helsand", 1);
}       
