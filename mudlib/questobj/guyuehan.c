 //TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW"天缺古月寒"NOR, ({ "guyuehan" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", @LONG
这是把中土罕见的刀，刀身狭窄，细长，弯度较大，前端出现刀锋
冷冷的月光照在上面，映出丝丝妖气，见过这把刀的人都承认这是
把奇特的刀是一把可以将使用者武功中的邪恶诡异之处发挥的淋漓
尽致的魔刀但是这样的一把刀上，竟然也有个缺口。
以石观音的武功，谁能让她的刀受到损伤呢？没有人知道，问过这
问题的人都死了。久而久之，没人再敢提这个问题了。只是江湖传
言，每逢月圆之时，石观音都会把自己和这把刀独自关在屋中。据
天枫派的弟子说，屋中会传来悲苍的歌声，曲调极其古怪，没人听
的懂唱的是什么，只是觉的仿佛天地间所有的悲伤，苍凉，哀怨，
痛苦，惆怅，渴求，无奈都一齐涌上心头。
日前石观音突然宣布此刀遗失，她将答应帮她找回此刀的人任何一
个条件消息一经传出，顿时整个江湖沸腾起来了。没人追问刀是怎
么丢失的，因为石观音许下的条件前面“任何”二字，已经使人忘
了其他的了。
LONG);
                set("rigidity", 2000);
                set("material", "steel");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);

        }
        ::init_blade(70);
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}