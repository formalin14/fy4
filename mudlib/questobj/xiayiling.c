#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"������˫��"NOR, ({ "xiayiling" }) );
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "���ǡ��޹�ɽׯ��������������ȥ�ǽ�����ʵؼ�Ӳ�ޱȣ�������Ȼ�к�⸡�֣�\n����ִ�����ߣ������޹�ɽׯׯ���������������֣�Ī�Ҳ��ӡ�\n");

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
