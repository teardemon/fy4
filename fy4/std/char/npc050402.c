#include <command.h>
inherit CHARACTER;
inherit F_CLEAN_UP;
#include <ansi.h> 
void init(){
        ::init();
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
varargs object carry_object(string file, mapping attr)
{
        object ob;
        string *keyList;
        int i; 
        if(!objectp(ob = new(file))) return 0;
        if(mapp(attr)) {
                keyList = keys(attr);
                for(i=0; i<sizeof(keyList); i++) {
                        ob->set(keyList[i], attr[keyList[i]]); 
                }       
        }
        
        ob->move(this_object());
        return ob;
} 
object add_money(string type, int amount)
{
        object ob; 
        ob = carry_object("/obj/money/" + type);
        if( !ob ) return 0;
        ob->set_amount(amount);
} 
int accept_fight(object who)
{
        string att; 
        att = query("attitude"); 
        if( is_fighting() )     switch(att) {
        case "heroism":
                command("say �ߣ����аɣ�\n");
           break;
        default:
                command("say ���ж�Ϊʤ���ⲻ������̫����\n");
                return 0;
        } 
        if( (int)query("gin") * 100 / (int)query("max_gin") >= 90
        && (int)query("kee") * 100 / (int)query("max_kee") >= 90
        && (int)query("sen") * 100 / (int)query("max_sen") >= 90 ) {
                switch(att)
                {
                case "friendly":
                        command("say " + RANK_D->query_self(this_object())
                                        + "���������" + RANK_D->query_respect(who)
                                        + "�Ķ��֣�\n");
                        return 0;
                case "aggressive":
                case "killer":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        if( !is_fighting() )
                                command("say ��Ȼ" + RANK_D->query_respect(who)
                                                + "�ͽ̣�" + RANK_D->query_self(this_object())
                                                + "ֻ�÷��㡣\n");
                }
                return 1;
        }
        else return 0;
} 
// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if( !environment()
        || environment()==home )
                return 1; 
        // Are we able to leave?
        if( !living(this_object())
   || is_fighting()
        || !mapp(environment()->query("exits")) ) return 0; 
        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                        environment(), this_object());
        return move(home);
} 
// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int intellgent_behavor()
{
        int enc,max;
        object *inv;
        enc = (int) query_encumbrance();
        max =  (int) query_max_encumbrance();
        if(enc * 3 < max)
        command("get all");
        return 1;
} 
int chat()
{
        string *msg;
        int chance, rnd; 
        if( !environment() ) return 0;
        if( query_temp("is_unconcious") ) return 0;
        if(query("intellgent")) intellgent_behavor();
        if( !chance = (int)query(is_fighting()? "chat_chance_combat":
                                                         "chat_chance") )
                return 0; 
        if(arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg")) 
                        && sizeof(msg) != 0) {
                if( random(100) < chance ) {
                        rnd = random(sizeof(msg));
                        if(stringp(msg[rnd])) {
                                say(msg[rnd]);
                        } else if(functionp(msg[rnd])) {
                                return evaluate(msg[rnd]);
                        }
                }
           return 1;
        }
        return 0;
} 
// Default chat function: Let the npc random move to another room.
// modified by silencer @4-14-2002 so NPC will only walk within his AREA. 
int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env;
        
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        my_birth_place = file_name(this_object());
        
        if (domain_file(to_go_place)!= domain_file(file_name(this_object()))){
                return 1;
        }
        command("go " + direction);
        return 1;
} 
// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill; 
        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell );
} 
// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill; 
        if( stringp(force_skill = query_skill_mapped("force")))
                SKILL_D(force_skill)->exert_function(this_object(), func);
} 
// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action) {
        object weapon;
        string martial_skill, act; 
        if(sscanf(action, "%s.%s", martial_skill, act) != 2 ) {
                return 0;
        }
        if(!stringp(martial_skill)) {
                return 0;
        }
        
        if(martial_skill == "axe" || martial_skill == "blade" 
                        || martial_skill == "dagger" || martial_skill == "fork" 
                        || martial_skill == "hammer" || martial_skill == "parry" 
                        || martial_skill == "staff" 
                        || martial_skill == "sword" || martial_skill == "throwing" 
                        || martial_skill == "spear" || martial_skill == "whip" ) {
                weapon = this_object()->query_temp("weapon");
                if(!objectp(weapon) || martial_skill != weapon->query("skill_type")) {
                        weapon = this_object()->query_temp("secondary_weapon");
                        if(!objectp(weapon) || martial_skill != weapon->query("skill_type")) {
                                return 0;               
                        }
                }       
        }
                        
        martial_skill = query_skill_mapped(martial_skill);
        return SKILL_D(martial_skill)->perform_action(this_object(), act);              
} 
/*      add reward for first time kills a npc.. 
        on the npc need to set("reward_npc", 1) and set("difficulty", lvl);
        
        current plan is to set difficulty between 1-40,
        difficulty=1 is roughly the reward of 1 task
        so the criteria of NPC setting are:
        1-5:��feel free to give it to any NPC you like, it's just a task or 2,
                However, suggest NPC exp>500k at least.
        5-15: some strong or fun NPCs, weak masters such as jinwuming,
        15-30: 
   30-40: reserved for tough NPC masters only. The reward is huge so be careful here
                example: Master shangguan=30, Huang=40
*/ 
void die(){
        object killer, owner;
        string location;
        int difficulty, difficulty2;     
        
        if (this_object()->query_temp("last_damage_from")) {
        
                killer = this_object()->query_temp("last_damage_from");
                if(owner=killer->query("possessed"))    killer = owner; 
                if (killer->query("combat_exp")>this_object()->query("combat_exp")/15) {     
                        if(this_object()->query("reward_npc")){
                                if(!killer->query("m_killer/" + this_object()->query("name"))&& !this_object()->is_ghost()) {
                                        killer->set("m_killer/" + this_object()->query("name"),1);
                                        difficulty = this_object()->query("difficulty");
                                        if(!difficulty) difficulty = 1;
                                        location = environment(this_object())->query("short");
                                        this_object()->master_reward(this_object(),killer,location,difficulty);
                                }
                        }
                }    
                if(this_object()->query("dungeon_npc")=="eren2" && !this_object()->is_ghost()){
                        difficulty2 = this_object()->query("dungeon_difficulty");
                        if(!difficulty2) difficulty2 = 1;
                        this_object()->dungeon_reward(this_object(),killer,difficulty2);
                //      dungeon_reward() is defined in /std/char/smart_npc.c 
                }
        }
        ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
        object money_reward;
        int i, pot, combat_exp, score;
        string reward_msg,kill_msg;    
        string *kill_type = ({ "��ɱ", "��ɱ", "��ɱ", "����","��ɱ","��ɱ","��ɱ",
                                "��ɱ", "ƴɱ", "նɱ", "ŭɱ", });
        reward_msg="";
   
        kill_msg= kill_type[random(11)];
        
           
                pot = difficulty*50;
                combat_exp = difficulty*300;
                score = difficulty*4;
        
                killer->add("potential",pot);
                killer->add("combat_exp", combat_exp);
                killer->add("score", score);
                for(i=0; i<difficulty*3; i++) {
                money_reward = new("/obj/money/gold");
                money_reward ->move(killer);
        }
        
        CHANNEL_D->do_sys_channel(
                "info",sprintf("%s��%s��%s%s%s��", NATURE_D->game_time(),
                        killer->query("name"), location, kill_msg, this_object()->name()) );  
        reward_msg +=HIW+"��ɹ���ɱ����һ�������콾���㱻�����ˣ�\n\t\t" +
        chinese_number(combat_exp) + "��ʵս����\n\t\t"+
        chinese_number(pot) + "��Ǳ��\n\t\t" +
        chinese_number(score) + "������\n\t\t" + 
        chinese_number(difficulty*3) + "���ƽ�\n" + NOR;
                
        tell_object(killer,reward_msg); 
         
}     
/* the following 2 functions are to help NPC recover. Without those, it takes long 
time for NPC to recover gin/kee/sen, and they will never recover from eff_gin/kee/sen
damages. 
if some NPCs need to be shown as hurt, for example, Master yichen, Hu tiehua...
Just set("no_heal",1) in that particular NPC. */  
int heal_up()
{
        int gin,kee,sen;
        int egin,ekee,esen;
        int mgin,mkee,msen;
            
        if (query("no_heal")) return 1;
           
        gin = (int) query("gin");
        kee = (int) query("kee");
        sen = (int) query("sen");
        egin = (int) query("eff_gin");
        ekee = (int) query("eff_kee");
        esen = (int) query("eff_sen");
        mgin = (int) query("max_gin");
        mkee = (int) query("max_kee");
        msen = (int) query("max_sen");
        
        if (gin==mgin && egin == mgin
                && kee==mkee && ekee==mkee
                && sen==msen && esen==msen )
                return 1;
        
        if( environment() && !is_fighting() && living(this_object()) ) {
                call_out("healing", 1);
                return 1;
        }
        else remove_call_out("healing");
        
        return ::heal_up() + 1;
} 
void healing()
{
    int gin,kee,sen;
    int egin,ekee,esen;
    int mgin,mkee,msen;
    int n;
    string force_type;
    
    if (query("combat_exp")>1500000)   n=12;
        else n=16;
                
    force_type=(string) query("class");
    
    gin = (int) query("gin");
    kee = (int) query("kee");
    sen = (int) query("sen");
    egin = (int) query("eff_gin");
    ekee = (int) query("eff_kee");
    esen = (int) query("eff_sen");
    mgin = (int) query("max_gin");
    mkee = (int) query("max_kee");
    msen = (int) query("max_sen");
    
    
    if(gin < mgin || kee < mkee || sen < msen
        ||egin<mgin || ekee<mkee || esen<msen)
        {
        if (gin+mgin/n<mgin) set("gin",gin+mgin/n);
                else set("gin",mgin);
        if (egin+mgin/n/2<mgin) set("eff_gin",egin+mgin/n/2);
                else set("eff_gin",mgin);
        if (kee+mkee/n<mkee) set("kee",kee+mkee/n);
                else set("kee",mkee);
        if (ekee+mkee/n/2<mkee) set("eff_kee",ekee+mkee/n/2);
                else set("eff_kee",mkee);
        if (sen+msen/n<msen) set("sen",sen+msen/n);
                else set("sen",msen);
        if (esen+msen/n/2<msen) set("eff_sen",esen+msen/n/2);
                else set("eff_sen",msen);          
        }
} 
