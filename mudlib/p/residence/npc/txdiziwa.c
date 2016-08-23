 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("С��", ({ "xiao bi", "waiter" }) );
        set("title", "��ѪС®");
        set("gender", "Ů��" );
        set("age", 15);
        set("richness",1000000);
        set("str", 12);
        set("cor", 90);
        set("cps", 30);
        set("per", 86);
        set("int", 33);
        set("con", 74);
        set("spi", 40);
        set("kar", 65);
        set("long",
"С������ѪС®��Ѿ����ϲ��ҹ��ʱ��С�ٲ���ϴ�衣\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "С��������Ц��Ц��˦˦�����ϵ�ˮ����\n",
                }) );
        set("combat_exp", 10000000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 01);
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

             set_skill("unarmed", 20);
        set_skill("parry", 140);
        set_skill("dodge", 150);
        set_skill("sword", 140);
        set_skill("force", 130);
        set_skill("literate", 170); 
        set_skill("qidaoforce", 140);
        set_skill("diesword",130);
        set_skill("meihua-shou", 140);
        set_skill("fall-steps", 110); 
        map_skill("unarmed", "meihua-shou");
        map_skill("sword","diesword");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps"); 
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action, "sword.caidiekuangwu" :),
        (: perform_action, "dodge.luoyeqiufeng" :),  
            }) ); 

        
        setup();
        carry_object("/d/resort/npc/obj/thin_sword")->wield();
        carry_object("/d/resort/npc/obj/pink_cloth")->wear();
        carry_object("/d/resort/npc/obj/shoe")->wear();

  
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
        command("emote ��������������˵������Ҫ��˼Ҳ�Ҫ��");
        command("shy");
        return 0;
}
       
