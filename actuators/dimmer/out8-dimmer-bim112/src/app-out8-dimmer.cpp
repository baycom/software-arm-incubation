/*
 *  app-out8-dimmer.cpp - An application ABB SD/S 8.16.1 8fold dimmer
 *
 *  Copyright (C) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#include <app-out8-dimmer.h>
#include "config.h"
#include "channel.h"
#include <sblib/eib.h>
#include <sblib/digital_pin.h>
#include <sblib/io_pin_names.h>
#include <sblib/serial.h>


Channel * channels[NO_OF_CHANNELS];

void objectUpdated(int objno)
{
    if (objno >= 13)
    {   // handle the com objects specific to one channel
        unsigned int channel = (objno - 13) / 20;
        Channel * chn = channels [channel];
        if (chn)
            chn->objectUpdate(objno);
    }
    else
    {   // handle global objects
        unsigned char value = objectRead(objno);
        for (unsigned int i = 0; i < NO_OF_CHANNELS; i++)
        {   Channel * chn = channels [i];
        }
    }
}

Timeout t;
int pwmScale=0;

void checkPeriodicFuntions(void)
{
	if(t.started() && t.expired()) {
		pwmScale+=10;
//	    serial.println(pwmScale, HEX, 4);

	    timer16_0.match(MAT0, pwmScale);
	    timer16_0.match(MAT2, pwmScale/2);
	    timer32_0.match(MAT0, pwmScale/3);
	    timer32_0.match(MAT1, pwmScale/4);
	    timer32_0.match(MAT3, pwmScale/5);
	    timer32_1.match(MAT0, pwmScale/6);
	    timer32_1.match(MAT1, pwmScale/7);
	    timer32_1.match(MAT3, pwmScale/8);

		t.start(1);
	}
    for (unsigned int i = 0; i < NO_OF_CHANNELS; i++)
    {
        Channel * chn = channels[i];
        if (chn)
            chn->periodic();
    }

}

void initApplication(void)
{
    unsigned int address = currentVersion->baseAddress;

    timer16_0.begin();
    timer16_0.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO0_8, OUTPUT_MATCH);
    timer16_0.matchMode(MAT0, SET);
    timer16_0.pwmEnable(MAT0);
    timer16_0.match(MAT0, 0x8000);

    pinMode(PIO3_2, OUTPUT_MATCH);  // configure digital pin PIO3_2(PWM) to match MAT2 of timer16 #0
    timer16_0.matchMode(MAT2, SET);  // set the output of PIO3_2 to 1 when the timer matches MAT2
    timer16_0.pwmEnable(MAT2);       // enable PWM for match channel MAT2
    timer16_0.match(MAT2, 0x8000);        // match MAT1 when the timer reaches this value

    timer16_0.start();

    timer32_0.begin();
    timer32_0.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO1_6, OUTPUT_MATCH);
    timer32_0.matchMode(MAT0, SET);
    timer32_0.pwmEnable(MAT0);
    timer32_0.match(MAT0, 0x8000);

    pinMode(PIO1_7, OUTPUT_MATCH);
    timer32_0.matchMode(MAT1, SET);
    timer32_0.pwmEnable(MAT1);
    timer32_0.match(MAT1, 0x8000);

    pinMode(PIO2_8, OUTPUT_MATCH);
    timer32_0.matchMode(MAT3, SET);
    timer32_0.pwmEnable(MAT3);
    timer32_0.match(MAT3, 0x8000);

    timer32_0.matchMode(MAT2, RESET);
    timer32_0.pwmEnable(MAT2);
    timer32_0.match(MAT2, 0x10000);

    timer32_0.start();

    timer32_1.begin();
    timer32_1.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO1_1, OUTPUT_MATCH);
    timer32_1.matchMode(MAT0, SET);
    timer32_1.pwmEnable(MAT0);
    timer32_1.match(MAT0, 0x8000);

    pinMode(PIO1_2, OUTPUT_MATCH);
    timer32_1.matchMode(MAT1, SET);
    timer32_1.pwmEnable(MAT1);
    timer32_1.match(MAT1, 0x8000);

    pinMode(PIO1_4, OUTPUT_MATCH);
    timer32_1.matchMode(MAT3, SET);
    timer32_1.pwmEnable(MAT3);
    timer32_1.match(MAT3, 0x8000);

    timer32_1.matchMode(MAT2, RESET);
    timer32_1.pwmEnable(MAT2);
    timer32_1.match(MAT2, 0x10000);

    timer32_1.start();

    t.start(1);

    #if 0
    for (unsigned int i = 0; i < NO_OF_OUTPUTS; i++)
    {
        digitalWrite(outputPins[i], 0);
        pinMode(outputPins[i], OUTPUT);
    }
    for (unsigned int i = 0; i < NO_OF_CHANNELS; i++, address += EE_CHANNEL_CFG_SIZE)
    {
    }
#endif
}
