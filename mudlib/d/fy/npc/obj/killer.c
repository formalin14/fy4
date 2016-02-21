 // zombie.c
#include <ansi.h> 
inherit NPC; 
void do_bite(); 
void create()
{
        set_name("��ò��ͨ��İ����", ({ "figure" }) );
        set("long",
"����ֵ�ɱ�֡�ʲô������ɾ�ֻ�������ģ�ר������ɱ�ˡ�\n");
        set("attitude", "heroism");
        set("hired_killer", 1);
        set_skill("move",1);
        set_skill("dodge",1);
        set_skill("dagger",1);
        set_skill("pyrobat-steps", 1);
        set_skill("xinyue-dagger", 1);
        map_skill("move", "pyrobat-steps");
        map_skill("dodge", "pyrobat-steps");
        map_skill("dagger", "xinyue-dagger"); 
        setup();
        carry_object(__DIR__"obj/killerpai");
        carry_object(__DIR__"obj/killersword")->wield();
} 
void init()
{
        remove_call_out("hunting");
        call_out("hunting",1);
}
void  hunting()
{
        object  hirer, targ;
        string  target;
                hirer = this_object()->query("possessed");
                target = query("haunttar");
                if(objectp(targ = present(target, environment()))
                && !this_object()->is_fighting() && living(targ)){
                        if( targ == this_object()) return;
                        if(userp(targ) && (int)targ->query("combat_exp") < 2000)
                                {
                                        if( hirer)
                                   message_vision("$Nָ��$n˵�������־�����ɫ�����ң��ټ���\n",this_object(),targ);
                                        set_leader(0);
                                        call_out("destkiller",1);
                                        return ;
                                
                                }
                        message_vision(HIR "$N��$n��ȵ������˻����������������������վ�����ļɳ����ϵ�ù�ɣ�\n"NOR,this_object(), targ);
                        this_object()->kill_ob(targ);
                        this_object()->set_leader(targ);
                        targ->kill_ob(this_object());
                }
                else{
                        if( !this_object()->is_fighting() && hirer ) this_object()->set_leader(hirer);
                }                       
        return ;
}
int accept_fight(object me)
{
        return 0;
} 
void destkiller()
{
destruct(this_object());
return ;
}    