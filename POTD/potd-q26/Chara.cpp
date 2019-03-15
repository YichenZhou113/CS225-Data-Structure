// your code here
#include <iostream>
#include <string>
#include "Chara.h"
#include <queue>
using namespace std;

string getStatus() const{
if(q->size()==0){
  return "Empty";
}else if(q->size()>0&&q->size()<=3){
  return "Light";
}else if(q->size()>=4&&q->size()<=6){
  return "Moderate";
}else{
  return "Heavy";
}
}

void addToQueue(string name){
  q->push(name);
  q->size()++;

}

string popFromQueue(){
  string nameone = q->front();
  q->pop();
  q->size()--;
  return nameone;
}
