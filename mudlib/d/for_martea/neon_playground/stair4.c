 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄石阶梯");
        set("long", @LONG 
黑黝黝的阶石蜿蜒向下，没入沉沉的黑暗中。越往下走，吹来的阴风
越刺骨。虽然有风在吹，你仍然感觉周围的黑暗中凝结着一股死气。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"stair3",
  "down" : __DIR__"griver",
  ]));
        set("indoors", "neon_playground");
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-100);
        setup();
        replace_program(ROOM);
}      
