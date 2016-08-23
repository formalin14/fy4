 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2040
#define Z_COOR 50
#define R_FLAG 2048
#define OWNER "chuchu"
#define CLASS "���Ƴ�"
inherit ROOM;
void create()
{
set("short", HIC"С��׿Ӻ��"NOR);
set("long", @LONG
�����ھ�������������׿Ӻ������һֱ�����ͻ��������������˿���˺���
    �����������ͯ�����磬���ο�ʼ�ĵط���һ�������ĺ�ˮ���Ǻ�ˮ��������
��ʹ�����Ȼ��һ�ֲ���һ������ȥ�ĳ嶯��ɲ�Ǽ���������ʲô�зɶ��˻�Ҳ
�������˼�������һ�ֻ��𡣺��������ż�ֻ�Ƴγε�СѼ�ӣ����ȵس���ֻ����
���������ĸ衣���߳����������де���ݣ��ݴ���ʢ���źúö�಻֪����Ұ����
���кܶ�ԲԲ�������ѹ�Ӣ��΢�����ʱһ�Ѱ�Сɡ���Ÿ��Ե��������Զ����
�ݵ���ſ�ŵ�һֻС������������ǰ�������С�
����԰�ӵ�һ����һ���ܸߵļ�ɽ��ɽ������һ�����µ�Сͤ��԰�ӵľ�ͷ��һƬ
�Դ����ε����֣��ƺ���һ���������۵�С·��ʧ�����У���֪ͨ��η���

LONG
);
        set("exits", ([
	//	"north" : __DIR__"chuchu8",
		"up" : __DIR__"chuchu7",
		"south" : __DIR__"chuchu2",
	]));

        set("item_desc", ([
        	"duck": "ССѼ�������ȵؽУ�����·��ҡ��ҡ��ҡ��\n���ǳ��ŻƳγε���ë���ۻƵı�����ͺͽ��ƣ�ԶԶ��ȥ��һ������ɫ��С����\n"NOR,
        	"СѼ��": "ССѼ�������ȵؽУ�����·��ҡ��ҡ��ҡ��\n���ǳ��ŻƳγε���ë���ۻƵı�����ͺͽ��ƣ�ԶԶ��ȥ��һ������ɫ��С����\n"NOR,
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
        add_action("do_jump","jump");
        add_action("do_listen","listen");
}

int do_listen(string arg) 
{ 
   	object me, room; 
   	me = this_player(); 
	
	if(random(5)) 
	{
   		tell_object(me,HIM"�����������������פ���������з��������ֶ������·�������һ����ң���ɼ��Ļ�����\n"NOR); 
   		message("vision",HIM""+me->name(me)+"ͻȻפ�㣬�ƺ�������������ʲô��\n"NOR, environment(me),me); 
   	} else {
   		tell_object(me,HIG"ڤڤ��һ�������������ֻ������������ͻ��㣬�����������ɻ���һ֧ʹ���Դ��ĸ裬
���㲻�ϵ����������������������˺���֮��������һ��ǧ���ѽ���ԡ�����������\n"NOR); 
   		message("vision",HIG"һ�������������컶�������ˮ��һϴ������ɱ��֮����"+me->name(me)+"����һ��Ʈ��������ڤڤ������������\n"NOR, environment(me),me); 
      		room = find_object(__DIR__"chuchu8"); 
      		if(!objectp(room)) room=load_object(__DIR__"chuchu8"); 
      		me->move(room); 
   	}     
 
   	return 1; 
} 


int do_jump()
{
        object me;
        me = this_player();
        message_vision(HIC"$N����ǰ�ľ������󣬲���һ��������ȥ��ֻ������ͨ��һ���������ĺ��潦��ʮ��\n", me);
	message_vision("�߸ߵ�ˮ����СѼ�ӱ��ŵ���ɢ�ο���$N�ΰ�����ͼ׷��СѼ�ӡ�\n"NOR, me);
        remove_call_out("curehimup");
        call_out("curehimup", 5+random(10), me);
	return 1;
}

void curehimup(object me)
{
        int gin,kee,sen,mana,force,atman;
        object ob;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
        mana=(int)me->query("max_mana");
        force=(int)me->query("max_force");
        atman=(int)me->query("max_atman");
	if( me && environment(me) == this_object())
        {
        	message_vision(HIC"$N���˰���һֻСѼ��Ҳû׷�ϣ����յ����ϰ�һͷ���ڲݵ��ϡ�\n"NOR, me);
	       	if(ob=present("dongdong", this_object()))
	       	{
        		message_vision(HIC"$N"+HIW"�����Դ�����$n���ƺ��ܲ�����", ob, me);
        		message_vision("$NΪʲôҪ���Լ�Ū�û���ʪ���ܵġ�\n"NOR, me);
        	}
        	message_vision("$N�ľ�����ȫ�ָ��ˣ���\n", me);
        	me->set("eff_gin",gin);
        	me->set("eff_kee",kee);
        	me->set("eff_sen",sen);
        	me->set("gin", gin);
        	me->set("kee", kee);
        	me->set("sen", sen);
        	me->set("mana", mana);
        	me->set("force", force);
        	me->set("atman", atman);
        	me->clear_condition();
        }
return;
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
    
