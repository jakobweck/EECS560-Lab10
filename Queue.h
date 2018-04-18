#ifndef QUEUE
#define QUEUE
#include "ConcatHeap.h"

#include "QueueNode.h"

class Queue{
private:
    QueueNode* head;
    QueueNode* tail;
    int count;
public:
    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(ConcatHeap* x);
    void dequeue();
    ConcatHeap* peek();

};
#endif