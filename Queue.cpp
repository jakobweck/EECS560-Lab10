#include "Queue.h"
#include "ConcatHeap.h"
Queue::Queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
}
Queue::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
}
//Add a node to the back of the queue.
void Queue::enqueue(ConcatHeap* x){
    QueueNode* newNode = new QueueNode(x, nullptr);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
    this->count++;
}
//Remove the node at the front of the queue.
void Queue::dequeue(){
    if(!isEmpty()){
        QueueNode* tmp = head;
        head = tmp->getNext();

        delete tmp;
        this->count--;
    }
}
//Get the value at the front of the queue
ConcatHeap* Queue::peek(){
    return head->getVal();
}
//Return whether the queue is empty.
bool Queue::isEmpty(){
    return (this->count == 0);
}