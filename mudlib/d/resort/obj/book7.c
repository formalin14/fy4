 // An example book
inherit ITEM; 
void create()
{
    set_name("听风辨器秘笈" , ({ "perception book","book" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍听风辨器之术的秘籍。\n");
        set("value", 0);
        set("skill", ([
                "name":                 "perception",      
                "exp_required": 100000,       
                "sen_cost":             35,
                "difficulty":   30,  
                "max_skill":    50     
        ]) );
}
       
