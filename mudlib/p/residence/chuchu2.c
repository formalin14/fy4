 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2039
#define Z_COOR 50
#define R_FLAG 30
#define OWNER "chuchu"
#define CLASS "���Ƴ�"
inherit ROOM;
void create()
{
set("short", HIG"����"NOR);
set("long", @LONG
���Ӳ���������һ�ź�ľ��(Table)�������Ա߰����������ӣ���������ٷ�
ֻ�ǳ�������߶�����˳ԡ�����ֻ�������յ����������Ӻ�һ����֪װ��ʲô�Ĵ�
���衣

LONG
);
        set("exits", ([
		"north" : __DIR__"chuchu6",
		"south" : __DIR__"chuchu1",
		"west" : __DIR__"chuchu4",
		"east" : __DIR__"chuchu3",
	]));

        set("item_desc", ([
        	"table": "һ�ź�ľ�Ƴɵİ�������������һ����ˮ���㣨boiled fish����\n",
        	"����": "һ�ź�ľ�Ƴɵİ�������������һ����ˮ���㣨boiled fish����\n",
        ]) );

        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("indoors","residence");
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
	if(arg=="boiled fish" || arg=="ˮ����")
	{
		message_vision(HIC"$N�����á�������һ������������ͷ��ƹ����һ��ײ���˷�����Ȼ�����ص�ˤ��", this_player());
		message_vision("��������$N���������ۣ�\n��Ϊ������������", this_player());
		message_vision("$N�Ѿ���ˮ������Ļ����鷭��:P\n"NOR, this_player());
	return 1;
	}
	write("�����ʲô��\n");
	return 1;
}


int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("��������������ҵ���ķ���:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("��û�������κ��˵���ķ��䡣\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("��Ҫ����˭? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("�㽫"+arg+"��������������г�ȥ��\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("������"+arg+"����ķ��䡣\n");
                }else
                {
                        write("��... ���������?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
    
