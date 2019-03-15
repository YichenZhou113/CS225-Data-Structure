#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
using namespace std;

class Stack {
public:
  Stack();
  int *arr;
  int size_;
  int index_;
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
private:



};

#endif
