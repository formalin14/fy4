 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "平原路"); 
        set("long", @LONG 
大道自北向南，地势渐平。路面铺着小石子，一条条车痕向南方和北方伸展，光 
脚走在上面，觉得颇为硌脚。道两旁的树木越来越少，骄阳似火，令人真想找个地方 
休息一下。 
LONG 
           ); 
        set("exits",  
           ([  
             "north" : __DIR__"woodsroad", 
             "south" : __DIR__"southsearoad", 
         "west" : AREA_CHENXIANG"fydao3",
            ])); 
        set("outdoors", "baiyun"); 
        set("NONPC",1); 
        set("coor/x",10); 
        set("coor/y",-630); 
        set("coor/z",0); 
        setup(); 
} 
 
int valid_leave(object who,string dir) 
{ 
        if(userp(who) && random(3)) 
          { 
           who->move(this_object()); 
           return notify_fail("");  
          } 
        return 1; 
}   
