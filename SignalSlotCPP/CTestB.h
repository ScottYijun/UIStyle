#ifndef CTESTB_H
#define CTESTB_H

#include "MyObject.h"

class CTestB: public MyObject
{
public:
    CTestB();
    void metacall(int slotID);

public My_slots:
    typedef enum {
        SLOT_1,
        SLOT_2,
    } SLOT_ID;

    void slotTestB();
    void slotTestB2();
};

#endif // CTESTB_H
