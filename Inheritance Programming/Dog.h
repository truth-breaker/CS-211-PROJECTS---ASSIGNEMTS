#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.h"

using namespace std;

class Dog : public Animal
{
private:
bool hasLongHair;
  public:
    Dog(string n, int a, double w, bool h);
    void speak();
    void displayData();
};

#endif