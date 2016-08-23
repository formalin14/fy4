 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "书斋");
        set("long", @LONG
马空群并不爱读书，书斋只是他思考问题的地方。与楼下不同，这儿布置得非
常俭朴，四壁抹着半蓝半灰的无以名之的颜色，家具是一把靠椅和一张桌子，桌上
有写过字的几张纸，但最引目的是许多烟。烟也各式各样的放着：有用纸包起来的，
有装在烟盒里面的，也有简直就堆在桌上的。
LONG
        );
        set("exits", ([ 
                "west": __DIR__"corridor3",
                "east" : __DIR__"uproom3",
        ]));
        set("objects", ([
        ]) );
        set("wanma_discussion",1);
        set("coor/x",-1110);
        set("coor/y",320);
        set("coor/z",10);
        setup();
        //replace_program(ROOM);
}      
int valid_enter(object me)
{
        object ying,yang,di;
        object room;
        
        room=this_object(); 
        
        if(me->query("wanma/上楼")) {   
        if(!objectp(di=present("ma kongqun",room)))
                {
                        di=new(__DIR__"npc/makongqun");
                        di->move(room);
                }
                return ;
             }
        return 1;
}