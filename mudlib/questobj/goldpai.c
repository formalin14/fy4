 // TIE@FY3
#include <armor.h>
inherit NECK;
#include <ansi.h>
void create()
{
        set_name(HIY"������˽���"NOR, ({ "gold pai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�����������ƶ�һЩ�й��׵����˵Ľ��ƣ���־����������Ϊ��ҷ���
�ܶࡣ��Ȼ����ֻ�����������Щ��ȡ�ľ���ֵ������������ѧϰ��������
����š��Ϲ����ᡡ���������
LONG);
                set("material", "stone");
                set("armor_prop/armor", 300);
                set("armor_prop/composure",50);
        }
        ::init_neck();
} 
