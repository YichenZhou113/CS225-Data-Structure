#include "TreeNode.h"
#include <cmath>

int getHeight(TreeNode* p){
  if (!p) return 0;
  int left_height = getHeight(p->left_);
  int right_height = getHeight(p->right_);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}


int getHeightBalance(TreeNode* root) {
  if(root==NULL){return 0;}

  int left = getHeight(root->left_);
  int right = getHeight(root->right_);

  // your code here
  return left-right;
}

bool isHeightBalanced(TreeNode* root) {
  if(root==NULL) return true;

  bool u = true;
  int b = getHeightBalance(root);
  if(b<=1 && b>=-1){return true;}else{return false;}
  u = u&&isHeightBalanced(root->left_);
  u = u&&isHeightBalanced(root->right_);
  return u;

  // your code here

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
