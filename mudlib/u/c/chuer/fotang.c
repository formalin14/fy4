inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"佛堂"NOR);
        set("long", @LONG
此处不大，正墙中间放着一个佛龛，顶上点着盘香，前面放着一个发黄的
蒲团，除此什么也没有！佛龛里供奉的怎么也看不清楚......
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
  case 4:tell_object(ob,HIR"天空中传来低沉的佛号： 南 无 阿 弥 陀 佛 ！\n\n\n"NOR);
            break;
  case 3:tell_object(ob,HIY"你心跳加剧，正义的力量慢慢撕开你邪恶的心灵！\n\n\n\n\n\n\n"NOR);
             break;
   case 2:tell_object(ob,HIW"你慢慢失去了知觉！灵魂渐渐离开了身体，飘向西方极乐世界！\n\n\n\n\n\n"NOR);
       break;
   case 1:
    ob->set_temp("death_msg", "超脱轮回，离开了尘世！\n");
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
           if (verb == "summon") return notify_fail(HIM"楚儿不会让你连累其他人的！\n"NOR);
    }
    return 0;
}
