#include "Node.h"

using namespace std;

Node *listUnion(Node *first, Node *second) {
  //int l1 = first->getNumNodes();
  //int l2 = second->getNumNodes();
  if(first==NULL&&second==NULL){
    return NULL;
  }
  Node *curr1 = new Node();
  if(first!=NULL){
  curr1 = first;
  while(curr1!=NULL){
    Node *st = curr1->next_;
    if(curr1 == st || st->data_ ==0){
      curr1->next_ = curr1->next_->next_;
    }
    curr1 = curr1->next_;
  }
  curr1->next_ = second;}
  curr1 = second;
  while(curr1!=NULL){
    Node *st = curr1->next_;
    if(curr1 == st || st->data_ ==0){
      curr1->next_ = curr1->next_->next_;
    }
    curr1 = curr1->next_;
  }
  return curr1;
  // your code here
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
