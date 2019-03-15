#include "Stack.h"
#include <iostream>
using namespace std;
// `int size()` - returns the number of elements in the stack (0 if empty)
Stack::Stack(){
cout<<'l'<<endl;
int *arr;
size_ = 0;
index_ = -1;
}

int Stack::size() const {

  return size_;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  if(size_==0){return true;}else{return false;}
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  if(index_==0){index_ --;}
  cout<<index_<<endl;
  index_ = index_+1;

   arr[index_] = value;
   cout<<index_<<endl;

   size_++;

   //index_++;

}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int ret = arr[index_];
  //index_ --;
  size_ --;
  index_ = size_ -1;
  return ret;
}
