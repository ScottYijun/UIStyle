#include <QCoreApplication>
//#include "CObject.h"
#include "CTestA.h"
#include "CTestB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //CObject obj1, obj2;
    //CObject::my_connect(&obj1, "signal1", &obj2, "slot1");
    //obj1.testSignal();
    CTestA testA;
    CTestB testB;
    MyObject::My_connect(&testA, CTestA::SIGNAL_1, &testB, CTestB::SLOT_1);
    MyObject::My_connect(&testA, CTestA::SIGNAL_2, &testB, CTestB::SLOT_2);
    testA.signalTestA1(CTestA::SIGNAL_1);
    testA.signalTestA1(CTestA::SIGNAL_2);
    return a.exec();
}
