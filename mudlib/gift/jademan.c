#include <ansi.h>
inherit NPC;
int weapon();
int jade();
void create()
{
        set_name("宝石匠", ({ "jade man","man" }) );
        set("long",
"这是一名武林当中非常出名的宝石匠，据说他能打磨有灵性的武器和装备，然后把
宝石镶嵌在上面。\n"); 
    set("attitude", "friendly"); 
    set("age",72); 
    set("str", 80);
    set("cor", 110);
    set("agi", 50); 
    set("combat_exp", 500000);
        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set("inquiry", ([
                "weapon" : (: weapon :),
                "兵器" : (: weapon :),
                "bingqi" : (: weapon :),
                "armor" : (: weapon : ),
                "护具" : (: weapon : ),
                "jade" : (: jade : ),
                "宝石" : (: jade : ),
                "stone" : (: jade : ),
        ]));
    set("chat_chance", 1);
    set("chat_msg", ({
"宝石匠叹了叹气，喃喃道：“世间难求的宝石，到底在什么地方呢？”\n",
    }) );
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
void init(){
        ::init();
//    add_action("do_inset","inset");
    add_action("do_give", "give");
} 
int weapon(){
        object me;
        me = this_player();
        message_vision("$N若有所思，喃喃道：“有些东西是有灵性的，而我可以给它们打上凹槽，\n", this_object());
        message_vision("有了这些凹槽，镶嵌上宝石就可以提升武器和装备的属性，只可惜，宝石是很难得的啊~~~~~。”\n", this_object()); 
        return 1;
} 
int jade(){
        object me;
        me = this_player();
        message_vision("$N点头道：“世间有些宝石是可以用来提升武器和护具的属性，\n", this_object());
        message_vision("我年轻的时候，曾看到有人无意当中得到过一枚，自此就再难看到了。”\n", this_object()); 
        return 1;
} 
int do_give(string arg){
        object ob,me,obj;
        int i, j;
        string longarg,acceptor,objectname;
        
        ob = this_object();
        me = this_player();
        
    if( sscanf(arg, "%s to %s", objectname, acceptor)==2 ){ 
        if(acceptor!="宝石匠"&&acceptor!="jade man"&&acceptor!="man")
                return 0;
        if(ob->query("busy"))
        	return notify_fail("宝石匠正在帮别人打磨，你稍等一下吧。\n");
        obj=present(objectname,me);
        if(!objectp(obj)) return 0;
        
        i = obj->query("hole");
        j = obj->query("level");
        longarg = obj->query("long");
        if(obj->query("can_inset") && !obj->query("hole")) {
        	if(j <= 2){
        		ob->set("busy",1);
                	message_vision(CYN"$N看着$n递过来的"NOR+obj->name()+CYN"道：“这件也算是把有点灵性的东西，那我帮你打几个凹槽吧。”\n"NOR,
                                ob, me);
                        message_vision("$N接过$n的"+obj->name()+"，“叮叮当当”地打磨起来......。\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"一会儿过后，$N把打磨好的"NOR+obj->name()+CYN"还给$n道：“打磨好了，可得好好珍惜啊，下次得到宝石，可以\n"NOR,ob,me);
                	message_vision(CYN"一起拿来，我帮你镶嵌(inset)。\n"NOR,ob); 
                	obj->set("long", "这件东西上面有"+chinese_number(j+1)+"个凹槽。\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j <= 5 && j > 2){ 
                	ob->set("busy",1);
                	message_vision(CYN"$N看着$n递过来的"NOR+obj->name()+CYN"，赞叹道：“不错不错，这样的东西，值得我仔细去打磨，好东西啊。”\n"NOR,
                                ob, me); 
                        message_vision("$N接过$n的"+obj->name()+"，“叮叮当当”地打磨起来......。\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"一会儿过后，$N把打磨好的"NOR+obj->name()+CYN"还给$n道：“打磨好了，可得好好珍惜啊，下次得到宝石，可以\n"NOR,ob,me);
                	message_vision(CYN"一起拿来，我帮你镶嵌(inset)。\n"NOR,ob);
                	obj->set("long", "这件东西上面有"+chinese_number(j+1)+"个凹槽。\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j <= 8 && j > 5){
                	ob->set("busy",1);
                	message_vision(CYN"$N看着$n递过来的"NOR+obj->name()+CYN"，惊叹道：“世间少有啊！！！这样的东西，可不能糟蹋了，我会用全身心去打磨它！！。”\n"NOR,
                                ob, me);
                        message_vision("$N接过$n的"+obj->name()+"，“叮叮当当”地打磨起来......。\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"一会儿过后，$N把打磨好的"NOR+obj->name()+CYN"还给$n道：“打磨好了，可得好好珍惜啊，下次得到宝石，可以\n"NOR,ob,me);
                	message_vision(CYN"一起拿来，我帮你镶嵌(inset)。\n"NOR,ob);
                	obj->set("long", "这件东西上面有"+chinese_number(j+1)+"个凹槽。\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j >=8 ){
                	ob->set("busy",1);
                	message_vision(WHT"$N看着$n递过来的"NOR+obj->name()+WHT"全身开始颤抖，激动的几乎说不出话来，只见他一脸虔诚，自言自语道：”武林至宝！\n"NOR,ob,me);
                	message_vision(WHT"武林至宝啊！！我今生能见此宝一次，死而无憾了，哎~~~只可惜我已经没有能力打磨他了。“\n"NOR,
                                ob, me);
                        ob->delete("busy");
                        return 0;
                }else {
                	message_vision(CYN"$N摇摇头，一副无辜的样子。\n"NOR,ob);
                	return 0;
                }          	                                      	
        }
        else if(obj->query("hole")){
        	message_vision(CYN"$N微笑道：“这件东西已经有凹槽了，不用再打磨了。\n"NOR,ob);
        	return 0;
        }
        else{
        	message_vision(CYN"$N轻蔑地看了看"NOR+obj->name()+CYN"道：这样的东西也拿来丢人显眼。\n"NOR,ob);
        	return 0;
        }
   }
}