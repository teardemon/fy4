#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int show_me(); 
void create()
{
        set_name("������",({"huo ji","huoji"}));
        set("title","���ׯ");
        set("long","����Ե�û����ɵ����ӣ�ֻϣ�����ڣ������ڵ�����Ȼ�ǻ�ƣ��ڼ�
��ȴ���ϰ塣\n");
        
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",1000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
                
        set("max_force",200+random(500));
        set("force",query("max_force"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                
        ])); 
//      set("death_msg",CYN"\n$N˵�����������ݣ������˶����Ź�����\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"�е��������˰���ǿ����������������\n", 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
           name()+"˵�����͹پ���������������������\n",
        }) );                   
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
}       