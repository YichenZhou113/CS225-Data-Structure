
// Your code here! :)
#include "student.h"
#include <iostream>
using namespace std;

namespace potd{
  student::student(){
    name_ = "Sally";
    grade_ = 5;
  }
  std::string student::get_name(){
    return name_;
  }
  void student::set_name(string name){
    name_ = name;
  }
  int student::get_grade(){
    return grade_;
  }
  void student::set_grade(int grade){
    grade_ = grade;
  }
}
