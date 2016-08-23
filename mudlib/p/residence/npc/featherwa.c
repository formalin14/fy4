 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("�˵���", ({ "waiter", "mentong" }) );
        set("title", "�˼�����");
        set("gender", "����" );
        set("age", 35);
        set("richness",1000000);
        set("str", 10);
        set("cor", 20);
        set("cps", 30);
        set("int", 40);
        set("per", 50);
        set("con", 60);
        set("spi", 70);
        set("kar", 80);
        set("long",
"һ���ɹǵ�������˼ҡ�\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "�˵�����������������Զ�������¶��һ˿΢Ц��\n",
                }) );
        set("combat_exp", 50000000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000);
        set("mana", 1000);
   set("mana_factor", 3);
//      set("price_index",0);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("notracesnow", 200);
        set_skill("snowshade-sword", 200);
        set_skill("sword", 200);
        
        map_skill("sword","snowshade-sword");
        map_skill("parry","snowshade-sword");
        map_skill("dodge","notracesnow");
        //map_skill("parry","taiji-sword");

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword_heart")->wield();
  
} 
void init()
{
        ::init();
        
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
} 
int accept_fight(object me)
{
        command("say ��֪��");
        command("heng");
        //kill_ob(me);
        return 1;
}
       
