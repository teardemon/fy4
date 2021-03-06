#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1); 
        if(me->query("class")!="fugui")
                return notify_fail("只有富贵山庄弟子才能使出「八方风雨会中州」的绝技。\n");
        if ( extra < 120) 
                return notify_fail("你的血战枪法还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("［八方风雨会中州］需要［鲲鹏步法］的配和！\n");
        if ( tmp < 120 )return notify_fail("你的［鲲鹏步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［八方风雨会中州］只能对战斗中的对手使用。\n");
        if (me->query_temp("perform/bafang")+20>time())
                return notify_fail("［八方风雨会中州］不能连续使用。\n"); 
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
    msg = HIR "\n\n$N大喝一声，漫天矛影中赫然使出『血战枪法』中的雷霆一击『--八方--风雨--会中州--』!!\n\n\n★休门★\n$N手中$w由缓至快向$n刺来！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★伤门★\n$N挥舞$w,化作漫天矛影,当空刺向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★杜门★\n$N将$w灌满真力,硬生生便朝$n砸了过来！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★景门★\n但见$N手中$w幻化出千万条银蛇,漫天攒动,扑向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★惊门★\n$N将$w舞得虎虎生风,卷起一波又一波滔天巨浪，飞向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIR  "★开门★\n$N奋起神威,手中$w大开大阖,旋风般朝$n袭了过来!！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★生门★\n$N断喝一声,手中$w迅如奔雷快如电掣,当胸捅向$n！" NOR;
   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "★死门★\n$w划出一道超出任何世俗之美的弧线,死神般划过$n的面门！" NOR;
        me->add_temp("apply/attack",tmp*4);
        me->add_temp("apply/damage",extra*4);   
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*5);
        me->add_temp("apply/damage",-extra*5);
        me->set_temp("perform/bafang",time());
        me->start_busy(4);
        return 1;
}   
