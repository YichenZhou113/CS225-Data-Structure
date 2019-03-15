#include "Queue.h"

Queue::Queue() {
size_ = 0;
index_ = 0;
}

// `int size()` - returns the number of elements in the stack (0 if empty)


int Queue::size() const {
  return size_;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  if(size_ ==0){return true;}
  else{return false;}
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
arr[index_] = value;
size_++;
index_++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  index_ = 0;
  int ret =  arr[index_];
  size_--;
  return ret;
}
