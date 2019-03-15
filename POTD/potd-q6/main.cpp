// Your code here! :)
#include <iostream>
#include "student.h"
#include "q6.h"
using namespace potd;
using namespace std;

int main(){
  student s;
  cout << s.get_grade() << endl;
  graduate(s);
  cout << s.get_grade() << endl;
  return 0;
}
