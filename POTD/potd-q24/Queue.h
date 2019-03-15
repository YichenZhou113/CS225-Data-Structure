#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
    public:
      Queue();
        int index_;
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
      private:
        int size_;
        int * arr;
};

#endif
