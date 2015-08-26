/*
 *  app_main.cpp - The application's main.
 *
 *  Copyright (c) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#include <config.h>
#include <sblib/eib.h>
#include <sblib/ioports.h>
#include <sblib/io_pin_names.h>
#include "app-out8-dimmer.h"
#include <string.h>
#include <sblib/serial.h>
#include <sblib/mem_mapper.h>
#include <sblib/eib/com_objects.h>

static const char APP_VERSION[] __attribute__((used)) = "8-fold Dimmer 0.0.1";


// Hardware version. Must match the product_serial_number in the VD's table hw_product
const HardwareVersion hardwareVersion[] =
{ {NO_OF_CHANNELS, EE_GLOBAL_CFG, { 0x00, 0x00, 0x40, 0x00, 0x00, 0x00 }, APP_VERSION}
};

const HardwareVersion * currentVersion;

/*
 * Initialize the application.
 */

Timeout timeout;

MemMapper memMapper(0xe000, 0xa00, false);

void setup()
{
#ifdef SERIAL_DEBUG
	serial.setRxPin(PIO3_1);
    serial.setTxPin(PIO3_0);
    serial.begin(115200);
    serial.println("Online\n");
#endif
    memMapper.addRange(0xad00, 0x900);
    memMapper.setEndianess(LITTLE_ENDIAN);
    bcu.setMemMapper(&memMapper);
    objectEndian(LITTLE_ENDIAN);
    bcu.setProgPin(PIO2_11);
    bcu.setProgPinInverted(false);
    bcu.setRxPin(PIO1_8);
    bcu.setTxPin(PIO1_9);

    currentVersion = & hardwareVersion[0];
    bcu.begin(0x0002, 0xa045, 0x0012);
    memcpy(userEeprom.order, currentVersion->hardwareVersion, sizeof(currentVersion->hardwareVersion));
    userEeprom.commsTabAddr = 0x4400;
    userEeprom.modified();

//    pinMode(PIN_INFO, OUTPUT);	// Info LED
//    pinMode(PIN_RUN,  OUTPUT);	// Run LED
    initApplication();
	timeout.start(1);
}

/*
 * The main processing loop.
 */
void loop()
{
    int objno;
    // Handle updated communication objects
    while ((objno = nextUpdatedObject()) >= 0)
    {
        objectUpdated(objno);
    }
    // check the periodic function of the application
    checkPeriodicFuntions();

    // Sleep up to 1 millisecond if there is nothing to do
    if (bus.idle())
        waitForInterrupt();
    if (timeout.started() && timeout.expired())
    {
    	timeout.start(1000);
//    	digitalWrite(PIN_INFO, !digitalRead(PIN_INFO));
    }
}
