 // Tea@fy4
inherit ROOM;
void create()
{
        set("short", "南天门");
        set("long", @LONG
走到这里，已经很接近天堂了。看着朵朵白云从窗外经过，你
完全忘记了自己身在何方。这里没有鸟语，没有花香，却有一种莫
名的舒适，令人感到身心通畅，焕然一新。
LONG
        );
        set("exits", ([
//  "south" : __DIR__"ahome",
//  "north" : __DIR__"bhome",
//  "east"  : __DIR__"marhome",
//  "west"  : __DIR__"teahome",
//  "up"    : __DIR__"chome",
  "down"  : __DIR__"home",
]));


        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}    
