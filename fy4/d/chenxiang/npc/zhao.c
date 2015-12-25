#include <ansi.h>
inherit NPC;
void create()
{
        set_name("赵一刀", ({ "zhao yidao", "zhao" }) );
        set("long",
                "丈八开外一条大汉，青布箭衣，青帕包头，一条腰带比血还红。\n");
        set("nickname", HIY"金刀太岁"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
            "赵一刀紧紧握着刀柄，狞笑道：你头痛啊？跑着这跟大爷抢生意，\n要不要大爷帮你治治啊，他奶奶的，刀落病除。\n",
                        })  );
        set("inquiry",([
        "孔雀图"  :"这玩意可是好东西啊，有了它，大江南北立马就是俺太\n行赵一刀的天下了。\n",
              ]) );
        set("combat_exp", 800000);
/*      set("max_gin",1000);
        set("max_kee",1000);
        set("max_sen",1000);  */
        set("int",20);
        set("str",30+random(20));
        set("cor",20);
        
        set_skill("unarmed",150);
        set_skill("blade",100);
        set_skill("demon-blade",100);
        set_skill("tigerstrike",100);
        map_skill("unarmed","tigerstrike");
        map_skill("blade","demon-blade"); 
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
        }) ); 
        
        setup();
        carry_object("/d/chenxiang/npc/obj/qingcloth")->wear();
        carry_object("/d/chenxiang/npc/obj/qingribbon")->wear();
        carry_object("/d/chenxiang/npc/obj/redgirth")->wear();
        carry_object("/d/chenxiang/npc/obj/gold_blade")->wield();
 } 
int accept_object(object me, object obj)
{                                                                 
        if( (string) obj->query("name") == "孔雀图" && obj->query("fake"))
        {
                message_vision(HIY"$N偷偷塞给$n一幅孔雀图。\n",me,this_object());
                message_vision(HIY"$N看了看，突然兴奋的哈哈大笑起来。\n",this_object());
                me->set_temp("marks/longlife_peacockmap",1);
                call_out("fighting",2,me);
                return 1;
        }
        else
        {
                message_vision("$N说道：东西小的照收，让我放弃孔雀图，没门！\n",this_object());
                return 1;
        }
          return 1;
}
int fighting(object me)
{
        object miao,zhang;
        if (present(me,environment(this_object())))
        {
                if (miao=present("miao shaotian",environment(this_object())))
                {
                        miao->kill_ob(this_object());
                        message_vision("$N说道：小兔崽子，交出孔雀图，我就饶了你！！\n",miao);
                        this_object()->kill_ob(miao);
                }
                if (zhang=present("zhang san",environment(this_object())))
                {
                        zhang->kill_ob(this_object());
                        message_vision("$N说道：谁想独吞孔雀图，我就要他的命！！\n",zhang);
                        this_object()->kill_ob(zhang);
                }
                return 1;
        }
        else
        {
                return 0;
        }
}      
