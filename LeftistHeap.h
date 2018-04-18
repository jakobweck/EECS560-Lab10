#ifndef LH_H
#define LH_H
#include "ConcatHeap.h"
class LeftistHeap: public ConcatHeap{
public:
  LeftistHeap(int x);
  ~LeftistHeap();
  void recFree();
  ConcatHeap* insert(int x);
  ConcatHeap* buildHeap(int* x, int size);
  ConcatHeap* deleteMin();
  int findMin();
  int rank();
  ConcatHeap* concat(ConcatHeap* h1, ConcatHeap* h2);
  void preorder();
  void postorder();
  void inorder();
  void levelorder();
  int val;
  LeftistHeap* left;
  LeftistHeap* right;
private:
};
#endif
