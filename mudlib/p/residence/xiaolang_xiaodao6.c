#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
你顺着小溪一边走一边看，一路上你闻着花草的香味，哗啦啦的溪水声衬托着
小道的宁静和安详，你能看到各种小鸟在花草树木中雀跃欢叫，时不时的还有各种
小动物在小路上来回穿梭，再往西就可以看到一个大大的露天温泉池。
LONG
        );
    set("exits", ([ 
								"north" : __DIR__"xiaolang_xiaodao4",
                "east" : __DIR__"xiaolang_huayuan",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",14);
    set("coor/y",2032);
    set("coor/z",30);
        setup();
} 
