#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title","昆仑四鹫");
//      set("nickname","笑里藏刀");
        set("long", "一个明眸皓齿巧笑嫣然的绿衣少女。没有人知道她的真实身份，有人
说她是屠娇娇的弟子，也有人说她是屠娇娇的亲戚。\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp",3200000);
                        
        set("max_atman",800);
        set("atman",800);
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1500);
        set("force",1500);
        
        set("inquiry", ([
                "小烟" : "小烟好像和几个孩子在竹林边玩",
                 "欧阳豆腐铺" : "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳丁" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳当" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang ding" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang dang" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
                "娇娇客栈": "娇娇客栈是我开的。",
                "恶人谷": "恶人们都跑光了，这恶人谷三字早已没人提了。",
                "燕南天": "燕大侠的名字谁人不晓，村里还有他的铁像呢。",
                "万春流": "万神医有起死回生之能。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "屠小娇笑道：“客官请上楼歇息。”\n",
        }) );
   set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,160,0,"/d/eren2/npc/obj/","fighter_u","all");
        set_name("屠小娇",({"tu xiaojiao","xiaojiao"}));
        set("age",20);
        set("gender","女性");
        set("force_factor",60);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$N姗姗走了过来，秋波向$n一瞟，万福道，“您好？”\n", this_object(),ob);
        return;
}    
