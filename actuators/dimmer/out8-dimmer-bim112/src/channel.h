
#ifndef OUT8_DIMMER_BIM112_SRC_CHANNEL_H_
#define OUT8_DIMMER_BIM112_SRC_CHANNEL_H_

#include <sblib/types.h>
#include <sblib/timeout.h>

#define NO_OF_CHANNELS 8
#define NO_OF_OUTPUTS  (NO_OF_CHANNELS * 2)
#define EE_CHANNEL_CFG_SIZE 256

extern const int outputPins[NO_OF_OUTPUTS];

class Channel
{
public:
    Channel(unsigned int number, unsigned int address);

    unsigned int isRunning(void);
    virtual void objectUpdate(unsigned int objno);
    virtual void periodic(void);

protected:

    // the following fields store the config for this channel
    unsigned char  busDownAction;
    unsigned char  busReturnAction;
    // the following fields are the current state of the channel
    unsigned char  number;           //!< need to calculate the object numbers
    unsigned char  firstObjNo;       //!< avoid multiple calculations
};

#endif /* OUT8_DIMMERL_BIM112_SRC_CHANNEL_H_ */
