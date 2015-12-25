 // silencer@fy
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;
        int gin;
        int kee;
        int sen;
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才能颂斗战胜诀！\n");
        
        skill = me->query_skill("lotusforce", 1);
        if(skill < 10) return notify_fail("你的莲华心法太差了！\n");
        
        if( target != me ) 
                return notify_fail("你只能提升自己的体能。\n"); 
        if( (int)me->query("force") < 100 )   
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("douzhan") ) 
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -100);
        message_vision(HIY"$N大喝一声“临 兵 斗 者 皆 阵 列 于 前”，全身泛出隐隐的金光．．．\n" NOR, me);
        gin = (int)me->query("gin");
        kee = (int)me->query("kee");
        sen = (int)me->query("sen");
        me->set("gin",gin+gin*skill/500);
        me->set("kee",kee+kee*skill/500);
        me->set("sen",sen+sen*skill/500);
        me->set_temp("douzhan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
} 
void remove_effect(object me, int amount)
{
        int gin;
        int kee;
        int sen;
        gin = (int)me->query("gin");
        kee = (int)me->query("kee");
        sen = (int)me->query("sen");
        me->set("gin",gin-gin*amount/500>0?gin-gin*amount/500:1);
        me->set("kee",kee-kee*amount/500>0?kee-kee*amount/500:1);
        me->set("sen",sen-sen*amount/500>0?sen-sen*amount/500:1);
        me->delete_temp("douzhan");
        tell_object(me, "你的〔斗战胜诀〕运行完毕，将内力收回丹田。\n");
}
       
