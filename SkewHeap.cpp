#include "SkewHeap.h"
#include <iostream>


SkewHeap::SkewHeap(int x){
  this->val = x;
  this->left = nullptr;
  this->right = nullptr;
}

SkewHeap::~SkewHeap(){
}
void SkewHeap::recFree(){
}

ConcatHeap* SkewHeap::buildHeap(int* x, int size){
  ConcatHeap* newHeap = new SkewHeap(x[0]);
  for(int i=1;i<size;i++){
    newHeap = newHeap->insert(x[i]);
  }
  return newHeap;
}

ConcatHeap* SkewHeap::insert(int x){
  ConcatHeap* newHeap = new SkewHeap(x);
  return concat(this, newHeap);
}
int SkewHeap::rank(){
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
ConcatHeap* SkewHeap::concat(ConcatHeap* h1, ConcatHeap* h2){
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
  int lRank = h1->left->rank();
  int rRank = h1->right->rank();
  if(lRank<rRank){
    ConcatHeap* tmp = h1->right;
    h1->right = h1->left;
    h1->left = tmp;
  }
  return h1;
}

ConcatHeap* SkewHeap::deleteMin(){
  return concat(this->left, this->right);
}
int SkewHeap::findMin(){
  return this->val;
}

void SkewHeap::preorder(){
  std::cout << this->val;
  this->left->preorder();
  this->right->preorder();
}


void SkewHeap::postorder(){
  this->left->postorder();
  this->right->postorder();
  std::cout << this->val;

}

void SkewHeap::inorder(){
  this->left->inorder();
  std::cout << this->val;
  this->right->inorder();
}

void SkewHeap::levelorder(){

}