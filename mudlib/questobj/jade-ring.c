#include <armor.h>
#include <ansi.h>
inherit FINGER; 
void create()
{
        set_name(HIC "�����ָ" NOR, ({ "jade-ring"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ε����ָ��\n");
                set("unit", "��");
                set("value", 100000);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");  
        }
        ::init_finger();
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
