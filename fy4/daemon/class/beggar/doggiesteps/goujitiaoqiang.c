 // silencer@fy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int ap,dp; 
//      if(me->query("class")!="beggar")
//      return notify_fail("你又不是叫花子，使这种招数忒丢身份了吧。\n"); 
        extra = me->query_skill("doggiesteps",1);
        if ( extra < 50) return notify_fail("你的［野狗步法］还不够纯熟！\n"); 
        if((int)me->query("kee")*100/(int)me->query("max_kee") > 80 && me->query("class")!="beggar")
                return notify_fail("还没到关键时刻呢！\n");   
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［狗急跳墙］只能对战斗中的对手使用。\n"); 
        message_vision(HIW"\n$N凌空一跳，身形如被逼急的野狗，双脚一前一后，作势向$n踢出！
        将到未到之时，忽然旋身飞转。 \n"NOR,me,target);
        ap=(int)target->query("combat_exp");
        dp=(int)me->query("combat_exp");
        
        message_vision(HIW"\n左窜 \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/200)))
        {
                me->remove_killer(target);
                target->remove_killer(me);
                message_vision(YEL"\n$N一个措手不及，让$n从身边溜了过去。 \n"NOR,target,me);
                return 1;
        }
        message_vision(HIR"$N身形一展，挡住$n的去路。 "NOR,target,me);
        msg = YEL "$N狂叫一声“不挡好狗道！“，趁势朝$n的$l踹去。" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                
        message_vision(HIW"\n右闪 \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/150)))
        {
           me->remove_killer(target);
                target->remove_killer(me);
                message_vision(YEL"\n$N一个措手不及，让$n从身边溜了过去。 \n"NOR,target,me);
                return 1;
        }
        message_vision(HIR"$N身形一晃，挡在$n面前。"NOR,target,me);
        msg = YEL "$N气急败坏，使出[恶狗争道]，向$n的$l踢去！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);  
        message_vision(HIW"\n就地再一滚 \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/150)))
        {
                message_vision(YEL"\n$N一个措手不及，让$n从身边溜了过去。 \n"NOR,target,me);
                me->remove_killer(target);
                target->remove_killer(me);
                return 1;
        } 
        me->start_busy(2);
        message_vision(HIR"$N摧动内劲，$n只觉混身一滞，避无可避 \n"NOR,target,me);
        return 1;
}    
