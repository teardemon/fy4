#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIB"战虎之魄"NOR, ({ "tiger soul","soul" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是从昔年蚩尤的战虎身上提炼出的百炼之魄，不灭之精。\n");
                set("rigidity", 5000);
                set("for_create_weapon",1);
                set("value", 50000);
                set("base_damage",60);
                set("material", "iron");
                set("max_enchant",8);
        } 
        ::init_hammer(60);
}      
