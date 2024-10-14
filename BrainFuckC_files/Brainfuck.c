#include "Brainfuck.h"
#include "BrainFuckUtils.h"


void BrainFuckInicReading(int Length, const char *commandsPaths[])
{
    Brainfuck_settings BrainfuctDefines = {0,1,40};
    int  DeepChanged = 0;

    int FileWorking = 0, UseCode = 0; 

    char * ExecFilePath; 

    for (int i = 0; i < Length; i++)
    {
        if(strcomp(commandsPaths[i],"--ASCII", -1))
            BrainfuctDefines.UseASCII = 1;
        
        else if(strcomp(commandsPaths[i],"--Space", -1))
            BrainfuctDefines.UseSpaces = 1;
        
        else if(strcomp(commandsPaths[i],"--D",3))
        {
            if(strlen(commandsPaths[i]) > 4)
            { 
                DeepChanged = 1;
                int digit =  atoi(commandsPaths[i] + 3);
                BrainfuctDefines.ZonesDeeep = digit;
            }
        }

        else if (strcomp(commandsPaths[i],"-f", -1)) 
        {
            if(i + 1 >= Length)
            {
                printf_s("  | -f argument is exist, but no file path has been declared.");
                return;
            }

            // File does exist, flag -r- is available
            if (access(commandsPaths[i+1],F_OK) == 0 && access(commandsPaths[i+1], 3) == 0){
                ExecFilePath = commandsPaths[i+1];
                FileWorking = 1;
            }

            // File does exist, flag -r- is not available
            else if(access(commandsPaths[i+1], 3) != 0){
                printf("The given file does exist, but unable to read");
            }

            // File neither does not exist, neither -r- flag has it
            else{
                printf("The argument -f is not a file or does not exist");
            }
        }
    }

    printf_s("\n| BrainFuck C Interpretator %i", BRAINFUCK_INTERPRETATOR_VERSION);
    printf_s("\n  | Use ASCII characters (1 - true/0 - false) - %i", BrainfuctDefines.UseASCII);
    printf_s("\n  | Use Spaces between chars (1 - true/0 - false) - %i", BrainfuctDefines.UseSpaces);

    if(DeepChanged == 1)
        printf_s("\n  | Use Max deep %i", BrainfuctDefines.ZonesDeeep);
    else
        printf_s("\n  | Use standart deep %i", BrainfuctDefines.ZonesDeeep);

    
    if(FileWorking)
        FileBrainFuckWorker(ExecFilePath,BrainfuctDefines);
    
    printf_s("\n\nBRAINFUCK has done without any exceptions... lucky one");
}



void FileBrainFuckWorker(const char * filePath, Brainfuck_settings BrainfuctDefines){

    FILE * file = fopen(filePath, "r");

    //File checking is skipped. If we're here, then file does exist and can be read.

    if(BrainfuctDefines.UseASCII == 1 && BrainfuctDefines.UseSpaces == 1)
        BrainfuctDefines.TOTAL_OUTPUT_MODE = 2;
    else if(BrainfuctDefines.UseSpaces == 1)
        BrainfuctDefines.TOTAL_OUTPUT_MODE = 1;
    else 
        BrainfuctDefines.TOTAL_OUTPUT_MODE = 0;
    

    int f_text_size = -1;
    fseek(file,0,SEEK_END); 
    f_text_size = ftell(file);
    fseek(file,0,SEEK_SET);

    char code[f_text_size];
    fgets(code,f_text_size,file);


    printf_s("\n\n\nRes:");
    BrainfuckWorker(code,f_text_size,BrainfuctDefines);
}


int BrainfuckWorker(const char * code, unsigned int codeLength, Brainfuck_settings brs){
    int  ARR[BRAINFUCK_ARRAY_SIZE] = {0};
    unsigned int  ArrI = 0;
    int BracketsDeep = 0;

    unsigned int * L_brackets_Deep = malloc(sizeof(unsigned int) * brs.ZonesDeeep);
    memset(L_brackets_Deep,0,brs.ZonesDeeep);




    for (unsigned int CodeI = 0; CodeI < codeLength; CodeI++)
    {
        switch (code[CodeI])
        {
        case '[':
            if(ARR[ArrI] == 0)
                while(code[CodeI] != ']')
                    CodeI++;
            else{
                BracketsDeep++;
                L_brackets_Deep[BracketsDeep] = CodeI; 
            }
            break;

        case ']':

            if(ARR[ArrI] != 0)
            {
                CodeI = L_brackets_Deep[BracketsDeep];
            }
            else 
            {
                BracketsDeep--;
            }

        break;


        case '+':
            ARR[ArrI]++;
        break;

        case '-':
            ARR[ArrI]--;
        break;

        case '>':
            ArrI++;
        break;

        case '<':
            ArrI--;
        break;

        case '.':

            switch (brs.TOTAL_OUTPUT_MODE)
            {
                // Nothing
                case 0:
                    printf_s("%i", ARR[ArrI]);
                break;

                // Spaces
                case 1:
                    printf_s(" %i", ARR[ArrI]);
                break;

                // ASCII + Spaces
                case 2:
                    printf_s(" %c", ARR[ArrI]);
                break;
            }

        break;

        case ',':

            
            printf_s("\n  ::Symbol at %i for number in %i requests a number:", CodeI, ArrI);
            char input_number[50];
            int number = -1;

            fgets(input_number,sizeof input_number,stdin);
            number = atoi(input_number);
            ARR[ArrI] = number;
            printf_s(" Transformed as: %i", ARR[ArrI]);
            
        break;


        
        default:
            break;
        }
    }
    
}