/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    Node *temp = t->right;
    Node *temp2 = temp->left;
    t->right = temp2;
    temp->left = t;
    t = temp;
    t->left->height = max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right)) + 1;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this`)`
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node *temp = t->left;
    Node *temp2 = temp->right;
    t->left = temp2;
    temp->right = t;
    t = temp;
    t->right->height = max(heightOrNeg1(t->right->left), heightOrNeg1(t->right->right)) + 1;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    rotateRight(t->right);
    rotateLeft(t);
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
  if(!subtree){return;}
  int h = heightOrNeg1(subtree->left)-heightOrNeg1(subtree->right);
  if(h>1){
    if(heightOrNeg1(subtree->left->left)>=heightOrNeg1(subtree->left->right)){
      rotateRight(subtree);
    }else{rotateLeftRight(subtree);}
  }else if(h<-1){
    if(heightOrNeg1(subtree->right->left)<=heightOrNeg1(subtree->right->right)){
      rotateLeft(subtree);
    }else{rotateRightLeft(subtree);}

  }

    // your code here
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
  if(!subtree){
    subtree = new Node(key,value);
    return;
  }
  if (key < subtree->key){
       insert(subtree->left, key,value);
     }
   else{
       insert(subtree->right, key,value);
     }

  subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;
  rebalance(subtree);
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
      remove(subtree->left,key);
      rebalance(subtree);
        // your code here
    } else if (key > subtree->key) {
      remove(subtree->right,key);
      rebalance(subtree);
        // your code here
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
          delete subtree;
          subtree = NULL;
            /* no-child remove */
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
          Node* temp = subtree->left;
          while (temp->right != NULL){
            	temp = temp->right;}
          swap(subtree, temp);
          remove(subtree->left, key);
            /* two-child remove */
            // your code here
        } else {
          if(subtree->left==NULL){
            Node *tp = subtree;
            subtree = subtree->right;
            delete tp;
          }else{
            Node *tp = subtree;
            subtree = subtree->left;
            delete tp;
          }
          //Node* temp = (subtree->left) ? subtree->left:subtree->right;
          //*subtree = *temp;
          //free(temp);
          rebalance(subtree);
          }
            /* one-child remove */
            // your code here
        }
        // your code here
    //rebalance(subtree);
}
