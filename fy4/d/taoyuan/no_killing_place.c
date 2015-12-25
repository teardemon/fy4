 inherit ROOM;
 
 
void init() 
{ 
        add_action("do_kill","kill"); 
} 
 
int do_kill(string arg) 
{ 
        object me; 
         
        me=this_player(); 
        if("/cmds/std/kill"->main(me,arg)) 
                me->set("vendetta/taoyuan",time()); 
        return 1; 
} 
 
int valid_leave(object me,string dir) 
{ 
        object girl; 
         
        if(!me->query("vendetta/taoyuan") 
                ||me->query("vendetta/taoyuan")+10800<time()) 
        return 1; 
//      message_vision("haha\n",me); 
        girl=find_living("hong er"); 
        if(!girl|| (girl->query("event_person"))) 
                girl=new("/questnpc/lovestory1/secretgirl"); 
        girl->set("following_person",me); 
        girl->set("killing_person",me); 
        girl->set("chasing_time",time()); 
        call_out("begin_chasing",3+random(3),girl); 
        return 1; 
} 
 
int begin_chasing(object girl) 
{ 
        girl->move(this_object()); 
        girl->heart_beat(); 
 
        return 1; 
}   
