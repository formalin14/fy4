#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIG"藤甲"NOR, ({ "chainarmor"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "vine");
                set("long", "一件用软藤织成的护甲，像在药物中浸泡过，坚韧异常。\n");
                set("value", 10000);
                set("armor_prop/armor", 60);
        }
        ::init_armor();
} 
