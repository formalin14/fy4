#include <ansi.h>
inherit ROOM;
string *names=({
        __DIR__"cemetery1",
        __DIR__"cemetery6",
        __DIR__"cemetery5",
        __DIR__"cemetery3",
} );  
void create()
{
        set("short", "�س�");
        set("long", @LONG
��ɫ��ɭ����Ҳ���䣬Զ���ߵ�������ص����ĺ��澹��һƬ�ޱ��޼ʵĻķء�
��Ȼ�ǰ��죬�ķؼ���Ȼ����������Ҳ��Ȼ���Թ����ˡ����������������Ե�������
�谵������У�һֻ��Ӱ�����������������������������������м������硣����
Ҳ����ɽ����ˮ����Ұ���ķء�
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-1175);
        set("coor/y",190);
        set("coor/z",0);
        setup();
} 
void reset()
{
        int i,j;
        string temp;
        ::reset();
        for (i=0;i<=3;i++)
        {
                j=random(4);
                temp=names[j];
                names[j]=names[i];
                names[i]=names[j];
                names[i]=temp;
        }
        set("exits", ([
                "north" : names[0],
                "south" : names[1],
           "east" : names[2],
                "west" : names[3],
        ]));
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if (!present("zombie", this_object()) && random(10)>7) {
                another = new(__DIR__"npc/zombie1");
                another->move(environment(obj));
                message_vision(YEL"�ض�������վ��һ��������������!\n"NOR, obj); 
                return notify_fail(another->name()+"������צ�ص����������ǰ��\n");
        }       
        return 1;
}     