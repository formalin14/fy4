 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIY"����"NOR, ({ "tiansun", "tian sun",  }) ); 
        set("gender", "����");
        set("age", 80);
        set("long",
 "\n�����ǵ��񽭺��������ص���֯�����ڡ���ͷ�죬�������źܶ��˵����ˡ�\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
//      set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );
        set("inquiry", ([
                "����" : (: give_hint:),
                "tianzong" : (: give_hint:) 
        ]));
        set("force", 4000);
        set("max_force", 80000);
        set("force_factor", 40);
        set("atman",1000);
        set("max_atman",1000);
        set("fly_target",1);
        set("combat_exp", 10000000);
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", HIG"����"NOR+WHT"����"NOR);
//        set("nickname", HIR"������˫"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        create_organization("����",1,"а");
}
int accept_fight(object me)
{
        command("say �ߣ���û������й���");
        return 0;
}
void init()
{
      add_action("give_mission", "mission");
      add_action("filish_mission","filish");
//      add_action("join_in","join");
}
int filish_mission()
{
        int  exp, pot, score;
        object me;
        string mission;
        
/*        if((string)who->query("organization/org_name") != "����")
                return 0;*/
        me=this_player();
        
        if(!me->query("mission/over"))
        {
          tell_object(me,"����ҡͷ�����������û����ɡ�");
          return 0;
        }
        else
        {
        tell_object(me,"����˵�����ã����úã����ھ���Ҫ���������˲ţ�\n");
        exp = random(150) + 10;
// put a cap
        exp = exp * (int) me->query_temp("mission_number")/3;
        exp += 1;
        pot = exp / 5 + 1;
        score = 1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",-score);
        tell_object(me,HIW"�㱻����������ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
//      chinese_number(score)+"���ۺ�����\n"NOR);
        me->set("mission/name", 0 );
        me->set("mission/over",0);
        me->add("QUEST",1);
                        return 1;
        }
                return 1;
}
int give_mission(string arg)
{
        string mission ;
        object me;
        int j, combatexp, timep, lvl=0;
        mixed *local;
        string *npcs,*objs,file;
        int  t;
        me = this_player();
// Let's see if this player is one of us
        if((string)me->query("guild") != "����")
                return 0;
   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"����赶�����Ц��˵��
���ҿ���ԡ����ڡ����������ģ�������ȥɱһ�������书�൱�ġ��ˡ��\n");
                return 1;
        } 
// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("��겻��Ҫ����\n");
                return 1;
        }
        if( me->query("mission/name") && !me->query("mission/over") )
        {
        	write("�����ڵ������ǹ���"+me->query("mission/name")+"��\n");
        return 1;
        }
// Let's see if this player still carries an un-expired task
        if((mission =  me->query("mission/name")))
        {
        if( ((int) me->query("mission_time")) >  time() )
                return 0;
        else
                me->set("kee", me->query("kee")/2+1);
                me->delete_temp("mission_number");
        }
        file = read_file("/quest/NPC");
        npcs = explode(file,"\n");
        file = read_file("/quest/OBJ");
        objs = explode(file,"\n");
        timep = random(300)+60;   //  big random factor
// A factor here to make time random
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
//        if(random(2))
//        {
        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"������ɱ��"+mission+"��\n"NOR);
        sysmsg +="ɱ��"+mission+"��";
/*        }
        else
        {
        mission = objs[random(sizeof(objs))];
        tell_object(me,"ȥ��"+mission+"�����ڡ�\n"NOR);
        sysmsg +="ȥ��"+mission+"��";
   }*/
        me->set("mission/name", mission);
        me->add("vendetta/authority",1);
        me->set("mission_time", (int) time()+(int) timep);
        if((int)me->query_temp("mission_number") < 5)
        me->add_temp("mission_number",1);
        CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)��%s",
        me->query("name"),me->query("id"),sysmsg)); 
return 1;
} 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t; 
        if(d) time = chinese_number(d) + "��";
        else time = ""; 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��"; 
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n��" + time + "��");
        sysmsg = "��" + time + "��";
        return 1;
}
int give_hint()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if(me->query_temp("num_of_ask") < random(4)+5)
        {
                me->add_temp("num_of_ask",1);
        tell_object(me,"����赵����������ڡ��ǵ��������������أ�а��İ�ᣬ���������¸�
�ɸ��֣��԰�ɱ��ʽ�������켺�������ڡ������ˣ�����������Ҳ�Ǹ������ԡ�
�����ڡ������޹ʲ�ɱ��������Ӣ�ۣ��Թ����Լ��������еĵ�λ��\n");
                return 1;
   }
        else{
        tell_object(me,"����赵��������ƺ��ԡ����ڡ��ܸ���Ȥ���Ƿ�������أ�join yes/no������\n");
        return 1;
        } 
}
int join_in(string arg)
{
        object me;
        me = this_player();
        if((int)me->query_temp("num_of_ask") < 5) return 0;
        if(!arg || arg != "yes" || me->query("combat_exp") < 800000)
        {
        me->delete_temp("num_of_ask");
        me->set_temp("in_doubt",1);
        return notify_fail("����赵����������ڡ���а���������������롲���ڡ���
�Ҿ����Ź��㣡��\n");
        }
        tell_object(me,"��������������������
����ʵ�Ҿ��ǡ����ڡ����������ӽ��Ժ����Ϊ�����ڡ������ɣ��Ҿ��Բ��������ģ�
���������Ҫ����quest��������һ��Ҫ֤������ǿ�ߣ���\n");
        me->set("guild","����");
        me->delete_temp("num_of_ask"); 
        return 1; 
}   
