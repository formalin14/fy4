#include <ansi.h>
inherit ROOM;
string flower();
void create()
{
        set("short", HIG"��԰Сͤ"NOR); 
        set("long", 
"�����������ɽׯ��ׯ���Ļ�԰�����Сͤ���ڳ������룬Ϫˮ���뻨԰��
�ĳ���������һ��������"+HIR"�һ�"NOR+"���ţ�΢�紵����ƬƬ�һ���ɢ�������������
�����������ļ��յ�������"+HIW"�ɻ�"NOR+"��Ὺ�ķǳ������֣���ֻ����ͣ����δ���ĺ�
���ϣ��ǳ��ɰ�����ȥ�����������Ϸɣ���������"+HIY"�ջ�"NOR+"��ζ�˱ǣ��������ӿſ�
�������������ѹ���֦ͷ����һƬ���յľ����������������������������
ѩ�����裬�����"+HIM"÷��"NOR+"�������ޣ���ʱ��ׯ����ʮһ���ܻ��������������
����÷�������۽���\n\n"
); 
        set("outdoors", "residence");
        set("exits",([
                "east": __DIR__"xiaolang_xiaodao5",
                "west":__DIR__"xiaolang_xiaodao4",
                "north":__DIR__"xiaolang_xiaodao3",
                "south":__DIR__"xiaolang_xiaodao2",
        ]) );
         set("objects", ([
                __DIR__"npc/xiaolangwa2" : 1,
       ]) );
        set("item_desc", ([
                "�һ�" : (: flower :),
                "÷��" : (: flower :),
                "�ջ�" : (: flower :),
                "�ɻ�" : (: flower :),
                "����" : "��ˮ�峺�����ļ��ڿ��Կ����ܶ�����׷����Ϸ��\n",
        ]) );
        set("coor/x",15);
        set("coor/y",2033);
        set("coor/z",30);
        set("no_death_penalty",1);
        setup();
} 
string flower(){
        object me;
        int i;
        me = this_player();
   i = NATURE_D->get_season();
        if( i ==1 ) tell_object(me, HIG"��Զ���������������ֿ����һ���΢�紵�����������ˡ�÷����ʼ��ѿ�������е�\n��Ҷ���̣������ƣ�С�ɲ�¶���ǣ�������������ͷ������˵�˾��ˡ�\n"NOR);
        if( i ==2 ) tell_object(me, HIG"�����еĺɻ����࿪�ţ���Ҷ������׷����Ϸ�������㣬���㣬���㣬��Ȼ����һЩ\n˵�������ֵ��㣻�����һ���л��÷�ִ��̣����˿��˷ǳ������\n"NOR);
        
        if( i ==3 ) tell_object(me, HIG"�������ӱ����������������ӣ����־ջ����������ݱ�����������������У�һƬ����\n�ľ������˸е������ˬ��\n"NOR);
//                     add_action("do_shang", "shang");
        if( i ==4 ) {
                tell_object(me, HIG"��ѩ������÷����ţ�����÷������֮˵����Ȼָ����÷�����º���֮�⣬������ЩƯ��\n��÷�����Ⱦ���÷��һ���������¡�\n"NOR);
                 add_action("do_shang", "shang");
                    }
 return "";               
} 
int do_shang(string arg) 
{ 
   object me; 
   me=this_player();   
       
   if(!arg || (arg != "meihua" && arg != "÷��" && arg != "÷")){
                return 0;
        }
   if( me->query_skill("literate",1) >= 150 && (arg == "meihua" || arg == "÷��" || arg == "÷")){
           if( random(10) == 5 ){
        			message_vision("\n$NԶ����ǰ��÷����΢��һ���������ˡ�\n", me);
        			tell_object(me,HIR "�����ģ����ƺ������ܴ����۵�÷֦������(lingwu)��ʲô��ѧ��\n"NOR); 
        			me->set_temp("marks/lingwu",1);
//        			add_action("do_lingwu","lingwu");
                                }
              else  message_vision("\n$NԶ����ǰ��÷����΢��һ���������ˡ�\n", me);
                                       } 
   else return notify_fail("û�²�Ҫ��ѧ�˼�����÷����\n");
   
   return 1;

} 

int do_lingwu(string arg)
{
   object me;
   int  s, amount, da;
  
   if(!arg || (arg != "÷֦" && arg != "meizhi")) 
      return notify_fail("��Ҫ����������\n");
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("������ս�����޷���������������ѧ���Ȱѵ��˴�����˵�ɣ�\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɣ����ܼ�������\n");
   me->start_busy(1);
   s = (int)me->query_skill("parry", 1);
   if( random(me->query("int")) > 10 ) {
      if(s >= 150) {
         message_vision("\n$N���ŲԾ�������÷֦������˼��\n", me);
         tell_object(me, "�㷢���Լ���Ͱ�÷֦����������ѧ��͸�ˡ�\n");
         return 1;
      } 
      if(s >= 50) {
         message_vision("\n$N���ŲԾ�������÷֦������˼��\n", me);
      } 
      tell_object(me, "�㷢�����۵�÷��֦�����Ų���ж��֮������Ĳ���ж��֮����Щ�����ˣ�\n");
      amount =  (me->query("int") + me->query("cps"));
      if(amount < 1) amount = 100;
      me->improve_skill("parry", 15*amount);
//      da = 30*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("sen", 100);
   } else {
      message_vision("\n$N��ϸ�۲�÷֦�ı仯��ʲôҲ���򲻳�����\n", me);
//      da = 200*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("sen", 50);
   }
   return 1;
}  
