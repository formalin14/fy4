 inherit ITEM;
void create()
{
        set_name("����ʯ�ذ�", ({ "floor" , "jade floor", "����ʯ�ذ�"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep", "on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long", "���ƽ���İ���ʯ�ذ壬�������һЩ������\n");
                set("value", 1);
        }
} 
int is_container() { return 1; }     
