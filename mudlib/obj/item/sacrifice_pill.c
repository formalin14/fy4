#include <ansi.h>
inherit ITEM;
void generate_name();
void create()
{
        set_name(HIR"舍身丹"NOR, ({"sacrifice pill" }));
        set_weight(1);
        set("unit", "粒");
        set("long", "一粒由生命炼制成的赪红的丹药，可在施[心识神通]时使用.\n");
        set("value", 100000);
        ::init_item();
}       
