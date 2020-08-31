#include <stdio.h>
#include <string.h>
#include "CObject.h"

static const char signal_names[] = "signal1\n";
static const char slots_names[] = "slot1\n";
MetaObject CObject::meta = {signal_names, slots_names};

CObject::CObject()
{

}

CObject::~CObject()
{
}

static int find_string(const char *str, const char *substr)
{
    if (strlen(str) < strlen(substr))
        return -1;
    int idx = 0;
    int len = strlen(substr);
    bool start = true;
    const char *pos = str;
    printf("pos=====%s   len=====%d   start===%d\n", pos, len, start);
    while (*pos) {
        printf("pos=====%s   len=====%d  substr======%s"
               "  pos[len]==%d\n", pos, len, substr, (pos[len] == '\n'));
        if (start && !strncmp(pos, substr, len) && pos[len]=='\n')
            return idx;
        start = false;
        if (*pos == '\n') {
            idx++;
            start = true;
        }
        pos++;
    }
    return -1;
}

//将信号和槽的信息存放到字符串中 ==>按顺序排放，所以有了索引值
void CObject::my_connect(CObject* sender, const char* sig, CObject* receiver, const char* slt)
{
    int sig_idx = find_string(sender->meta.signal_names, sig);
    int slt_idx = find_string(receiver->meta.slots_names, slt);
    if (sig_idx == -1 || slt_idx == -1) {
        perror("signal or slot not found!");
    } else {
        Connection c = {receiver, slt_idx};
        sender->connections.insert(std::pair<int, Connection>(sig_idx, c));
    }
}

void CObject::slot1()
{
    printf("exec slot function");
}


void MetaObject::active(CObject* sender, int idx)
{
    ConnectionMapIt it;
    std::pair<ConnectionMapIt, ConnectionMapIt> ret;
    ret = sender->connections.equal_range(idx);
    for (it=ret.first; it!=ret.second; ++it) {
        Connection c = (*it).second;
        c.receiver->metacall(c.method);
    }
}
//信号发射 其实就是 信号函数==> 信号的索引
void CObject::testSignal()
{
    my_emit signal1();
}

void CObject::signal1()
{
    MetaObject::active(this, 0);
}
//metacall 其实就是 槽的索引==> 槽函数
void CObject::metacall(int idx)
{
    switch (idx) {
        case 0:
            slot1();
            break;
        default:
            break;
    };
}

//https://blog.csdn.net/dbzhang800/article/details/6376422
