#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,bonus;
        int num, j, count;
        object weapon, *enemy;
        
//      if (me->query("class") != "huashan") 
//              return notify_fail("只有华山弟子可以使用「漫天花雨」。\n");
        
        if((int)me->query_skill("tanzhi-shentong",1) < 50)
                return notify_fail("你的弹指神通还不够精纯！\n");
        
        num = (int)(me->query_skill("throwing")/ 100);
        if (num>4) num=4+(me->query_skill("tanzhi-shentong",1)-160)/40;
        weapon = me->query_temp("weapon");
        count = weapon->query_amount();
        if (count < 10)
                return notify_fail("你的暗器数量太少。\n");
                
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("［漫天花雨］只能对战斗中的对手使用。\n");
        if(target)
                return notify_fail("这个绝招不需要指定使用对象！！\n");
        
        
        if (me->query("class")== "huashan") {
                extra = me->query_skill("throwing")/4;
        }
                        
        me->add_temp("apply/attack", extra);
        msg = YEL  "$N轻叱一声，衣袖一扬，无数"+ weapon->name() +"竟然从袖中纷纷飞出，\n"CYN"化成"+HIC"  漫"+HIG"  天"+HIY"  花"+HIR"  雨"+NOR CYN" 洒向在场每一个人！\n" NOR;
        message_vision(msg,me);
        weapon->set_amount(count-1);
        i = 0; 
        for (j=0; j<num;j++)
   {
                msg=HIY"$N手中的$w射向$n的$l！！"NOR;
                COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                if (i==sizeof(enemy)-1) i=0;
                        else i++;
        }
        if (me->query("class") == "huashan" && me->query("open_sesame")) {
                message_vision(YEL"\n$N身形一个转折，手中"+weapon->name()+NOR YEL "连连射出。。。\n\n"NOR,me);  
                i= sizeof(enemy)-1;
                for ( j = num; j>0; j--)
                {
                        msg=HIY"$N手中的$w射向$n的$l！！"NOR;
                        COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                        if (i==0) i=sizeof(enemy)-1;
                                else i--;
                }
        }
        
        
        
        me->add_temp("apply/attack", -extra);
        if (num>2) { 
                if (me->query_busy()<3) 
                        me->start_busy(3);
                }
        else   {
                if (me->query_busy()<2) 
                        me->start_busy(2);
                }
        return 1;
}      
