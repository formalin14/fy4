#include <room.h>
inherit NEWBIE_HELP_ROOM; 
void create()
{
        set("short", "凤求凰客栈");
        set("long", @LONG
前厅挂着一幅龙凤双飞的巨画。当门挂着对鸳鸯球。球上系着几个小小的黄铜
风铃。微风掠过，风铃发出清脆悦耳的叮咚声。大门两侧挂着斗大的大红灯笼，上
书凤凰两字。朱门上横批一个“求”字。门前一口大缸，为往来行人提供清水。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"swind1",
        ]));
    set("resource/water", 1);
    set("liquid/container", "水缸");    
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",-10);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",-10);
        set("coor/z",0);
        set("no_dazuo",1);
        set("no_study",1);
        setup();
        replace_program(NEWBIE_HELP_ROOM);
}   
