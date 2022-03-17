//=====================================================
// le_io.c
// M-Code hardware input/output functions
//
// Lilith M-Code Emulator
//
// Guido Hoss, 12.03.2022
//
// Published by Guido Hoss under GNU Public License V3.
//=====================================================

#include "le_mach.h"
#include "le_io.h"


// le_ioread()
// Read word from hardware channel
//
uint16_t le_ioread(uint16_t chan)
{
    error(1, 0, "READ not implemented (%d)", chan);
}


// le_iowrite()
// Write word to hardware channel
//
void le_iowrite(uint16_t chan, uint16_t w)
{
    error(1, 0, "WRITE not implemented (%d,%d)", chan, w);
}