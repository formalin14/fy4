#include <ansi.h> 
 inherit ITEM;
void create()
{
        set_name(RED"ֽ��"NOR, ({ "note", "ֽ��"}) );
        set_weight(1);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ź�ɫ������ֽ����
ֽ�������ƺ���Щ��Ҫ����ʾ���������ϸ�Ķ�(read)һ�¡�\n");
                set("value", 0);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
        }
        ::init_item();
} 
void init() {
        add_action("do_read", "read");
} 
int do_read(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "note" && arg != "ֽ��")) {
                return 0;
        }
        else
        {
           message_vision("$N����ֽ����ϸ�쿴��\n" ,this_player());
           tell_object(me, "ֻ��ֽ����д�ţ���ϲ�㽫���ʥ��������ȥ����(whisper)ʥ������(tianji)\n����������(gift)�ľ�����ȡ�취�ɡ�\n");
           me->set("ʥ������/gift", 1); 
         }
         return 1;
}    
