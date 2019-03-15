#include "potd.h"
#include <iostream>
#include <string>

using namespace std;

string stringList(Node *head) {
  int count = 0;
  string cast;
  if(head==NULL){
    return "Empty list";
  }else {
    while(head->next_ !=NULL){
      cast = cast+"Node "+to_string(count)+": "+to_string(head->data_)+" -> ";
      head = head->next_;
      count++;
    }
    cast = cast + "Node "+to_string(count)+": "+to_string(head->data_)+" -> ";
    cast.erase(cast.end()-4,cast.end());
    return cast;

  }

    // your code here!
}
