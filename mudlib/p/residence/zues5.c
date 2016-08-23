#include <ansi.h>
#define X_COOR -20
#define Y_COOR 2040
#define Z_COOR 50
#define R_FLAG 18
#define OWNER "zues"
#define CLASS "������"
inherit ROOM;
string cliff();
void create()
{
set("short", WHT"����"NOR);
set("long", @LONG
���Ϸ���һƬ������ɳ̲����ˮ(water)�Ĵ��Ű�ɫ��ɳ̲(sand)�������յ�
�����ĺ�ˮ�����˽�⡣��Ÿ�����Ͼ���ط��裬����ڱ̲��л������Ծ����
��ĺ��紵����������أ�ֻ�뾡�����������⡢�̺��������ɳ̲����������
һ������(cliff)��ɽ����һ��ַ���ڽ�ɫ���������Ե��ر���á�ʱ��ʱ������
����֤���������������͵���˥��
LONG
);
        set("exits", ([
	"east" : __DIR__"zues3",
]));
	set("objects", ([
       	]) );
       
          set("item_desc", ([
                "cliff" : (: cliff :),
                "����"  : (: cliff :),
                "sand"  : "�װ׵�ɳ�������ƺ���Щ������������Ѱ(search)һ�¡�\n",
                "ɳ̲"  : "�װ׵�ɳ�������ƺ���Щ������������Ѱ(search)һ�¡�\n",
                "water" : "��ǰ�����ĺ�ˮ����ֹ��ס�볩��(swim)һ����\n",
                "��ˮ"  : "��ǰ�����ĺ�ˮ����ֹ��ס�볩��(swim)һ����\n",
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
    add_action("do_swim", "swim");
    add_action("do_search","search");
}

string cliff(){
        object me;
        me = this_player();
        tell_object(me, "��ע�⵽�±ߵĺ�ˮ�ƺ��Ƚ�ǳ���ƺ�������Ǳ(dive)��\n");
        add_action("do_dive", "dive");
        return "";
} 
int do_dive(string arg){
        object me, room;
   	me = this_player();
        if(!arg || (arg != "down" && arg != "����"&& arg !="cliff")){
                return notify_fail("��Ҫ��������Ǳ��\n");
        }
        message_vision("$N��׼�˶����º�ˮ����ǳ������ͨ��һ����������ˮ�С�\n", me);
        room = find_object("/p/residence/zues6");
        if(!objectp(room)){
            room = load_object("/p/residence/zues6");
                }
                me->move("/p/residence/zues6");
        return 1;       
} 
int do_swim()
{
        object me;
        int wait;
        me = this_player();
        wait = 15;
        message_vision("$N����ε���ĺ�ˮ������ס�ѹ��·�������ˮ�г���������\n",me);
        tell_object(me,"���̵ĺ�ˮ����ȫ���쳣��̹��\n");
        remove_call_out("curehimup");
   call_out("curehimup", wait, me);
return 1;
}  

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision("��ˮ��$N�ľ�����ָ��ˡ�\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
return;
}   

int do_search(string arg)
{
        object me, obj;
        me = this_player();
        if(!arg) {
            write("��Ҫ�������Ҷ�����\n");
            return 1;
        }
        if( me->is_busy() ) {
            return notify_fail("����һ��������û����ɣ�����������\n");
        }
        if( arg == "sand" || arg == "ɳ̲"  ){
            if ( query("littlething") > 0 && !random(3) ) {
                        message_vision("$N�������ӣ���ɳ̲����Ѱ�ţ�ͻȻ��ɳ���ڳ���С���⡣\n",me);
                        obj = new("/d/baiyun/obj/littlething");
                        obj->move(environment(me));
                        add("littlething", -1);
            } else {
            message_vision("$N���ͷ��ķ��˰��죬��ʲô��û���ҵ���\n",me);
            me->start_busy(2);
            }
        }
        return 1;
}

void reset()
{
        ::reset();
        set("littlething", 25);
} 