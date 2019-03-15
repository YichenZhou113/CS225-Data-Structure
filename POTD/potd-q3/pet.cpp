#include <string>
#include "pet.h"

using namespace std;

Pet::Pet(string Name, int Birthyear, string type,string owner_name){
 this->Name = Rover
 this->Birthyear = 2017
 this->type = dog
 this->owner_name = Cinda



}

// Put your constructor code here!

void Pet::setName(string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(string newType) {
  type = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name = newName;
}

string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

string Pet::getType() {
  return type;
}

string Pet::getOwnerName() {
  return owner_name;
}
