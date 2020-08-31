#ifndef CTESTA_H
#define CTESTA_H

#include "MyObject.h"

class CTestA: public MyObject
{
public:
    CTestA();
    void metacall(int slotID);

My_signals:
    typedef enum {
        SIGNAL_1,
        SIGNAL_2,
    }SIGNAL_ID;

    void signalTestA1(int signalID);
    void signalTestA2(int signalID);
};

#endif // CTESTA_H
