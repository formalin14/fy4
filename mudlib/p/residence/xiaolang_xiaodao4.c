#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
你顺着小溪一边走一边看，一路上你闻着花草的香味，哗啦啦的溪水声衬托着小
道的宁静和安详，你能看到各种小鸟在花草树木中雀跃欢叫，时不时的还有各种小动
物在小路上来回穿梭，再往西就可以看到一个大大的露天温泉池。
LONG
        );
    set("exits", ([ 
								"east" : __DIR__"xiaolang_huayuan",
                "west" : __DIR__"xiaolang4",
//                "south" :__DIR__"xiaolang_xiaodao6",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",14);
    set("coor/y",2033);
    set("coor/z",30);
        setup();
} 
