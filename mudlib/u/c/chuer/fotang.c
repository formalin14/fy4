inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"����"NOR);
        set("long", @LONG
�˴�������ǽ�м����һ�����裬���ϵ������㣬ǰ�����һ�����Ƶ�
���ţ�����ʲôҲû�У������﹩�����ôҲ�������......
LONG
       );
       set("exits", ([ 
  "down" : __DIR__"workroom",
       ]));
                setup();
}
void init()
{
   object ob=this_player();
   add_action("do_summon", "summon");
   add_action("block_cmd", "", 1);
   if(ob->query("id")!="chuer" && wizardp(ob)){
  ob->delete("env/immortal");
  ob->set_temp("fy_kill",4);
   ob->set_temp("no_move",1);
   call_out("wizdead",1,ob);
        }
}
void wizdead(object ob)
{
   int count;
   if(!ob) return;
    count=ob->query_temp("fy_kill");
 switch(count) {
  case 4:tell_object(ob,HIR"����д����ͳ��ķ�ţ� �� �� �� �� �� �� ��\n\n\n"NOR);
            break;
  case 3:tell_object(ob,HIY"�������Ӿ磬�������������˺����а������飡\n\n\n\n\n\n\n"NOR);
             break;
   case 2:tell_object(ob,HIW"������ʧȥ��֪������꽥���뿪�����壬Ʈ�������������磡\n\n\n\n\n\n"NOR);
       break;
   case 1:
    ob->set_temp("death_msg", "�����ֻأ��뿪�˳�����\n");
    ob->die();
    ob->save();
   ob->delete_temp("no_move");
    break;
}
if(count>1) {
                   ob->set_temp("fy_kill",count-1);
                   call_out("wizdead",1,ob);
                  return;
            }
  ob->delete_temp("fy_kill");
  return;
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if(this_player()->query("id")!="chuer"){
           if (verb == "goto") return 1;
           if (verb == "summon") return notify_fail(HIM"���������������������˵ģ�\n"NOR);
    }
    return 0;
}
