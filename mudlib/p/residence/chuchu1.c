 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2038
#define Z_COOR 50
#define R_FLAG 30
#define OWNER "chuchu"
#define CLASS "���Ƴ�"
inherit ROOM;
void create()
{
set("short", HIR"����"NOR);
set("long", 
"һ�ȿ������������˼�û��ʲô��ͬ��Ժ��(Door)�������Ϸ�����һ��СС��
�ң�����д�š�"+HIC"��߶�ͳ����ļ�"+NOR"����������ڣ������治ʱ������Ц����������
���̲�סҲ����������\n
    ��������һ��������\n
    "+HIM"��           ��
    ��           ��
    ��           ��
    ��           ��
    ��           ��\n"+NOR"
"

);
        set("exits", ([
		"west" : __DIR__"room7",

	]));

        set("item_desc", ([
        	"door": "����ͨ��ľ�ţ��������Ż���ring�����ƺ������ã�knock���������������˵�ע�⡣\n",
        	"��": "����ͨ��ľ�ţ��������Ż���ring�����ƺ������ã�knock���������������˵�ע�⡣\n",
        	"ring": "��ͭ�����Ż���\n",
        ]) );

        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("outdoors","residence");
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
        add_action("do_knock","knock");
        add_action("do_push","push");
        add_action("do_pull","pull");
}

int do_knock(string arg)
{
	if(arg=="ring")
	{
		message_vision(HIC"$N���Ż��������������£����ﴫ������������~~~�˲��ڼң���~~~�Ķ�ȥ�ˣ���~~~~�������㣡��\n"NOR, this_player());
		message_vision(HIC"$N���ɵ������������ľ���� \n"NOR, this_player());
	return 1;
	}
	write("��Ҫ��ʲô��\n");
	return 1;
}

int do_push(string arg)
{	
	if(arg=="door" || arg=="��")
	{
		message_vision(HIC"$N�����������ţ���ͻȻһ���ӾͿ��ˣ�Ȼ���͵ص�������", this_player());
		message_vision("$N⧲�������", this_player());
		message_vision("���Ŵ��˸�ͷ���ۻ���\n"NOR, this_player());
	return 1;
	}
	write("��Ҫ�ƿ�ʲô��\n");
	return 1;	
}

int do_pull(string arg)
{
	if(arg=="door" || arg=="��")
	{
		message_vision(HIC"$N�����������ţ��š�֨ѽ��һ�����ˡ�\n"NOR, this_player());
	        if( !query("exits/north") ) 
	        {
        		set("exits/north", __DIR__"chuchu2");
        		call_out("close_path", 5);
        	}
		return 1;
	}
	write("��Ҫ����ʲô��\n");
	return 1;
}

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","���ֹ����ˡ�\n", this_object() );
        delete("exits/north");
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
    
