#ifndef COBJECT_H
#define COBJECT_H

#include <map>
#define my_slots
#define my_signals protected
#define my_emit

class CObject;
struct MetaObject
{
    const char *signal_names;
    const char *slots_names;
    static void active(CObject *sender, int idx);
};

struct Connection
{
    CObject *receiver;
    int method;
};

typedef std::multimap<int, Connection> ConnectionMap;
typedef std::multimap<int, Connection>::iterator ConnectionMapIt;

class CObject
{
    static MetaObject meta;
    void metacall(int idx);

public:
    CObject();
    virtual ~CObject();
    static void my_connect(CObject*, const char*, CObject*, const char*);
    void testSignal();

my_signals:
    void signal1();

public my_slots:
    void slot1();

friend class MetaObject;

private:
     ConnectionMap connections;
};

#endif // COBJECT_H
