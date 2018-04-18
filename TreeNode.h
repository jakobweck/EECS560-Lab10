#ifndef BSTN_H
#define BSTN_H

class TreeNode{
public:
  TreeNode(int initVal);
  ~TreeNode();
  TreeNode* left;
  TreeNode* right;
  int val;
};
#endif