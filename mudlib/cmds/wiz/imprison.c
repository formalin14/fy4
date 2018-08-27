 // imprison.c
 
#include "/doc/help.h"
#define SYNTAX  "指令格式：imprison <玩家id> because <原因>\n"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        object room;
        string name,reason;
        if (!wizardp(me)) return notify_fail("你没有权力使用这个指令。\n");
        if (!arg) return notify_fail(SYNTAX);
        if (sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);
        ob = find_player(name);
        if (!ob) return notify_fail("找不到这个玩家。\n");
        message_vision("$N手一挥，一阵微风将$n吹入风云监狱．．．\n",me,ob);
        seteuid( geteuid(this_player(1)) );
        if(!(room =find_object(AREA_WIZ"jail")))
        room = load_object(AREA_WIZ"jail");
        ob->move(room);
        ob -> save();
        log_file("static/imprison", sprintf("[%s] %s imprison %s(%s) because %s.\n",
                ctime(time())[0..15], me->query("id"), ob->query("name"), ob->query("id"), reason));    
        return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: mprison <玩家id> because <原因>
将某个玩家禁锢在风云的监狱里，在监狱里什么也做不了，
一直到被提出监狱。 
HELP
   );
   return 1;
}
