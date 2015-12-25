 inherit NPC;
void create()
{
        set_name("厨师", ({ "chef" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一个满脸红光的大厨。\n");
        set("combat_exp", 1000000);
        set("force", 500);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force_factor", 12);
        set_temp("apply/attack", 150);
        set_temp("apply/dodge",150);
  
  
        set("inquiry", ([
                "原料" : "烧菜的原料不够，哈老板正急着找人帮忙呢。",
                "山雀舌": "知道我还要你帮忙？",
                "烤山猪肉": "知道我还要你帮忙？",
                "沙虫肝": "知道我还要你帮忙？",
                "熊掌": "知道我还要你帮忙？",
        ]));      
        set("chat_chance", 1);
        set("chat_msg", ({
                "大厨汗流浃背地忙着烧菜，香味四溢。。。\n",
                "大厨叹口气说：原料不全，巧妇难为无米之炊啊。\n",
        }) );
        setup();
        carry_object(__DIR__"obj/apron")->wear();
}
