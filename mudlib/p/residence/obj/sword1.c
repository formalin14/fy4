// sword.c
#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(RED"��ӧ��"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�������ȫ�����ոɽ�Īа����������������ı�׼�������ġ�\n�ߴ�ĳ��̡������Ŀ�ȡ����ɵ���ʽ���������������õ�Ƥ���ͭ�Σ�������Ũ��Ĺŷ磬������ʵ����ز�¶��������������һ����\n");
                set("value", 400000);
                set("material", "steel");
                set("rigidity", 80);
                set("wield_msg", "$N�����г��һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_sword(100);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return RED"��ӧ��������ƣ����Ϻ�ӧ��������˵�ɱ����\n" NOR;
}   