#include <ansi.h>
inherit NPC;
void create()
{
    set_name("С��ȸ", ({ "yellow bird", "bird" }) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "����һֻС��ȸ��ԭ����������ë���Ҳ�����
�������Ѿ����ˣ����ƺ����԰�������һ�¡���baozha����\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("verbs", ({ "bite","claw" }) );
//    set("unique_amount", 1);  
//    ITEM_D->setup_unique(this_object());  
    set("eff_kee", 1);
        set("weight", 200);
        set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
    setup();
}  
int kill_ob(object me){   
    message_vision("$N�鴤�˼��£��;�ֹ�����ˡ� \n",this_object());
    me->set("marks/kill_bird", 1);
    ::die();
    return 1;
}
void init() {
    ::init();

        add_action("do_heal", "baozha");
        call_out("not_cured", 60);
} 
void not_cured(){
//    if(!userp(environment(this_object()))){
        if(query("eff_kee") == 1){
                message_vision("$N�鴤�˼��£���һ�������ˡ� \n",this_object());
                   set("long", "����һֻС��ȸ��ԭ����������ë���Ҳ�����\n");
                ::die();
        }
} 

int do_heal(string arg) {
        object me, bird;
        
        me = this_player();
        bird = present("yellow bird", environment(me));
        if(!arg || (arg != "yellow bird" && arg != "bird")) {
                return 0;
        }
        if(!present("yellow bird", environment(me))){
                return 0;
        }
        message_vision(HIW"\n$N�����$n���˿ڰ�����������\n"NOR, me, bird); 
        message_vision(HIW"$n�����˼��£���$Nͷ����������Ȧ��\nȻ����������ش��ƶ�ȥ��\n"NOR, me, this_object());
				if(!me->query("marks/��ȸ")) 
				me->set("marks/��ȸ", 1);
        destruct(this_object()); 
        
        return 1;
}
