#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal
{
  protected:
    string name;
    int age;
    double weight;
  public:
    Animal();
    Animal(string n, int a, double w);

    void speak();
    void setData(string n, int a, double w);
    void displayData();
};

#endif