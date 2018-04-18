#include "SkewHeap.h"
#include <iostream>
#include "Queue.h"
//all skewheap methods are mostly the same as leftistheap methods with exception of concat
SkewHeap::SkewHeap(int x){
  this->val = x;
  this->left = nullptr;
  this->right = nullptr;
}

SkewHeap::~SkewHeap(){
}
void SkewHeap::recFree(ConcatHeap* root){
  SkewHeap* rootSh = (SkewHeap*) root;
  SkewHeap* right = rootSh->right;
  SkewHeap* left = rootSh->left;
  if(right != nullptr) recFree(right);
  if(left != nullptr) recFree(left);
  if (rootSh != nullptr) delete(rootSh);
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
//rank is irrelevant for skew heaps and we don't need to calculate it
int SkewHeap::rank(){
  return -1;
}
//similar merge process to leftist heap, but don't worry about rank
//always swap the merged subtree to the left and the unmerged subtree to the right
SkewHeap* SkewHeap::concat(ConcatHeap* h1, ConcatHeap* h2){
  SkewHeap* sh1 = (SkewHeap*) h1;
  SkewHeap* sh2 = (SkewHeap*) h2;
  if (sh1 == nullptr) return sh2;
  if (sh2 == nullptr) return sh1;
  if(sh1->val>sh2->val){
    SkewHeap* tmp = sh1;
    sh1 = sh2;
    sh2 = tmp;
  }
  SkewHeap* newLeftChild = concat(sh1->right, sh2);
  sh1->right = sh1->left;
  sh1->left = newLeftChild;
  return sh1;
}

ConcatHeap* SkewHeap::deleteMin(){
  return concat(this->left, this->right);
}
int SkewHeap::findMin(){
  return this->val;
}

void SkewHeap::preorder(){
  std::cout << this->val << " ";
  if(this->left != nullptr) this->left->preorder();
  if(this->right != nullptr) this->right->preorder();
}


void SkewHeap::postorder(){
  if(this->left != nullptr) this->left->postorder();
  if(this->right != nullptr) this->right->postorder();
  std::cout << this->val << " ";

}

void SkewHeap::inorder(){
  if(this->left != nullptr) this->left->inorder();
  std::cout << this->val << " ";
  if(this->right != nullptr) this->right->inorder();
}

void SkewHeap::levelorder(){
  Queue* q = new Queue();
  q->enqueue(this);
  SkewHeap* curr;
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;

  while(!q->isEmpty()){
    nodesInCurrentLevel--;
    curr = (SkewHeap*) q->peek();
    std::cout << curr->val << " ";
    if(curr->left != nullptr){//std::cout <<"\n";
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
  delete(q);
}