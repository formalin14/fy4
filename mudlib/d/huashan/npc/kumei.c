#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    set("nickname", HIW "���ɹ�"NOR);
    set("gender", "Ů��");
    set("class","huashan");
    create_family("��ɽ��", 16, "����");
    set("student_title","����");
    set("age", 59);
    set("str", 45);
    set("int", 30);
        set("per", 3);
    set("con", 25);
    set("kee", 7000);
    set("max_kee", 7000);
    set("gin", 2000);
    set("max_gin", 2000);
    set("force", 9000);
    set("max_force", 9000);
    set("force_factor", 30);
    set("combat_exp", 2000000);
    set("attitude", "friendly");
    set_skill("unarmed", 100);
    set_skill("zhaixin-claw",60);
    set_skill("move", 100);
    set_skill("dodge", 100);
    set_skill("parry", 90);
        map_skill("unarmed", "zhaixin-claw"); 
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    setup();
    carry_object("/d/qianfo/npc/obj/black_suit")->wear(); 
} 
void init()
{
        ::init();
        add_action("do_open","open");
} 
void apprentice_me(object player)
{
        object kumei;
        kumei = this_object();
        message_vision("$N��Цһ���������Ȼ�ܸ����������ˡ�\n",kumei);
        message_vision("$N�ƺ��ڴ���$n��\n\n",kumei,player);
        message_vision(YEL"ͻȻ����������������ɭɭ��������$n˵������֪����̫������ܣ����²���
����������߳������Ҫָ������ȥ��ֻ�а��������£�����ʦ�����
й¶�����ܡ������������������󣯣�\n"NOR,kumei, player);
        set("marks/inquiry",1);
        add_action("do_accept","accept");
        call_out("auto_kill",60,player);
}  
void auto_kill(object player)
{
        object kumei;
        kumei = this_object();
        delete("marks/inquiry");
        if(interactive(player) && present(player, environment(kumei))){
                message_vision("$N��ɭɭ��˵�������ݲ�������ԥ�ˡ���\n",kumei);
                call_out("check_status",2,player);
                kumei->kill_ob(player);
                kumei->ccommand("perform zhaixin");
        } else {
                message_vision("$N����һ����˫��һ�㣬���Ӷ�ȥ����\n",kumei);
                destruct(kumei);
        }
}  
void check_status(object player)
{
        object kumei;
   kumei = this_object();
        if (interactive(player) && present(player,environment(kumei))){
                message_vision("\n$N�������ŵؿ���$n�������㾹�ܶ������һ�У�����һ�����������ķ�Ҫ��������
�ã���������ҷŹ��㡣��\n",kumei,player);
        }
        message_vision("$N����һ����˫��һ�㣬���Ӷ�ȥ����\n",kumei);
        destruct(kumei);
}  
int do_accept(string arg)
{
        object player,kumei;
        player = this_player();
        kumei = this_object();
        if (arg != "yes" && arg != "no"){
                return 0;
        }
        if (!query("marks/inquiry")){
                return 0;
        }
        remove_call_out("auto_kill");
        delete("marks/inquiry");
        if (arg == "yes")
        {
                player->set("marks/�ҳ�",-1);
                tell_object(player,"�㿴����Χ��һƬ���ţ�û�а�������������룬�����Ȼ���ȥ�ɡ� \n");
                message_vision("$N˵�������ã���Ը����Ϊʦ����\n",player);
                kumei->ccommand("remove suit");
                message_vision("$N�����Ц������������֪���㲻������ʧ���ġ���\n",kumei );
                call_out("after_apprentice",2,player);
        } else if (arg == "no") {
                message_vision("\n$N����һ����ҡҡͷ˵�����Ұݵ��죬�ݵõأ���ô�ܰ������������������Ϊʦ������\n",player);
                message_vision("��������Ц�������ã����У�����\n", player);
                call_out("check_status", 2 , player);
                player->set("marks/�ҳ�",1);
                kumei->kill_ob(player);
                kumei->ccommand("perform zhaixin");
        }
        return 1;
}  
void after_apprentice(object player)
{
        object kumei;
        kumei = this_object();
        if (player && present(player,environment())){
                if (player->query("class") == "huashan"){
                        message_vision("$N�������ã��ã����Ժ�Ҫ�����ŷ����󡣡�\n",kumei);
                } else {
                        message_vision("$N�����������ڻ����ǿ���֮�š������������Ŀɼ��ķ��ϣ����߰ɣ���\n",kumei);
                }
        }
        message_vision("$N˫��һ�㣬���Ӷ�ȥ��\n��",kumei);
        destruct(kumei);
} 
int do_open(string arg)
{
        object player;
        player = this_player();
        if(arg != "ᣲ�" && arg != "curtain") {
                return 0;
        }
        message_vision("$N����ص���$nһ�ۣ������������ʲô����\n",this_object(),player);
        return 1;
}  
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        if(killer->query("marks/�ҳ�")== -1) killer->set("marks/kill_kumei", 1);
    ::die();
} 