#include "stats.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "setjmp.h"

jmp_buf savebuf;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i;
    float sum=0;
    
    if (setlength <= 0)
    {
        longjmp(savebuf,1);
    }
    for(i = 0; i< setlength; i++)
    {
        sum = sum + numberset[i];
    }
    if(setjmp(savebuf) == 0)
    {
        s.average = sum / setlength;
    }
    else
    {
        s.average = NAN;
    }
    s.max = numberset[0];
    s.min = numberset[0];
    for(i = 1; i< setlength; i++)
    {
        if( numberset[i] > s.max)
        {
            s.max = numberset[i];
        }
        if( numberset[i] < s.min)
        {
            s.min = numberset[i];
       }        
    }
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
