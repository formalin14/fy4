#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"���ֵ�"NOR, ({ "jiledan" }) );
//    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("base_unit", "��");
            set("base_weight", 1);
            set("material", "stone");
            set("long", "һ�輫�ֵ�������԰�����(pour)�ھ�ˮ֮��ʹ�á�\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

          } 
        set_amount(1);
//    ::init_item();
}
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
        
}
   
void init()
{
        add_action("do_pour", "pour");
} 
int do_pour(string arg)
{
        string me, what;
        object ob;
        function f; 
        if( !arg
        ||      sscanf(arg, "%s in %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("ָ���ʽ: pour <ҩ��> in <��Ʒ>\n"); 
        ob = present(what, this_player());
        if( !ob )
                return notify_fail("������û�� " + what + " ����������\n");
        if( !ob->query("liquid/remaining") )
                return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩˮ�Ʋ����ܻ�ҩ�ۡ�\n");
        f = (: call_other, __FILE__, "drink_drug" :);
        ob->set("liquid/drink_func", bind(f, ob));
        ob->add("liquid/slumber_effect", 100);
        message_vision("$N��һЩ" + name() + "����" + ob->name() 
                + "��ҡ���˼��¡�\n", this_player());
   add_amount(-1);
        return 1;
} 
int drink_drug(object ob)
{
        this_player()->apply_condition("slumber_drug",
                (int)this_player()->query_condition("slumber_drug") 
                + (int)ob->query("liquid/slumber_effect") );
        return 0;
}         
