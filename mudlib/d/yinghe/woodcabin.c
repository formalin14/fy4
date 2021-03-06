 // Room: woodcabin.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "沉香木屋"); 
        set("long", @LONG
这是一间不起眼的小木屋。木料的颜色暗暗的，然而却有一种缥缈的香气从
四周传来。屋子里面有一扇小门，似乎有羽毛振动的声音从那边传来。
LONG);  
        //{{ --- by MapMaker
        set("exits",([
        "west":__DIR__"center",
        ]) );
        //}}
        set("item_desc", ([
                "door" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
                "小木门" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
                "门" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
        ]));    
        set("objects", ([
                "/obj/food_item/shuihu" : 2,
                "/obj/food_item/dumpling" : 2,
        ]));
        set("indoors", "yinghe");
        setup(); 
}
void init(){
        add_action("do_push", "push");
} 
void close_path(){
        object room;
        
        room = find_object(__DIR__"garden");
        if(!objectp(room)){
                room = load_object(__DIR__"garden");
        }
        if( room->query("exits/west")){
                message("vision","吱呀。。。一声木门又掩上了。\n",room );
        room->delete("exits/west");
    }
   if( query("exits/east") ) {
    message("vision","吱呀。。。一声木门又掩上了。\n",this_object() );
    delete("exits/east");
    }
} 
int do_push(string arg){
        object me, room;
    me = this_player();
    if(query("exits/east")){
        return notify_fail("门是开着的。\n");
    }
    if( arg=="door" || arg =="门" || arg == "小木门") {
        message_vision("$N往小木门上轻轻地一推，吱。。。的一声门开了。\n", me);
                room = find_object(__DIR__"garden");
                if(!objectp(room)){
                        room = load_object(__DIR__"garden");
                }
                set("exits/east", __DIR__"garden");
                message("vision", "小门被人打开。\n", room);
                room->set("exits/west", __DIR__"woodcabin");
                call_out("close_path", 5);
        } else {
                write("你要推什么呢？\n");
        }
        return 1;       
} 
int valid_leave(object obj, string dir){
        if(dir == "west") {
                if(obj->query("attribute_mark") != "wood") {
                        return notify_fail("阵阵羽毛振动的声音让你不由得止步不前。\n");
                }
                return 1;
        }
        return 1;
}       
