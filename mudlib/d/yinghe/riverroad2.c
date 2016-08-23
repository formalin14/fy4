 // Room: riverroad2.c --- neon
inherit ROOM; 
void create()
{
        set("short", "河谷"); 
        set("long", @LONG
一条长河在谷地蜿蜒流动。河岸边时有上游漂来的浮冰。冰块在流水中碰撞，
发出喀喀的声响。远处一道瀑布从山上垂下，涧水飞流，云雾腾起。隆隆的轰响
声声入耳。
LONG); 
        set("outdoors","yinghe");
        set("exits",([
        "west":__DIR__"waterpath",
        "southeast":__DIR__"riverroad1",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
