#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(MAG"��ң����"NOR, ({ "magrobe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/spells", 50);
                set("long", @LONG
��ң��Ҵ�֮����������ң���үү������ɽ��ر���׽��һֻǧ����ϣ�����
���ñ��ϵ�˿������һ����ɫ�����ӡ�һ���ǧ�궯������Ķ��������������
�ã��������Ҳ�����⣬���۴������϶�ů��������ǹ���룬����������������     
LONG);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
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
