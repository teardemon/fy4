 // version.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        string output;
//      write(__VERSION__+"\n");
        output = read_file("/doc/help/version.txt");
        write(output);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
 
这个指令会显示游戏目前所用的MudOS以及MudLIB版本.
 
HELP
    );
    return 1;
}
   
