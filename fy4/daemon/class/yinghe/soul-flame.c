 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int soul_flame(object me, object obj, int lvl, int counter);
int cast(object me, object target)
{
        int lvl,i, number;
        object env, *inv;
        if(me->query("class")!="yinghe")
                return notify_fail("只有荧河武士才可以使用青冥魔咒！\n");
        if((int) me->query_skill("devil-spells",1) < 200)
                return notify_fail("你的青冥魔咒不够高深！");
                
        lvl = (int) me->query_skill("spells");
        if( me->query("mana") < 110 )
                return notify_fail("你的法力不够！\n");
        if( me->query("sen") <= 60 )
                return notify_fail("你的神不够！\n"); 
        me->add("mana", -100);
        me->receive_damage("sen", 50);
        message_vision(NOR CYN"$N面色阴沉如铁，口中喃喃念起咒语。缓缓将青魔手举至胸前，作火焰升腾状。 \n" NOR, me); 
        message_vision(BLU"无数幽幽的蓝火仿佛受到青魔手的召唤从地下升腾而起， \n$N周围顿时变成了恐怖的人间炼狱。 ", me);
        
        if(target)
                soul_flame(me, target, lvl,1);
        else
        {
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if( !inv[i]->is_fighting(me)) continue;                 
                        number++;
                        soul_flame(me, inv[i], lvl/number, 0);
                        
                }
        }
         
        if (userp(me)) me->start_busy(3) ;
        else  me->start_busy(1);
        return 1; 
} 
int soul_flame(object me, object obj, int lvl, int counter)
{
        int ratio;
        if (! obj->is_fighting() ) return 0;
        if (counter) message_vision(NOR BLU "\n蠕动的蓝火从$N脚下蜿蜒游动而起。\n"NOR, obj);
        message_vision(HIC "\n一条条蠕动的蓝火如蟒蛇般缠上了$N。\n"NOR, obj);
        if(obj->is_zombie()==1) {
                message_vision(RED "$N发出一阵焦臭味道，顿时化成黑黑的木炭！\n" NOR, obj);
                obj->die();
                return 1;
        }
        ratio = 100 + 100* (int) me->query("combat_exp") / (10 + (int) obj->query("combat_exp"));
        
        obj->set_temp("last_damage_from", me);
        obj->receive_wound("gin",lvl,me);
        obj->receive_wound("kee",lvl,me);
        obj->receive_wound("sen",lvl,me);
        
        COMBAT_D->report_status(obj); 
        return 1;
} 
