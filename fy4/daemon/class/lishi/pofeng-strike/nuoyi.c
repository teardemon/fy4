 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［乱泼风］只能对战斗中的对手使用。\n");
        extra = me->query_skill("pofeng-strike",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N双掌血红，五指绽开，无数道掌风破空而出，隐隐带着雷声迅疾无比地击向$n！" NOR;
        COMBAT_D->do_attack(target,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;
}  
