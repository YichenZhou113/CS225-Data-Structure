#ifndef _THING2_H
#define _THING2_H
#include <string>
#include "thing1.h"
//using namespace std;

class Thing2: public Thing1 {
public:

  std::string foo();
  std::string bar();
  virtual ~Thing2();

};

#endif
