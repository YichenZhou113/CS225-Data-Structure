#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  Node * cn = first;
  Node * ckn = second;
  Node * itc = new Node();
  itc->next_ = NULL;
  Node * head = itc;
  Node *ret = NULL;
  while(ckn!=NULL){
    cn = first;
    while(cn!=NULL){
      if(ckn->data_ == cn->data_){
        itc->next_ = new Node();
        itc->data_ = cn->data_;
        itc->next_ = NULL;
        itc = itc->next_;
      }
      cn = cn->next_;
    }
    ckn = ckn->next_;
  }
  ret = head->next_;
  delete head;
  head = NULL;
  return ret;
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
