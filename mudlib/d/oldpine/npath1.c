 // Room: /d/oldpine/npath1.c
inherit ROOM; 
void create()
{
        set("short", "林间小路");
        set("long", @LONG
你现在正走在一条林间的小路，往西不远处走出这座林子就是梦仙
龛，小路两旁长满了许多高耸的松树，周围的居民都把这里叫做「老松
林」，据说林子里有株树龄上千的老松树，颇有灵验。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"npath2",
  "west" : AREA_TAISHAN"mengxian",
]));
        set("outdoors", "oldpine"); 
        set("coor/x",500);
        set("coor/y",2390);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}       
