 // road.c
// QC'ed by Tie@fy2
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里靠近佛教名山千佛洞，又是往来山上山下的必经之路。
在路边有一片小小树林，一张石桌，几张石凳。一个小贩在大
声叫卖，生意颇为兴隆。
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"road0",
  "west" : AREA_QIANFO"tanghuai",
]));
        set("objects", ([
               __DIR__"npc/xiaofan" : 1, 
       ]) );
        set("outdoors", "tieflag");
        set("coor/x",40);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
