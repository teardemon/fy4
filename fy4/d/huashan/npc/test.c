 inherit NPC;
void create()
{
        set_name("试验品", ({ "tester" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
          set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}  
void die(){
    object killer;
    string location;
    int difficulty;     
    location="菜市口";
    
    killer = this_object()->query_temp("last_damage_from");
         
    if(!killer->query("m_killer/tester")) {
         killer->set("m_killer/tester",1);
         difficulty =1;
         this_object()->master_reward(this_object(),killer,location,difficulty);
        }
        
    ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
    object money_reward;
    int i, pot, combat_exp, score;
    
    pot = difficulty*200;
    combat_exp = difficulty*10000;
    score = difficulty*50;
    killer->add("potential",difficulty*200);
    killer->add("combat_exp", difficulty*10000);
    killer->add("score", difficulty*50);
    
    for(i=0; i<difficulty+1; i++) {
        money_reward = new("/obj/money/tenthousand-cash");
        money_reward ->move(killer);
        }
        write(sprintf("你被奖励了%s潜能。\n", CHINESE_D->chinese_number(pot)));
        write(sprintf("你被奖励了%s经验值。\n", CHINESE_D->chinese_number(combat_exp)));
        write(sprintf("你被奖励了%s评价。\n", CHINESE_D->chinese_number(score)));
CHANNEL_D->do_sys_channel(
        "info",sprintf("%s，%s于%s击杀%s。", NATURE_D->game_time(),
                      killer->name(), location, this_object()->name()) ); 
//      for example 你被奖励了,xxxxx潜能，xxxxx经验值, xxxxx评价, xxxxxx
//黄金 
/*      Also, put an announcement in 传闻 'info' channel.      
        varibles are: date, killer, master, location, 
        date= mud time, do we have a 年月日 in Fy ?
        killer = xxder;
        victim = tester;
        location = 菜市口;
        
        
        the announcement will be similar to:
         [传闻] 某年某月某日,小蝶儿于菜市口击杀试验品! (风云第一人)
         
         
*/       
}   
