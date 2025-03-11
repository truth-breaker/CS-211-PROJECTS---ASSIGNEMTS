#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat()
{
  
}

Cat::Cat(string n, int a, double w) : Animal(n,a,w)  {
  //call Animal overloaded ctor in initialization list
  //nothing needed here.
}

void Cat::speak()
{
  cout << "Meow!" << endl;
}

void Cat::purr()
{
  cout << "Purrrrrrrrrrrrrrrrrrr" << endl;
}
