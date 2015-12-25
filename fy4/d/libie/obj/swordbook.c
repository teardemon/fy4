 // An example book
inherit ITEM; 
void create()
{
        set_name("残破剑谱" , ({ "swordbook" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "一本残缺不全的剑谱，左边的一半已经被焚毁，因此每个招式都只剩下一半。\n");
        set("value", 0);
        set("skill", ([
                "name":                 "libie-sword",      
                "exp_required": 1500000,       
                "sen_cost":       50   ,
                "difficulty":  100,  
                "max_skill":    80     
        ]) );
        set("no_get",1);
        set("no_drop",1);
}
     
