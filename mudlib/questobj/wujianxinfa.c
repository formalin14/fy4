#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�޽��ķ�"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ���ƾɣ��ּ�ģ�����顣\n");

            set("skill", ([
                        "name":         "doomsword",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
          } 
    ::init_item();
} 
/*void owner_is_killed(object killer)
{
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);
}*/
