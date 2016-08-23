 inherit ROOM;
void create()
{
        set("short", "慕容庄园");
        set("long", @LONG
桃源的一角不知何时建了一个小小的庄园，灰色的院墙，灰色的瓦顶，四周静
悄悄的。朱漆的大门微掩着，门口悬挂着一个灯笼，上书“慕容”二字。庄园的门前
是一片绿色的草坪，后面则是一片密林。
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "south" : AREA_TAOYUAN"road3",
        ]) ); 
        set("item_desc", ([
                "door" : "朱漆大门只是轻掩着，似乎轻轻一推就开了。\n",
                "门" : "朱漆大门只是轻掩着，似乎轻轻一推就开了。\n",
        ]) ); 
        set("outdoors","murong");
    set("coor/x",210);
        set("coor/y",-30);
        set("coor/z",0);
        setup(); 
} 
void init() { 
        add_action("do_push", "push");
}  
void close_path()
{
        if( query("exits/north") ) {
    message("vision","朱漆大门轻轻掩上。\n",this_object() );
    delete("exits/north");
    }
} 
int do_push(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="门") {
        message_vision("$N往朱漆大门上轻轻地一推，吱。。。的一声门开了。\n", me);
                set("exits/north", __DIR__"menkou");
           call_out("close_path", 5);
        } else {
                write("你要推什么呢？\n");
        }
        return 1;       
 }  
