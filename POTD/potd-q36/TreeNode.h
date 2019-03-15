#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    int balance_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
    }
};

int getHeight(TreeNode* root);

int getHeightBalance(TreeNode* root);

bool isHeightBalanced(TreeNode* root);

bool isAVL(TreeNode* root);

void deleteTree(TreeNode* root);

#endif
