#include "KMotionDef.h"

void main()
{
    printf("Thread 7 started !!!!!!!!!!!!!!! \n");
    int i;

    for (i = 0; i <= 199; i++)
    {
        printf("%d-", persist.UserData[i]);
    }
    while (!persist.UserData[35])
    {
        ;
    }

    // for (i = 0; i < 10000; i++)
    // {
    //     ClearBit(47);
    //     Delay_sec(0.2);
    //     SetBit(47);
    //     Delay_sec(0.3);
    // }
}