#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"÷԰С��"NOR);
        set("long", @LONG
��˳��СϪһ����һ�߿���һ·�������Ż��ݵ���ζ����������Ϫˮ��������С
���������Ͱ��꣬���ܿ�������С���ڻ�����ľ��ȸԾ���У�ʱ��ʱ�Ļ��и���С��
����С·�����ش����������Ϳ��Կ���һ������¶����Ȫ�ء�
LONG
        );
    set("exits", ([ 
								"east" : __DIR__"xiaolang_huayuan",
                "west" : __DIR__"xiaolang4",
//                "south" :__DIR__"xiaolang_xiaodao6",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",14);
    set("coor/y",2033);
    set("coor/z",30);
        setup();
} 
