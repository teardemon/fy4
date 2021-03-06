#include <ansi.h>
inherit ITEM;
string bow_desc();
void create()
{
        set_name(YEL"落云地弓"NOR, ({ "ground bow", "bow", "installed bow" }) );
        set_weight(70000);
        set("no_shown", 1);
        set("no_get", 1);
        set("no_drop", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", (: bow_desc :));
                set("value", 1000);
        set("material", "metal");
    }
        ::init_item();
} 
void init(){
        object me;
        
        me = this_player();
        if(this_player()==environment()) {
        add_action("do_install", "install");
    }
        add_action("do_search", "search");
        if(query("installed") && environment(me) == environment(this_object())){
                call_out("shoot", 1, me);       
        }
} 
string bow_desc(){
        if (query("installed")){
                return "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。\n";
        } else {
                return "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。
也许可以安装（ｉｎｓｔａｌｌ）试试。\n";
        }       
} 
int do_install(string arg){
        object me, arrow;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "ground bow"){
                return notify_fail("你要装什么？\n");
        }
        if(present("installed bow", environment(me)) || environment(me)->query("no_fight")){
                return notify_fail("你没找到合适的地方。\n");
        }
        arrow = present("giant arrow", me);
        if(!objectp(arrow)){
                return notify_fail("缺少箭，没有办法装。\n");
        }
        if(me->query("kee") < 100) {
                return notify_fail("你实在太累了，先休息一下吧。\n");
        }
        if(query("installed")){
                tell_object(me, HIG"你找了个隐蔽角落仔细把弓安装好。\n"NOR);
                this_object()->move(environment(me));
                set("owner", me->query("id"));
                me->receive_damage("kee", 50);
                return 1;
        }       
        if(me->query_str() > 45 ) {
                tell_object(me, HIG"你找了个隐蔽角落，奋起神力，缓缓把弓拉满，又仔细地安装上了箭头。\n"NOR);
                set("long", "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。\n");
        } else {
                message_vision("$N用力拉弓，神弓却丝毫不动。\n", me);
                return 1;
        }
        destruct(arrow);
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 50);
        return 1;
} 
int do_search(){
        object me, bow;
   me = this_player();
        if(!present("ground bow", environment(me))){
                return 0;
        }
        tell_object(me, "你仔细在这里搜索了一遍.\n");
        
        if(!random(5)) {
                tell_object(me, "你什么都没有找到。\n");
        } else {
                tell_object(me, "你在一个隐蔽的角落找到一个落云地弓。\n");
                this_object()->move(me);
        }
        return 1;
} 
int shoot(object me){
        int kee, i;
        string *limbs, limb, output, msg; 
        if(environment(me) != environment(this_object())) {
                return 0;
        }
        limbs = me->query("limbs");     
        limb = limbs[random(sizeof(limbs))];
        i = me->query_skill("perception");
        if(me->query("id") == query("owner")){
                return 0;
        }
        if( random(i) < 20){
                msg = HIR"不知从何处射来一只暗箭，“啪”的一声，正中$N的$l。\n"NOR;
                output = replace_string(msg, "$l", limb);
                message_vision(output, me);
                kee = me->query("eff_kee");
                me->receive_wound("kee", kee/3, me);
                COMBAT_D->report_status(me);
        } else {
                message_vision("一只暗箭不知从何射来，$N耳闻破空之声，一个转身及时避开。\n", me);
        }
        
        delete("installed");
        set("long", "一个似弓似弩的怪东西，似乎是猎人用来扑捉动物的。
也许可以安装（ｉｎｓｔａｌｌ）试试。\n");
   return 1;
}  
int query_autoload() { return 1; }    
