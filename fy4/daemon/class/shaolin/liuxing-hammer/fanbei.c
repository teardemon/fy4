 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,n;
        extra = me->query_skill("liuxing-hammer",1);
        if ( extra < 50) 
                return notify_fail("你的反转流星锤法还不够纯熟！\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "xiaochengforce" && extra<170)
                return notify_fail("170级以下的反转流星锤法需要［小乘心法］的配合！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［反背连环锤］只能对战斗中的对手使用。\n");
        msg = HIY  "$N使出反转流星锤法中的［反背连环］，假意抽身急退，蓦地反身抖手一锤！" NOR;          
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        if (extra > 75) {
                msg = HIY  "$N紧跟一招，另一锤反身又是一锤！！" NOR;
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        }       
        if (extra > 100) {
                msg = HIY  "$N竟然还不回头，两臂一振，再来一锤！" NOR;
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        }
        if (me->query("class")!="shaolin" && extra>100) n=3; 
   if (me->query_busy()<2) me->start_busy(n);
        return 1;
}       
