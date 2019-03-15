#include "TreeNode.h"

int height(TreeNode* root){
  if (root == NULL) return -1;
  else{
    int left = height(root->left_);
    int right = height(root->right_);
    if (right > left) return right + 1;
    else return left + 1;
  }
}

int getHeightBalance(TreeNode* root) {
  // your code here
  if (root == NULL) return 0;
  else {
    int leftsub = height(root->left_);
    int rightsub = height(root->right_);
    return leftsub - rightsub;
  }
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
  int b = getHeightBalance(root);
  if (b >= -1 && b <= 1){
    return true;
  }
  else return false;
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  if (root == NULL) return NULL;
  else {
    if (isHeightBalanced(root))
      root->balance_ = 1;
    else root->balance_ = 0;
    TreeNode* left = findLastUnbalanced(root->left_);
    TreeNode* right = findLastUnbalanced(root->right_);
    if (left == NULL && right == NULL){
      if (root->balance_ == 1) return NULL;
      else return root;
    }
    else if (left != NULL && right == NULL){
      return left;
    }
    else if (left == NULL && right != NULL){
      return right;
    }
    else {
      if (height(right) < height(left))
        return right;
      else return left;
    }

  }

  return NULL;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
