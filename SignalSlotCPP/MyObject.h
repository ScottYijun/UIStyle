#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <map>
#define My_slots
#define My_signals public
#define My_emit

class MyObject;
struct MetaObject
{
    static void active(MyObject *sender, int idx);
};

struct Connection
{
    MyObject *receiver;
    int slotID;
};

typedef std::map<int, Connection> ConnectionMap;


class MyObject
{
public:
    MyObject();
    virtual ~MyObject();
    static void My_connect(MyObject *sender, int signalID, MyObject *receiver, int slotID);

protected:
    virtual void metacall(int slotID) = 0;

private:
    ConnectionMap connections;
    friend class MetaObject;//����һ��Ҫ��friend����Ȼactive()�ﲻ��ʹ�ö���
    static MetaObject meta;
};

#endif // MYOBJECT_H
