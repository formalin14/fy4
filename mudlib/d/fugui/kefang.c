#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "客栈睡房");
        set("long", @LONG
客栈的一间睡房，房间干干净净，一张大床，供客人们休息睡觉，房内有个男
人，油头粉面的，看上去很腻人。房间窗户开着，窗外就是吉祥镇的街道。
LONG
        );
        set("type","house");
        set("exits",([
                "down":__DIR__"kezhan",
        ]) );
        set("objects",([
                __DIR__"npc/xianggong" : 1,
        ]));
        set("coor/x",-590);
        set("coor/y",120);
        set("coor/z",10);
        setup();
} 
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && me->query("age")<16 )
        {
                room = find_object("/d/fugui/xiaojie1");
                if(!objectp(room)) 
                        room = load_object("/d/fugui/xiaojie1");
                message_vision(HIY"突然．．．$N莫名其妙的被人从窗口扔出去．．．\n"NOR,me);
                me->move(room);
           me->receive_damage("kee",50);
                message_vision(HIY"$N听到身后有人嘀咕：“谁家的小孩，这么小就去那种地方．．．”\n"NOR,me);
        }
}      
