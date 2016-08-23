#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"÷԰С��"NOR);
        set("long", @LONG
����ɽׯ���ţ�һ����ʯС·���쵽ǰ���Ļ�԰��С·���Գ��Ÿ�ʽ��������
����ݣ�ïʢ����֦�ڵ���С·�Ϸ����γ����еĹ��ţ�����С���ڻ�����ľ��ȸ
Ծ���У������ļ��紺������ɢ������ζ���㲻��������һ�ڡ�
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"xiaolang1",
                "north" : __DIR__"xiaolang_xiaodao2",
        ]));
/*    set("objects", ([
                __DIR__"npc/woodcutter2" : 1,
        __DIR__"npc/yellowbird" : 1,
    ]));    */
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2031);
    set("coor/z",30);
        setup();
} 
void init(){
    int i;
    
    add_action("do_smell","smell");
    i = NATURE_D->set_season();
        if(i == 4){
                return;
        }
        if(NATURE_D->is_day_time() && NATURE_D->get_weather() == "��" 
                && !query("heal_bird")) {
                set("heal_bird", 1);
        call_out("heal_bird", random(20), this_player());
    }    
} 
int heal_bird(object me){
    object bird;
    
    if(environment(me) != this_object()) {
        return 0;
    } 
    bird = new(__DIR__"npc/bird");
    if(objectp(bird) && !present("yellow bird", this_object()) ){
        bird->move(this_object());
        message_vision(HIG"\nͻȻ�ݴ���һ���춯��ԭ����һֻ���˵�$N��������\n"NOR,bird);
    }  
} 

int do_smell(string arg) 
{ 
   object me; 
   int gin, sen; 
   
   me = this_player(); 
   
   if(!me->query_temp("marks/smelled")){
      	tell_object(me,HIR "��������һ��������ʱ��԰�����˱Ƕ��������㾫��Ϊ֮һ��\n"NOR); 
   			gin = (int) me->query("eff_gin");
   			sen = (int) me->query("eff_sen");
   			me->set("gin", gin);
   			me->set("sen", sen);
   			me->set_temp("marks/smelled", 1); 
                                       } 
    else{
   			tell_object(me,HIR "��������һ��������ʱ��԰�����˱Ƕ�����\n"NOR);  
   			message("vision",me->name(me)+"�����۾����ñ���������һ������\n", environment(me),me);   
   			me->start_busy(1); 
   			me->set_temp("marks/smelled", 1); 
   			}
   return 1; 
} 

 void reset(){
        ::reset();
        delete("heal_bird");
}
