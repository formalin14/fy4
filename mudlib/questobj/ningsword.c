 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>  
inherit SWORD; 
void create()
{
        set_name(HIG "���̽�" NOR, ({ "ningsword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
����һ��������䣬�������˵ı������������߶��������Ͽ��С���÷��
���֣��ּ����㣬ٲȻ����Ů��֮�֣����Զ���������ǻ�ɽ����������
������÷��ʦ���佣����÷��ʦ�Դ�һֻ�ֱ������ս��󣬾��ܹ���û��
��Ӱ�죬���ж��ܲ�����ǰ��㣬���ұ������ȶ����֣�Ƣ��Ҳ��ñ���
ǰ���ꡣ������ͽ����һ����Ե���ǧ�꺮��һ�飬���������ѳɳ�����
�������������������Լ��ٿ�÷��ʦ�˹�ʱ�����ȶ��尾֮�ࡣ�Դ���
�󣬿�÷��ʦ���䡰���̽����Ӳ���������÷���̡�Ҳ��Ϊ��ɽ�ɵı�
־��  
LONG);
                set("material", "steel");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        }
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        ::init_sword(150);
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
