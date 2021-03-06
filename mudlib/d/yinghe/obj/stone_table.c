 inherit ITEM;
int assign_weapon(string arg, object me);
int move_weapon(string arg, object me);
void create()
{
    set_name("大石桌", ({ "table" , "大石桌", "stone table"}) );
    set_weight(8000000);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("prep", "on");
        set("unit", "个");
        set("long", "一个巨大的石桌，上面排列着刀、剑、枪、锤、斧、鞭、匕首七种
武器的盒子，盒子上宝光四迤，你不由想伸手摸摸看。（ｔｏｕｃｈ）\n");
    }
    ::init_item();
} 
int is_container() { return 1; } 
void init(){
        add_action("do_touch", "touch");
} 
int do_touch(string arg){
        object me, weapon;
        
        me = this_player();
        if(arg == "blade" || arg == "刀" ){
                assign_weapon("blade", me);
        } else if(arg == "sword" || arg == "剑" ){
                assign_weapon("sword", me);
        } else if(arg == "spear" || arg == "枪"){
                assign_weapon("spear", me);
        } else if(arg == "hammer" || arg == "锤" ){
                assign_weapon("hammer", me);
        } else if(arg == "axe" || arg == "斧" ){
                assign_weapon("axe", me);
        } else if(arg == "whip" || arg == "鞭" ){
                assign_weapon("whip", me);
   } else if(arg == "dagger" || arg == "匕首" ){
                assign_weapon("dagger", me);
        } else {
                return notify_fail("你要摸什么？\n");
        }       
        return 1;
} 
int assign_weapon(string arg, object me) {
        object weapon; 
        if(me->query("attribute_mark") == "fire"){
                move_weapon("fire_"+arg, me);
        } else if(me->query("attribute_mark") == "gold"){
                move_weapon("gold_"+arg, me);
        } else if(me->query("attribute_mark") == "wood"){
                move_weapon("wood_"+arg, me);
        } else if(me->query("attribute_mark") == "earth"){
                move_weapon("earth_"+arg, me);
        } else if(me->query("attribute_mark") == "water"){
                move_weapon("water_"+arg, me);
        } else {
                return 0;
        }
        return 1;
} 
int move_weapon(string arg, object me){
        object weapon;
        
        weapon = new(__DIR__+arg);
        if(query("box/"+arg)){
                tell_object(me, "武器盒已经被开了。\n");
                return 1;
        }
        if(objectp(weapon)){
                message_vision("盒子弹开，一个" + weapon->name() + "弹出落入$N怀中。\n", me);
                weapon->move(me);
                set("box/"+arg, 1);
        }
        return 1;               
}    
