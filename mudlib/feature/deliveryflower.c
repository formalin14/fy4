 // This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Nov/2/2001 
#include <ansi.h> 
int flower_delivery_reward(object me, object who) {
        mapping delivery;
        int exp,pot;
        object flower,coin;
        flower = this_object();
        if(!mapp(delivery = flower->query("delivery"))) return 0;
        if(base_name(who) != delivery["receiver"]) return 0;
        
        switch (random(3))
        {
        case 0:
                message_vision("$N兴奋地惊叫一声：“这是他送来的么？ ”\n",who);
                break;
        case 1:
                message_vision("$N甜甜地对$n一笑。\n",who,me);
                break;
        case 2:
                message_vision("$N满面春风，笑意盈盈，拍了拍$n道：“这是给你的，辛苦你了”。\n",who,me );
                coin = new("/obj/money/silver");
                coin->set_amount(random(1000)+100);
                coin->move(me);
                tell_object(me,who->name()+"递给你一些钱。\n");
                break;
        }
        pot = random(500);
        exp = 1000+random(300);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        tell_object(me,"你被奖励了：\n" + chinese_number(exp) + "点实战经验\n"
                        + chinese_number(pot) + "点潜能\n");
        me->delete("delivery");
        me->delete("delivery_time");
        /*
        if(!undefinedp(quest["fin_func"])) {
                call_other(this_object(),quest["fin_func"],me,who,quest_item);
        }*/
   if(flower) {
                destruct(flower);
        }
        return 1;
}  
/*void wither()
{
        if (query("delivery"))
        {
                set("name","枯萎的"+name());
                set("long","这原来是一朵"+query("long")+"不过现在已经枯萎了。\n");
                delete("delivery");
        }
}*/
