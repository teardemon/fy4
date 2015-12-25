// garrison.c

#include <ansi.h>

inherit NPC;
int give_guard();
void create()
{
        set_name("殷羡", ({ "yinxian" }) );
        set("long",
                "一个锦衣华服的带刀侍卫，也是钦差大人殷正廉的远方侄儿。
殷大人命其负责济南府众侍卫调度,朝廷将领可向他征召护卫(guard).\n");

        set("attitude", "heroism");
        set("title", "朝廷命官 四品带刀侍卫");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
	set("difficulty", 10);

//      set("str", 27);
        set("cor", 26);
        set("cps", 25);

/*        set("max_gin", 2000);
        set("max_sen", 2000);
        set("max_kee",4000); */
        set("combat_exp", 1000000+random(20000000));

        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));

        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
	set_temp("apply/parry", 200);
        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"殷羡眼睛里闪着光，苦笑道：后天便是叶孤城与西门吹雪决战紫禁城之\n日。哎！可殷大人却丢了尚方宝剑，实在又离开不得。。。\n"
        }) );

	set("inquiry"	,	([
		"护卫"	: (:give_guard:),
		"guard" : (:give_guard:),
		]) );
        setup();

        carry_object(__DIR__"obj/yafu")->wear();
    carry_object(__DIR__"obj/peidao")->wield();
}

int give_guard()
{
	object me,shiwei;
	int extra,maximum,gcount,gcount1,i;
	
	me=this_player();
	
	if(me->query("class")!="official")
	{
		message_vision("殷羡对$N说道：“你算什么东西，有什么资格要护卫？”\n",me);
		return 1;
	}
	
	if(me->query("marks/shiwei")+6000>time()) {
		message_vision("殷羡对$N说道：“你对手下太不爱惜了,我都来不及训练了.”\n",me);
		message_vision("殷羡说：“过一会儿再来要护卫吧.”\n",me);
		return 1;
	}
	
	extra=me->query_skill("strategy",1)*me->query_skill("strategy",1);

//	maximum=extra/10000;
	maximum = me->query_skill("leadership",1);
	maximum = maximum/50;
	if (maximum <1) maximum =0;
	
	if (me->query("marks/官府/岳飞")) {
        	maximum=maximum/2;
        	}
        
        gcount=me->query_temp("guard_count");
	if(gcount>maximum||gcount==maximum)
	{
		message_vision("殷羡对$N说道：“朝廷的典制，你不可以指挥再多兵士了。”\n",me);
		return 1;
	}
	gcount1=maximum-gcount;
	me->set("marks/shiwei",time());
	for(i=0;i<gcount1;i++)
	{
		if(me->query("sen")<150) 
		{
			tell_object(me,"你的神不够，无法指挥再多兵士了。\n");
			break;
		}
		shiwei=new("/d/jinan/npc/shiwei");
		shiwei->invocation(me,extra/100);
		shiwei->move(environment());
		message_vision("殷羡对$N说道：“好好跟着"+me->query("name")+"将军干，有你的好处。”\n",shiwei);
		me->add_temp("guard_count",1);
		me->add("sen",-150);
	}
	return 1;
}
