// sword.c
#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(HIY"��"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ĳ߾Ŵ��߷ֳ��Ľ�������ʮ����������Ǯ���԰׽�?���ɣ��ƽ�?��ϻ��\n������������񣬼�ֵ��ʮ���������ϣ������Իͣ������ױȣ���δ��ϻ�����Ѿ��㹻�������ǡ�\n");
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
        dam = (int) me->query("max_gin");
        victim->receive_damage("sen",dam/10,me);
        return HIY"���Ϻ�Ȼ��⼤�䣬���������ƿգ��̵�$n�������ۣ�\n" NOR;
}   