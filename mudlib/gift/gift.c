#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED "ʥ������" NOR, ({ "gift" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ�����������������������ģ��������������˶��������ƺ����Դ�(open)��\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, note,gift,me;
        object weapon,obj;
        int exp,pot,score,gold1;
        me = this_player();
        exp=10000+random(5000);
        pot=5000+random(2500);
        score=500+random(500);
        gold1=800+random(200);
        if(arg != "gift" && arg != "ʥ������") return 0;
        if (me->query("open"))
            return notify_fail("���Ѿ����������ˣ����˲���̫̰�ģ�\n");
        if(query("opened"))
                return notify_fail("ʥ����������˴򿪹��ˣ�����Ķ��������ù��ˣ�\n");
        gold = new("/obj/money/gold");
        gold->set_amount(gold1);
        gold->set("name","��Ҷ��");
        gold->set("base_unit","��");
        gold->move(this_player());
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        note = new("/gift/note");
        switch(random(5))
        {
        	case 0:
        	    gift=new("/d/wolfmount/npc/obj/zhuguo");
        	    gift->move(this_player());
        	    break;
        	case 2:
        	    gift=new("/d/daimiao/obj/forcedan");
        	    gift->move(this_player());
        	    break;
        	case 3:
        	    gift=new("/d/xinjiang/obj/salt");
        	    gift->move(this_player());
        	    obj=new("/d/xinjiang/obj/salt");
        	    obj->move(this_player());
        	    break;
        } 
        switch(random(5))
        {
        	case 0:
        	      weapon=new("/d/wolfmount/npc/obj/shield");
        	      weapon->move(this_player());
        	      break;
        	case 1:
        	      weapon=new("/d/wolfmount/npc/obj/tigersoul");
        	      weapon->move(this_player());
        	      break;
        	case 2:
        	      weapon=new("/d/wolfmount/npc/obj/putistaff");
        	      weapon->move(this_player());
        	      break;
        	case 3:
        	      weapon=new("/d/wolfmount/npc/obj/skull_whip");
        	      weapon->move(this_player());
        	      break;
        	case 4:
        	      weapon=new("/d/wolfmount/npc/obj/wolf-fist");
        	      weapon->move(this_player());
        	      break;  
        	}   	
        if ( random(80) == 1)
            {
            	note->move(this_player());
            	tell_object(me,WHT"\n��ϲ��õ�ʥ�����ʥ�����֣�����õ���:\n" + chinese_number(gold1) + "�Ž�Ҷ�ӣ�\n"+chinese_number(exp)+"�㾭�飡\n"+chinese_number(pot)+"��Ǳ�ܣ�\n"+chinese_number(score)+"�����ۣ�\n"NOR);
            	tell_object(me,HIC"\n��ʱ����ͻȻ��������ڻ���һ�ź�ɫ��"NOR+RED"ֽ��\n"NOR);
            }
        else
            	tell_object(me,WHT"\n��ϲ��õ�ʥ�����ʥ�����֣�����õ���:\n" + chinese_number(gold1) + "�Ž�Ҷ�ӣ�\n"+chinese_number(exp)+"�㾭�飡\n"+chinese_number(pot)+"��Ǳ�ܣ�\n"+chinese_number(score)+"�����ۣ�\n"NOR);
        set("opened",1);
        me->set("open",1);
        return notify_fail(HIR "\n���ʥ����������۷��⣬һ����ϲ��\n\n" NOR);
}
