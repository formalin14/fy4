#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HIR"���ɢ����"NOR, ({ "huaqun" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
���������Ľ������ʦ������������ʮ������ɵ�ȹ�ӣ�ȹ���ɽ𡢺�����
˿��֯�ɣ��°��������÷�����꣬������Ůɢ��һ�㡣�����д�˵��ȹ��
������һ�ž����书���Ӵ˽�����Ϊ��չ����һ������֮ս��������һ��Ե
�ɺ��еõ�����ȹ�ӣ�����ȹ���͸������ɶ�����Ϊ����֮�á�
LONG);

                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/intelligence",3);
        }
        ::init_cloth();
}
/*
void init()
{
        set("dynamic_quest", (
                        "owner_name" : "/d/qianjin/npc/lin",
                        "fin_func" : "execute_accept_object",
                        "file_name" : "/questobj/huaqun",
                        ])
                ); 
}
*/   
/*void owner_is_killed(object killer)
{
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);
}*/
