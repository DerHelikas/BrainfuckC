#include "ArgumentSetter.h"

Brainfuck_settings CLIargumentFetcher(int argc,  void *argv[])
{
    if(argc < 2)
    {
        printf_s("\n  -| Gave no arguments!");
        exit(-1);
    }

    Brainfuck_settings settings = {0,0,3000,10,0,'\0', ""};
    
    for (int i = 0; i < argc; i++)
    {
        if(strcomp(argv[i], "-ASCII",-1) || strcomp(argv[i], "--A",-1))
            settings.UseASCII = 1;
        
        else if(strcomp(argv[i], "-Space",-1) || strcomp(argv[i], "--s",-1))
            settings.UseSpaces = 1;
        
        else if(strcomp(argv[i], "-File",-1) || strcomp(argv[i], "--f",-1))
            {
                if(i + 1 < argc && isFileExistAndCanBeRead(argv[i + 1]) == 1){
                    settings.ExecFileCode = 'f';
                    settings.ExecuteArg = argv[i + 1];
                }
                else
                {
                    printf_s("\nThe given file can't be read or does not exist.");
                    exit(-1);
                }
            }
        else if(strcomp(argv[i], "-Code",-1) || strcomp(argv[i], "--c",-1))
            {
                if(i + 1 < argc)
                {
                    settings.ExecuteArg = argv[i + 1];
                    settings.ExecFileCode = 'c';
                }

                else
                {
                    printf_s("\nArgument -Code/--c requare a code");
                    exit(-1);
                }
            }
        

        else if(strcomp(argv[i], "--Da",-1)){
            for(int j = 0; j < argc; j++)
            printf_s("\n%s",argv[j]);
        }

        else {
            printf_s("Unknown argument:%s", argv[i]);
        }
    }

    
    if(settings.UseASCII == 1 && settings.UseSpaces == 1)
        settings.TOTAL_OUTPUT_MODE = 3;
    
    else if(settings.UseASCII == 1)
        settings.TOTAL_OUTPUT_MODE = 2;

    else if(settings.UseSpaces == 1)
        settings.TOTAL_OUTPUT_MODE = 1;
    
    else 
        settings.TOTAL_OUTPUT_MODE = 0;
    

    return settings;
}