 // neon@fengyun.com
#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void create()
{       set_name( WHT"落云锥"NOR, ({ "luoyun zhui" , "zhui"}) );
        set_weight(10);
        set("unit", "柄");
        set("long", "一柄晶晶闪亮的飞锥，可以用来射人（shootz）。\n");
        set("value", 0);
        set("level", 50);
        set("no_drop", 1);
        ::init_item();
} 
void init(){
        add_action("do_shoot", "shootz");
        add_action("do_shoot", "shoot");
} 
int do_shoot(string arg){
        object me, target;
        int level, exp, t_exp, damage, exp_bonus, resist;
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("你要打谁？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n"); 
        target = present(arg,environment(me));
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");      
        
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
        exp   = (int) me->query("combat_exp");
        msg  = HIW"$N念动真言，指并剑诀，祭起一" + query("unit") + name()+HIW"，";
   msg += HIW"\n只见一道白光急射$n！！\n\n"NOR; 
//       success rate:1/2+ random(5)
//      damage = 200*100/10= 2000, 2000+random(2000); at 8M 3000+random(3000);
//      sen = 750+random(750)
        if( random(exp)*level/20 + exp/2 > t_exp ) {
                damage = me->query_skill("alchemy",1)* level /10;
                damage = damage + random(damage);
                if (userp(me)) exp_bonus= (me->query("combat_exp")-4000000)/1000*damage/8000;
                damage = damage + exp_bonus;
                if (damage>6000) damage = 6000;
                msg +=  name() +HIW "象一道闪电击中了$n！！\n" NOR;
                target->receive_wound("kee",damage,me);
                target->receive_wound("sen", damage/6, me);
//              message_vision("sen damage"+(string)(damage/6)+"\n",me);
//              message_vision("kee damage"+(string)(damage)+"\n",me);
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,1);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
}   
