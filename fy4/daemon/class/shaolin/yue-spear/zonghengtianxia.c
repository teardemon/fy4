#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
    string forceskill,msg;
        int extra;
        int tmp;
        object weapon;
        
        weapon=me->query_temp("weapon");
    extra = me->query_skill("yue-spear",1);
    if ( extra < 60) 
        return notify_fail("你的岳家中平枪法还不够纯熟！\n");
        forceskill = (string) me->query_skill_mapped("force");
    if ( forceskill != "manjianghong")
        return notify_fail("『纵横天下』需要『满江红心法』的配合！\n");
    tmp = me->query_skill("manjianghong",1);
    if ( tmp < 60 )return notify_fail("你的『满江红心法』还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("『纵横天下』只能对战斗中的对手使用。\n");
        
        if ((string)me->query("class") != "official"||extra < 150){ 
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N仰天长啸，手中$w幻化出千重矛影，一式『纵横天下』从四面八方直刺$n！！\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2); 
                return 1;
        }
        
        if (!me->query("marks/官府/岳飞") && extra <180 ) {
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N仰天长啸，手中$w幻化出千重矛影，一式『纵横天下』从四面八方直刺$n！！\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2);   
                return 1;
        }
                
/*        if (extra < 150||!me->query("marks/官府/岳飞")) {
                me->add_temp("apply/attack", tmp);    
                me->add_temp("apply/damage", extra);
        msg = HIR  "$N仰天长啸，手中$w幻化出千重矛影，一式『纵横天下』从四面八方直刺$n！！\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp);
                me->add_temp("apply/damage", -extra);
                me->start_busy(2);   
        } */
        else {
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
    msg = HIW "\n$N仰天长啸，浩然正气直冲霄汉，手中$w幻化出千重矛影，正是『岳家中平枪法』\n百战无敌之式『--纵-横-天-下--』!!"NOR+HIC"\n\n动\n$N手中$w直指长空，陡然直刺$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "寒光\n$N怒喝一声，千重矛影惊涛骇浪般直刺$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "星黯然\n$N握枪之手移至中间，枪头枪尾有若两道急电点向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "纵横天下\n$N手中$w如狂风落叶，无处不在，漫天枪影中一点红光直刺$n！" NOR;
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*2);  
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "马长嘶\n$w虎虎生风，咝咝作响，仿佛万马奔腾！" NOR;
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra*2); 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "血溅\n$N手中$w枪头颤震，倏得爆开，变成满天血光！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "静\n四周一切突复宁静，$N手中$w枪影消失。" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    
    if (!me->query("marks/官府/岳飞")) { me->start_busy(7);}
    else     me->start_busy(6);
    
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        } 
        return 1;
} 
