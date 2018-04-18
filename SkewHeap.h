#ifndef SH_H
#define SH_H
#include "ConcatHeap.h"
class SkewHeap: public ConcatHeap{
public:
  SkewHeap(int x);
  ~SkewHeap();
  void recFree(ConcatHeap* root);
  ConcatHeap* insert(int x);
  ConcatHeap* buildHeap(int* x, int size);
  ConcatHeap* deleteMin();
  int findMin();
  int rank();
  SkewHeap* concat(ConcatHeap* h1, ConcatHeap* h2);
  void preorder();
  void postorder();
  void inorder();
  void levelorder();
  int val;
  SkewHeap* left;
  SkewHeap* right;
private:
};
#endif
