// animal.cpp
// animal.cpp
#include "animal.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Animal::Animal()
{
	string s = "cat";
	string ss = "fish";
	setType(s);
	setFood(ss);
}
Animal::Animal(string type, string food)
{
	setType(type);
	setFood(food);
}
string Animal::getType()
{
	return type_;
}
void Animal::setType(string type)
{
	type_ = type;
}
string Animal::getFood()
{
	return food_;
}
void Animal::setFood(string food)
{
	food_ = food;
}
string Animal::print()
{
	/*string s = getType();
	return
		string("I am a") +
		std::to_string(s);*/
	string s = getType();
	ostringstream r;
	r << "I am a " << s;
	return r.str();
}
