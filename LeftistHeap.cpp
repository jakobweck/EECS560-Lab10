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
  ConcatHeap* newHeap = new LeftistHeap(x);
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
LeftistHeap* LeftistHeap::concat(ConcatHeap* h1, ConcatHeap* h2){
  LeftistHeap* lh1 = (LeftistHeap*) h1;
  LeftistHeap* lh2 = (LeftistHeap*) h2;
  if (lh1 == nullptr) return lh2;
  if (lh2 == nullptr) return lh1;
  if(lh1->val>lh2->val){
    LeftistHeap* tmp = lh1;
    lh1 = lh2;
    lh2 = tmp;
  }
  LeftistHeap* newRightChild = (LeftistHeap*)concat(lh1->right, lh2);
  lh1->right = newRightChild;
  //adjust rank
  int lRank;
  int rRank;

  if(lh1->left == nullptr){
    lRank = 0;
  }
  else {
    lRank = lh1->left->rank();
  }

  if(lh1->right == nullptr){
    rRank = 0;
  }
  else{
    rRank = lh1->right->rank();
  }

  if(lRank<rRank){
    LeftistHeap* tmp = lh1->right;
    lh1->right = lh1->left;
    lh1->left = tmp;
  }
  return lh1;
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
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;

  while(!q->isEmpty()){
    nodesInCurrentLevel--;
    curr = q->peek();
    std::cout << curr->val << " ";
    if(curr->left != nullptr){
      q->enqueue(curr->left);
      nodesInNextLevel++;
    }
    if(curr->right != nullptr){
      q->enqueue(curr->right);
      nodesInNextLevel++;
    }
    if(nodesInCurrentLevel==0){
      std::cout<<"\n";
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;
    }
    q->dequeue();
  }
  //std::cout <<"\n";
}