#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
你漫步在这条碎石小路上，闻着花草的香味，这里的宁静安详让你暂时忘却了
江湖中的血雨腥风，你看到各种小鸟在花草树木中雀跃欢叫，时不时的还有各种小
动物在小路上来回穿梭，再向前面走，你可以看到有一扇门(door)，里面是主人的
房间。
LONG
        );
    set("exits", ([ 
								"south" : __DIR__"xiaolang_huayuan",
//                "enter" : __DIR__"xiaolang2",
        ]));
    set("objects", ([

    ]));
    set("item_desc", ([
        "door" : "小门只是轻掩着，似乎轻轻一推就开了。\n",
        "门" : "小门只是轻掩着，似乎轻轻一推就开了。\n",
        ]) );
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2034);
    set("coor/z",30);
        setup();
} 
void init() {
        add_action("do_push", "push");
}  

void close_path()
{
    if( query("exits/enter") ) {
       message("vision","小门被风一吹，关上了。\n",this_object() );
       delete("exits/enter");
    }
} 
int do_push(string arg)
{
        object me;
        me = this_player();
        if( arg=="door" || arg =="门") {
        message_vision("$N往小门上轻轻地一推，吱......的一声小门开了。\n", me);
                set("exits/enter", __DIR__"xiaolang2");
                call_out("close_path", 2);
        }
        else {
                write("你要推什么呢？\n");
        }
        return 1;       
 }      