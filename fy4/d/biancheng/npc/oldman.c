#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int show_me(); 
void create()
{
        set_name("看坟老人",({"oldman"}));
        set("long","老人已经七十多岁了，身板依旧挺直。鬓发变白和稀疏了，露出宽阔而突起的
脑门。他的脸刻着深深的皱纹，每一道都是岁月的痕迹。\n");
        
        set("gender","男性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",4000000);  
        set("age",72);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
                
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
        
        set("inquiry", ([
                "驱鬼" :        (: show_me :),
                "鬼" :           (: show_me :),
                "坟地" :         (: show_me :),
        ])); 
//      set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                   10: name()+"道：“来人啊，强盗来盗墓啦！”\n", 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                name()+"说：“如果有人能驱鬼就好了。”\n",
        }) );                   
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,165,0,"/obj/weapon/","fighter_w","taiji",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
        add_money("gold", random(3));
}  
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query_temp("wanma/僵尸")>=40 && !ob->query("wanma/平僵尸")) {
                command("touch "+ob->get_id());
                command("say 太感谢了，这坟地应该能太平一阵了！");
                if (!ob->query("wanma/平僵尸")) {
                        ob->set("wanma/平僵尸",1);
                        ob->add("combat_exp",1000);
                        ob->add("potential",200);
                        ob->add("wanma/声誉",1);
                        tell_object(ob,HIW"你被奖励了！一千点实战经验，二百点潜能！\n"NOR);
                   tell_object(ob,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
                } 
        }       
        if (ob->query("wanma/平僵尸")) {
                command("greet "+ob->query("id"));
                return;
        }
        command("say 这位"+RANK_D->query_respect(ob)+"请止步，坟地有鬼，不太平啊。");
        return; 
}   
int show_me()   {
        object me,ob;
        
        me=this_player();
        ob=this_object();
        if (me->query("wanma/平僵尸")) {
                command("say 多亏你的帮助，现在镇上的人又敢来扫墓了。");
                return 1;
        }
        command("say 这坟地自半年前开始闹鬼，先是晚上有怪叫声，现在连白天也不太平了。");
        command("say 镇上的人都不敢去扫墓，也有几个胆大的结伙进去，这一去就没出来过。");
        command("shiver");
        command("say 前些天有个穿黑衣服的官爷不信邪闯了进去，现在还没有消息，看来凶多吉少。");
        command("say 你若能把这里面的恶鬼都驱个干净，咱们全镇老少都感激不尽。");
        tell_object(me,"说罢，老人颤巍巍地走到一旁。 \n");
        me->set("wanma/准备杀僵尸",1);
        return 1;
}     
