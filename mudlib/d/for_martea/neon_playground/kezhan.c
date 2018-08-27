 inherit ROOM;
void create()
{
        set("short", "新月客栈");
        set("long", @LONG
山脚下一间小小的客栈。黄梨木的篱笆，黄梨木的门。门口新月形
的标记仿佛是微笑的眼睛。来来往往的人们都是从这里匆匆走过，就象
从家门口走过那样平常。
    也许，对浪迹江湖的人来说，客栈也就如家一样吧。
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ 
        "north" : __DIR__"grassland",
        "west" : __DIR__"hall",
        ]));
        set("indoors", __DIR__"neon_playground");
        set("coor/x", 0);
        set("coor/y",30000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
