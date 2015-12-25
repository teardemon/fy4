 // Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "神台", ({ "shentai", "shen tai", "神台"  }) );
        set("unit", "个");
        set("no_get",1);
        set("no_shown", 1);
        set("value",20);
        set("long","
紫石英神台，神台正中是一紫玉柱（ｊａｄｅ），四面又分别以白（ｗｈｉｔｅ），
红（ｒｅｄ），黄（ｙｅｌｌｏｗ），黑（ｂｌａｃｋ）四色玉镶嵌而成。
玉成凹形可以放东西。
\n");
        set_weight(5000);
        ::init_item();
}
void init()
{
        add_action("do_turn","turn");
}  
int open_path(object me) {
    object room; 
    message("vision", "瞬间玉石上冒出五彩，一阵五彩光闪过，"+me->name()+"已失去了踪影。\n", environment(me), me);
    tell_object(me, "蓦然间你眼前是一片五彩光芒，你只觉得身子在向下坠去。\n\n");
    room = find_object("/d/yinghe/weaponroom");
    if(!objectp(room)){
        room = load_object("/d/yinghe/weaponroom");
    }
    me->move(room);
    tell_object(me, "眼前光芒消失，你已身在异处。\n");
    return 1;
} 
int check_jade(object me){
        object red, white, yellow, black, env, *inv;
        object red_jade, yellow_jade, white_jade, black_jade; 
        env = environment(this_object());
   if(!objectp(red=present("red", env))) return 0;
        if(!objectp(white=present("white", env))) return 0;
        if(!objectp(black=present("black", env))) return 0;
        if(!objectp(yellow=present("yellow", env))) return 0;
        inv = all_inventory(red);
        if( sizeof(inv) != 1) return 0;
        red_jade = inv[0];
        if((string)red_jade->query("name") != HIR"丹心聚碧"NOR) return 0;
    inv = all_inventory(white);
    if( sizeof(inv) != 1) return 0;
    white_jade = inv[0];
    if((string)white_jade->query("name") != HIW"玉羊脂精"NOR) return 0;
    inv = all_inventory(black);
    if( sizeof(inv) != 1) return 0;
    black_jade = inv[0];
    if((string)black_jade->query("name") != BLU"玄心墨金"NOR) return 0;
    inv = all_inventory(yellow);
    if( sizeof(inv) != 1) return 0;
    yellow_jade= inv[0];
    if((string)yellow_jade->query("name") != HIY"凝黄石胆"NOR) return 0;
// now we have everything, let's open path! and reset this room;
        red_jade->move(env); destruct(red_jade);
    yellow_jade->move(env); destruct(yellow_jade);
    white_jade->move(env); destruct(white_jade);
    black_jade->move(env); destruct(black_jade);
        open_path(me);
        return 1;
}
int do_turn(string arg)
{
    object me,env;
    if( !arg ) return 0;
    if( arg != "紫玉柱" && arg != "jade") return 0;
    me = this_player();
    if((int) me->query("mana") < 500) {
            write("你的法力不够！\n"); return 1;}
        if(((int) me->query("force") >= 100) && me->query_temp("yinghe_marks/altar")) {
                me->add("force",-100);
                open_path(me);
                return 1;
    }
    me->add("force",-50);
    message_vision("$N用聚起法力转动紫玉柱。\n", me);
    if( check_jade(me) ) {
            if(!me->query("m_success/五色土祭坛")){
                me->set("m_success/五色土祭坛",1);
                me->add("score",300);
                me->add("combat_exp", 2000);
                me->add("potential", 2000);
                }
                if(!me->query_temp("yinghe_marks/altar")){
                        me->set_temp("yinghe_marks/altar",1);
                }
                open_path(me);
        } else {
                message_vision("在$N法力将尽时，神台上微微冒出五彩光芒，瞬间既失！！\n",me);
    }
    return 1;
}       
