#include <ansi.h>
#include <combat.h> 
inherit NPC;  
void smart_fight();
object offensive_target(object me);
void create()
{
        set_name("公孙大娘", ({ "gongsun daniang" }) );
        set("gender", "女性" );
        set("title", "红鞋子");
        set("nickname",HIW"剑器动四方"NOR);
    set("age", 58);
        set("int", 65);
        set("per", 5);
        set("str", 50);
        set("fle", 50);
        set("dur", 42);
        set("cor", 60);
        set("agi",80);
    set("long",
"这人身高八尺开外，眯着眼睛，就像是条懒睡的猛虎。阳光外面斜斜地照过来，照着他两
条黑墨般的浓眉，照着他棱棱的颧骨，也照着他满脸青惨惨的胡渣子直发光。
\n"
                );
        set("force_factor", 120);
        set("max_force",9000);
        set("force",9000); 
        set("combat_exp", 10000000);
        set("score", -90000);
        set_skill("unarmed", 220);
        set_skill("throwing", 200);
        set_skill("force", 300);
        set_skill("parry", 450);
        set_skill("literate", 110);
        set_skill("dodge", 350);
        set_skill("demon-force", 250);
        set_skill("demon-strike",300);
        set_skill("demon-steps",200);
        
                
   map_skill("force", "demon-force");
        map_skill("unarmed","demon-strike");
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("throwing","tanzhi-shentong");
        set("chat_chance",3);
        set("chat_msg",({
                "熊姥姥眯起眼睛，似乎望着天边，喃喃地说：“每当月圆的时候，我就想杀人。”\n",
                "熊姥姥皱起纹路纵横的老脸，对你笑了笑：“刚出锅的糖炒栗子，要不要尝尝？”\n",
                })      
        );
      
        setup();
        /*carry_object(__DIR__"obj/grey_cloth")->wear();
        carry_object(__DIR__"obj/owl_shoes")->wear();
        carry_object(__DIR__"obj/fried_nuts")->wield();
        */
}  
void heart_beat()
{
        ::heart_beat();
        if(is_fighting())
                smart_fight();
} 
smart_fight() {
        
}     
