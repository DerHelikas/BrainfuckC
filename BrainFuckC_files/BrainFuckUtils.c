#include "BrainFuckUtils.h"

int strcomp(const char *A, const char *B, int StopAt)
{
       int Amtc = 0, Bmtc = 0, Itr = 0;

    if(StopAt <= -1){
        while((int)*A == (int)*B)
        {
            A++;B++;
            if(*A == '\0' && *B == '\0')
                return 1;
        }
        return 0;
    }
    else{
        
        while(((int)*A == (int)*B))
        {
            A++;B++;
            if(*A == '\0' && *B == '\0')
                return 1;

            if(Itr == StopAt - 1)
                return 1;

            Itr++;            
        }
        return 0;
    }
}

int isAllocated(void *pointer, const char *messageIfnot)
{
    if(pointer == NULL){
        printf_s(messageIfnot);
        exit(-1);
    }
}

int isFileExistAndCanBeRead(const char *path)
{
    int fileState = access(path,3);

    switch (fileState)
    {
        case EACCES:
        return 0;

        case ENOENT:
        return 0;

        case -1:
        return 0;
    }

    return 1;
}
