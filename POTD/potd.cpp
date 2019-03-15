#include "potd.h"
#include <iostream>

using namespace std;


void insertSorted(Node **head, Node *item) {
  Node* myhead = *head;
  if (myhead == NULL)
  {
    *head = item;
    return;
  }else if (myhead->data_ > item->data_)
  {
    item->next_ = myhead;
    *head = item;
    return;
  }
  for (int i = 0; myhead->next_ != NULL; i++, myhead= myhead->next_)
  {
    if (myhead->next_->data_>item->data_)
    {
      item->next_ = myhead->next_;
      myhead->next_ = item;
      return;
    }
  }
  myhead->next_ = item;
  item->next_ = NULL;

}
