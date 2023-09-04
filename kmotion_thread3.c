#include "KMotionDef.h"

void main()
{
    printf("Thread 3 started !!!!!!!!!!!!!!! \n");
    double i;
    for (i = 0; i < 10000; i++)
    {
        ClearBit(46);
        Delay_sec(0.2);
        SetBit(46);
        Delay_sec(0.3);
    }
}