#ifndef CHEAP
#define CHEAP

class ConcatHeap{
public:
  ConcatHeap() {};
  virtual ~ConcatHeap() {};
  virtual void recFree() = 0;
  virtual ConcatHeap* insert(int x) = 0;
  virtual ConcatHeap* buildHeap(int* x, int size) = 0;
  virtual ConcatHeap* deleteMin() = 0;
  virtual int findMin() = 0;
  virtual int rank() = 0;
  virtual ConcatHeap* concat(ConcatHeap* h1, ConcatHeap* h2) = 0;
  virtual void preorder() = 0;
  virtual void postorder() = 0;
  virtual void inorder() = 0;
  virtual void levelorder() = 0;
  int val;
  ConcatHeap* left;
  ConcatHeap* right;
private:
};
#endif
