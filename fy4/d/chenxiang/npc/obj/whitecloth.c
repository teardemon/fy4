 // icy_cloth.c
#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
    set_name(WHT"白色披风"NOR, ({ "white cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 40000);
        set("long", "这是一件雪白的披风，迎着风猎猎作响，威武异常。\n");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
        }
        ::init_cloth();
}    
