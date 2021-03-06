 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, bonus;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［右手诀］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        
        extra = me->query_skill("sword");
        bonus = me->query_skill("lefthand-sword", 1); 
        if (bonus>130) extra = extra + bonus;
        
        me->add_temp("apply/attack", bonus);    
        me->add_temp("apply/damage", extra);
        msg = HIR"$N"+HIR"将"+weapon->name() +HIR"换到右手，更快，更毒，更准地向$n"+HIR"刺出！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}  
