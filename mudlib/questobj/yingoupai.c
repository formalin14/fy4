#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"银钩牌"NOR, ({ "yingoupai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
                set("long", @LONG
武林确实是一个莫名其妙的地方。不仅有莫名其妙的怪人，也有莫名其妙
的宝物。其中，银钩赌坊大老板蓝胡子的小舅子，方玉飞方大少爷的银钩
牌就是比较出名的一件。其莫名其妙之处在于，以方大少的家世而言，这
么一个亮闪闪的牌子根本就看不出值钱在哪里，也根本就算不上是宝物。
而我们的方大少偏偏就把它当宝物，走到哪里都挂在腰间，就算跟女人上
床他也要放在床沿。众所周知，方大少吃喝嫖赌，样样精通，是个有名的
花花公子。他的身边当然少不了女人，梧叶飘就是其中一位。她也可说是
比花花解语，比玉玉生香般的人物了，可偏偏痴心于方玉飞这么一个花花
公子。为了拴住方玉飞，她竟然在方玉飞不注意时，把他的银钩牌藏了起
来。这件事本来已经有点莫名其妙，更莫名其妙的是她自己也忘了藏到哪
里去了，当然，也大有可能是被人偷走了。可怜的方玉飞也只好悬赏寻物
了。
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
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
