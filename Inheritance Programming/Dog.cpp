#include <iostream>
#include "Dog.h"

using namespace std;

Dog::Dog(string n, int a, double w, bool h) : Animal(n,a,w) {  //call Animal overloaded ctor in initialization list
  hasLongHair = h;
}

void Dog::displayData()
{
  Animal::displayData(); //call displayData from the animal class first
  cout << "Has Long Hair?: " << boolalpha << hasLongHair << endl; //then add the new display specific to Dogs
}

void Dog::speak()
{
  cout << "Woof!"<< endl;
}


