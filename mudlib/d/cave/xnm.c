 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "西南门");
        set("long", @LONG
铺路用的石头在这里散乱地堆放着，还有一些零散的工具。
向南的地方有个大洞，一看就是刚刚刨出来的。似乎是这里的主
人嫌这里不够大，想从此再向南扩张。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"txnd",
  "east" : __DIR__"zl",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-37);
        set("coor/y",-24);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer p", this_object()))
                {
                        another = present("killer p", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_p");
                        another->move(environment(obj));
                   message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}      
