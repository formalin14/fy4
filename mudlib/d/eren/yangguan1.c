 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "大漠");
        set("long", @LONG
再往前走，沙漠无边无际，除了茫茫一片雪白什么也没有，连一个皱折也找不
到。远处是西北的群山，都积着雪，层层叠叠，直伸天际。在这样的天地中独个儿
行走，侏儒也变成了巨人，在这样的天地中独个儿行走，巨人也变成了侏儒。
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yangguan2",
        "southeast" : __DIR__"yangguan",
        ]));
        set("objects", ([
                __DIR__"obj/sand": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-970);
        set("coor/y",120);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(userp(obj) && (dir == "northwest" || dir == "southeast") && obj->query_temp("eren/haha_4")){
//              if (!find_living("sandworm")) return 1;
                if (!random(3)) {
                        message("vision",YEL"脚下的沙子忽然滑动起来，"+obj->query("name")+"一个站脚不住，直往下滑去。\n"NOR,this_object());
                        message_vision(YEL"$N向下越陷越深。。腿部。。腰部。。头部。。\n"NOR,obj);
                        obj->start_busy(2);
                        call_out("enter_sand",3,obj); 
                        return notify_fail(""); 
                }       
        } else if (userp(obj) && random(3)) {
                obj->move(this_object());
                return notify_fail("");
                }
   return 1;
}   
void enter_sand(object obj) {
        object room;
        room = find_object(__DIR__"sandtrap");
        if(!objectp(room)) 
                room = load_object(__DIR__"sandtrap");  
        obj->move(room);
        tell_object(obj,YEL"通地一声，你似乎碰到了实地。\n"NOR);        
} 
