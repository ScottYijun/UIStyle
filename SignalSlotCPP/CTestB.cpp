#include "CTestB.h"
#include <QDebug>

CTestB::CTestB()
{

}

void CTestB::metacall(int slotID)
{
    switch (slotID) {
        case SLOT_1:
            slotTestB();
            break;
        case SLOT_2:
            slotTestB2();
            break;
        default:
            break;
    }
}

void CTestB::slotTestB()
{
    qDebug() << "exec slotTestB==========";
}

void CTestB::slotTestB2()
{
    qDebug() << "exec slotTestB2==========2";
}
