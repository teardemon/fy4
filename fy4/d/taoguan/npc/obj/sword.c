 // sword.c
#include <ansi.h> 
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name(  "咒剑王夫" , ({ "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"这是一把桃木雕成的古剑，闻起来有一股香味，剑身刻著许多你从未见过的咒\n"
                        "文，只有剑柄部份有两个依稀可以辨认的篆字：「 王 夫 
」\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/spirituality", 3);
                set("for_taoist",1);
        } 
        ::init_sword(44);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        if( victim->is_zombie())
        {
                victim->receive_wound("gin",random(me->query("atman")*10));
                return HIR "就在这一刹那，王夫剑发出耀眼的红光！\n"NOR;  
        }
        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > 
(int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY 
"王夫剑发出一股金色的罡气，流遍$N的全身。\n"NOR;
                }
                return random(me->query_spi());
        }
}
   
