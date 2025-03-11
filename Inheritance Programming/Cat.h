#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.h"

using namespace std;

class Cat : public Animal
{
  public:
    Cat();
    Cat(string n, int a, double w);
    void speak();
    void purr();
};

#endif