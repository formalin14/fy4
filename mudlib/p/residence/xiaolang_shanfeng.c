 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"ɽ��"NOR);
        set("long", @LONG
�嶥����������ľ����ľ������һ������ݵأ�̤���ݵأ��͵������±ߣ�ÿ��
�賿���٣��ڴ˹ۿ��ճ������Ǳ��з�ζ����ĿԶ�����пɼ���ãã�����˸п���
ǧ��������ʮһ������Ӧ����Ů�����ιۿ��ճ���������������ԭ�򣬽�û�г��У�
����ׯ�������������ǹۿ��ճ������ǻӽ�ϰ�䡣
LONG
        );
    set("exits", ([ 
//                "down" : __DIR__"xiaolang4",
        ]));
        set("objects", ([
                "/d/huashan/npc/songshu" : 1,
                "/d/wolfmount/obj/noflower" : 1,
        ]));  
    set("outdoors", "residence"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
//    replace_program(ROOM);
}   
void init()
{
        add_action("do_jumping", "feizong");
} 

int do_jumping()
{
        object obj;
        object me;
        
        me = this_player();
        message_vision("$N����һ����������һԾ��˳��ɽ�¼��ݶ��¡�\n", me);
        me->move(__DIR__"xiaolang4");
        message_vision(HIW"$N��ɽ���ϼ�������������\n"NOR, me);
        return 1;

}
