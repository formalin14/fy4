 // curse_yinshen.c
#include <ansi.h> 
inherit SSERVER;
int curse(object me, object target)
{
        int lvl,i;
        object env, *inv;

        if(me->query("env/invisibility"))
                return notify_fail("������ʩչ����������\n");

        message_vision(RED "$N���������дʣ������������黯��ʧ......\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me :), 1);
//        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 20+lvl/10+3*random(lvl/10));
//        if( me->is_fighting() ) me->start_busy(3);
        return 1; 
}
/* void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        message_vision(HIG "$N�����ν��������ֳ�����\n" NOR, me);
        me->move(environment(me));
        me->start_busy(1);
        tell_object(me,YEL"�����ʶʧЧ�ˡ�\n"NOR);
} */
void take_effect (object me)
{
        me->set("env/invisibility", 1);
        tell_object(me,YEL"��ɹ������ˡ�\n"NOR);
        
} 
        
       
