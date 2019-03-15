#include "TreeNode.h"

int getHeight(TreeNode* p){
  if (!p) return 0;
  int left_height = getHeight(p->left_);
  int right_height = getHeight(p->right_);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}


int getHeightBalance(TreeNode* root) {
  if(root==NULL){return -1;}

  int left = getHeight(root->left_);
  int right = getHeight(root->right_);

  // your code here
  return left-right;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
