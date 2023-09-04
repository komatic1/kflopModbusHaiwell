#include "KMotionDef.h"

// Trigger a message box on the PC to be displayed
// defines for MS Windows message box styles and Operator
// response IDs are defined in the KMotionDef.h file
int MsgBox(char *s, int Flags);
// put the MDI string (Manual Data Input - GCode) in the
// gather buffer and tell the App where it is
int MDI(char *s);
// Put a Float as a parameter and pass the command to the App
int DoPCFloat(int cmd, float f);
// Put an integer as a parameter and pass the command to the App
int DoPCInt(int cmd, int i);
// Pass a command to the PC and wait for it to handshake
// that it was received by either clearing the command
// or changing it to a negative error code
int DoPC(int cmd);

main()
{
    printf("Pallet change started 2 !!!!!!!!\n");
    persist.UserData[35] = 1;

    int Answer;
    double *pD = (double *)persist.UserData;

    DoPC(PC_COMM_ESTOP);
    DoPC(PC_COMM_HALT);
    DoPC(PC_COMM_EXECUTE);
    DoPC(PC_COMM_SINGLE_STEP);
}