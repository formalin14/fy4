 // Room: irongate2.c --- neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "霹雳园");
        set("long", @LONG
这似乎是一座花园。但园中树木都似被火燎烤过一般，黑黑的树干上，枝叶七
零八落。北面是一座乌黑的大铁门，南面是一座黝黑的大铁门。门前的土地似乎有
被人翻动过的痕迹。
LONG); 
        set("outdoor","yinghe");
        set("objects", ([
                __DIR__"npc/guard1" : 1,
                __DIR__"obj/yubow" : 1,
        ]));
        set("item_desc", ([
                "door" : "南北各有两个大铁门。(north door/south door)\n",
                "south door" : "一座黝黑的大铁门， 可以打开。（ｏｐｅｎ）\n",
                "黝黑的大铁门" : "一座黝黑的大铁门， 可以打开。（ｏｐｅｎ）\n",
                "乌黑的大铁门" : "一座乌黑的大铁门， 可以打开。（ｏｐｅｎ）\n",
                "north door" : "一座乌黑的大铁门， 可以打开。（ｏｐｅｎ）\n",
        ]));
        //}} 
        setup();
} 
void init(){
        object bow;
        add_action("do_open", "open");
        bow = present("yu bow", this_object());
        if(objectp(bow)){
                bow->set("installed", 1);
        }
} 
void close_path(int i){
        object room;
        switch(i) {
        case 1:
                if( query("exits/south") ) {
                message("vision","哐铛一声大门在你面前关闭。\n",this_object() );
           delete("exits/south");
                room = find_object(__DIR__"irongate3");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate3");
                }
                message("vision","哐铛一声大门在你面前关闭。\n", room);
                        room->delete("exits/north");
            }
        break;
        case 2:
                if( query("exits/north") ) {
                message("vision","哐铛一声大门在你面前关闭。\n",this_object() );
                delete("exits/north");
                room = find_object(__DIR__"irongate");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate");
                }
                message("vision","哐铛一声大门在你面前关闭。\n", room);
                        room->delete("exits/south");
            }   
    break;
    }
}
int do_open(string arg){
        object room, me, room1;
        
        me = this_player();
    if( arg=="south door" || arg =="黝黑的大铁门") {
                if(query("exits/south")){
                        return notify_fail("门已经被打开了。\n");
                }
        message_vision("$N往大铁门上轻轻地一推，大铁门缓缓打开。\n", me);
                room = find_object(__DIR__"irongate3");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate3");
                }
                message("vision", "门被人从另外一边打开。\n", room);
                room->set("exits/north", __DIR__"irongate2");
                set("exits/south", __DIR__"irongate3");
                call_out("close_path", 5, 1);
           return 1;
        } 
        if (arg=="north door" || arg =="乌黑的大铁门") {
                if(query("exits/north")){
                        return notify_fail("门已经被打开了。\n");
                }
        message_vision("$N往大铁门上轻轻地一推，大铁门缓缓打开。\n", me);
                room = find_object(__DIR__"irongate");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate");
                }
                message("vision", "门被人从另外一边打开。\n", room);
                room->set("exits/south", __DIR__"irongate2");
                set("exits/north", __DIR__"irongate");
                call_out("close_path", 5, 2);
                return 1;
        } 
        if(arg = "door"){
                return notify_fail("你要开那一扇门？（ｎｏｒｔｈ　ｄｏｏｒ／ｓｏｕｔｈ　ｄｏｏｒ）\n");
        }
        else {
                write("你要推什么呢？\n");
        }
        return 1;       
        message_vision("$N伸手推开了大铁门。\n", me);
} 
int valid_leave(object ob, string dir){
        object guard;
        if(ob->query("attribute/mark") == "fire" && dir == "north"){
                guard = present("yinghe guard", this_object());
                if(objectp(guard)){
                        message_vision(HIY"$N对$n大喝一声：没过我着一关，你休想在前进一步。\n"NOR, guard, ob);
                        return notify_fail("");
                }
                return 1;
        }
        return 1;
} 
