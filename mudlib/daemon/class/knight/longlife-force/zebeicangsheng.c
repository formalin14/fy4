#include <ansi.h>
inherit F_CLEAN_UP; 
void remove_effect(object me, int amount); 
int exert(object me,object target,int amount)
{
        int extra, num; 
        if(me->query("class")!="knight")
                return notify_fail("只有快活林弟子才能够领略到苍生诀得真谛。\n"); 
        if(me->query_temp("resup"))
                return notify_fail("你已经在运用『泽被苍生』了。\n");

		extra = me->query_skill("longlife-force",1);

		if(extra < 150) 
				return notify_fail("你对苍生诀领悟得还不够！\n");
		if((int)me->query_skill("herb") < 150) 
				return notify_fail("你得药道不够高！\n");
        
        if( (int)me->query("force") < 300 )
                return notify_fail("你的内力不够。\n");
      
        me->add("force", -300);
		num = (int)extra / 20;
        
        message_vision(HIW"$N运起苍生诀之精髓——『泽被苍生』，$N感觉到自己的生命力增强了！\n"NOR,me);
        
        me->add("resistance/kee", num);
        me->add("resistance/sen", num);
        me->add("resistance/gin", num);
		me->set_temp("resup", 1); 
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         num :), (int)extra/4); 
		if( me->is_fighting()) me->start_busy(3); 
        return 1;
} 
void remove_effect(object me,int amount)
{
        me->add("resistance/kee", -amount);
        me->add("resistance/sen", -amount);
        me->add("resistance/gin", -amount);
		me->delete_temp("resup");
        tell_object(me,"你的『泽被苍生』运行完毕。\n");
}
