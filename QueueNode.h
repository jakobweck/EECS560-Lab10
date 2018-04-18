#ifndef QNODE
#define QNODE
#include "LeftistHeap.h"
class QueueNode{
private:
    LeftistHeap* val;
    QueueNode* next;
public:
    QueueNode();
    QueueNode(LeftistHeap* val, QueueNode* next);
    LeftistHeap* getVal();
    QueueNode* getNext();
    void setNext(QueueNode* newNext);
};

#endif