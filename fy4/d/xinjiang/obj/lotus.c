 // medicine.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"��ɽѩ��"NOR,({"snow lotus"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ���溮�ޱȵģ�����һ�ֵ���ɽѩ����\n");
            set("unit","��");
            set("value", 20000);
        }
        ::init_item();
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
        if(!this_player()->query("m_success/��ɽѩ��"))
        {
        this_player()->set("m_success/��ɽѩ��");
        this_player()->add("score",200);
        }
        message_vision("$Nһ�ſڣ���һ���溮�ޱȵ���ɽѩ���������ڣ�\n",this_player()); 
        this_player()->apply_condition("cold_energy",10+random(10));
        destruct(this_object());
        return 1;
}  