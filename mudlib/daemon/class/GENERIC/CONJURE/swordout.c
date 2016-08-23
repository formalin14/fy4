 // silencer@fy4
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        object sword;   
        int skill;
        object *inv, ob;
        int i;
        
        seteuid(getuid());
                
        if( me->is_fighting() )
                return notify_fail("你还是先把敌人打发了再说吧！\n");
        
        if (me->query("class")!="wudang")
                return notify_fail("只有武当弟子才领略了剑道.\n");
        
        if (me->query_skill("sword",1)<100)
                return notify_fail("你的剑术太差了.\n");
                
        if (me->query_skill("incarnation",1)<100)
                return notify_fail("你对修仙术领略不够.\n");
                
        if (me->query("atman")<110)
                return notify_fail("你的灵力不够.\n");
        
        if (me->query("gin")<110)
                return notify_fail("你的精力不够.\n");
               
        if ((me->query_skill("sword",1)>400) && (me->query_skill("incarnation",1)>300))
        {
        	inv = all_inventory(me);
                for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== HIY"金剑"NOR
                        ||ob->query("name")== HIG"木剑"NOR
                        ||ob->query("name")== HIW"纸剑"NOR
                        ||ob->query("name")== HIR"心剑"NOR
                        ||ob->query("id") == "forcesword")
                        {
                        return notify_fail("你已经有一把类似的剑了。\n");
                }
           }
               	sword = new("/obj/weapon/sword_heart");
                sword->move(me);
                tell_object(me,"你暗颂剑道心诀："+HIG"无处不成剑，无物不成剑，无事不成剑.\n"NOR);
                message_vision(HIY"$N身上一道金光一闪而逝......\n"NOR,me); 
                tell_object(me,"你得到了一把"+sword->name()+".\n");
                return 1;
        }
                      
                        
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== HIY"金剑"NOR
                        ||ob->query("name")== HIG"木剑"NOR
                        ||ob->query("name")== HIW"纸剑"NOR
                        ||ob->query("name")== HIW"心剑"NOR
                        ||ob->query("id") == "forcesword")
                        {
                        return notify_fail("你已经有一把类似的剑了。\n");
                }
        } 
        
        
// if (me->query_temp("sword_number")==1)
//              return notify_fail("你已经有一把剑了.\n"); 
                
        skill=(me->query_skill("incarnation",1)+me->query_skill("sword"))/200;
        
        me->add("atman", -100);
        me->receive_damage("gin", 100); 
        tell_object(me,"你暗颂剑道心诀："+HIG"无处不成剑，无物不成剑，无事不成剑。\n"NOR);
        message_vision(HIY"$N身上一道金光一闪而逝......\n"NOR,me); 
        me->start_busy(2);
        
        switch( skill ){
        
        case 0: 
                return notify_fail("你一无所获\n");
                break;
        case 1:
                sword = new("/obj/weapon/sword_gold");
                sword->move(me);
                break;
        case 2: 
                sword = new("/obj/weapon/sword_wood");
                sword->move(me);
                break;
        default:
                sword = me->query("open_sesame") ? 
                                  new("/obj/weapon/sword_cq") 
                                : new("/obj/weapon/sword_paper");
                sword->move(me);
                break;
        }
//      me->set_temp("sword_number",1); 
        tell_object(me,"你得到了一把"+sword->name()+".\n");
        return 1;
}      
