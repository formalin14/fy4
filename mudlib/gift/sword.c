#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "哈哈" NOR, ({ "haha" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把看黑色的长剑，份量不轻。\n");
                set("timestamp","mdedrnq");
                set("value", 10000);
        	set("rigidity",100);
        	set("level",0);
        	set("apply/damage_type","kee");
        	set("apply/damage",20);
                set("can_inset",1);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword();
}
string query_save_file()
{
	return sprintf(DATA_DIR "questitem/%s", query("timestamp"));
}
int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam,i;
        string p;
        
        p=(string)this_object()->query("apply/damage_type");
        i=(int)this_object()->query("apply/damage");
        if(i)     //如果有伤害
        switch( p ) {
        	case "gin":
        		dam = i*100;
        		victim->receive_damage("gin",dam,me);
        		return this_object()->name()+HIY"身上发出耀眼的光芒，让$n精力疲惫。\n" NOR;
        		break;
        	case "sen":
        		dam = i*100;
        		victim->receive_damage("sen",dam,me);
        		return this_object()->name()+HIW"闪出道道白光，让$n心神不宁。\n" NOR;
        		break;
        	case "kee":
        		dam = i*200;
        		victim->receive_damage("kee",dam,me);
        		return this_object()->name()+HIR"如出水蛟龙，无数幻影刺入$n的身体。\n" NOR;
        		break;
 		default:
 		       	return "";
 		}
 	else return "";
        
} 