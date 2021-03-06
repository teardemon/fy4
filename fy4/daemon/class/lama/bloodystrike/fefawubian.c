 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra;
        extra=me->query_skill("bloodystrike",1);
        if(me->query("class")!="lama" && extra<100)
                return notify_fail("你密宗大手印的修为还不够高。\n");   
        if(extra<20)
                return notify_fail("你密宗大手印的修为还不够高。\n");   
                if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［佛法无边］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");        
        
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        
        if (target->query("boss") || target->query("big_boss")) yourexp=yourexp*7; 
//      200/2+1.1*140 = 254, 254/(35+9)+1 = 6.7 
        lvl = (int) me->query_skill("unarmed") / (35+random(10)) + 1;
        if(me->query("class")!="lama") lvl=lvl/2+1;
        msg = HIR "$N"NOR+HIR"使出密宗大手印中的［佛法无边］，幻出无数掌影击向$n！" NOR;
        if( random(myexp * lvl+yourexp) < myexp*lvl )
        {
                message_vision(msg + "\n", me, target);
                msg = "结果$n被$N攻了个手忙脚乱！\n";
                message_vision(msg, me, target);
                target->start_busy(3);
        }
        else
        {
                me->add_temp("apply/attack",extra/3);   
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack",-extra/3);  
        }
        me->start_busy(2);
        return 1;
}       
