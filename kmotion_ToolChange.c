#include "\include\KMotionDef.h"
#include "\include\KflopToKMotionCNCFunctions.c"

#define TMP 10 // which spare persist to use to transfer data
#define AXISA 3
#define TOOL_VAR 9 // Tool changer desired new tool Var
// Tool changer Last tool loaded is saved globally in this Var
#define LAST_TOOL_VAR 8 //  -1=Spindle empty, 0=unknown, 1-80 Tool Slot loaded into Spindle
#define TOOL_DISK_FILE "e:\\cncmachines\\kflopModbusHaiwell\\ToolChangerData.txt"

#define CNT_PER_DEGREE_A 1000.0

// function prototypes
int DoToolChange(int ToolSlot);
int GetCurrentTool(int *tool);
int SaveCurrentTool(int tool);
BOOL ToolNumberValid(int tool);
int UnloadTool(int CurrentTool);
int LoadNewTool(int CurrentTool, int Tool);

//-----------------------------------------
//      Rotary TOOL CHANGING
//-----------------------------------------

main()
{
    printf("kmotion_ToolChange.c started  !!!!!!!!\n");
    // int slot = persist.UserData[9];   // value stored is an int
    // int id = persist.UserData[9 + 1]; // value stored is an int
    // printf("Tool Set to slot %d id %d\n", slot, id); // print the slot and id

    int ToolSlot = persist.UserData[TOOL_VAR]; // Requested tool to load (value stored an integer)

    if (DoToolChange(ToolSlot)) // perform Tool Change
    {
        // error, Halt Job
        DoPC(PC_COMM_HALT);
    }
}

// Perform Tool Change.  Return 0=Success, 1=Failure
int DoToolChange(int ToolSlot)
{
    int CurrentTool;

    if (GetCurrentTool(&CurrentTool))
        return 1; //  -1=Spindle empty, 0=unknown, 1-4 Tool Slot loaded into Spindle

    printf("Load Tool Slot %d requested, Current Tool %d\n", ToolSlot, CurrentTool);

    if (!ToolNumberValid(ToolSlot)) // check if invalid
    {
        char s[80];
        sprintf(s, "Invalid Tool Change Number %d\n", ToolSlot);
        printf(s);
        MsgBox(s, MB_ICONHAND | MB_OK);
        return 1;
    }

    // load requested tool
    if (LoadNewTool(CurrentTool, ToolSlot))
        return 1;

    SaveCurrentTool(ToolSlot); // save the one that has been loaded
    return 0;                  // success
}
