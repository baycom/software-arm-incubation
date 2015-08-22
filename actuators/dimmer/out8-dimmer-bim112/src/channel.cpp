/*
 *  Copyright (c) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#include "config.h"
#include "channel.h"
#include <sblib/digital_pin.h>
#include <sblib/io_pin_names.h>
#include <sblib/timer.h>
#include <sblib/eib.h>
#include <string.h>


const int outputPins[NO_OF_OUTPUTS] =
    { PIN_IO1, PIN_IO2, PIN_IO3, PIN_IO4, PIN_IO5, PIN_IO6, PIN_IO7, PIN_IO8 };

Channel::Channel(unsigned int number, unsigned int address)
  : number(number)
  , firstObjNo(13 + number * 20)
{
    for (unsigned int i = number * 2 ;i <= (number * 2 + 1); i++)
    {
        pinMode(outputPins [i], OUTPUT);
        digitalWrite(outputPins [i], 0);
    }

//    busDownAction   = userEeprom.getUInt8 (baseAddr + 0x00 + 2 * number);
//    busReturnAction = userEeprom.getUInt8 (baseAddr + 0x01 + 2 * number);
}

void Channel::objectUpdate(unsigned int objno)
{
    unsigned int fct = objno - firstObjNo;
    unsigned int value = objectRead(objno);
    switch (fct)
    {
    default:
        break;
    }
}

