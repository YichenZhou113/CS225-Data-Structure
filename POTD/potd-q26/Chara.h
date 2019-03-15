#ifndef _CHARA_H
#define _CHARA_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <typename string> class Chara{
  queue<string> q;
    public:
        string getStatus() const;
        void addToQueue(string name);
        string popFromQueue();
};

#endif
