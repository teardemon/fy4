#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int my_exp,your_exp;
        
        if(me->query_skill("qingpingsword",1)<50)
                return notify_fail("�����ƽ�����ȼ�������\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���⡹�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (target->query("step_less")==1) 
                return notify_fail(HIW"�Է�������������տ�����ᱻ�˽����Ի�ġ�\n"NOR);
        
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        
        msg = CYN "$N"+CYN"ʹ����ƽ�����еġ��⡹�־�����������������ͼ����$n"+CYN"�Ĺ��ƣ�";
        me->start_busy(1);
        
        my_exp = random(me->query("combat_exp")*15/4);
        your_exp = (int)target->query("combat_exp");
        
        if(me->query("class")!="shenshui") 
                my_exp= 3*random(me->query("combat_exp"));
        
        if( my_exp > your_exp) {
                msg += "���$p"+CYN"��$P"+CYN"���˸����ֲ�����\n" NOR;
        
        if (userp(me)) target->start_busy((int)me->query_skill("qingpingsword", 1) / 100 + 2);
                else target->start_busy(3);
        } else {
                msg += "����$p"+CYN"������$P"+CYN"����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target); 
        return 1;
}      