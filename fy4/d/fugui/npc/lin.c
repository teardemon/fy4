#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林太平", ({ "lin taiping","lin" }) );
        set("long",
         "林太平是个很秀气、很纤弱，而且非常漂亮的人。若说燕七长的有点\n像女孩子，那么他简直就象是个女孩子化装的。他的嘴很小，就算用\n“樱桃小嘴”来形容他也决不过分。\n");
        set("attitude", "heroism");
        create_family("富贵山庄",7,"副庄主");
        set("vendetta_mark", "fugui");
        set("str", 40);
        set("cor", 35);
        set("cps", 32);
        set("agi", 35);
        set("int", 40);
        set("per", 30);
        set("con", 35);
        set("dur", 40);
        set("fle", 25);
        set("tol", 30);
        set("eff_gin",900);
        set("eff_kee",1500);
        set("eff_sen",1300);
        set("gin",300);
        set("kee",600);
        set("sen",300);
                
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "move.tianwaifeixian" :),
        }) ); 
        set("combat_exp", 4000000);
        set_temp("apply/damage",30);
        set_skill("unarmed", 100);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("sword",100);
        set_skill("feixian-sword",140);
        set_skill("feixian-steps",140);
        set_skill("jingyiforce",100);
        set_skill("literate",100);
        map_skill("sword","feixian-sword");
        map_skill("dodge","feixian-steps");
        map_skill("move","feixian-steps");
        map_skill("force","jingyiforce"); 
        setup();
        this_object()->disable_player(" <昏迷不醒>");
        this_object()->set_temp("is_unconcious",1);
        set_temp("block_msg/all", 1);
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
        COMBAT_D->announce(this_object(), "unconcious"); 
} 
void init()
{
        ::init();
        add_action("do_kill","kill");
} 
void heart_beat()
{
        if(query_temp("is_unconcious"))
        {
                this_object()->unconcious();
                return;
        }
        else return ::heart_beat();
} 
int do_kill(string arg)
{       object ob;
        if ((arg=="lin"||arg=="lin taiping") && ob=present("yan qi",environment(this_object())))
        {
                ob->kill_ob(this_player());
                ob->ccommand("say 要杀我林兄弟，就得先杀了我！！");
                this_object()->remove_all_killer();
                return 1;
        }
        else if((arg=="lin"||arg=="lin taiping") && !(ob=present("yan qi",environment(this_object()))))
   {
                this_object()->set_temp("is_unconcious",0);
                this_object()->revive();
                call_out("heart_beat", 0, this_object());
                this_object()->ccommand("say 趁人之危，不知羞耻！！\n");
                
                return 0;
        }
} 
void imbue_event(object me) {
        object weapon, *inv, obj;
        string prop;
        int i;
        
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }       
    if(!objectp(weapon)) {
    if(!objectp(obj)) {
           message_vision(RED"地上顿时溅满了黑血。\n" NOR,me);
    } else {
                message_vision(RED"$N的" + obj->name() + RED"顿时溅满了黑血，血渍渐渐褪去，" 
                                + obj->name() + RED"依旧光灿如新。\n"NOR,me);
    } 
    } else {
                message_vision(RED"\n$N的"NOR + weapon->name() + RED"顿时溅满了黑血，血渍渐渐褪去，但"NOR 
                                + weapon->name() + RED"上却留下了一道紫红色的印痕。。\n"NOR,me);
                
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
           if(weapon->query("equipped") == "wielded"){
                        weapon->unequip();
                        if(me->query("宿命B/黄山_云海") ) {
                weapon->add(prop+"karma", 5);
                                weapon->add(prop+"courage", 5);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"courage", 2);
                        }
                        weapon->wield();
                } else {
                        if(me->query("宿命B/黄山_云海") ) {
                weapon->add(prop+"karma", 5);
                                weapon->add(prop+"courage", 5);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"courage", 2);
                        }
                }
                weapon->save();                 
                me->set("imbue/lin", 1);
                me->save();
                return;
        } 
        me->set("imbue/lin", 2);
        me->save();
        return;
}   
