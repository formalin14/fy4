#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIB"曲蔓"NOR, ({ "quman" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/karma", 50);
                set("long", @LONG
在风云众多的至宝之中，曲蔓是极其神奇的一件。它不但是一件防身护体
的宝衣，而且据说它可以带给人们一生一世的好运。而这其中有一个美丽
动人的故事。
一个美丽而善良的姑娘名字叫古丽娜。她的眼睛就象天上的星星一样闪亮，
她的头发就象春天的风一样飘柔。古丽娜却病倒了。一种让所有部落里的
医生束手无策的病。在人们都已绝望的情况下，阿里木站了出来，“我要
上天山”。人们都吃了一惊。原来那时在古老的部落里流传着一种袭习。
就是当你最亲爱的人垂危的时候，若是你能独自一人，历尽千辛万苦到天
山上摘来千年雪蔓。那么山神就会因此而感动，从而怜悯于你施救你的至
亲。可是却是一件极其冒险的事情。几乎是用你的生命来换取你爱人的生
命。在人们一片哗然的时候，阿里木悄悄的离开，独自一人上了天上。五
天后人们在关外发现了他的尸体。在他怀中紧紧抱着的却是他用生命换来
的千年雪蔓。或许他对古丽娜的爱感动了山神，古丽娜很快愈痊了。然而
阿里木已死了，古丽娜活着又有什么意义。古丽娜在阿里木死后的第七天，
怀抱阿里木的尸身而死。后人为了纪念他们。就把那千年雪蔓做成了一件
背心。
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
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
