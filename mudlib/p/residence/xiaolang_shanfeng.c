 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"山峰"NOR);
        set("long", @LONG
峰顶长满各种树木，树木中央有一块宽阔草地，踏过草地，就到了悬崖边，每当
凌晨来临，在此观看日出当真是别有风味，举目远望，有可见雾海茫茫，让人感慨万
千，当年萧十一郎曾答应带他女友来次观看日出，后来由于种种原因，仅没有成行，
后来庄主多次来这里，或是观看日出，或是挥剑习武。
LONG
        );
    set("exits", ([ 
//                "down" : __DIR__"xiaolang4",
        ]));
        set("objects", ([
                "/d/huashan/npc/songshu" : 1,
                "/d/wolfmount/obj/noflower" : 1,
        ]));  
    set("outdoors", "residence"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
//    replace_program(ROOM);
}   
void init()
{
        add_action("do_jumping", "feizong");
} 

int do_jumping()
{
        object obj;
        object me;
        
        me = this_player();
        message_vision("$N提了一口气，飞身一跃，顺着山坡急纵而下。\n", me);
        me->move(__DIR__"xiaolang4");
        message_vision(HIW"$N从山峰上急速纵了下来。\n"NOR, me);
        return 1;

}
