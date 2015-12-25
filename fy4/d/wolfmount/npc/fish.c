 inherit NPC;
void create()
{
        set_name("五彩神仙鱼", ({ "fish","colorful fish" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一条鱼头鱼脑的野鱼，在日光辉映下，身上变换出五彩的颜色，美丽异常。\n");
        set("max_kee", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80);
        setup();
}  
