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

#define PWM_RATIO_INVALID_VALUE -1
#define PWM_RATIO_INVALID_CHANNEL -2
#define SWITCH_INVALID_CHANNEL -3

const int outputPins[NO_OF_CHANNELS] =
    { PIO2_5, PIO3_5, PIO0_7, PIO2_9, PIO1_11, PIO1_5, PIO2_7, PIO2_6 };

Timeout msTimeout;
Timeout inBetriebTimeout;

unsigned int inBetrieb;
unsigned int inBetriebValue_0;
unsigned int inBetriebZeit;


int switchChannel(int channel, int value)
{
	if(channel < 0 || channel > NO_OF_CHANNELS) {
		return SWITCH_INVALID_CHANNEL;
	}
	digitalWrite(outputPins[channel], value);
	return 0;
}

inline void setupPWM(void)
{
    timer16_0.begin();
    timer16_0.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO0_8, OUTPUT_MATCH);
    timer16_0.matchMode(MAT0, CLEAR);
    timer16_0.pwmDisable(MAT0);
    timer16_0.match(MAT0, 0xffff);

    pinMode(PIO3_2, OUTPUT_MATCH);
    timer16_0.matchMode(MAT2, CLEAR);
    timer16_0.pwmDisable(MAT2);
    timer16_0.match(MAT2, 0xffff);

    timer16_0.matchMode(MAT3, RESET);
    timer16_0.match(MAT3, 0xffff);

    timer16_0.start();

    timer32_0.begin();
    timer32_0.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO1_6, OUTPUT_MATCH);
    timer32_0.matchMode(MAT0, CLEAR);
    timer32_0.pwmDisable(MAT0);
    timer32_0.match(MAT0, 0xffff);

    pinMode(PIO1_7, OUTPUT_MATCH);
    timer32_0.matchMode(MAT1, CLEAR);
    timer32_0.pwmDisable(MAT1);
    timer32_0.match(MAT1, 0xffff);

    pinMode(PIO2_8, OUTPUT_MATCH);
    timer32_0.matchMode(MAT3, CLEAR);
    timer32_0.pwmDisable(MAT3);
    timer32_0.match(MAT3, 0xffff);

    timer32_0.matchMode(MAT2, RESET);
    timer32_0.pwmDisable(MAT2);
    timer32_0.match(MAT2, 0xffff);

    timer32_0.start();

    timer32_1.begin();
    timer32_1.prescaler((SystemCoreClock / 10000000) - 1);

    pinMode(PIO1_1, OUTPUT_MATCH);
    timer32_1.matchMode(MAT0, CLEAR);
    timer32_1.pwmDisable(MAT0);
    timer32_1.match(MAT0, 0xffff);

    pinMode(PIO1_2, OUTPUT_MATCH);
    timer32_1.matchMode(MAT1, CLEAR);
    timer32_1.pwmDisable(MAT1);
    timer32_1.match(MAT1, 0xffff);

    pinMode(PIO1_4, OUTPUT_MATCH);
    timer32_1.matchMode(MAT3, CLEAR);
    timer32_1.pwmDisable(MAT3);
    timer32_1.match(MAT3, 0xffff);

    timer32_1.matchMode(MAT2, RESET);
    timer32_1.pwmDisable(MAT2);
    timer32_1.match(MAT2, 0xffff);

    timer32_1.start();
}

int setChannelPWMRatio(int channel, int pwmScale)
{
	if (pwmScale < 0 || pwmScale > 0xffff) {
		return PWM_RATIO_INVALID_VALUE;
	}

	pwmScale = 0xffff - pwmScale;

	switch(channel) {
	case 0:
		if(pwmScale == 0xffff) {
		    timer32_1.pwmDisable(MAT3);
		} else {
		    timer32_1.pwmEnable(MAT3);
		}
		timer32_1.match(MAT3, pwmScale);
		break;
	case 1:
		if(pwmScale == 0xffff) {
		    timer32_1.pwmDisable(MAT1);
		} else {
		    timer32_1.pwmEnable(MAT1);
		}
		timer32_1.match(MAT1, pwmScale);
		break;
	case 2:
		if(pwmScale == 0xffff) {
		    timer32_1.pwmDisable(MAT0);
		} else {
		    timer32_1.pwmEnable(MAT0);
		}
		timer32_1.match(MAT0, pwmScale); break;
	case 3:
		if(pwmScale == 0xffff) {
		    timer32_0.pwmDisable(MAT1);
		} else {
		    timer32_0.pwmEnable(MAT1);
		}
		timer32_0.match(MAT1, pwmScale);break;
	case 4:
		if(pwmScale == 0xffff) {
		    timer32_0.pwmDisable(MAT0);
		} else {
		    timer32_0.pwmEnable(MAT0);
		}
		timer32_0.match(MAT0, pwmScale);break;
	case 5:
		if(pwmScale == 0xffff) {
		    timer16_0.pwmDisable(MAT2);
		} else {
		    timer16_0.pwmEnable(MAT2);
		}
		timer16_0.match(MAT2, pwmScale);break;
	case 6:
		if(pwmScale == 0xffff) {
		    timer32_0.pwmDisable(MAT3);
		} else {
		    timer32_0.pwmEnable(MAT3);
		}
		timer32_0.match(MAT3, pwmScale);break;
	case 7:
		if(pwmScale == 0xffff) {
		    timer16_0.pwmDisable(MAT0);
		} else {
		    timer16_0.pwmEnable(MAT0);
		}
		timer16_0.match(MAT0, pwmScale);break;
	default:
		return PWM_RATIO_INVALID_CHANNEL;
	}
	return 0;
}

void objectUpdated(int objno)
{
    if (objno >= 10)
    {   // handle the com objects specific to one channel
        unsigned int channel = (objno - 10) / 25;
        Channel * chn = channels [channel];
        if (chn)
            chn->objectUpdate(objno);
    }
}

int pwm=0;
Timeout timeoutTest;

void checkPeriodicFuntions(void)
{
	if(msTimeout.started() && msTimeout.expired()) {
		msTimeout.start(1);
		for (unsigned int i = 0; i < NO_OF_CHANNELS; i++)
		{
//			setChannelPWMRatio(i, pwm&0xffff);
//			pwm+=1;
			Channel * chn = channels[i];
			if (chn)
				chn->periodic();
		}
		memMapper.doFlash();
	}
	if(inBetriebTimeout.started() && inBetriebTimeout.expired()) {
		inBetriebTimeout.start(inBetriebZeit*1000);
		objectWrite(COMObj_In_Operation, inBetriebValue_0);
	}
	if(timeoutTest.started() && timeoutTest.expired()) {
		timeoutTest.start(1000);
//		objectWrite(209, inBetriebValue_0);
	}
}

void initApplication(void)
{
    unsigned int address = currentVersion->baseAddress;
    setupPWM();

    for (unsigned int i = 0; i < NO_OF_CHANNELS; i++)
    {
        digitalWrite(outputPins[i], 0);
        pinMode(outputPins[i], OUTPUT);
        channels[i] = new Channel(i, address+16+i*256);
    }

    unsigned int initZeit = memMapper.getUInt8(P_InitZeit + address);
    Timeout startupDelay;
    if (initZeit)
    {
        startupDelay.start(initZeit);
        while (!startupDelay.expired())
        {
            waitForInterrupt();
        }
    }

/*  no yet used
    unsigned int telegrUnbegr = memMapper.getUInt8(PD_TelegrUnbegr + address);
    unsigned int telegrUebZeit = memMapper.getUInt16(P_TelegrUebZeit + address);
*/

    inBetrieb = memMapper.getUInt8(P_InBetrieb + address);
    inBetriebValue_0 = memMapper.getUInt8(P_InBetriebValue_0 + address);
    inBetriebZeit = memMapper.getUInt16(P_InBetriebZeit + address);

    if(inBetrieb != 255) {
    	inBetriebTimeout.start(1);
    }

    unsigned int einerFuerAlle = memMapper.getUInt8(t_EinerFuerAlle + address);

    msTimeout.start(1);
    timeoutTest.start(1);
}
