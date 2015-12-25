 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if(me->query("class") != "official")            
                return notify_fail("你不是朝廷官员，不可以用玉环鸳鸯拳。\n");
        extra = me->query_skill("unarmed");
        if ( extra < 220) return notify_fail("你的少林长拳还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［玉环鸳鸯拳］只能对战斗中的对手使用。\n");
        if (me->query("force")<me->query("force_factor")*3)
                return notify_fail ("你的内力不够。\n");
        me->add("force_factor",extra/7);
        me->add_temp("apply/attack",extra/10);
        msg = HIY  "$N使出少林长拳中的［玉环鸳鸯拳］，一招连环七式向$n攻出！\n" NOR;
        message_vision(msg,me,target);
        msg = HIY  "上一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "下一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "左一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "右一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "前一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "后一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       msg = HIY  "最后再一拳！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   if (me->query_busy()<5) me->start_busy(5);
        me->set("force_factor",0);
        if((int)me->query("force") < 0 ) me->set("force",0);
        me->add_temp("apply/attack",-extra/10);
        return 1;
}  
