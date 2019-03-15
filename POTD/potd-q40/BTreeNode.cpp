#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {

    // Your Code Here
    BTreeNode* retval;
    int flag=0;
    if(root==NULL){
      return NULL;
    }
    int i = root->elements_.size();
    int counter = 0;
    if(key==root->elements_[0]){
      flag =1;
    }else if(key<root->elements_[0]){
      flag =0;
    }else{
      counter++;
      while(counter<i){
        if(key==root->elements_[counter]){
          flag=1;
          break;
        }
        if(key>root->elements_[counter-1] && key<root->elements_[counter]){
          break;
        }
        counter++;
      }
    }
    if(flag==1){
      flag=0;
      return root;
    }
    if(root->children_.size()==0){return NULL;}else{
      retval = find(root->children_[counter],key);
    }
  return retval;
}
