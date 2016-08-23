 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "洞底");
        set("long", @LONG
你隐约能听到有人愤怒的惊呼声。声音很短促，然后一切又归于平静。 
但平静并不代表安全，黑暗中仍然到处都潜伏着危险！ 你发觉右边是一扇
门（rightdoor）。有笑声从门后发出来的，笑声突然变成了令人心跳的呻
吟声。声音妖媚而诱惑，简直令人无法拒绝。你再向左移动，又找着另一扇
门（leftdoor）。这扇门后没有声音。
LONG
        );
        set("objects", ([
        __DIR__"npc/bianfu": 1,
                        ]) );
        set("item_desc", ([
                "rightdoor": "你虽然什么也看不见，但心跳已经加快了...\n",
                "leftdoor": "这门和右边那扇一模一样。\n",
        ]) );
        set("coor/x",3310);
        set("coor/y",0);
        set("coor/z",-30);
        setup();
} 
void init()
{
        add_action("do_open", "open");
} 
int do_open(string arg)
{
        int i;
        int damage;
        object me,room;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "leftdoor" ) {
           me = this_player();
                message_vision(HIR"$N刚一推开门，一阵冷箭以快得不能再快的速度射了出来。\n"NOR,me);
                me->receive_wound("kee",random(1000)+150);
                COMBAT_D->report_status(me,1);
                return 1;
        }
        if( arg == "rightdoor") {
                me = this_player();
                tell_object(me,HIR"你刚一推开门，就有一个人投入你的怀抱，将你拉了过去！ \n"NOR);
                message("vision",HIR""+me->name()+"刚一推开门，就有一个人投入"+me->name()+"的怀抱，将"+me->name()+"拉了过去！ \n"NOR,environment(me),me);
                room =load_object(__DIR__"room1");
                me->move(room);
                return 1;
          } 
}   
