#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��������"NOR, ({ "yumeiren" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", WHT"һ�����ֵ�ɣ���Ө������İ������ˣ������·�������ӣ���ʳ\n�˼��̻𣬵�˧��������Ϊ�������������أ���������ͬ������\n�峺��һ����ˮ��̤�¾��ǣ������������ض���\n"NOR);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

                set("skill", ([
                        "name":         "charm",
                        "exp_required": 100000,
                        "sen_cost":     100,
                        "difficulty":   100,
                        "max_skill":    50
                        ]) );
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
