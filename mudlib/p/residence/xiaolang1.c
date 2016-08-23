 // a skeleton for user rooms
#include <ansi.h>
#include <room.h>
#define X_COOR 15
#define Y_COOR 2030
#define Z_COOR 30
#define R_FLAG 2561
#define OWNER "xiaolang"
#define CLASS "��÷ɽׯ"
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"����ɽׯ"NOR);
set("long", 
"���ƹ�С������ǰһƬ���ʣ�̧ͷ��ȥ��������ų�����������顰���ǡ����֣�
�ſ���������Сʫ��\n"
+HIG"                    ��          ��
                    ��          ��
                    ��          ��
                    ��          ��
                    ��          ��
                    ��          ��
                    ��          ��\n"NOR
+"  ʫ��д�ţ���ʮһ�����⣬�����������һֻ��ʯ�������������������÷��
�������������ľ��ï���쳣�������ʱ��΢�紵��÷����������ζ�����Ŀ�
����������ҹվ�������е�Ī���Ľ��ţ�����ú���������һ˫�۾������Լ���\n\n"
);
        set("exits", ([
		"west" : __DIR__"room4",
		"north" : __DIR__"xiaolang_xiaodao",
		]));
		 set("objects", ([
                __DIR__"npc/xiaolang_guard" : 1,
       ]) );
        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
//        set("owner", OWNER);
        set("class", CLASS);
        set("no_steal",1);
//        set("no_fight",1);
        set("no_death_penalty",1);
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("outdoors","residence");
}
int valid_leave(object me, string dir)
{
        object ob, shiwei;    
            
        if (!shiwei=present("xiao qiushui",this_object()))
                return 1;
        
        if ( userp(me) && dir=="north" ) {
                if((string)me->query("id") != "xiaolang" && (string)me->query("id") != "lsky"){
                			if (!ob=present("qingtie",me))
                        		return notify_fail(shiwei->name()+"��Цһ������û��ׯ������������ƾʲô��ȥ��\n");
                			if (!me->query_temp("����ɽׯ/����"))
                        		return notify_fail(shiwei->name()+"˵�����ѵ��㻹û�������(read)��ׯ������������\n");
               																					 }
                return 1;
        }
        
        return 1;
}    
