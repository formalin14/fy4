 // tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit SWORD;
void create()
{
        set_name( GRN "���Ǻ�����"NOR, ({ "hudie-sword" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�Ѻ���ͨ��ƽ���Ľ���Ψһ����עĿ���ǽ�����Ƕ��һ����ʯ����������\n����ҹ�ա�\n");
                set("wield_msg", HIG"����է���������ǣ��̴ٵ����ã�$N΢Ц�������������Ǻ�������\n�����������ƺ��ʵ����裬�ٻ����ţ�Ѥ���ޱȡ�\n"NOR);
                set("unwield_msg", HIG"$N΢΢һЦ�����������Ǻ������������С�\n"NOR);
                set("value", 0);
                set("material", "steel");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        }
        ::init_sword(60);
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

mixed hit_ob(object me, object victim,int extra,int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_atman")/10;
        extra = (int)me->query_skill("diesword",1);
        if(extra>100 && me->query("class")=="legend")
        {
                   victim->receive_damage("sen",dam);
                   victim->start_busy(random(5));
                   return HIG "����һ������һ˲��ĻԻ�ȴ���ö����㣬$n�������������\n" NOR;
         }
          else
         {
             me->receive_wound("kee",dam);
             if (me->query_busy()<=2) me->start_busy(2);
             return HIY "$Nֻ����ǰ�ǹ��ʵ����裬�������죬�޷����ơ�\n" NOR;
         }
}
