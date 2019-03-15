// Your code here
#include <string>
#include <iostream>
#include "potd.h"
using namespace std;

string getFortune(const string &s){
  if(s.length()%5 == 0){
    return "As you wish!";
  }else if(s.length()%5 ==1){
   return "Nec spe nec metu!";
 }else if(s.length()%5 == 2){
    return "Do, or do not. THere is no try";
  }else if(s.length()%5 == 3){
    return "This fortune intentionally left blank.";
  }else {
    return "Amor Fati";
  }
}
