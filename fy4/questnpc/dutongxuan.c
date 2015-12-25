#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER; 
void create()
{
        set_name("杜桐轩", ({ "du tongxuan", "du" }) );
        set("gender", "男性" );
        set("nickname",BLU"翰林学士"NOR); 
        set("age", 47);
        set("int", 25);
        set("per", 20);
        set("str", 40);
        set("dur", 35);
        set("cor", 35);
        set("fle",20);
        set("long",
"这人很高，很瘦，穿著极考究，态度极斯文，年纪虽不甚
大，两翼却已斑白，一张清瘤瘦削的脸上，仿佛带著三分
病容，却又带著七分威严，令人绝不敢对他有丝毫轻视。\n");
        set("force_factor", 35);
        set("max_gin", 1900);
        set("max_kee", 3200);
        set("max_sen", 1800);
                set("max_force",2000);
                set("force",2000); 
        set("combat_exp", 1300000);
        set("score", 12000);
        set_skill("unarmed", 180);
        set_skill("force", 80);
        set_skill("parry", 160);
        set_skill("literate", 130);
        set_skill("dodge", 150); 
        set_skill("changquan", 130);
                
        map_skill("unarmed", "changquan");
     
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.changquan":),
        }) );
        setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/baiyubi");
        carry_object(__DIR__"obj/yubanzhi");
//      add_money("gold",15);
//        carry_object(__DIR__"obj/feiyunspear")->wield();
}
/*
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}  
*/
