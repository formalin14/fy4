#include <ansi.h>
#include <weapon.h> 
inherit HAMMER; 
void create()
{
        set_name( HIB"���˴�"NOR, ({ "wave-hammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ʽ��׾�Ĵ���������Լһ�ٰ�ʮ� \n");
                set("material", "gold");

        set("no_drop", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
                set("rigidity", 200000); 
                set("wield_msg", "$N�������ף�ŭ���л�Ȼ���һ��$n�����˵�������������С�\n");
                set("unwield_msg", "$N�����������е�$n��\n");
        }
        ::init_hammer(150);
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
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return HIB"���˴������Ʒ磬���纣���������ŵ�$nһ�һ㶣�\n" NOR;
}   