#include <ansi.h>
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name("����ɫ�ĳ���", ({ "cyan robe","robe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value", 1000);
                set("armor_prop/armor", 10);
                set("long","һ������ɫ�ĳ��ۣ���Ե��˿�߷ǳ����¡�\n");
        }
        ::init_armor();
}    