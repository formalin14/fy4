#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "洞口");
        set("long", @LONG
山石上已没落脚之处，再往上爬是不可能的。山壁上
有一个洞口，洞里黑暗潮湿。你心里有一种不祥的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hole3",
]));
        set("item_desc", ([
                "up": "山石上已没有落脚之处。\n",
                "mountain": "山石上已没有落脚之处。\n",
                "山": "山石上已没有落脚之处。\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",80);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_climbb", "wantfly");
}
int do_climbb(string arg)
{       
        object me;
        me = this_player();
        if( arg == "sfy")
        {
        me->add("score", 1);
        me->add("potential", 100);
        me->add("combat_exp",200);
          return 1;
        }
        return 1;
}
 
int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        me = this_player();
        if( arg == "up" || arg == "山" || arg == "mountain")
        {
           message_vision("$N慢慢地往山上爬去。\n", me);
                message_vision(RED "不好！$N一个不小心掉了下去！\n"NOR , 

me);
                me->move(__DIR__"road5.c");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
                me->receive_wound("gin", 50);
                return 1;
        }
        else if( arg == "down") {
                message_vision("$N慢慢地往山下爬去。\n", me);
                me->move(__DIR__"ping_tai.c");
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}   

