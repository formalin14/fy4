#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB "������" NOR, ({ "shengsibu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", @LONG
����һ��������С���ӣ���������������ʹ�׭���������������ഫ����
��֮�˿ɽ��Լ������ֹ������ó������ϣ���һ��ʱ�����粻��֮�͵���
�ܵظ���������й٣������������׻�������սս�����ط������ӣ���ʧ
�����ط�������ȫ���������������ģ������Ҳ���������֣�
LONG);
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
