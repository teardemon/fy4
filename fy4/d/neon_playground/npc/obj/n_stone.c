 // pearl.c
#include <weapon.h> 
inherit THROWING; 
void create()
{
        set_name("银针", ({ "stone", "stone piece" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一根细如丝线的银针\n");
                set("unit", "束");
                set("base_unit", "根");
                set("base_weight", 1);
                set("base_value", 1);
                set("stone",1);
        }
        set_amount(500);
        ::init_throwing(40);
}    
