#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"种子"NOR, ({"black seed", "seed"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗黑色的种子。\n");
                set("lore",1);
                set("unit", "颗");
                set("value", 1);
        }
    ::init_item();
}   
