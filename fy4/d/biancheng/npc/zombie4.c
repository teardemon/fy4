#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
void do_bite(); 
void create()
{
        set_name("�Ͻ�ʬ",({"zombie"}));
        set("title","�˼����");
        set("long","�����������۾���һ����ƽ�������������������Ǳ��Ӻͱǿף�һ���ѷ�
������ͣ��촽û���ˣ���������¶�����档һֻ�ֱ�Ť������������
��һ��һ�ͣ������˻��Ǵӹ��Ź����߻����Ľ�ʬ��\n"); 
        set("gender","����");
        set("attitude", "aggressive");
        
        set("combat_exp",5000000);  
        set("age",82);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        set("str",40);
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_force",1000+random(500));
        set("force",query("max_force"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
        
        set_skill("unarmed",900);
        set_skill("dodge",900);
        set_skill("parry",900);
        set_skill("move",900);
        set_skill("force",600);
                
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([
                        10: name()+HIR"�����﷢��ϣ��������������ɱ������ɱ����������\n"NOR,
                        70: (: do_bite() :),
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                
        }) );                   
        
        setup();
    
} 
void do_bite()
{
        object *enemy;
        message_vision(HIB"$N�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n"NOR,this_object());
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("sen", 400);
                COMBAT_D->report_status(enemy[i]);
        }
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(me->query("wanma/׼��ɱ��ʬ"))
                        me->add_temp("wanma/��ʬ",4);
        message_vision("$N�����ص���ȥ��ʧ�ˡ�\n",this_object());
        destruct(this_object());
}       