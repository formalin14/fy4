 // vendor.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
#include <ansi.h>
#include <dbase.h>
mapping holiday_list = ([
                                                "1-1":"春节",
                                                "1-15":"元宵节",
                                                "3-10":"清明节",
                                                "5-5":"端午节",
                                                "7-7":"七夕节",
                                                "7-15":"鬼节",
                                                "8-15":"中秋节",
                                                "9-9":"重阳节",
                                                "12-8":"腊八节",                                                
                                                ]); 
int buy_object(object me, string what)
{
        mapping goods;
        string list, *name, *holidays;
        int i;
                string current_time, current_holidayname;
                mixed *local; 
        if( !mapp(goods = query("vendor_goods")) ) return 0;
                //find if today is a holiday
                local= NATURE_D->get_current_time();
                current_time = (local[3]+1) + "-" + (local[2]+1);
                holidays = keys(holiday_list);
                for (i=0;i<sizeof(holidays);i++)
                        if (current_time == holidays[i])
                                current_holidayname = holiday_list[holidays[i]]; 
                name = keys(goods);
        for(i=0; i<sizeof(name); i++)
                {
                        if (name[i]->query("holiday") == 0 || name[i]->query("holiday")==current_holidayname)
                        {
                                if(what ==  name[i]->name() || what == (name[i]->query("id")))
                                        return    (int)  (name[i]->query("value")) ;
                   }
            }
        return 0; 
} 
int compelete_trade(object me, string what)
{
        string ob_file;
        object ob;
        mapping goods;
        string list, *name, last = "";
        int i;
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++){
        if(what ==  name[i]->name() || what == (name[i]->query("id")))
        {
                if( stringp(ob_file = name[i]) ) {
                ob = new(ob_file);
// Let's decrement the amount if it goes to zero, delete it from vendor list
                        if(ob->move(me)){
                                goods[name[i]]--;
                                if(goods[name[i]] <= 0){
                                map_delete(goods,name[i]);
                                last = "最后";}  
                                printf("你向%s买下%s一%s%s.\n",this_object()->query("name"),
                                last,
                                ob->query("unit"), ob->name());
                                return 1;
                        }
                        else
                        {
                            destruct(ob);
                            // akuma add the above line to avoid new many many ob but cannot move to player
                            // to save memory
                            // on 2002-10-08
                                return 0;
                        }
                
                } 
        }
        }
        return 0;
} 
string price_string(int v) {
        if(v%10000 == 0) {
                return CHINESE_D->chinese_number(v/10000) + "两黄金";
        }
        if(v%100 == 0) {
                return CHINESE_D->chinese_number(v/100) + "两银子";
        }
        return CHINESE_D->chinese_number(v) + "文钱";
} 
/*
int do_vendor_list(string arg)
{
        mapping goods;
        string list, *name;
        int i; 
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        if( arg && !this_object()->id(arg) ) return 0;
        name = keys(goods);
        if(!sizeof(name))
                return notify_fail("这儿的东西全卖光了。\n");
        list = "你可以购买下列这些东西：\n";
        for(i=0; i<sizeof(name); i++)
                list += sprintf("%-10s %-20s ：%s\n",
                        name[i]->name(),name[i]->query("id"),
                        price_string(name[i]->query("value")) );
        write(list);
        return 1;       
} */ 
int do_vendor_list(string arg)
{
        
        mapping goods;
        string item, list, *name, *holidays,*count;
        int i, j, k, extra, num;
        string current_time, current_holidayname;
        mixed *local;
        
   if( !mapp(goods = query("vendor_goods")) ) return 0;
        if( arg && !this_object()->id(arg) ) return 0;
        name = keys(goods);
        count= values(goods);
        if(!sizeof(name))
                return notify_fail("这儿的东西全卖光了。\n"); 
        //find if today is a holiday
        local= NATURE_D->get_current_time();
        current_time = (local[3]+1) + "-" + (local[2]+1);
        holidays = keys(holiday_list);
        for (i=0;i<sizeof(holidays);i++)
                if (current_time == holidays[i])
                        current_holidayname = holiday_list[holidays[i]]; 
        num = 0;
        list =    HIY"┌─────────────┐"NOR + HIR"　货品价格表　"NOR + HIY"┌─────────────┐\n"NOR
                        + HIY"├─────────────┘"NOR + HIR"～～～～～～～"NOR + HIY"└─────────────┤\n"NOR; 
        for(i=0; i<sizeof(name); i++) {
                if(name[i]->query("holiday") == 0 || name[i]->query("holiday")==current_holidayname) {
                        item = sprintf("%s　『%s』(%s)",
                                        HIY"│"NOR,
                                        name[i]->name(),
                                        name[i]->query("id"));
                                        k = 0;
                        extra = 0;
                        for(j=0; j<strlen(item); j++) {
                                if(item[j] == ESC[0]) {
                                        k = 1;  
                                }
                                if(k == 1) {
                                        extra++;
                                }
                                if(item[j] == 'm') {
                                        k = 0;  
                                }
                        }                
                if (name[i]->query("base_unit")) {
                list += sprintf("%-*s%-14s%6s%s%s\n",
                                        (50 + extra), 
                                        item, 
                    price_string(name[i]->query("value")),
                                   CHINESE_D->chinese_number(count[i]),
                                        name[i]->query("base_unit"),
                                        HIY"│"NOR);
                } else { 
                        list += sprintf("%-*s%-14s%6s%s%s\n",
                                        (50 + extra), 
                                        item, 
                    price_string(name[i]->query("value")),
                                        CHINESE_D->chinese_number(count[i]),
                                        name[i]->query("unit"),
                                        HIY"│"NOR);
                        }
                        
                        if ((++num % 20) == 0) {
                                write(list);
                                list = "";
                        }
                }
        } 
        if (!num)
                return notify_fail("这儿的东西全卖光了。\n"); 
        list += HIY"└───────────────────────────────────┘\n"NOR; 
// i think below should be this_player()->start_more(list),that is ok.
// but it does not work:((,it is an add_action,but why can not i call "this_player()" to start_more()?
// so i can only change it to write 1024 then write another 1024....
// what's more, it is not very good when the list is tooo long,it will flood player's screen.
// originally is : write(list);
        do {    
                write(list[0..1024]);
                list=list[1025..];
        }while(strlen(list)>1024);
        if(strlen(list)>0)
                write(list);
// changed by akuma for : if a vendor's list is too long that players can't finish it by "list"
// on 2002-9-18
        return 1;       
}   
