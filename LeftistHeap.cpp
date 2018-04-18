#include "LeftistHeap.h"
#include <iostream>
#include "Queue.h"

LeftistHeap::LeftistHeap(int x){
  this->val = x;
  this->left = nullptr;
  this->right = nullptr;
}

LeftistHeap::~LeftistHeap(){
}
void LeftistHeap::recFree(){
}

ConcatHeap* LeftistHeap::buildHeap(int* x, int size){
  ConcatHeap* newHeap = new LeftistHeap(x[0]);
  for(int i=1;i<size;i++){
    newHeap = newHeap->insert(x[i]);
  }
  return newHeap;
}

ConcatHeap* LeftistHeap::insert(int x){
  LeftistHeap* newHeap = new LeftistHeap(x);
  return concat(this, newHeap);
}
int LeftistHeap::rank(){
  if(this->left==nullptr || this->right == nullptr){
    return 1;
  }
  int lRank = this->left->rank();
  int rRank = this->right->rank();
  if (lRank == rRank){
    return (lRank+1);
  }
  else{
    if(lRank>rRank) return rRank;
    return lRank;
  }
  return 1;
}
//this is being called on the weird instance of concatheap that every leftistheap contains
//instead of on the leftistheap itself
//that instance obviously doesn't have its value set
//todo fix this
ConcatHeap* LeftistHeap::concat(ConcatHeap* h1, ConcatHeap* h2){
  if (h1 == nullptr) return h2;
  if (h2 == nullptr) return h1;
  if(h1->val>h2->val){
    ConcatHeap* tmp = h1;
    h1 = h2;
    h2 = tmp;
  }
  ConcatHeap* newRightChild = concat(h1->right, h2);
  h1->right = newRightChild;
  //adjust rank
  int lRank;
  int rRank;

  if(h1->left == nullptr){
    lRank = 0;
  }
  else {
    lRank = h1->left->rank();
  }

  if(h1->right == nullptr){
    rRank = 0;
  }
  else{
    rRank = h1->right->rank();
  }

  if(lRank<rRank){
    ConcatHeap* tmp = h1->right;
    h1->right = h1->left;
    h1->left = tmp;
  }
  return h1;
}

ConcatHeap* LeftistHeap::deleteMin(){
  return concat(this->left, this->right);
}
int LeftistHeap::findMin(){
  return this->val;
}

void LeftistHeap::preorder(){
  std::cout << this->val;
  this->left->preorder();
  this->right->preorder();
}


void LeftistHeap::postorder(){
  this->left->postorder();
  this->right->postorder();
  std::cout << this->val;

}

void LeftistHeap::inorder(){
  this->left->inorder();
  std::cout << this->val;
  this->right->inorder();
}

void LeftistHeap::levelorder(){
  Queue* q = new Queue();
  q->enqueue(this);
  LeftistHeap* curr;
  while(!q->isEmpty()){
    curr = q->peek();
    std::cout << curr->val << " ";
    if(curr->left != nullptr){
      q->enqueue(curr->left);
    }
    if(curr->right != nullptr){
      q->enqueue(curr->right);
    }
    q->dequeue();
  }
  std::cout <<"\n";
}