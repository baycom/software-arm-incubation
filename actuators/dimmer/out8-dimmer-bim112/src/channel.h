
#ifndef OUT8_DIMMER_BIM112_SRC_CHANNEL_H_
#define OUT8_DIMMER_BIM112_SRC_CHANNEL_H_

#include <sblib/types.h>
#include <sblib/timeout.h>
#include <sblib/platform.h>
#include <sblib/mem_mapper.h>
#include "config.h"

class Channel
{
public:
    Channel(unsigned int number, unsigned int address);
    void objectUpdate(unsigned int objno);
    void periodic(void);

    int switchState(int state);  // Switch channel on or off
    int startDim(int direction); // Start dimming in a direction
    int pauseDim();              // Pause dimming
    int muteDim();               // Keep counting ramps but prevent pwm output

protected:
    // the following fields store the config for this channel
    unsigned char  busDownAction;
    unsigned char  busReturnAction;
    // the following fields are the current state of the channel
    unsigned char  number;           //!< need to calculate the object numbers
    unsigned int address;
    unsigned char  firstObjNo;       //!< avoid multiple calculations

    int dimVal;
    int dimRunning;
    int dimDirection;
};

#endif /* OUT8_DIMMERL_BIM112_SRC_CHANNEL_H_ */
