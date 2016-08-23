 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM; 
void create()
{
        object con,item; 
    set("short", HIC"荧河"NOR);
    set("long", @LONG
洞穴到这里已是尽头。周围是无边的空旷与寂静。前面水波粼粼，竟是不知多
宽多远的河面。在岸边望去，幽幽的河底深处，似乎有荧光浮动。
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"stair3",
        ]));
    set("indoors", "yinghe");
    set("item_desc", ([
        "river": "蓝色的水面平静无波，水色越来越深，透过幽暗的蓝色，你似乎看到有荧光浮动。
你似乎可以潜下去。（ｄｉｖｅ）\n",
                "荧河" : "蓝色的水面平静无波，水色越来越深，透过幽暗的蓝色，你似乎看到有荧光浮动。
你似乎可以潜下去。（ｄｉｖｅ）\n",
    ]));
    set("objects", ([
                __DIR__"obj/stair" : 1,
        __DIR__"npc/old_man" : 1,
    ]) );
        
    set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-100);
        setup();
        
} 
void init(){
        add_action("do_dive", "dive");
} 
int do_dive(){
        object oldman, me, room;
   
        me = this_player();
        oldman = present("wu ming", this_object());
        if(objectp(oldman)){
                if(me->query_temp("marks/yinghe_prepared")){
                        message_vision("$N对$n道：你既已有备而来，不妨下去见识一番。\n", oldman, me);
                        message_vision(HIB"$N右手微抬，一股微微的蓝光笼罩在$n全身。\n"NOR, oldman, me);
                        me->delete_temp("marks/yinghe_prepared");
                        message_vision("$N入水后迅速向下沉去。\n", me);
                        tell_object(me, "\n骤然间你觉得四周压力减轻，你身形不由得急速向下落去。\n\n");
                        room = find_object(__DIR__"center");
                        if(!objectp(room)){
                                room = load_object(__DIR__"center");
                        }
                        me->move(room);
                        return 1;
                } else {
                        message_vision("$N对$n道：那是一个未知的世界，你还是不要乱闯，等你准备好在来吧。\n", oldman,me);
                }
        }
        message_vision("\n$N身形还未靠近水面，一股反弹力吧$N弹开。\n", me);
        return 1;
}       
