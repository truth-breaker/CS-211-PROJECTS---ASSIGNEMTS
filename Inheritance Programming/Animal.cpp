#include <iostream>
#include "Animal.h"

using namespace std;

void Animal::speak()
{
  cout << "The animal speaks!" << endl;
}

void Animal::displayData()
{
  cout << "Name: " << name << endl;
  cout << "Age: "<< age << endl;
  cout << "Weight: " << weight << endl;
}

void Animal::setData(string n, int a, double w)
{
  name = n;
  age = a;
  weight = w;
}

Animal::Animal(string n, int a, double w)
{
  setData(n,a,w);
}

Animal::Animal()
{
  name = "Unknown";
  age = 0;
  weight = 0.0;
}