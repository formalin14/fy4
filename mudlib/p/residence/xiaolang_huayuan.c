#include <ansi.h>
inherit ROOM;
string flower();
void create()
{
        set("short", HIG"花园小亭"NOR); 
        set("long", 
"这里便是忘忧山庄的庄主的花园，这个小亭建在池塘中央，溪水流入花园中
的池塘，春天一至，东面"+HIR"桃花"NOR+"尽放，微风吹来，片片桃花瓣散落进池塘，引来
游鱼无数；夏季刚到，池中"+HIW"荷花"NOR+"便会开的非常的热闹，数只蜻蜓停留在未开的荷
尖上，非常可爱；夏去秋来，大雁南飞，池塘两旁"+HIY"菊花"NOR+"香味扑鼻，池中莲子颗颗
饱满，蜜桃早已挂满枝头，好一片丰收的景象；秋天过后，天气渐渐变凉，冬天
雪花飞舞，西面的"+HIM"梅花"NOR+"齐相争艳，这时候，庄主萧十一郎总会邀请好友来此饮
酒赏梅，比武论剑。\n\n"
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
                "桃花" : (: flower :),
                "梅花" : (: flower :),
                "菊花" : (: flower :),
                "荷花" : (: flower :),
                "池塘" : "池水清澈，春夏季节可以看到很多游鱼追逐嬉戏。\n",
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
        if( i ==1 ) tell_object(me, HIG"你远望池塘东岸，桃林开满桃花，微风吹来，香气宜人。梅树开始发芽，池塘中的\n荷叶嫩绿，古人云：小荷才露尖尖角，早有蜻蜓立上头，就是说此景了。\n"NOR);
        if( i ==2 ) tell_object(me, HIG"池塘中的荷花争相开放，荷叶间游鱼追逐嬉戏。有鲤鱼，鲫鱼，草鱼，当然还有一些\n说不上名字的鱼；岸边桃花尽谢，梅林翠绿，让人看了非常舒服。\n"NOR);
        
        if( i ==3 ) tell_object(me, HIG"池塘莲子饱满，桃树挂满桃子，各种菊花开的如火如荼，其他花儿夹杂其中，一片丰收\n的景象让人感到秋高气爽。\n"NOR);
//                     add_action("do_shang", "shang");
        if( i ==4 ) {
                tell_object(me, HIG"大雪漫漫，梅花齐放，古有梅花傲骨之说，当然指的是梅花不怕寒冬之意，看着这些漂亮\n的梅花，喝酒赏梅是一件人生乐事。\n"NOR);
                 add_action("do_shang", "shang");
                    }
 return "";               
} 
int do_shang(string arg) 
{ 
   object me; 
   me=this_player();   
       
   if(!arg || (arg != "meihua" && arg != "梅花" && arg != "梅")){
                return 0;
        }
   if( me->query_skill("literate",1) >= 150 && (arg == "meihua" || arg == "梅花" || arg == "梅")){
           if( random(10) == 5 ){
        			message_vision("\n$N远望眼前的梅花，微风一起，香气宜人。\n", me);
        			tell_object(me,HIR "渐渐的，你似乎发现能从曲折的梅枝中领悟(lingwu)出什么武学。\n"NOR); 
        			me->set_temp("marks/lingwu",1);
//        			add_action("do_lingwu","lingwu");
                                }
              else  message_vision("\n$N远望眼前的梅花，微风一起，香气宜人。\n", me);
                                       } 
   else return notify_fail("没事不要乱学人家欣赏梅花。\n");
   
   return 1;

} 

int do_lingwu(string arg)
{
   object me;
   int  s, amount, da;
  
   if(!arg || (arg != "梅枝" && arg != "meizhi")) 
      return notify_fail("你要从哪里领悟？\n");
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("你正在战斗，无法静下心来领悟武学，先把敌人打发了再说吧！\n");
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成，不能继续领悟。\n");
   me->start_busy(1);
   s = (int)me->query_skill("parry", 1);
   if( random(me->query("int")) > 10 ) {
      if(s >= 150) {
         message_vision("\n$N看着苍劲有力的梅枝若有所思！\n", me);
         tell_object(me, "你发现自己早就把梅枝所包含的武学参透了。\n");
         return 1;
      } 
      if(s >= 50) {
         message_vision("\n$N看着苍劲有力的梅枝若有所思！\n", me);
      } 
      tell_object(me, "你发现曲折的梅树枝隐含着拆招卸力之法！你的拆招卸力之法有些进步了！\n");
      amount =  (me->query("int") + me->query("cps"));
      if(amount < 1) amount = 100;
      me->improve_skill("parry", 15*amount);
//      da = 30*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("sen", 100);
   } else {
      message_vision("\n$N仔细观察梅枝的变化，什么也领悟不出来！\n", me);
//      da = 200*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("sen", 50);
   }
   return 1;
}  
