#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name(HIY"��"NOR+HIR"��"NOR, ({ "dragon scale", "scale" }) );
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "������ۿ���ȥ�ǽ�ǲ���Ҳ��֪������ʲô֯�ɵģ����Ǿ�˵\n"
                        "����������ʿ��������Ķ����������н���һ������\n");
                set("unit", "��");
                set("no_drop",1);
                set("no_get",1);
                set("no_sell",1);
                set("value", 10000000);
                set("material", "blacksilk");
                set("armor_prop/armor", 300);
                set("armor_prop/spirituality",5);
                set("armor_prop/courage",10);
                set("armor_prop/armor_vs_force", 50);
                set("armor_prop/parry",30);
                set("armor_prop/spells",30);
                set("armor_prop/magic",30);
                set("armor_prop/unarmed",20+random(5));
                set("armor_prop/sword",10+random(5));
                set("armor_prop/blade",10+random(5));
                set("armor_prop/spear",10+random(5));
                set("armor_prop/whip",10+random(5));
                set("armor_prop/axe",10+random(5));
                set("armor_prop/staff",10+random(5));
                set("armor_prop/dagger",10+random(5));
                set("armor_prop/hammer",10+random(5));
                set("armor_prop/throwing",10+random(5));
                set("armor_prop/force",20+random(5));
                set("armor_prop/herb",20+random(5));
                set("armor_prop/dodge", 40);
                set("armor_prop/iron-cloth", 40);
        }
        ::init_cloth();
} 
int query_autoload() { return 1; }  
