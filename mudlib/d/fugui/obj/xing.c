#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"极乐之星"NOR, ({ "xing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("value", 50000);
            set("long", "一枚状如鸽卵、价值连城的宝石，为西域龟兹王之物。\n");
            set("no_sell",1);
            set("thief_obj",1);
          }
        ::init_item();
}     
