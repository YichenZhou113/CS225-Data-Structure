// Your code here! :)
#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

using namespace std;

namespace potd{
  class student{
  public:
    student();
    string get_name();
    void set_name(string name);
    int get_grade();
    void set_grade(int grade);
  private:
    string name_;
    int grade_;
  };
}

#endif
