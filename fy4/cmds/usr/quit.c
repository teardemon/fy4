 // quit.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
//      last modified by silencer at 9/24/2002 to fix autoload(),
//      it seems to depend on the sequence of inventory destroy. 
#include <command.h> 
//inherit F_DBASE;
inherit F_CLEAN_UP; 
void create()  {
        seteuid(getuid());
//    set("name", "离线指令");
//    set("id", "quit");
} 
int main(object me, string arg) {
        int i;
        object *inv, link_ob;
        // comment by HL to avoid warning.
        // int stage; 
        if(!me->query_temp("netdead")) {
                if(me->is_busy()) {
                        return notify_fail("你上一个动作还没有完成,不能退出。\n");
                }
                if(me->query_temp("no_quit")) {
                        return notify_fail("你现在不可以退出风云！\n");
                }
                if(environment(me)->query_temp("lock_scene"))
                {
                        if(time()<environment(me)->query_temp("lock_scene")+120)//防止万一没有去掉那个temp mark，出问题。
                                return notify_fail("你感觉到周围被一阵气场紧紧缩住，无法动弹。\n");
                }
        }
        me->heart_beat();
        if(!(int)me->query("kee")) {
                me->set("kee",1);
        }
        me->save(); 
        inv= all_inventory(me);
        for (i=0;i<sizeof(inv);i++) {
                if (!wizardp(me) && !inv[i]->query_autoload())
           if(!DROP_CMD->do_drop(me, inv[i])) {
                        write(inv[i]->name() + "化成一蓬粉末消失了。\n");
                        destruct(inv[i]);
                }
        } 
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if (wizardp(me)|| inv[i]->query_autoload()) {
                        write(inv[i]->name() + "化成一蓬粉末消失了。\n");
                        destruct(inv[i]);
                }
        }  
        link_ob = me->query_temp("link_ob"); 
        // We might be called on a link_dead player, so check this.
        if( link_ob ) {
                // Are we possessing in others body ?
                if( link_ob->is_character()) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                } 
                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        } 
        write("欢迎下次再来！\n");
        if(environment(me)) {
                message("system", me->name() + "离开游戏。\n", environment(me), me);
        } 
        CHANNEL_D->do_sys_channel("sys",sprintf(
                "%s(%s)离开游戏了。", me->name() , me->query("id")));
        log_file( "USAGE", sprintf(
                "%s quits at %s with exp: %d, pot: %d, money: %d\n",
                me->query("id"), ctime(time()), me->query("combat_exp"),
                me->query("potential"), me->query("deposit")));
        log_file("STAT", sprintf(
                "OFF %s %s %d %d %d %d %d %d %s\n",
                me->query("id"),me->query("name"),me->query("combat_exp"),
           me->query("deposit"),me->query("potential"),me->query("TASK"),
                me->query("mud_age"), me->query("QUEST"), ctime(time()) ) );
        destruct(me); 
        return 1;
} 
int help(object me)
{
        write(@HELP
指令格式 : quit 
当你(玩家)想暂时离开时, 可利用此一指令。
HELP
                );
        return 1;
}   
