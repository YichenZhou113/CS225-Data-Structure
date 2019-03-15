#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {
  TreeNode *temp = root->left_;
  TreeNode *temp2 = temp->right_;
  root->left_ = temp2;
  temp2->parent_ = root;
  temp->right_ = root;
  root = temp;
  root->parent_=NULL;
  root->right_->parent_=root;
    // Your code here

}


void leftRotate(TreeNode* root) {
  TreeNode *temp = root->right_;
  TreeNode *temp2 = temp->left_;
  root->right_ = temp2;
  temp2->parent_ = root;
  temp->left_ = root;
  root = temp;
  root->parent_=NULL;
  root->left_->parent_=root;
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
