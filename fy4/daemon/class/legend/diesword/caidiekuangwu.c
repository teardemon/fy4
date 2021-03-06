#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int third_sword(object me,object target,int extra,object blade);
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        extra = me->query_skill("diesword",1);
        weapon=me->query_temp("weapon");
        if ( extra < 30) return notify_fail("你的蝶恋花剑法还不够纯熟！\n"); 
        if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
                return notify_fail("［彩蝶狂舞］需要［棋道心法］的配和！\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［彩蝶狂舞］只能对战斗中的对手使用。\n");
        
if (me->query("class")!="legend") {
        msg = HIG  "$N使出蝶恋花剑法中的［彩蝶狂舞］，一招连环两剑，\n手中的"+ weapon->name()+  HIG"闪电般向$n"HIG"攻出第一剑！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "第二剑！" NOR;
        me->add_temp("apply/damage",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra);
        if (extra<130) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        } 
        me->add_temp("apply/damage",extra*2);
        msg = HIG  "$N剑尖急抖，一片剑影中又攻出第三剑！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*2);
        if (me->query_busy()<3)  me->start_busy(3);
        return 1;
} 
        me->add_temp("apply/damage",extra);
        msg = HIG  "$N使出蝶恋花剑法中的［彩蝶狂舞］，一招连环两剑，\n手中的"+ weapon->name()+  HIG"闪电般向$n"HIG"攻出第一剑！“心如镜，肩上细蝶飞”" NOR;
   COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "第二剑！“应趁无风投比翼, 待得愁落去人回”" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra);            
        
        if (extra <130) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        }
        
        third_sword(me,target,extra,weapon);                            
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        
} 
        
int third_sword(object me,object target,int extra,object weapon)
{
        string msg;
        int bonus, exp_bonus;
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0;
        exp_bonus = me->query("combat_exp")/1000*extra/8000;    
        if(me->query("宿命A/风云_蝴蝶")) bonus=extra;
        me->add_temp("apply/damage",extra*7+ bonus+exp_bonus);
        msg = HIG  "$N剑尖急抖，一片剑影中又攻出第三剑！“波乱影难归。”" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*7-bonus-exp_bonus);
        return 1;
}      
