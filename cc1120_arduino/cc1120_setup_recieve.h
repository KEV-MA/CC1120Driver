#ifndef SETUP_RECIEVE_CC1120_H
#define SETUP_RECIEVE_CC1120_H

#include <stdbool.h>

bool setRXFilterBandwidth(int RXFilterBandwidth);
bool getRXFilterBandwidth(int *RXFilterBandwidth);
bool setAGCReference(int RSSIOffset);

#endif /* SETUP_RECIEVE_CC1120_H */
