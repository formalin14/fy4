 // jiayiforce.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "嫁衣神功");
        set("usage/force", 1);
        set("skill_class", "tieflag");
        set("effective_level", 120);
        set("learn_bonus", -30);
        set("practice_bonus", -10);
        set("black_white_ness", 60);
} 
/*
void skill_improved(object me)
{
    int s; 
    s = me->query_skill("jiayiforce", 1);
    if(!(s%50) && (me->query_skill("force",1)/6 < me->query_skill("jiayiforce",1))){
        tell_object(me,HIR "\n你体内真气振荡，一股气流走入叉道，啊！！....\n\n" NOR); 
        me->set_skill("jiayiforce",s/2);
        me->unconcious();               
    } 
}*/  
