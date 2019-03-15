// Your code here!

/* Include essential libraries. */
#include <string>
#include "thing.h"

using namespace std;

using namespace potd;

Thing::Thing(int size){

  properties_ = new string[size];

  values_ = new string[size];

  props_ct_ = 0;

  props_max_ = size;
}


void Thing::_copy(const Thing&t){

  props_ct_ = t.props_ct_;
  props_max_ = t.props_max_;

  properties_ = new string [t.props_max_];
  values_ = new string [t.props_max_];

  for (int i = 0; i< t.props_ct_; i++){
    properties_[i] = t.properties_[i];
    values_[i] = t.values_[i];
  }
}

Thing::Thing(const Thing &t){
  _copy(t);
}

Thing& Thing::operator = (const Thing &t){
  if (this == &t){
    return *this;
  }

  // For the sake, do this at first.
  delete[] properties_;
  delete[] values_;

  // Then perform copy_
  _copy(t);
  return *this;

}

int Thing::set_property(string name, string value){

  for (int i = 0; i < props_ct_; i++){
    if (properties_[i] == name){
      values_[i] = value;
      return i;
    }
  }

  if (props_ct_ == props_max_){
    return -1;
  }   // Put the check here instead!

  properties_[props_ct_] = name;
  values_[props_ct_] = value;
  props_ct_ ++;
  return props_ct_ -1;

}

string Thing::get_property(std::string name){

  for (int i = 0; i < props_ct_; i++){
    if (properties_[i] == name){
      return values_[i];
    }
  }
  return "";

}

Thing::~Thing(){
  _destroy();
}

void Thing::_destroy(){
  delete [] properties_;
  properties_ = NULL;

  delete [] values_;
  values_ = NULL;
}
