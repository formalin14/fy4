 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄武门西");
        set("long", @LONG
方砖，绿草。和东边没有什么两样。十丈方圆的地方显得特别的
协调，不大也不小。从这里可以清楚地望到不远处的旗杆和旗杆顶部
的观望亭。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "east" : __DIR__"cxs3",
          "west" : AREA_WOLFMOUNT"yinroad1",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-510);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
