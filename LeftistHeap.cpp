#include "LeftistHeap.h"
#include <iostream>
#include "Queue.h"

LeftistHeap::LeftistHeap(int x){
  this->val = x;
  this->left = nullptr;
  this->right = nullptr;
}

LeftistHeap::~LeftistHeap(){
  //recFree(this);
}
void LeftistHeap::recFree(ConcatHeap* root){
  LeftistHeap* rootLh = (LeftistHeap*) root;
  LeftistHeap* right = rootLh->right;
  LeftistHeap* left = rootLh->left;
  if(right != nullptr) recFree(right);
  if(left != nullptr) recFree(left);
  if (rootLh != nullptr) delete(rootLh);
}

ConcatHeap* LeftistHeap::buildHeap(int* x, int size){
  ConcatHeap* newHeap = new LeftistHeap(x[0]);
  for(int i=1;i<size;i++){
    newHeap = newHeap->insert(x[i]);
  }
  return newHeap;
}
//As evidenced by the type structure here, a single node is trivially a leftist heap
//so we  can just use merge to insert
ConcatHeap* LeftistHeap::insert(int x){
  ConcatHeap* newHeap = new LeftistHeap(x);
  return concat(this, newHeap);
}
//rank represents distance from a leaf node in the extended binary heap
//anything with a null child has a rank of 1
//anything with 2 non-null children has the minimum rank of its children plus one
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
    if(lRank>rRank) return rRank+1;
    return lRank+1;
  }
  return 1;
}
//merge two leftist heaps
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
  //right subtree of new heap will be merged heap of h1's right tree and h2
  LeftistHeap* newRightChild = (LeftistHeap*)concat(lh1->right, lh2);
  lh1->right = newRightChild;

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
  //swap to ensure subtree with max rank is on the left
  if(lRank<rRank){
    LeftistHeap* tmp = lh1->right;
    lh1->right = lh1->left;
    lh1->left = tmp;
  }
  return lh1;
}
//merge by ignoring the root and merging its left and right subtrees into one new tree
ConcatHeap* LeftistHeap::deleteMin(){
  return concat(this->left, this->right);
}
int LeftistHeap::findMin(){
  return this->val;
}

void LeftistHeap::preorder(){
  std::cout << this->val << " ";
  if(this->left != nullptr) this->left->preorder();
  if(this->right != nullptr) this->right->preorder();
}


void LeftistHeap::postorder(){
  if(this->left != nullptr) this->left->postorder();
  if(this->right != nullptr) this->right->postorder();
  std::cout << this->val << " ";

}

void LeftistHeap::inorder(){
  if(this->left != nullptr) this->left->inorder();
  std::cout << this->val << " ";
  if(this->right != nullptr) this->right->inorder();
}

void LeftistHeap::levelorder(){
  Queue* q = new Queue();
  q->enqueue(this);
  LeftistHeap* curr;
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;

  while(!q->isEmpty()){
    nodesInCurrentLevel--;
    curr = (LeftistHeap*)q->peek();
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
  delete(q);
}