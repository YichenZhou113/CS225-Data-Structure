// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	Animal(string type, string food);
	string getType();
	void setType(string type);
	string getFood();
	void setFood(string food);
	virtual string print();
private:
	string type_;
protected:
	string food_;
};

#endif
