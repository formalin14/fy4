 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 16
#define Y_COOR 2039
#define Z_COOR 50
#define R_FLAG 2063
#define OWNER "chuchu"
#define CLASS "���Ƴ�"
inherit ROOM;
void create()
{
set("short", HIM"������"NOR);
set("long", @LONG
�������ţ�һ������Ϯ�˶�����ԭ���Ѿ�������߶�ͳ��������ҡ�
�������ݶ����봹�µ�������ɴ��һ��ԲԲ�Ĵ��������棬ɴ���Ｘֻө�����
ӯ���裬��������������á��������ź�����������ޣ��������һ��ѩ����
����Shoupa����������һ���˳���Ⱦ������������ʢ�š�
�������ӵĽ�����̴��¯��ů��ȼ���ţ���������һ�����̣������ܻ᲻�Ծ���
�����񣬳ճտ����������������̣��·����˳���ƽ�͵��������硣
�������ְܰ�վ��ǽ�ߣ����΢Ц�����������һ�У��ƺ�����������ӡ�

LONG
);
        set("exits", ([
		"west" : __DIR__"chuchu2",
	]));

        set("item_desc", ([
        	"shoupa": "���ǵ�������͸���߶������������ż��о����С�֣�
"+HIC"�����������������ã�ִ��֮�֣��������ϡ�\n"NOR,
        	"����": "���ǵ�������͸���߶������������ż��о����С�֣�
"+HIC"�����������������ã�ִ��֮�֣��������ϡ�\n"NOR,
        	"bearpapa": "һ���ܴ�ܴ��ë����ߣ���һֻ���ܵ����ͣ����Խ������ְܰ֡����ߴ���࣬
��Լ�˳ߣ���Ҳ���߳ߣ�վ��ǽ�߼�����ס�˰���ǽ��ԲԲ�Ĵ�ͷ����ֻ��Բ��
���䣬����Ц����ĺ��۾��������ϴ��ż�����ɫ��T-Shirt��������ϵ��һ��
"+HIR"Ѫ��˿��"+NOR"������������۾������ڿ����㣬�·���Ц���ַ·����Ͼ�Ҫ�ſں���
˵��һ����\n",
        	"���ְܰ�": "һ���ܴ�ܴ��ë����ߣ���һֻ���ܵ����ͣ����Խ������ְܰ֡����ߴ���࣬
��Լ�˳ߣ���Ҳ���߳ߣ�վ��ǽ�߼�����ס�˰���ǽ��ԲԲ�Ĵ�ͷ����ֻ��Բ��
���䣬����Ц����ĺ��۾��������ϴ��ż�����ɫ��T-Shirt��������ϵ��һ��
"+HIR"Ѫ��˿��"+NOR"������������۾������ڿ����㣬�·���Ц���ַ·����Ͼ�Ҫ�ſں���
˵��һ����\n",
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
        add_action("do_rabbit","rabbit");
        add_action("do_ask","ask");
}

int do_ask(string arg)
{
	string obname, things, about;
	if(!arg || sscanf(arg, "%s %s %s", obname, about, things)!=3 )
	{
		write("��Ҫ��˭ʲô�°���\n");
		return 1;
	}
	if(obname=="bearpapa" || obname=="���ְܰ�")
	{
		if(things=="������û�л���������")
		{
			message_vision(HIC"���ְܰ������վ�����������˵����������������л��˸������ﰡ����\n"NOR, this_player());
		}
		else
		{
			if(random(2))
				message_vision(HIC"���������ְֲܰ�����$N��\n"NOR, this_player());
			else
			{	message_vision(HIC"���ְֶܰ�$N�µ�������Ϊ��������ϼ������"NOR, this_player());
				message_vision(HIC"���ְֿܰ�������$Nһ�ۣ�����һ�����߸�\n"NOR, this_player());
				message_vision(HIC"�İ�ͷ��������.......����$N....\n"NOR, this_player());
			}
		}
	return 1;
	}
	else
	{
		write("��Ҫ��˭����\n");
	}
	return 1;
}

int do_rabbit(string arg)
{
	if(arg=="bearpapa" || arg=="���ְܰ�")
	{
		message_vision(HIC"$N�Դ��ְֳܰ����������ְ֣ܰ����Ŷ�������С����Ҫ��������\n"NOR, this_player());
	        if( !query("exits/east") ) 
	        {
	        	message_vision(HIC"���ְֶܰ�$NЦ��Ц��һ����¶��ǽ�ϵ�һ�Ȱ���С�š�\n"NOR, this_player());
        		set("exits/east", __DIR__"chuchu5");
        		call_out("close_path", 5);
        	}
		return 1;
	}
	message_vision(HIC"$N��������С�ùԹԣ����Ŷ���������\n"NOR,this_player());
	return 1;
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","���ְܰ�����ס��ǽ�ϵ�С��\n", this_object() );
        delete("exits/east");
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
    
