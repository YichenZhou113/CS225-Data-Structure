#ifndef _QUEEN_H
#define _QUEEN_H
#include "piece.h"
#include <string>
using namespace std;

class queen:public piece  {

public:
  //~queen();
  string getType();
  string type;
};

#endif
