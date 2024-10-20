#include "Brainfuck.h"


void CodeBrainFuckWorker(const char * code, Brainfuck_settings BrainfuckDefines);
void FileBrainFuckWorker(const char * filePath, Brainfuck_settings BrainfuckDefines);
int BrainfuckWorker(const char * code, unsigned int codeLength, Brainfuck_settings brs);


int BrainfuckCodeVerifier(const char * code,Brainfuck_settings BrainfuctDefines){
    char * pCode = code;
    unsigned int i =0;
    int  req_ARR_pointerMoves = 0, bracketsZones = 0;
    while(*pCode){

        switch (*pCode)
        {
        case '+':
        case '-':
        case ',':
        case '.':
            break;
        
        case '>':
            req_ARR_pointerMoves++;
            if(req_ARR_pointerMoves > BrainfuctDefines.ARRsize)
            {
                printf_s("\n  Requested Array pointer shifts are greater than defined. Current: %i(Array size: %i) at %i ", req_ARR_pointerMoves,BrainfuctDefines.ARRsize, i);
                return - 1;
            }
        break;

        case '<':
            req_ARR_pointerMoves--;
            if(req_ARR_pointerMoves < 0)
            {
                printf_s("\n  Requested Array pointer shifts are lower than 0(Array size: %i) : %i at %i ",BrainfuctDefines.ARRsize, req_ARR_pointerMoves, i);
                return - 1;
            }
        break;

        case ']':
            if(bracketsZones <= 0)
            {
                printf_s("\n  CRITICAL! Wrong brackets closing. Did you forget to open it? At: %i", i);
                return  - 1;
            }
            bracketsZones--;
        break;

        case '[':
            bracketsZones++;
        break;

        default:
            printf_s("\n      Unexpected symbol %c int:%i has been detected at %i", *pCode, (int)*pCode, i);
            break;
        }

        pCode++;
    }

    if(bracketsZones != 0){
        printf_s("\n  CRITICAL! Some brackers are not closed. Check gave: %i", bracketsZones);
        return -1;
    }
}

void BrainFuckInicReading(int argc,  void *argv[])
{
    struct Brainfuck_settings BrainfuctDefines = CLIargumentFetcher(argc,argv); 
    char * ExecFilePath, *Code;     

    printf_s("\n| BrainFuck C Interpretator %i", BRAINFUCK_INTERPRETATOR_VERSION);
    printf_s("\n  | Use ASCII characters (1 - true/0 - false) - %i", BrainfuctDefines.UseASCII);
    printf_s("\n  | Use Spaces between chars (1 - true/0 - false) - %i", BrainfuctDefines.UseSpaces);


    
    if(BrainfuctDefines.ExecFileCode == 'f')
        FileBrainFuckWorker(BrainfuctDefines.ExecuteArg,BrainfuctDefines);

    else if(BrainfuctDefines.ExecFileCode == 'c')
        CodeBrainFuckWorker(BrainfuctDefines.ExecuteArg,BrainfuctDefines);
    
    else {
        printf_s("\n  -| You gave no file/code to work with");
    }

    printf_s("\n\nBRAINFUCK has done without any exceptions... lucky one");
}

void CodeBrainFuckWorker(const char * code, Brainfuck_settings BrainfuckDefines){
    printf_s("\n  | > Checking code ... It can take some seconds, if this code is big");
    if(BrainfuckCodeVerifier(code,BrainfuckDefines) == -1)
    {
        printf_s("Finished because of an exception");
        exit(-1);
    }

    int codeSize = 0;
    char * p = code; 
    while(*p++)
    codeSize++;

    printf_s("\n\n\nRes:");
    BrainfuckWorker(code,codeSize,BrainfuckDefines);
}

void FileBrainFuckWorker(const char * filePath, Brainfuck_settings BrainfuckDefines){

    FILE * file = fopen(filePath, "r");

    int f_text_size = -1;
    fseek(file,0,SEEK_END); 
    f_text_size = ftell(file);
    fseek(file,0,SEEK_SET);

    char code[f_text_size];
    fgets(code,f_text_size,file);


    printf_s("\n  | > Checking code ... It can take some seconds, if this code is big");
    if(BrainfuckCodeVerifier(code,BrainfuckDefines) == -1)
    {
        printf_s("Finished because of an exception");
        exit(-1);
    }

    printf_s("\n\n\nRes:");
    BrainfuckWorker(code,f_text_size,BrainfuckDefines);
}


int BrainfuckWorker(const char * code, unsigned int codeLength, Brainfuck_settings brs){
    int  ArrI = 0;
    int BracketsDeep = 0;

    int * ARR = malloc(sizeof (int) * brs.ARRsize);
    isAllocated(ARR, "Can't allocate memory for Array");
    memset(ARR, 0, brs.ARRsize);

    
    int * L_brackets_Deep = malloc(sizeof(int) * brs.ZonesDeeep);
    isAllocated(L_brackets_Deep, "Can't allocate memory for Brackets control");
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

                // ASCII
                case 2:
                    printf_s("%c", ARR[ArrI]);
                break;

                // Space + ASCII
                case 3:
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

    free(L_brackets_Deep);
    free(ARR);
    free(code);
}