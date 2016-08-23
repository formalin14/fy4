 inherit SKILL;
void setup() {
        set("name",                     "天狼血咒");
        set("learn_bonus",              -500);
        set("practice_bonus",           10);
        set("black_white_ness",         0);
        set("usage/cursism",            1);
        set("skill_class",              "wolf");
}  
int practice_skill(object me)
{
        return notify_fail("天狼血咒只能学的。\n");
        
}  
int valid_learn(object me)
{
        if( (int)me->query_skill("wolf-force",1) < (int)me->query_skill("wolf-curse",1)+70)
                return notify_fail("你的天狼心法修为不够，无法领悟更高深的天狼血咒。\n");
        return 1;
}
