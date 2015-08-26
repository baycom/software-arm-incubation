/*
 *  Copyright (c) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#include "config.h"
#include "channel.h"
#include "app-out8-dimmer.h"
#include <sblib/digital_pin.h>
#include <sblib/io_pin_names.h>
#include <sblib/timer.h>
#include <sblib/eib.h>
#include <string.h>

Channel::Channel(unsigned int number, unsigned int address)
  : number(number), address(address), firstObjNo(10 + number * 25)
{
//    busDownAction   = userEeprom.getUInt8 (baseAddr + 0x00 + 2 * number);
//    busReturnAction = userEeprom.getUInt8 (baseAddr + 0x01 + 2 * number);
}

void Channel::objectUpdate(unsigned int objno)
{
    unsigned int fct = objno - firstObjNo;
    unsigned int value = objectRead(objno);
    dimVal+=value;
    switch (fct)
    {
    case COMObj_CH_Switch_Status:break;
    case COMOBj_CH_Status:break;
    case COMOBj_CH_Relative_Dimming:break;
    case COMOBj_CH_Brightness_Value:break;
    case COMOBj_CH_Status_Brightness_Value :break;
    case COMOBj_CH_Rel_Dimming_Speed:break;
    case COMOBj_CH_Forced_Operation:break;
    case COMOBj_CH_Call_Preset_1_And_2:break;
    case COMOBj_CH_Set_Preset_1_And_2:break;
    case COMOBj_CH_Call_Preset_3_And_4:break;
    case COMOBj_CH_Set_Preset_3_And_4:break;
    case COMOBj_CH_8_Bit_Scene:break;
    case COMOBj_CH_Restore_Standard_Scene:break;
    case COMOBj_CH_Block:break;
    case COMOBj_CH_Activate_Staircase_Function:break;
    case COMOBj_CH_Permanent_ON:break;
    case COMOBj_CH_Duration_Of_Staircase_Lighting:break;
    case COMOBj_CH_Warning_Staircase_Lighting:break;
    case COMOBj_CH_Statusbyte:break;
    default:
        break;
    }
}

int Channel::startDim(int direction)
{

	return 0;
}

int Channel::pauseDim(void)
{

	return 0;
}

void Channel::periodic(void)
{
//	if(dimRunning) {
	int anzahlXYPaare = memMapper.getUInt8(Anzahl_XY_Paare);
	int relDimmzeit = memMapper.getUInt16(P_relDimmenDimmzeit + address);


//	}

}
