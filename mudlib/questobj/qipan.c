#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"棋盘"NOR, ({ "qipan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
                        set("long", @LONG
弈者对垒，“三尺之局兮作战场”，投子于枰，布阵列势，宛若将帅在
调动兵马，布置攻防。然而棋子毕竟是没有生命力的静物，阵列于纵横
十九的棋盘上，竟然能生出无穷玄奥的变化来，所以竟有称棋局为“鬼
阵”者。
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
