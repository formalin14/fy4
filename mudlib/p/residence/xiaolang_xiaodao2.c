#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"÷԰С��"NOR);
        set("long", @LONG
��������������ʯС·�ϣ����Ż��ݵ���ζ���������������������ʱ��ȴ��
�����е�Ѫ���ȷ磬�㿴������С���ڻ�����ľ��ȸԾ���У�ʱ��ʱ�Ļ��и���С
������С·�����ش���
LONG
        );
    set("exits", ([ 
								"south" : __DIR__"xiaolang_xiaodao",
                "north" : __DIR__"xiaolang_huayuan",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2032);
    set("coor/z",30);
        setup();
} 
void init(){

        if(this_player()->query("marks/��ȸ") && NATURE_D->is_day_time() 
                        && NATURE_D->get_weather() == "��") {
                call_out("bird_come", 2, this_player());
        }
        if( this_player()->query_temp("know/zhuguo") ){
               add_action("do_east","east");
               }
}
void bird_come(object me){
        object obj;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
//        obj = new("/d/wolfmount/npc/obj/zhuguo");
        if (random(10)>=5){
                message_vision("\nһֻС��ȸ������$N��ǰ������ȥ�����������Ľи���ͣ��\n", me);
      					tell_object(me, HIW"��ȸ������һ���������˺������������������������\n"NOR); 
      					tell_object(me, HIW"С��ȸ��ͣ�����Ŵ��ֵĶ��������ţ�\n�ƺ��������������ȥ��\n"NOR);
      					tell_object(me, HIW"����С�����ߵĴ�����ϸһ����������һ��������\n"NOR);
      					me->set_temp("know/zhuguo",1);
//                obj->move(me);
        }
        me->delete("marks/��ȸ");
}  
int do_east(){
        object room;
        object me=this_player();
        
        if( me->query_temp("know/zhuguo") ) {
                message("vision", me->name()+"���ְѹ�ľ�Էֿ���һͷ���˽�ȥ��\n", 
                                environment(me), me);   
                room = find_object(__DIR__"xiaolang_guanmu");
                if(!objectp(room)){
                        room = load_object(__DIR__"xiaolang_guanmu");
           }
                me->move(room);
                me->delete_temp("know/zhuguo");
                message("vision", me->name()+"�Ӵ���֮�����˳�����\n", environment(me), me);
                return 1;
        }
        return 0;
}     
