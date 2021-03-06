 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int bbqthem(object me, object obj);
int cast(object me, object target)
{
        int lvl,i;
        object env, *inv;
        if(me->query("class")!="lama")
                return notify_fail("只有大昭寺的弟子才可以使用真言！\n");
        if((int) me->query_skill("kwan-yin-spells",1) < 120)
                return notify_fail("你的观音六字明咒不够高深！");
        if (!me->is_fighting())
                return notify_fail("“呢”只能在战斗中使用。\n"); 
        lvl = (int) me->query_skill("spells");
        if( me->query("mana") < 200 )
                return notify_fail("你的法力不够！\n");
        if( me->query("max_sen") <= 200 )
                return notify_fail("你的神不够！\n"); 
        if (target==me)
                        return notify_fail("不要命了？\n");
        if (userp(me)) me->add("mana", -200);
        if (userp(me)) me->receive_damage("sen", 200);
        
        message_vision(WHT"$N沉喝一声“呢”，右手护心，左手平摊，霎那间三宝在握，灵神归一， 
只见淡淡的白光透出体外。 \n" NOR, me);
        message_vision(HIW "．．．$N被一股淡淡的白烟所包围！！\n" NOR, me);
        if(target) {
                bbqthem(me, target);
        }
        else
        {
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if( !inv[i]->is_fighting(me)) continue;                 
                        bbqthem(me, inv[i]);
           }
        }
        if(me->query_busy()<5) me->start_busy(5); 
        return 1; 
} 
int bbqthem(object me, object obj)
{
        int magic,objsen;
        
        magic = (int) me->query_skill("spells");        
        
        message_vision(MAG "\n紫气从"NOR+"$N"+MAG"的头上升起，盘旋着注入$n的体内，\n" NOR, obj,me);
        obj->receive_damage("sen", 1, me);
        
        if(obj->is_ghost()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N随即形神俱灭，无影无踪！\n" NOR, obj);
                me->add("kee",obj->query("sen")/10);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N象是全部生机都被抽走一样，木头似地倒下，化为了一滩血水！\n" NOR, obj);
                me->add("kee",obj->query("kee")/10);
                obj->die();
                return 1;
        }
        
        magic = random(magic*2) + magic;
        obj->receive_damage("sen",magic,me);
        
        me->receive_curing("kee", magic);
        if (me->query("kee")<me->query("eff_kee"))   me->add("kee",magic);
                else me->set("kee",me->query("eff_kee"));
        
        COMBAT_D->report_status(obj);
        COMBAT_D->win_lose_check(me,obj,1);
        return 1;
}        
