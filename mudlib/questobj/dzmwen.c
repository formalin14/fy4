#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG "��������" NOR, ({ "dzmwen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�������µ����ģ�
���������Ӳ�����ʧ����Ϊ����������ƶɮ��Ϊ���֣��޿�����
�������������� 
                                ����\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

          } 
    ::init_item();
             
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
