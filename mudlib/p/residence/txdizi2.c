 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2050
#define Z_COOR 50
#define R_FLAG 17
#define OWNER "txdizi"
#define CLASS "��ѩɽׯ"
inherit ROOM;
void create()
{
set("short", "��֪����");
set("long", @long
������䡢���μ��ӵ���֪���ݣ���С�ɵ�������С®��ͨ��
��ν����֪��Դ�ڡ����ס�ϵ�ʡ�����Ⱥ��֪΢��֪�á�֪�ᡢ֪�ա���
���и��˼���ľ�ʣ�һ��ľ����������ЩС��Сյ��������Щ����ˮ��
�������ݷõĿ��˿��˶��ˣ���������ʳ�á�

long
);
        set("exits", ([
        

"east" : __DIR__"txdizi1",

]));
set("objects", ([
//"/p/residence/npc/featherwa" : 1,
       ]) );
        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("gao_amount", 100);
        set("tea_amount", 100);
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
                add_action("do_look", "look");
        add_action("do_eat", "eat");
        add_action("do_drink", "drink");
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
  

int do_look(string arg) {
        object me;
        int i, j;
        
        me = this_player();

    i = query("gao_amount");
    j = query("tea_amount");
    if( !arg || arg != "table" && arg != "ľ��" && arg !="Сյ" && arg!= "teacup" 
) return 0;
    if(arg == "table" || arg == "ʯ��") {
                if (i > 0) {
            write("ľ�����м��̾��µ�С����������Щ÷���⣬���Գԣ��������ġ�\n");
                } else {
            write("ľ�������м���С��������ֻʣ����һЩ��������\n");
                }       
        me->set_temp("know_gao", 1);
    } else if (arg == "Сյ" || arg == "teacup" ) {
                if (j > 0) {
            write("��յ��ʢ��������������ð�����������������Ժȣ������룩��\n");
                } else {
            write("��յ�ѿ��ˣ������������ڿ����е�����\n");
                }
        me->set_temp("know_tea", 1);
        }
        return 1;
}        
int do_eat(string arg) {
        object me;
        int i;
        
        me = this_player();
    i = query("gao_amount");
        
    if( !arg || arg != "taosu gao" && arg != "÷����" && arg != "gao" ) return 0;
        if( me->is_fighting()) return notify_fail("�����ڲ��ܳԡ�\n");
    if( i > 0 && me->query_temp("know_gao")) {
                if (me->query("food") >= me->max_food_capacity() ) {
                        write("���Ѿ��Ա��ˣ�ʵ�ڳԲ����ˡ�\n");
            message("vision", me->name() + "������ɫ�Ŀ�����ǰʣ�µĸ�㡣\n",
                                        environment(me), me);
                        return 1;
                } else {
                        if(me->is_busy()) return notify_fail("������æ�����ܳԡ�\n");
            message_vision("$N����һ��÷���⣬������Ʒ���š�\n", me);
                        me->start_busy(2);
           }
        //add("gao_amount", -1);
        me->add("food", 100);
    } else if( i =0 && me->query_temp("know_gao")) {
        write("�Ѿ�û�и���ˣ�\n");
        } else { 
                return 0;
        }
        return 1;
} 
int do_drink(string arg)
{
        object me;
        int i;
        
        me=this_player();
    i = query("tea_amount");
        
    if(!arg || arg != "tea" && arg != "������") return 0;
        if(me->query("water") >= me->max_water_capacity())
                        return notify_fail("���ƺ������ʡ�\n");
        if(me->is_fighting()) return notify_fail("�����ڲ��ܺȡ�\n");
        if(me->is_busy()) return notify_fail("������æ�����ܺȡ�\n");
    if (i > 0 && me->query_temp("know_tea")) {
        message_vision("$N���������յ�����ĵ�Ʒ��������\n",me);
                me->start_busy(2);
       // add("tea_amount", -1);
        me->add("water",100);
    } else if( i = 0 && me->query_temp("know_tea")) {
        write("��յ�Ѿ����ˡ�\n");
        message("vision", me->name() + "�����յ���˿���\n", environment(me), me);
        } else {
                return 0;
        }
        return 1;
}
