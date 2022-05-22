#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i,sum=0;
    for(i = 0; i< setlength; i++)
    {
        sum = sum + numberset[i];
    }
    s.average = sum / setlength;
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
