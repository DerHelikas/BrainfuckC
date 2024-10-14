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
