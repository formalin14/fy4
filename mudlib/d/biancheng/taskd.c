 // questd.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
#define MAX_SPREAD  100 
#include <ansi.h> 
inherit F_DBASE; 
mapping *quests;
mapping *read_table(string file);
string *roomlines;
int init_dynamic_quest(int hard);
void auto_reset_quest(int count);
int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
string locate_obj(object me,string str); 
void create() {
        string file;
        set("name", "使命精灵");
        set("id", "questd");
        quests = read_table("/quest/dynamic_quest");
        file = read_file("/quest/dynamic_location");
        roomlines = explode(file,"\n"); 
        auto_reset_quest(100);
} 
int quest_reward(object me, object who,object quest_item) {
        mapping quest;
        int exp,pot,score,combat_exp;
        
        if(!mapp(quest = quest_item->query("dynamic_quest"))) return 0;
        if(base_name(who) != quest["owner_name"]) return 0;
        combat_exp=me->query("combat_exp");
        if(combat_exp<10000)
                exp = 300+random(combat_exp/50);
        else if(combat_exp<128000)
                exp = 500 - random(2220000/combat_exp);
        else if(combat_exp<1024000)
                exp = 700 - random(45000000/combat_exp);
        else if(combat_exp<2400000)
                exp = 800 - random(300000000/combat_exp);
        else if(combat_exp<3000000)
                exp = 900 - random(600000000/combat_exp);
        else if(combat_exp<6800000)
                exp = 600 - random(300);
        else if(combat_exp>8800000)
                exp = 333 + random(666);
        else if(combat_exp>13600000)
                exp = 333 + random(999);
        else
                exp = 200 + random(400);
      
        // To encourage >1 - 2 M player do task gain pots
        if (combat_exp >1000000 && combat_exp <2000000) {
            pot = exp/4 + random(70-40000000/combat_exp);
        }
        else if (combat_exp>2000000) {
            pot=exp/5;
        }
        else if (combat_exp>12000000) {
            pot=exp/8;
        }
        else
            pot = exp/6;
        
        score = random(10)+1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        tell_object(me,"你被奖励了：\n" + chinese_number(exp) + "点实战经验\n"
                        + chinese_number(pot) + "点潜能\n" + chinese_number(score)+"点综合评价\n");
        CHANNEL_D->do_sys_channel("qst", sprintf("%s完成了%s的%s。\n",
                        me->name(1)+"（"+me->query("id")+"）", who->name(1), quest_item->name()));
        me->add("TASK",1);
        if(!undefinedp(quest["fin_func"])) {
                call_other(this_object(),quest["fin_func"],me,who,quest_item);
        }
        if(quest_item) {
                destruct(quest_item);
        }
        return 1;
} 
int init_dynamic_quest(int hard) {
   int i, j, usernum, numq, sq;
        
        if(hard) {
                message("system", HIR "\n\n重新分布所有使命．．．"+HIG"．．．重新分布完毕 \n\n" NOR, users());
        }
        
        for(i=0; i<sizeof(quests); i++) {
                spread_quest(quests[i],hard);
        }
        
/*
        // distribute quest according to number of people online.       
        j = 0;
        for(i=0; i<sizeof(quests); i++) {
                if(hard) {
                        already_spreaded(quests[i]["file_name"], hard);
                } else {
                        j += already_spreaded(quests[i]["file_name"], hard);
                }
        }
        
        usernum=sizeof(users());
        numq = sizeof(quests);
        sq = usernum >= MAX_SPREAD ? (numq - j) : (numq - j) * usernum / MAX_SPREAD;
        
        for( i=0; i < sizeof(quests); i++) {
                if(random(numq) < sq) {
                        spread_quest(quests[i],hard);
                        j++;
                }
        }

        if(hard){
                message("system", HIG "．．．重新分布完毕 \n" NOR, users()); 
        }
        
        return j;
*/
} 
void auto_reset_quest(int count) {
        int delay;
   
        if(count >= 8) {
                message("system", HIY "\n\n所有使命将在一分钟后重新分布！\n\n" NOR, users());
                EVENT_D->add_event(time()+60, this_object(), (: init_dynamic_quest, 1 :));
                count = 0;
                delay = time() + 10 + random(100);            
        } else if(count >= 6) {
                message("system", HIY "\n\n所有使命将在" + chinese_number(9-count) + "分钟后重新分布！\n\n" NOR, users());
                delay = time() + 60;
        } else {
                init_dynamic_quest(0);                  
                delay = time() + 900 + random(1800);
        }
        count++;
        EVENT_D->add_event(delay, this_object(), (: auto_reset_quest, count :)); 
} 
varargs int spread_quest(mapping quest, int hard) {
	object obj0,obj1,obj2,obj3;
	object cur_obj;
	object next_obj;
	object tar;
	object *inv;
	object *target=({});
	int i;
	string location;
	if(already_spreaded(quest["file_name"],hard)) return 0;
	reset_eval_cost();
	location = roomlines[random(sizeof(roomlines))];
	obj0=find_object(location);
	if(obj0)
	obj0->reset();
	else
	obj0=load_object(location);
	cur_obj =obj0;
	if(cur_obj)
	{
	inv = all_inventory(cur_obj);
	for(i=0; i<sizeof(inv); i++) {
	if(inv[i]->is_character() && !userp(inv[i]))
	target += ({ inv[i] });
	if(inv[i]->is_container()) target += ({ inv[i] });
		}
	}
	if(sizeof(target)) cur_obj = target[random(sizeof(target))];
	if(cur_obj)
	{
	tar = new(quest["file_name"]);
	tar->set("value",0);
	tar->set("dynamic_quest",quest);
	tar->move(cur_obj);		
	}
return 1;
} 
int sort_quest_list(mapping a, mapping b) {
        if(a["done"] == b["done"]) {
                return strcmp(a["item"]->query("id"), b["item"]->query("id"));
        } else {
                return b["done"] - a["done"];
        }
} 
string random_room() { return roomlines[random(sizeof(roomlines))]; }
string dyn_quest_list() {
        string output="", quest_string;
        object owner,item;
        mapping *quest_list = ({ });
        int i, j, k, extra;
        
        for( i=0; i < sizeof(quests); i++) {
                reset_eval_cost();
                if(!objectp(owner= find_object(quests[i]["owner_name"])) &&
                                !objectp(owner = load_object(quests[i]["owner_name"]))) {
                        write("error: cannot load " + quests[i]["owner_name"] + "\n");
                   continue;
                }       
                if(!objectp(item= find_object(quests[i]["file_name"])) && 
                                !objectp(item = load_object(quests[i]["file_name"]))) {
                        write("error: cannot load " + quests[i]["file_name"] + "\n");
                        continue;
                }
                quest_list += ({        ([      "owner"         :       owner,
                                                                "item"          :       item,
                                                                "done"          :       already_spreaded(quests[i]["file_name"], 0) ? 0 : 1
                                                        ])      });
        }
        quest_list = sort_array(quest_list, (: sort_quest_list :));
        for(i=0; i<sizeof(quest_list); i++) {
                quest_string = sprintf("%s%s的『%s』(%s)%s",
                                quest_list[i]["done"] ? "【" : "　",
                                quest_list[i]["owner"]->query("name"),
                                quest_list[i]["item"]->query("name"), 
                                quest_list[i]["item"]->query("id"), 
                                quest_list[i]["done"] ? "】" : "　");
                k = 0;
                extra = 0;
                for(j=0; j<strlen(quest_string); j++) {
                        if(quest_string[j] == ESC[0]) {
                                k = 1;  
                        }
                        if(k == 1) {
                                extra++;
                        }
                        if(quest_string[j] == 'm') {
                                k = 0;  
                        }
                }
                output += sprintf("%-*s", (45 + extra), quest_string);
                if(i%2) {
                        output += "\n";
                }
        }
        output += "\n";
        return output;
} 
  
string locate_obj(object me,string strr) {
        string *distance = ({
                "极近", "很近", "比较近", "不远",
                "不近", "比较远", "很远", "极远"
        });
        string *altitude =({
                "高处", "地方", "低处"
        });
        string *directions=({
                "周围","北方", "南方", "东方","西方",
                "东北方","西北方","东南方","西南方"
        });
        object ob, tmpobj,where, *ob_list;
        object item,room;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
        int tmp;
        string str="";
        reset_eval_cost();
        for( i=0; i < sizeof(quests); i++)
        {
                if(!objectp(item= find_object(quests[i]["file_name"])))
                        item = load_object(quests[i]["file_name"]);
        if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
        }
        if(str != "") {
                room = environment(me);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        ob=find_env(ob_list[i]);
                        if(ob)
                        {
                                x0= (int)room->query("coor/x");
                                y0= (int)room->query("coor/y");
                                z0= (int)room->query("coor/z");
                                x=(int)ob->query("coor/x")-x0;
                           y=(int)ob->query("coor/y")-y0;
                                z=(int)ob->query("coor/z")-z0;
                                realdis=0;
                                if(x<0)realdis-=x; else realdis+=x;
                                if(y<0)realdis-=y; else realdis+=y;
                                if(z<0)realdis-=z; else realdis+=z;
                                tmp =(int)  realdis/50;
                                if(tmp>MAX_DIS) tmp = MAX_DIS;
                                dis=distance[tmp];
                                if(z>0) alt=altitude[0];
                                if(z<0) alt=altitude[2];
                                if(z==0) alt=altitude[1];
                                if(x==0&&y==0) dir=directions[0];
                                if(x==0&&y>0) dir=directions[1];
                                if(x==0&&y<0) dir=directions[2];
                                if(x>0&&y==0) dir=directions[3];
                                if(x<0&&y==0) dir=directions[4];
                                if(x>0&&y>0) dir=directions[5];
                                if(x<0&&y>0) dir=directions[6];
                                if(x>0&&y<0) dir=directions[7];
                                if(x<0&&y<0) dir=directions[8];
                                output = "『"+ob_list[i]->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
                                return output;
                        }
                }
        }
        else 
        // the checking of official and wizard is transferred to locate.c--mimicat 5.3.02
        /*if(wizardp(me) || me->query("class") == "official")*/
        {
                /*
                if (!wizardp(me) && me->query("combat_exp")<50000)
                        {tell_object(this_player(),"你的经验还不足以确定他人的所在。\n");
                                return"";
                        }
                */      
                        tmpobj = find_player(strr);
                        if(!tmpobj) tmpobj = find_living(strr);
                        if(!tmpobj) return "";
                        ob = find_env(tmpobj);
                   room = environment(me);
                        if(ob)
                        {
                                x0= (int)room->query("coor/x");
                                y0= (int)room->query("coor/y");
                                z0= (int)room->query("coor/z");
                                x=(int)ob->query("coor/x")-x0;
                                y=(int)ob->query("coor/y")-y0;
                                z=(int)ob->query("coor/z")-z0;
                                realdis=0;
                                if(x<0)realdis-=x; else realdis+=x;
                                if(y<0)realdis-=y; else realdis+=y;
                                if(z<0)realdis-=z; else realdis+=z;
                                tmp =(int)  realdis/50;
                                if(tmp>MAX_DIS) tmp = MAX_DIS;
                                dis=distance[tmp];
                                if(z>0) alt=altitude[0];
                                if(z<0) alt=altitude[2];
                                if(z==0) alt=altitude[1];
                                if(x==0&&y==0) dir=directions[0];
                                if(x==0&&y>0) dir=directions[1];
                                if(x==0&&y<0) dir=directions[2];
                                if(x>0&&y==0) dir=directions[3];
                                if(x<0&&y==0) dir=directions[4];
                                if(x>0&&y>0) dir=directions[5];
                                if(x<0&&y>0) dir=directions[6];
                                if(x>0&&y<0) dir=directions[7];
                                if(x<0&&y<0) dir=directions[8];
                                output = "『"+tmpobj->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
                                return output;
                        }
                }
        return ""; 
}  
int already_spreaded(string str,int hard) {
        object ob,*ob_list;
        int i;
        if(!str) return 0;
	if(hard)
	{
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
		{ ob_list[i]->move(VOID_OB);
		 destruct(ob_list[i]);
		}
	}
	return 0;
	}
	else
	{
	if(!str) return 0;
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
			return 1;
	}
	return 0;
	}
} 
object find_env(object ob) {
        while(ob) {
                if(ob->query("coor")) {
                        return ob;
                } else {
                        ob=environment(ob);
                }
        }
        return ob;
} 
mapping *read_table(string file) {
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn; 
        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
           if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        } 
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}
void big_reward(object me, object who, object item)
{
        tell_object(me,"你真行！！\n");
} 
void execute_accept_object(object me, object who, object item)
{
        who->accept_object(me,item);
}
