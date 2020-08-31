#include "CTestA.h"
#include <QDebug>

CTestA::CTestA()
{

}

void CTestA::metacall(int slotID)
{
    qDebug() << "slotID===========" << slotID;
}

void CTestA::signalTestA1(int signalID)
{
    MetaObject::active(this, signalID);
}

void CTestA::signalTestA2(int signalID)
{
    MetaObject::active(this, signalID);
}
