 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,extra_damage;
        object weapon;
        extra = me->query_skill("wuche-axe",1);
        
        if ( extra < 100) return notify_fail("你的悟彻波风斧法还不够纯熟！\n");
        
        if (me->query("class")=="shaolin") extra_damage=extra;
        
        if (me->query("class")!="shaolin") extra=extra/4;
                else extra = extra/2;
                        
//      if (userp(me) && me->query_skill_mapped("force") != "xiaochengforce")
//              return notify_fail("［三板斧］需要［小乘心法］的配合！\n"); */
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［三板斧］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra);
        msg = HIY  "$N使出悟彻波风斧法中的［三板斧］，一招连环几斧，手中的"+ weapon->name()+  "劈山般向$n砍出第一斧！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        msg = HIY  "第二斧！" NOR;
        me->add_temp("apply/damage",extra_damage);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        if (me->query_skill("wuche-axe",1) > 130) {
                        msg = HIY  "第三斧！" NOR;
                        me->add_temp("apply/damage",extra_damage);
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->add_temp("apply/damage",-extra_damage);             
                   }
        else tell_object(me,HIG"\n你的手法不够熟练,第三斧没使出来.\n"NOR);      
        
        me->add_temp("apply/damage",-extra_damage);
        me->add_temp("apply/attack",-extra);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}      
