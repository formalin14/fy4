#include <ansi.h>
 inherit ROOM;
string tree();
void create()
{
        set("short", HIG"��ľ��"NOR);
        set("long", 
"������խ�Ĺ�ľ�ԣ���ǰͻȻ��Ŀ��������㶨��һ����ԭ������������
������ֵ�С�����͸�������Ļ��ݣ���������ֵ��ǣ���֪��������һ������
����Ʈ����ıǿס�\n\n"
        );
    set("exits", ([ 
            "west" : __DIR__"xiaolang_xiaodao2",
        ]));
    set("objects", ([
//                __DIR__"obj/tree" : 1,
    ]));
    set("item_desc", ([
                "tree" : (: tree :),
                "С��" : (: tree :),
        ]));   
    set("zhuguo", 1);
    set("indoors", "residence"); 
    set("coor/x",16);
    set("coor/y",2032);
    set("coor/z",30);
        setup();
} 
string tree(){
        object me;
        int i;
        me = this_player();
   i = NATURE_D->get_season();
        if(i == 1 || i == 2){
                if( query("zhuguo")>0 ){
                tell_object(me, HIG"��Ȼ�Ǵ��ļ��ڣ�������ֵ������С���ϳ���һ�������쳣��"NOR+RED"��ɫ��ʵ"NOR+HIG"������ȥ�ƺ�����ժ(pick)������\n"NOR);
                add_action("do_pick", "pick");
                												} else tell_object(me, "�����С��ɢ����һ���������ζ��\n");
       										 } else if(i == 3 || i == 4){
                if(query("zhuguo") > 0) {
                        tell_object(me, HIG"�ﶬ���ڣ���Ȼ�����������˵�"NOR+RED"��ɫ��ʵ"NOR+HIG"����С����,�ƺ�����ժ(pick)������\n"NOR);
                   			add_action("do_pick", "pick");
                												} else tell_object(me, HIG "�����С��ɢ����һ���������ζ��\n"NOR);
        														} 
        return "";
} 
int do_pick(string arg){
        object me, obj;
        me = this_player();
        if(!arg || (arg != "zhuguo" && arg != "��ɫ��ʵ" && arg != "���")){
                return 0;
        }
 
        if(query("zhuguo") > 0 && (arg == "zhuguo" || arg == "��ɫ��ʵ" || arg == "���")) {
                message_vision("$Nժ����һ�ź�ɫ�Ĺ�ʵ��Ȼ��Ͻ��������뻳�\n", me);
												obj = new("/d/wolfmount/npc/obj/zhuguo");
                if(objectp(obj)){
                        obj->move(me);
                }
                add("zhuguo", -1);
        }
        return 1;
} 

void reset(){
        ::reset();
        set("zhuguo", 1);
}     