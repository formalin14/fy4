 // Room: /d/chuenyu/dustyroad.c
inherit ROOM; 
void create()
{
        set("short", "乡间小路");
        set("long", @LONG
这是一条从小镇通出来的黄土小路。南面是小镇的郊外，你似乎还
可以听到从小镇传来的噪杂人声。往北是一望无际的平原。一座黑朦朦
的山从云雾里忽隐忽现。
LONG
        );
        set("exits", ([ 
  "southwest" : AREA_PALACE"palace_path1",
  "north" : __DIR__"dustyroad.c",
]));
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) );
        set("outdoors", "chuenyu"); 
        set("coor/x",100);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
    if(random(2))
    {
        this_player()->move(this_object());
        return 1;
    }
}     
