#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int my_exp,your_exp;
        int extra, n, force,damage,damage1,damage2;
        int tmp,chance,skill;
        object weapon;
        
        skill = me->query_skill("xuemo-blade",1);
        extra=skill+random(skill);
          
        damage = extra*3/2;
        if (skill < 100) return notify_fail("���Ѫħ�����������죬���ܽ������Ũ�μ��գݵ�������磬�����߻���ħ��\n");

        tmp = me->query_skill("blade",1);
        if (tmp < 100) return notify_fail("��Ļ����������������죡�����׼���Ѫħ������\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("����Ũ�μ��գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        chance=extra+tmp;
   
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",damage);
        weapon = me->query_temp("weapon");
        message_vision(HIR "\n\n $N�������֣������������һƬ���£����д��һ����"NOR,me);
        msg =HIR "\n ��"+HIM"��"+HIR"��"+HIY"Ũ"+HIR"��"+BLU"��"+HIR"��"+HIG"��"+HIR"��"+WHT"��"+HIR"��\n" NOR;
// msg += HIM "\n��\n" NOR; 
        msg += MAG "\n$N"+MAG"�����г���ħ�⣬���е�ħ���ڿ��з��裡\n"+CYN"Զ������һ����������������Զ������һȺ����ӵ��һ�Ż���������������������"NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-damage); 
        if (chance>random(300)) {
  message_vision(HIM"\n       				��"NOR,me);
// message_vision(HIY "\n Ũ\n" NOR,me);
         msg =WHT "\n�����Ĺ���"+HIG"�п�ȸ���ᣬ"+BLU"������ĳᣬ"+BLK"�����ӵļ�β��"+HIY"���۷�Ķ��룬"+HIC"��ߵĳ���أӥ��\n"
         +BLU"��ߵĳ�������"+HIG"��ߵ���ë�ǿ�ȸ��"+HIR"��ߵ���ë�Ƿ�ˡ�\n"+HIW"�����ɡ����ڣ����ӵļ�β��������ȸ����ë�Իͣ���˵���ë������\n"+HIM"ÿһ����ɫ������ϵ�������������Ѱ����������Ѱ���Ĺ֡�\n"
         +HIG"ÿһֻ��Ĳ����϶�����һ���塣�������죬�·�Ҫ���˵Ļ��ǡ�\n"NOR;


        my_exp = random(me->query("combat_exp")*5);
        your_exp = (int)target->query("combat_exp");
        
        if( my_exp > your_exp) {
                msg += HIR "\n$n"+HIR"�Ļ��ǲ�δ��������������ǿ�"+HIR"$n"+HIR"�Ǹ����ӣ�ȴ�������ǲ��壬ʧ�����ǣ�\n" NOR;
// target->start_busy(3);
                 damage1 = extra*7;
                 target->receive_damage("gin", damage1,me);
                 target->receive_damage("sen", damage1,me);
        } else {
                msg += CYN "\n$n"+CYN"���˶�����û�б���ǰ�ļ����Ի󣬵���Ȼ����������\n" NOR;
                if (target->query_busy()<3) 
                		target->query_busy(3);
        }
        message_vision(msg, me, target); 
        }
        if (chance>random(350)) {
          me->add_temp("apply/attack",extra);
                me->add_temp("apply/damage",damage);
                message_vision(HIY "\n      			 	Ũ" NOR,me);
// message_vision(BLU "\n ��" NOR,me);

                msg = MAG "\n$N"+MAG"ͻȻ��ʧ��"+MAG"��������к�Ȼ������ʮ���$w��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra);
          me->add_temp("apply/damage",-damage);
        }
        if (chance>random(400)) {
          me->add_temp("apply/attack",extra);
                me->add_temp("apply/damage",damage);
                message_vision(BLU "\n       				��" NOR,me);
// message_vision(HIG "\n ��"NOR,me); 
                msg = MAG "\n���°��$w"+MAG"��ҫ������Ĺ�â��\n" +MAG"����ʮ����ħ�����У������������֣��������������������֮��һƬ���¡�"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra);
          me->add_temp("apply/damage",-damage);
        }
        if (chance>random(450)) {
          me->add_temp("apply/attack",extra);
                me->add_temp("apply/damage",damage);
                message_vision(HIG "\n       				��"NOR,me);
// message_vision(WHT"\n ��" NOR,me); 
          msg = HIC "\nһ�����������ͻȻ�ڱ������������ʮ����ħ�����յ�������������ʳָ�����ݸ����¡�\n"+BLINK RED"�����һ����\n"NOR;
    msg += HIC "ʮ���$w"+HIC"һ�����ʮ��ֻʳָ֮�ϣ�ʮ���ħѪ�ӵ����зɳ�����ħָ�зɳ���"NOR;
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
          me->add_temp("apply/attack",-extra);
          me->add_temp("apply/damage",-damage);
  }
         if (chance>random(500)) {
           
           if (me->query("class")!="xuemo") 
             {
               damage = damage*5;
               extra = extra*5;
             }
           
           me->add_temp("apply/attack",extra);
           me->add_temp("apply/attack",damage);
           message_vision(WHT"\n       				��" NOR,me);
           msg= HIG "\n�����ǧ���ٰ�ʮ�ߵ�ħѪ�γ���һֻ"+HIR"Ѫ����"+HIG"��$n"+HIG"��Χ��������"NOR;
    COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    me->add_temp("apply/attack",-extra);
    me->add_temp("apply/attack",-damage);
        }
        if (me->query_busy()<4) 
                me->start_busy(4);
        
        return 1;
} 
