#include <weapon.h>
#include <ansi.h>
inherit BLADE; 
void create()
{
        set_name( GRN"̤��Ʈ����"NOR , ({ "pxshan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
               set("long", "���Ǳ��൱���µ����ȣ��ȹ����������������д�š�̤�¶�����\n���ֿ�ݣ���Լɢ������翵������㡣\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ����$nչ���������У������������¡�\n");
                set("unwield_msg", "$N�����е�$n�����������С�\n");
        }
        ::init_blade(50);
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_kee");
        victim->receive_damage("sen",dam/10,me);
        return HIG "̤��Ʈ��������ɢ����һ˿�������޵������㣬�����ͣ���Զ������\n" NOR;
}  
