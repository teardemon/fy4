 inherit SSERVER;
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int force, lvl;
        object obj;
        lvl = me->query_skill("bibo-force",1);
        if (lvl<80)
                return notify_fail("你的碧波心法火候太差！\n");
                
        if( target != me)
                return notify_fail("你只能为自己驱毒。\n");
                
        force =(int) me->query("force");
        if( force <=100) return notify_fail("你的真气不足。\n");
        
        message_vision(HIW"$N运功抗毒，头上冒出豆大的汗．．．\n"NOR, me);       
        me->add("force", -100  );
        
        if (random(lvl) < 50)   return notify_fail("你失败了。\n");
                else    {
                        me->clear_condition();
                        write("你成功了！\n");
                        return 1;
                        }
        }              
