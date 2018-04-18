#ifndef QNODE
#define QNODE
#include "ConcatHeap.h"
class QueueNode{
private:
    ConcatHeap* val;
    QueueNode* next;
public:
    QueueNode();
    QueueNode(ConcatHeap* val, QueueNode* next);
    ConcatHeap* getVal();
    QueueNode* getNext();
    void setNext(QueueNode* newNext);
};

#endif