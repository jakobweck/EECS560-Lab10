#include "QueueNode.h"
#include "LeftistHeap.h"
QueueNode::QueueNode(LeftistHeap* val, QueueNode* next){
    this->val = val;
    this->next = next;
}
LeftistHeap* QueueNode::getVal(){
    return this->val;
}
QueueNode* QueueNode::getNext(){
    return this->next;
}
void QueueNode::setNext(QueueNode* newNext){
    this->next = newNext;
}
