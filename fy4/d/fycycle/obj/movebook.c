 inherit ITEM;
void create()
{
        set_name("轻功简介", ({ "move book", "movebook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一本介绍基本轻功的书。\n");
                set("value", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_sell",1);
                set("material", "paper");
                set("skill", ([
                        "name": "move",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 120,
                ]) );
        }
}   
