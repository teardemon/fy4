#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{       int damage,dp,ap;
        string msg;
        if (me->query("class") != "baiyun") return notify_fail("只有白云岛弟子可以演奏「百鸟朝凤」。\n");
    //add qin check here ->
    
    //<-
    if( me->is_fighting() )
        return notify_fail("「百鸟朝凤」不能在战斗演奏。\n"); 
/*
play 百鸟朝凤（play bainiaochaofeng) （60 lev music，耗心神100点，需隔1分钟 
才能反复使用) 
CYN你轻拨琴弦，琴声清丽，平正中和，隐隐有王者之意，忽听得空中振翼之声大作，各处飞 
来无数雀鸟，或止歇树巅，或上下翱翔，毛羽缤纷，蔚为奇观。 
GRN碧空中一只青鸟来回盘旋了几下，叼了一颗灵草丢在你身上，清啼一声，飞了开去。 
*/
        if((int)me->query_skill("essencemagic",1) < 40)
                return notify_fail("你的法术不够高！\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种法术只能对战斗中的对手使用。\n"); 
        if((int)me->query("atman") < 100 )
                return notify_fail("你的法力不够！\n"); 
        if( random(me->query("max_atman")) < 40 ) {
                write("你失败了！\n");
                return 1;
        } 
        msg = HIC "$N闭目凝神，印堂发出一道金芒射向$n！\n\n" NOR;
        damage = me->query_skill("magic")*5/2;
        dp = target->query("combat_exp");
        ap = me->query("combat_exp");
        
        if( random(ap *3 ) > dp ) {
                damage = damage + random(damage);
                msg +=  HIY "金芒从$p身上透体而过，拖出一条长长的血箭直射到两三丈外的地下！\n" NOR;
           target->receive_damage("kee", damage, me);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        } else
                {       msg += HIB"但是被$n躲开了。\n\n"NOR;
                        message_vision(msg, me, target);
                        }
        me->start_busy(2);
        me->add("atman",-40);
        return 1;
}      
