 inherit ROOM;
void create()
{
        set("short", "海底废墟");
        set("long", @LONG
这是一个荒废了不知道多少年的遗址，大半淹没在海草和泥土中，其中保存得最好
的是一个祭坛(Altar)。各种鱼类已经把这里作为它们的家，自由进出着。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zues5",
]));
	set("objects", ([
		"/d/palace/npc/fish" : 1,
        	"/d/palace/npc/shrimp" : 1,
       		__DIR__"obj/altar" : 1,
       	]) );
       	set("item_desc", ([
//                "altar": "这是一处祭祀古代神灵的祭坛，你似乎可以在这里许愿（wish)。\n",
//                "祭坛": "这是一处祭祀古代神灵的祭坛，你似乎可以在这里许愿（wish)。\n",
        ]) );
        
        set("indoors", "residence"); 
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",0);
        setup();
}
void init()
{
    add_action("do_wish", "wish");
}

int do_wish(){
        object me, room;
   	me = this_player();
        message_vision("$N在心里默默许了一个愿。\n", me);
        room = find_object("/p/residence/zues3");
        if(!objectp(room)){
            room = load_object("/p/residence/zues3");
                }
                me->move("/p/residence/zues3");
        return 1;       
} 