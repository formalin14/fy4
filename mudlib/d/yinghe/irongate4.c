 // Room: irongate4.c --- by neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "荒草坡"); 
        set("long", @LONG
这是一块荒草及腰的山坡，草丛中不时簌簌作响。草坡东面一座山庄隐约可见，
东北方有个黑黑的山洞，阵阵腥风从里面飘出，似乎有无数蛇虫在里面蠕动。
LONG); 
        set("outdoor","yinghe");
        set("exits",([
                "east":__DIR__"thundercity",
                "northeast":__DIR__"snakehall",
        ]) );
        //}} 
        setup();
} 
// 虹说道： if player ne, or northeast, will a message
//虹说道： tells them, too many snakes down there, better not go 
int valid_leave(object obj, string dir){
        if(dir == "northeast"){
                if(obj->query_skill("animal-training")>200){
                        return 1;
                }               
                return notify_fail(HIY"“嘶嘶~~”的声音加上群蛇蠕动的景象让你心生退意。\n"NOR);
        }
        return 1;
}       
