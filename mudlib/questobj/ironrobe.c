#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIC"������"NOR, ({ "ironrobe" }) );
        set_weight(300000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

                set("armor_prop/armor", 20);
        }
        ::init_cloth();
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
