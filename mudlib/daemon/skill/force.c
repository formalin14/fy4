 // force.c
#include <ansi.h> 
inherit SKILL; 
void setup() {
        set("name", "内功心法");
        set("effective_level",          50);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("force", 1);
        if( s%10==9 && (int)me->query("con") < s/5) {
                tell_object(me, HIW"由於你的内功修炼有成，你的体质改善了。\n" NOR);
//                me->add("con", 2);
                me->set("con",(s+1)/5);
        }
} 
