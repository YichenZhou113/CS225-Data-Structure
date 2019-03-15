#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  Node* curr1 = first;
  Node* curr2 = second;

  while(curr1!=NULL){
    if(curr2==NULL){
        break;
    }
    Node* st1 = curr1->next_;
    Node* st2 = curr2->next_;
    curr1->next_ = curr2;
    curr1 = st1;
    curr2->next_ = curr1;
    curr2 = st2;
  }
  // your code here!
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
