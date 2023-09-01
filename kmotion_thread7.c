#include "KMotionDef.h"

void main()
{
    printf("Thread 7 started !!!!!!!!!!!!!!! \n");
    double i;
    for (i = 0; i < 10000; i++)
    {
        ClearBit(47);
        Delay_sec(0.2);
        SetBit(47);
        Delay_sec(0.3);
    }
}