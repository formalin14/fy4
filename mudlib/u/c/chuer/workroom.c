inherit ROOM;
#include <ansi.h>
void create()
{
         set("short", HIG"������Сľ��"NOR);
        set("long", @LONG
�򵥡����ʡ�����Ȼ�Ĵ����������ɽ��ǧ���ľ���ɣ�������
������һ�壡�����������ӳ���������������֣�
LONG
        );
        set("exits", ([ 
         "up" : __DIR__"fotang",
]));
     set("valid_startroom",1);
    set("item_desc" , ([ /* sizeof() == 1 */
        "up": HIW"һ�����Ʈ�˹�������ס��������ߣ�\n"NOR,
]));
        setup();
}
int valid_leave(object me, string dir)
{
        object ob,arr;
        string idname;
       ob = this_player();
        arr = present("arrow", ob);
        idname = ob->query("id");
        if ( dir=="up" &&
             !(idname=="chuer") )
                return notify_fail(HIY"����������������㲻�ܶ�����\n"NOR);
        return ::valid_leave(me, dir);
}
