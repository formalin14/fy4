#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create() {
        set_name( HIW"纸剑"NOR, ({ "papersword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "极轻,极薄的一把纸剑.\n");
                set("value", 0);
                set("no_get", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_sell", 1);
                set("no_burn", 1);
                set("material", "steel");
                set("rigidity", 200);
                set("wield_msg", "$N不知从什么地方摸出一把$n握在手中。\n");
                set("unwield_msg", "$N手中的$n一闪而逝。\n");
        }
        ::init_sword(100);
}     
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/8,me);
        return HIW "纸剑迎风荡漾，剑锋如灵蛇吐舌般骤隐骤现。\n" NOR;
} 