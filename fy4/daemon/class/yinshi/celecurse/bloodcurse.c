#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg,id_enemy;
        int damage, ap, dp;
        int extradam, my_exp;
        
        if(me->query("class")!="yinshi")
                return notify_fail("只有帝王谷弟子才能下降头。\n");
        if((int)me->query_skill("celecurse", 1) < 150
                && userp(me))
                return notify_fail("你的降头术不够高！\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||target->is_corpse()
                ||target==me)
                return notify_fail("你要对谁施展这个降头？\n");
    
        if((int)me->query("kee") < 100 && userp(me))
                return notify_fail("你的气血不够！\n");
    
        me->receive_wound("kee", 5);
        msg = RED "$N"+RED"的眼中红光一闪，一条细如发丝的血线射向$n！\n\n" NOR;
    
        ap = me->query_skill("cursism");
        my_exp=me->query("combat_exp");
        dp = target->query("combat_exp");
    
        if (userp(me)) {
                extradam = me->query("kee");
                extradam = extradam/5;
        } else  extradam = 1000; 
//      message_vision("extradam is"+(string)(extradam)+".\n",me);
//      =10000/5
    
        damage = ap*3 + random(ap*4) + extradam/4;
//      400x3+ random(400x4) + 2000/4
//      lowest 1700, highest 3300, average 2300 
// message_vision("damage is"+(string)(damage)+".\n",me);
 
        if(damage >me->query("max_kee")) damage = me->query("max_kee");
    
        if (userp(me)) ap=random(my_exp/80*ap);
                        else ap=random(8*my_exp);
        if( ap>dp) {
                if (!me->is_fighting(target)) {
                if (!userp(target)||!userp(me)) {
                        target->kill_ob(me);
                        me->kill_ob(target);
                }else { 
                        id_enemy=target->get_id();
                        me->ccommand("kill "+id_enemy);
                        target->kill_ob(me);
                }
                }
                message_vision(msg, me, target);
                target->receive_wound("kee", damage/2, me);
                target->receive_damage("kee", damage/2, me);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else          {
                msg += WHT"但是被$n"NOR+WHT"发现了！！\n"NOR;
                message_vision(msg, me, target);
                if (!me->is_fighting(target)) {
                if (!userp(target)||!userp(me)) {
                        target->kill_ob(me);
                        me->kill_ob(target);
                }else { 
                        id_enemy=target->get_id();
                        me->ccommand("kill "+id_enemy);
                        target->kill_ob(me);
                }
                }
        }
        me->start_busy(3) ;   
        return 1;
}        
