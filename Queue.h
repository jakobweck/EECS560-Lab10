#ifndef QUEUE
#define QUEUE
#include "LeftistHeap.h"

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
    void enqueue(LeftistHeap* x);
    void dequeue();
    LeftistHeap* peek();

};
#endif