 inherit ITEM;
void create()
{
        set_name("ҹ����", ({ "lighting-pearl", "pearl"}) );
        set_weight(3);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
һ�ŵ���ɫ��С���ӣ��ںڰ�������ɢ������͵Ĺ�â�����������˵�
�۾�����ô����������ô�Ķ��ˡ����ſ��ţ��㲻�����ˣ��ǲ���Ҳ��
���˴�ǰ��������һ����������֮�£�������Я�������ڰٻ�֮�䣬
��������˫����������������ŵ�������ˮ���۾���
Ϲ���ϵ�����������࣬ȴ���Ͻ������������Ƿ�������Ҳ������һ��
���£�
LONG);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
                set("value", 10000);
        }
        ::init_item();
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
        add_action("do_use", "use");
} 
int do_use(string arg)
{
        if( arg != "pearl" && arg!="lighting-pearl" ) return 0; 
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->light_notify(this_object(), 1); 
        return 1;
}         