#include "MyObject.h"
#include <QDebug>

void MetaObject::active(MyObject *sender, int idx)
{
    //qDebug() << "idx=================" << idx;
    Connection c = sender->connections[idx];
    c.receiver->metacall(c.slotID);
}

MyObject::MyObject()
{

}

MyObject::~MyObject()
{

}

void MyObject::My_connect(MyObject *sender, int signalID, MyObject *receiver, int slotID)
{
    Connection c = {receiver, slotID};
    sender->connections.insert(std::pair<int, Connection>(signalID, c));
}


