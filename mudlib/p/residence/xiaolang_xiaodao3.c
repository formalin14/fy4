#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"÷԰С��"NOR);
        set("long", @LONG
��������������ʯС·�ϣ����Ż��ݵ���ζ���������������������ʱ��ȴ��
�����е�Ѫ���ȷ磬�㿴������С���ڻ�����ľ��ȸԾ���У�ʱ��ʱ�Ļ��и���С
������С·�����ش�������ǰ���ߣ�����Կ�����һ����(door)�����������˵�
���䡣
LONG
        );
    set("exits", ([ 
								"south" : __DIR__"xiaolang_huayuan",
//                "enter" : __DIR__"xiaolang2",
        ]));
    set("objects", ([

    ]));
    set("item_desc", ([
        "door" : "С��ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
        "��" : "С��ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
        ]) );
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2034);
    set("coor/z",30);
        setup();
} 
void init() {
        add_action("do_push", "push");
}  

void close_path()
{
    if( query("exits/enter") ) {
       message("vision","С�ű���һ���������ˡ�\n",this_object() );
       delete("exits/enter");
    }
} 
int do_push(string arg)
{
        object me;
        me = this_player();
        if( arg=="door" || arg =="��") {
        message_vision("$N��С���������һ�ƣ�֨......��һ��С�ſ��ˡ�\n", me);
                set("exits/enter", __DIR__"xiaolang2");
                call_out("close_path", 2);
        }
        else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
 }      