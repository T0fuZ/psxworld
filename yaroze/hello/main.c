#include <libps.h>
#include "pad.h"

#define PACKETMAX       (10000)
#define PACKETMAX2      (PACKETMAX*24)
#define OT_LENGTH       (14)      
GsOT        WorldOrderingTable[2];
GsOT_TAG    zSortTable[2][1<<OT_LENGTH];   
PACKET      GpuOutputPacket[2][PACKETMAX2];

int main (void)
{
    u_long PadStatus = 0;
    int outputBufferIndex;
                        
    SetVideoMode( MODE_PAL );

    ResetGraph(0);
    GsInitGraph(320 ,240, GsOFSGPU|GsNONINTER, 1, 0);           
    GsDefDispBuff(0, 0, 0, 256);
    FntLoad(960, 256);  
    FntOpen(32, 32, 256, 200, 0, 512);
    PadInit();
    WorldOrderingTable[0].length = OT_LENGTH;
    WorldOrderingTable[1].length = OT_LENGTH;
    WorldOrderingTable[0].org = zSortTable[0];
    WorldOrderingTable[1].org = zSortTable[1];

    for (;;)
    {
        PadStatus = PadRead();
        if (PadStatus & PADselect)
            break;
        outputBufferIndex = GsGetActiveBuff();
        GsSetWorkBase( (PACKET*)GpuOutputPacket[outputBufferIndex]);
        GsClearOt(0, 0, &WorldOrderingTable[outputBufferIndex]);
        DrawSync(0);
        VSync(0);
        GsSwapDispBuff();
        GsSortClear(0x0, 0x0, 0x0,
            &WorldOrderingTable[outputBufferIndex]);
        GsDrawOt(&WorldOrderingTable[outputBufferIndex]);
        FntPrint("Net Yaroze!\n");
        FntFlush(-1);
    }
    ResetGraph(3);
    return 0;
}