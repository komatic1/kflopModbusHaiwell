#include "KMotionDef.h"

void main() 
{
	int i;
	for (i=0; i<100; i++)
	{
        // Output IO bit status to console
		printf("IObit(0-7) %d-%d-%d-%d-%d-%d-%d-%d ", 
			ReadBit(0),ReadBit(1),ReadBit(2),ReadBit(3),
            ReadBit(4),ReadBit(5),ReadBit(6),ReadBit(7)
            );
		printf("-IObit (36-44) %d-%d-%d-%d-%d-%d-%d-%d\n", 
			ReadBit(36),ReadBit(37),ReadBit(38),ReadBit(39),
            ReadBit(40),ReadBit(41),ReadBit(42),ReadBit(43)
            );

		// just for delay
		ClearBit(46);
		Delay_sec(0.1);
		SetBit(46);
		Delay_sec(0.1);
	}
}