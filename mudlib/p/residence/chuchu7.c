 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2040
#define Z_COOR 252
#define R_FLAG 2048
#define OWNER "chuchu"
#define CLASS "���Ƴ�"
inherit ROOM;
void create()
{
set("short", HIW"����ͤ"NOR);
set("long", 
"һ���ó���ľ���ɵĽ��ڸ߸ߵļ�ɽ���ϵ�Сͤ��ͤ�Ӳ���ֻ�����ɼ�����
�����档ͤ����������Сʯ�ʣ�һ��Сʯ����һ���ٰ���
������ɽ��һ·ͨ�����ǵ�ɶ��������ģ����ʯ̨�ף�������Ӣ�ͷ׵�С����һ
·�����ܸо�ȫ��Ⱦ�����������·����˼䲽���ɾ������Ϸ���һ�̲��壬������
���������������¡�������һβ���ٺ�һ�����ף���Ͼʱ����ϲ�������︧�ټ�����
��߶����һ������������߶��Ф��ţ������˵�Լ��ǡ���ţ���١�������ͤ�����
����ֻСѼ�ӡ� "+HIY"^=^"+NOR"
������������߶ƽʱ�פ��ĵط�����Ϊ����������б�����ɣ������Ŀ���ɽ��
��һ���ˮ�����á�����ҹĻ�ʹ��������µ�㷱�Ƿ·��ֿɼ���

    ������ƣ�\n
    "+HIC"��              Ū
    ��              ��
    ��              Ӱ 

    ã              ��
    ã              ��
    ��              ��
    ��              ˭
    ��              ��\n\n"NOR
);
        set("exits", ([
		"down" : __DIR__"chuchu6",
	]));

        set("item_desc", ([
        	"qin": "һ�ѹ����ɫ�����٣�һ����֪������֮�\n",
        	"��": "һ�ѹ����ɫ�����٣�һ����֪������֮�\n",
        	"qupu": "������������ؼ����ų����������ļ�ֻ���ף�����������������qingxin������ʮ
�����������shimian���������񳯷�������bainiao�������̺�����������bihai����
������ˮ��������xiaoxiang����������ɢ����guanglingsan����\n",
        	"����": "������������ؼ����ų����������ļ�ֻ���ף�����������������qingxin������ʮ
�����������shimian���������񳯷�������bainiao�������̺�����������bihai����
������ˮ��������xiaoxiang����������ɢ����guanglingsan����\n",
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
        add_action("do_play","play");
}

int do_play(string arg)
{
	int lvl;
	object me;
	
	me=this_player();
	lvl=me->query_skill("music", 1);
	if(arg=="qingxin" || arg=="����������")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң���������������������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIW"�����������������ƣ���֮���ɼ������з���֮�飬��ɽ���ʹ���⡣ \n"NOR, me);
		me->clear_condition();
		me->set("bellicosity", 0);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺ��������������\n", me);
		}
	}
	if(arg=="shimian" || arg=="ʮ�������")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң���ʮ���������������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIM"����֮��ʱ������ʮ�����֮���������Ȿ�������������������ĵı���Ĳã��ĳ�
�������󣬲�����ʧ�����ۻ�׳��֮�ƣ������Ϊ�����֮�⣬���߶��ݣ��㲻�ܶ��� \n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺʮ�����������\n", me);
		}
	}
	if(arg=="bainiao" || arg=="���񳯷���")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң������񳯷�����������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIC"��������������๽�˿����������Ȼ������֮�⣬����������Ҳ����������ż�ã���������Ϊ��С���ˣ�
Σ�ڵ�Ϧ֮�ʣ��ٰ����Σ�����һ�����񳯷ȴ���������������������������������Ż���Ϊ�ġ�\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺ���񳯷�������\n", me);
		}
	}
	if(arg=="bihai" || arg=="�̺�������")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң����̺���������������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIB"������Ϊ�������࣬��������֮�ܣ�ȴҲ��һβ����������ʧɫ�����߷·�����
������֮�У�������ӿ�£�������ʧ��\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺ�̺�����������\n", me);
		}
	}
	if(arg=="xiaoxiang" || arg=="����ˮ����")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң�������ˮ������������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIG"����ˮ�Ƽ䣬������������������ĸ������ף��˺׶�ȥ������Ϊ���ˡ�\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺ����ˮ��������\n", me);
		}
	}
	if(arg=="guanglingsan" || arg=="����ɢ")
	{
		if(lvl>=200)
		{
		message_vision("$N���������Ღ���ң�������ɢ��������ˮ���ָ�们�䡣���������������ʣ�������ʱ��Ĵ��ڡ�\n", me);
		message_vision(HIR"κ��ʱ���������̶��У��ࡶ���꡷һ������̾������ɢ�ڽ���ӡ�Ȼ����֮�����������������״�֮��
��¼�������������һŭ�̺�������������������һ����ɱ֮�������ǹ���Ϊ֮���������Ϊ֮���ݡ�\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N���ٵ���Ϊ��������޷����ࡺ����ɢ����\n", me);
		}
	}
	message_vision("$N�����뵯��һ�������ٷ����ö��ġ��������ˡ�������������ϧ����������\n", this_player());
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
    
