 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( RED "投诉意见墙" NOR, ({ "wall" }) );
        set("location", AREA_FY"egate");
        set("board_id", "egate_b");
        set("long",     "一堵便於张贴和涂鸦的城墙。\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
