 inherit ROOM;
#include <ansi.h>
#include <room.h> 
void create()
{
        set("short", HIC"¶��ԡ��"NOR);
        set("long", @LONG
��Ѱ����������ǰ�������㾪�Ȳ��ѣ���֪���������Ȫ��Сɽ���ϵ�Ȫ����
��ӿ�������γ����е�С�ٲ����������ԡ�أ���˵�������Ȫ�����˵���Ч��
���������������𣩽�ȥ�������ܡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiaolang_xiaodao4",
        ]));
        set("item_desc", ([
                "�ٲ�": "��Ȫ������ӿ��������Ȫ�γɵ�С���ٲ�������ȥ�ǳ�׳�ۣ�\n",
                "ԡ��": "�����ٲ����ڳ���γɵ���Ȼԡ�أ����̲�ס������jump)��ȥ��\n",
        ]) );
          set("objects", ([
//              __DIR__"npc/xiaolangwa" : 1,
                     ]) );
        set("outdoors","residence");
        set("no_steal",1);
        //set("no_fight",1);
        set("coor/x",13);
        set("coor/y",2033);
        set("coor/z",30);
        set("resource/water", 1);
        set("liquid/container", "Ȫ��"); 
        setup();
} 
void init()
{
        add_action("do_jump", "jump");
        add_action("do_fly", "feizong"); 
} 
int do_jump()
{
        object me;
        int wait;
        me = this_player();
        wait=5;
        message_vision(HIG"$N�ѵ��������·�������ͨ��һ��������¶��ԡ��!\n"NOR,me);
        tell_object(me,HIG"��Ȫ����е�ȫ��ǳ����......\n"NOR);
        remove_call_out("curehimup");
        call_out("curehimup",wait, me);
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
        message_vision(HIG"��Ȫ��Ȼʹ$N���˿��������ϣ���\n"NOR, me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
return;
}  

int do_fly()
{
        object obj;
        object me;

        me = this_player();
        message_vision("$N�����˸߸ߵ�ɽ�£�����һ�������������Ծ��ȥ��\n", me);
        me->move(__DIR__"xiaolang_shanfeng");
        message_vision(HIW"$N��ɽ�·�Ծ��������\n"NOR, me);
        return 1;

}
