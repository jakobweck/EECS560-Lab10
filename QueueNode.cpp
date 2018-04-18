#include "QueueNode.h"
#include "ConcatHeap.h"
QueueNode::QueueNode(ConcatHeap* val, QueueNode* next){
    this->val = val;
    this->next = next;
}
ConcatHeap* QueueNode::getVal(){
    return this->val;
}
QueueNode* QueueNode::getNext(){
    return this->next;
}
void QueueNode::setNext(QueueNode* newNext){
    this->next = newNext;
}
