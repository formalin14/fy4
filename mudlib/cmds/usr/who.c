 // who.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//              - 07/13/2001 by Daniel Q. Yu.
//
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP; 
int sort_user(object,object);
int help(); 
private void create() { 
        seteuid(getuid()); 
} 
mixed main(object me, string arg, int remote) {
        string name, str, rule, *option;
        object *list, *ob, ob1;
        int i, opt_long,opt_number, numPlayer;
        
        if(remote && sizeof(arg)<2) arg="";
        ob = filter_array(children(USER_OB),(: userp :));
        ob = filter_array(ob, (: environment($1) :));
        ob = filter_array(ob, (: $2->visible($1) :), me);
        numPlayer = sizeof(ob);
        str = HIY"\n◎ 「"+ MUD_NAME+"」"HIW"目前";
        rule = "";
        if(arg) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- ) {
                        switch(option[i]) {
                                case "-h": 
                                        return help();
                                case "-l": 
                                        opt_long = 1;
                                        break;
/*                                case "-w": 
                                   rule += "巫师";
                                        ob = filter_array(ob, (: wizardp($1) || wizhood($1) == "(immortal)" :));
                                        break;*/
                                case "-p": 
                                        if(me->query("family/family_name")) {
                                                rule += me->query("family/family_name");
                                        } else {
                                                rule += "普通百姓";
                                        }
                                        ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
                                        break;
                                case "-f": 
                                        rule += "女性";
                                        ob = filter_array(ob, (: $1->query("gender") =="女性" :));
                                        break;
                                case "-m": 
                                        rule += "男性";
                                        ob = filter_array(ob, (: $1->query("gender") == "男性" :));
                                        break;
                                case "-a": 
                                        opt_number = 1;
                                        break;
                                case "-d": 
                                        rule += "断线";
                                        ob = filter_array(ob, (: $1->query_temp("netdead") :));
                                        break;
                                default:
                                        if(option[i][0]=='@'){
                                        RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
                                        write("网路讯息已送出，请稍候。\n");
                                        return 1;
                                        }
                                        ob1 = present(option[i], environment(me));
                                        if(!ob1) {
                                                ob1 = find_player(option[i]);
                                        }
                                        if(!ob1) {
                                                ob1 = find_living(option[i]);
                                        }
                                        if((!ob1) && (option[i] =="me")) {
                                           ob1=me;
                                        }
                                        if(!ob1) {
                                                return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
                                        }
                                        me = ob1; 
                                        if(me->query("family/family_name")) {
                                                rule += me->query("family/family_name");
                                        } else {
                                                rule += "普通百姓";
                                        }
                                        ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
                                }
                        }
                }
                str += rule + "玩家有：";
        str += HIY"\n────────────────────────────────────\n"NOR;      
        list = sort_array(ob,"sort_user");
        if(!sizeof(list)) {
                str = "目前游戏中并没有" + rule + "玩家。\n";
        } else if(opt_number) {
                str = HIY"「"+ MUD_NAME+"」"NOR + WHT"目前共有"+chinese_number(sizeof(ob))+ "位" + rule + "玩家。\n";
                } else if(opt_long) {
                        i = sizeof(list);
                        while(i--) {
                                str += sprintf("%s%s%s%s\n",
                                                interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                                list[i]->is_ghost() ? HIB"@"NOR : " ",
                                                list[i]->query("gender") == "女性" ? "♀" : "♂",
                                                list[i]->short(1)
                                );
                        }
                str += HIY"────────────────────────────────────\n"NOR;
                str += sprintf("共有%s位使用者连线中，系统负担：%s\n\n", 
                                CHINESE_D->chinese_number(numPlayer), query_load_average());
        } else {
                        i = sizeof(list);
                        while(i--){
                                str += sprintf("%s%s%s%-20s ", 
                                                interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                           list[i]->is_ghost() ? HIB"@"NOR : " ",
                                                list[i]->query("gender") == "女性" ? "♀" : "♂",
                                                sprintf("%s(%s)", list[i]->name(1), capitalize(list[i]->query("id"))));
                                if(i%3 == sizeof(list)%3) {
                                        str += "\n";
                                }
                        }
                        if(sizeof(list)%3) {
                                str += "\n";
                }
                str += HIY"────────────────────────────────────\n"NOR;
                str += sprintf("共有%s位使用者连线中，系统负担：%s\n\n", 
                                CHINESE_D->chinese_number(numPlayer), query_load_average());
        }
        if(remote) {
                return str;
        } else {
                me->start_more("", str, 0);
                }
        return 1;
} 
int sort_user(object ob1, object ob2) {
        string name1, name2;
        if(wiz_level(ob1) != wiz_level(ob2)) {
                return wiz_level(ob2) - wiz_level(ob1);
        }
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");
        if(intp(name1)) {
                name1 = "";
        }
        if(intp(name2)) {
                name2 = "";
        }
        if(name1 > name2) {
                return -1;
        }
        if(name1 < name2) {
                return 1;
        }
   return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
} 
int help() {
        write(" 
指令格式 : who [-h] [-l] [-p] [-f] [-m] [-a] [-d] [<ID>] 
这个指令可以列出所有在游戏中的玩家及其等级。 
-h 列出帮助屏幕。
-l 选项列出较长的讯息。
-p 只列出同门派的玩家。

-f 只列出游戏中的女玩家。
-m 只列出游戏中的男玩家。
-a 只列出当前游戏中玩家的总人数。
-d 只列出当前游戏中处于断线状态中的玩家。 
<ID> 列出<ID>代表玩家所属门派的玩家。 
"HIG"*"NOR" 表示"HIG"发呆"NOR"中，"HIR"#"NOR" 表示"HIR"断线"NOR"中，"HIB"@"NOR" 表示"HIB"鬼气"NOR"中。 
相关指令： finger \n\n");
        return 1;
}     
