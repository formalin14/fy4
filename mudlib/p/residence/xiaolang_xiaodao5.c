#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
你漫步在这条碎石小路上，闻着花草的香味，这里的宁静安详让你暂时忘却了
江湖中的血雨腥风，你看到各种小鸟在花草树木中雀跃欢叫，时不时的还有各种小
动物在小路上来回穿梭，向东面过去是主人的卧房。
LONG
        );
    set("exits", ([ 
								"west" : __DIR__"xiaolang_huayuan",
								"east" : __DIR__"xiaolang3",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",16);
    set("coor/y",2033);
    set("coor/z",30);
        setup();
} 
