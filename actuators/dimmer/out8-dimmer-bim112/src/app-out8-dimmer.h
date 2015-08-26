#ifndef OUT8_DIMMER_BIM112_SRC_APP_OUT8_DIMMER_H_
#define OUT8_DIMMER_BIM112_SRC_APP_OUT8_DIMMER_H_
/*
 *  app-out8-dimmer.cpp - An application ABB SD/S 8.16.1 8fold dimmer
 *
 *  Copyright (C) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#include "channel.h"

extern Channel * channels[NO_OF_CHANNELS];
extern MemMapper memMapper;

/**
 * Called from the main loop whenever a com object has been updated
 * via a group address write
 */
void objectUpdated(int objno);

/**
 * Called during each iteration of the main loop
 */
void checkPeriodicFuntions(void);

/**
 * Called during the initialization of the application
 */
void initApplication(void);

int switchChannel(int channel, int value);
int setChannelPWMRatio(int channel, int pwmScale);


#endif /* OUT8_DIMMER_BIM112_SRC_APP_OUT8-DIMMER_H_ */
