#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
void create()
{
    set_name("�����",({"gongsun duan","gongsun"}));
    set("title","��׾޺�");
    set("long","����������ף�һ�����£�����ϵ��һ�߿���ţƤ����Ƥ����б���Ű������ڱ���
�����䵶�����ﻹ���ű��ơ��Ʊ����������������̫�󣬵����������ֻ��Ҳ
δ��������ס��\n");
        set("gender","����");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N������ˮ�ؿ���һ��������ļҾߡ������� \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "��׾޺����ͷ���������ҽй���ϣ����Ǹ����ˣ��������\n"
        }) );                   
           
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}   