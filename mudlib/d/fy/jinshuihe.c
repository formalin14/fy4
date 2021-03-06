 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"金水玉带河"NOR);
        set("long", @LONG
一条宛如玉带般的金水河，清风徐来，鳞鳞水光仿佛玉带临风，栩栩如生，河
上五座白玉大理石石桥通向对岸。正中所谓“御路桥”，乃当今天子之路；其左右
称“王公桥”，是宗室亲王们走的；最外两桥方为“品级桥”，供一般官员行走。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"hall",
                "enter" : __DIR__"taihedian",
        ]));
        set("objects", ([
                __DIR__"npc/jindian_guard" : 2,
        ])); 
        set("outdoors", "fengyun");
        set("coor/x",50);
        set("coor/y",15);
        set("coor/z",0);
        setup(); 
} 
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    if( me->query("class") != "official" && dir == "enter" && ob=present("palace guard", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
      
            if( (string)(inv[i]->query("id")) == "silk" &&
                !(int)(inv[i]->query("equipped")))
                return notify_fail(ob->name()+"朗声道：「请装备後入宫的信物。」\n");
            if( (string)(inv[i]->query("id")) == "silk" )
                withtowel = 1;
        }
        if( !withtowel)
            return notify_fail(ob->name()+"凝神怒喝：「没有"+HIR"七"+HIY"彩"+HIG"丝缎带"+NOR"不能进入！滚！」\n");
    }
    if( dir == "south" && ob=present("palace guard", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if( (string)(inv[i]->query("id")) == "silk")
            {
                tell_object(me,ob->name()+"躬身接过你交回的"+
                            inv[i]->name()+"，「恭送贵宾。。。」．\n\n\n"); 
                destruct(inv[i]);
            }
        }  
    }
    return 1;
}   




/*int valid_leave(object me, string dir)
{
        object ob;
        if( me->query("class") != "official" && dir == "enter" && ob=present("palace guard", this_object()))
        {
                return notify_fail(ob->name()+"怒喝：“这太和殿也是你们这些无赖进去的么！滚！”\n");
        }
                return 1;
}   


int valid_leave(object me, string dir){
        object silk;
        
        if(obj->query("bellicosity") > 100 || obj->query_temp("weapon") || obj->query("vendetta/authority") || !objectp(silk)) {
                        return notify_fail("金殿武士神色一紧，怒喝道：“止步！”\n");
                }
        if(objectp(silk) && silk->query("equipped") != "worn")
                        return notify_fail("金殿武士神色缓和地道：“请着装好！”\n");
                if(objectp(silk) && silk->query("equipped") == "worn"){
                        message_vision("金殿武士一抱拳，躬身道：这位"+RANK_D->query_respect(obj) +"，总管吩咐，凡配有七彩丝缎带的请往里走！\n\n",
                                        obj); 
                        return 1;
                }
        }       
        }
        return 1;
}*/
