#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        object corp,new1,room;
        if(me->query("class")!="yinshi")
                return notify_fail("只有帝王谷弟子才能下降头。\n");
        if( !target ) target = offensive_target(me); 
        if((int)me->query_skill("cursism") < 120 )
                return notify_fail("你的降头术不够高！\n"); 
        if( !target
        || !target->is_ghost()
        ||      target==me
        ||  userp(target) )
                return notify_fail("你只能对鬼魂下这个降头。\n");
        room=environment(target); 
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不够！\n");
        if(!corp = present("corpse",environment(me)))
                return notify_fail("你的周围没有尸体！\n");
        if( target->query("combat_exp") > 3 * me->query("combat_exp"))
                return notify_fail("你的的经验不足以控制"+target->name()+"！\n");
        
        me->receive_wound("kee", 100);
        msg = HIC "$N凌空对着$n虚点几下，$n缓缓的站了起来！\n\n" NOR;
        message_vision(msg,me,corp);
        destruct(corp);
        target->be_ghost(0);
        target->set("title",HIB"借尸还魂"NOR);
        extradam = (int) target->query("combat_exp");
        target->set("combat_exp",  extradam/2); 
        
        msg = HIC "$n对$N发出了令人毛骨悚然的笑声：“主人，有什么吩咐。。。”\n\n" NOR;
        message_vision(msg,me,target);
        
        target->set("possessed",me);
        target->set("acc_cmd",me);
   target->set_leader(me);
        me->start_busy(2);
        return 1;
}     
