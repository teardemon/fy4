 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "剑林");
        set("long", @LONG 
此处虽名为林，却只是一方硕大无比的空旷石岩，三面环山，岩石表面被打磨得
十分光滑，乃是白云城弟子朝夕练剑习武之处，白云城主虽为一极其洒脱，鄙夷世俗
之人，但对门下弟子习武要求极严，因此白云城弟子皆刻苦练剑，不敢有丝毫滞惰，
剑林石壁上插满了各式各样断折的长剑，白云城主有谓：剑于剑士，可谓十指于心。
即便断折的废剑，也要妥善处置。此处名为剑林，实为剑冢。
LONG 
           ); 
        set("exits",  
           ([  
       "northwest" : __DIR__"jintaoting",
       "southup" : __DIR__"guajianbei",
       "westdown" : __DIR__"qianlonghu",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/jiannu" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}       
