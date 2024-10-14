#include "stdio.h"
#include "BrainFuckC_files/Brainfuck.h"


#include <stdio.h>

#define MAX_PATHS_DEEP 200

int main(int argc, void *argv[]){


    // Hello World. (From wiki)
    const char * BrainfuckCode = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.>>>++++++++[<++++>-]<.>>>++++++++++[<+++++++++>-]<---.<<<<.+++.------.--------.>>+.>++++++++++.";
    
    
        /*
            Supports args:
            --ASCII - will out all ints as character by according of ASCII table
            --Space - will out all symbols/ints with spaces between them
            --D[int] (Deep) - will set deep size of brackets "zones" in a prgoram. <Will be removed>
            -f (File) file path argument.
        */ 
        BrainFuckInicReading(argc,argv);

    // {
    //     getchar();
    // }
    return 0;
}