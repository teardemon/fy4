#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int kill_him(); 
void create()
{
        set_name("陈大倌",({"chen daguan","chen","daguan"}));
        set("title","绸缎行的老板");
        set("long","这人白白的脸，脸上好像都带着微笑，正是那绸缎行的老板福州人陈大倌。镇
上没有人比他更会做生意，也没有人比他更得人缘了。\n");
        set("gender","男性");
        set("age",52);
                
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
        
        set("inquiry", ([
                "强盗" : "镇外有强盗，镇内也有强盗，这日子可怎么过下去呀！\n",
                "镇外的强盗" : "还不就是龙虎寨的那些山贼么！\n",
                "镇内的强盗" : "不能说，不能说呀。。\n",
                "江湖五毒"      :       (: kill_him :),
                "采花蜂"        :               (: kill_him :),
        ]));
        
        set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
           set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "陈大倌愁眉苦脸地说道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
        }) );                   
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","taiji",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}  
int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"陈大倌现在没空回答你。\n");
                return 1;
                }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n",this_object());
        another = new(__DIR__"caihua");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}
