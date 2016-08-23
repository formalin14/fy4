 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him(object me);
void create()
{
    set_name("梅花盗", ({ "meihua dao" }) );
    set("gender", "男性" );
    set("age", 25);
    set("int", 30);
    set("str",60);
    set("per", 10);
    set("agi",100); 
    set("long",
        "这死尸又干又瘦，脸上刀疤纵横，也看不出他本是何面貌，身上穿的是件紧身
黑衣，连肋骨都凸了出来。
他紧咬着牙齿，竟是死也不肯放松，身上也瞧不见什么伤痕。\n"
        );
    set("force_factor", 120);
    set("chat_chance", 1);
    set("chat_msg", ({
        "梅花盗不怀好意地打量着你。\n",
            "梅花盗声音古怪地笑了起来：“虽然比不上武林第一美人，也算是人间尤物了。。。”\n",
            "梅花盗眼光闪烁着邪异的光芒，慢慢伸手向你靠近。。。\n",
            }) ); 
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 3000);
    set("eff_kee", 3000);
    set("eff_sen", 3000);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 3000);
    set("force", 3000);
    set("max_mana", 300);
    set("mana", 300);
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yaozhan" :),
            }) );
    set("combat_exp", 4200000); 
    set_skill("unarmed", 100);
    set_skill("blade", 150);
    set_skill("force", 100);
    set_skill("parry", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100); 
    set_skill("kongshoudao", 100);
    set_skill("wind-blade", 130);
    set_skill("ghosty-force", 200);
    set_skill("ghosty-steps", 100); 
    map_skill("unarmed", "kongshoudao");
    map_skill("blade", "wind-blade");
    map_skill("force", "ghosty-force");
    map_skill("parry", "wind-blade");
    map_skill("dodge", "ghosty-steps");
    setup();
    carry_object(__DIR__"obj/skinmask")->wear();
    carry_object(__DIR__"obj/black_cloth")->wear();
    carry_object(__DIR__"obj/needle_pipe");
    
}   
int kill_him(object me)
{
        message_vision(HIR"\n梅花盗听到铁门响动，猛的转过头来，眼中犹在闪着野兽的光芒。\n\n",me);
        message_vision("梅花盗阴狠冷鹫的眼神在$N身上扫了扫，道：你可是想来分－－\n",me);
        message_vision("话未说完，就忽然有一蓬乌星自他嘴里向$N直射出来！\n\n"NOR,me);
      ccommand("shoot "+me->query("id"));
       stop_busy();
       me->start_busy(3);
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
void init()
{
        object ob;
        ::init();
        
        if( interactive(ob = this_player()) ) {
        
        if(!ob->query_temp("marks/meihuadao")) {
                if (ob->query_temp("afei_on_the_way")) {
                         remove_call_out("afei_help");
                         call_out("afei_help", 5, ob);
                }
                kill_him(ob);
        }
        
}
} 
void die()
{
        int i;
        object *players, room, afei;             
        
        remove_call_out("afei_help");
        players = all_inventory(environment());
        for (i=0; i<sizeof(players); i++) {
                if (players[i]->query_temp("afei_on_the_way")) {
                        players[i]->delete_temp("afei_on_the_way");
                        players[i]->add("marks/afei_help", 1);
                }
                        
                if (players[i]->query_temp("marks/meihuadao")) {
                        players[i]->delete_temp("marks/meihuadao");
                        message_vision(HIG"$N忽然觉得一股暖流传入体内，霎时内息流畅，活动自如。\n"NOR, players[i]);
                }
                if (players[i]->query("id") == "afei") {
                        afei = players[i];
                        if( objectp(afei) && domain_file(base_name(afei)) == "qianjin" ){
                                room=find_object(AREA_QIANJIN"jinge");
                                if(!objectp(room))
                                        room=load_object(AREA_QIANJIN"jinge");
                           message_vision("$N挥了挥手，转身匆匆离开。\n", afei);
                                if (!present("afei",room)) afei->move(room);
                                else destruct(afei);
                        }
                } 
        }
        
        ::die();
} 
void afei_help(object player) 
{
        object afei, room;
        if (present("afei",environment())) return;
        if (environment(player) == environment() && player->is_fighting(this_object()))
                {
                room=find_object(AREA_QIANJIN"jinge");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"jinge");
                afei = present("afei", room);
                if (objectp(afei)) 
                {
                        message_vision(HIG"\n阿飞似乎忽然听到了什么动静．．．\n阿飞对林仙儿道：我下去看看，马上就回来陪你。\n\n", afei);
                        message_vision(HIG"\n$N急匆匆的离开了。\n\n", afei);
                        afei->move(environment());
                        message_vision(HIC"\n$N忽然从上面一跃而下！。\n\n"NOR CYN"$N对梅花盗说：“我不能再让你活下去！”。\n\n"HIY"剑光闪动，$N已经出手！\n"NOR,afei);
                        afei->kill_ob(this_object());
                }
        }
}     
