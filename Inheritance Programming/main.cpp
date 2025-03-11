#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Animal.h" //only needed to create base class Animal objects, not to create Dogs or Cats.
using namespace std;

int main()  {

  Cat c;

  Animal a("Sample", 12, 34.56);
  cout << "Information on Animal:" << endl;
  a.displayData();
  cout << "The Animal says ";
  a.speak();
  //a.purr(); //ILLEGAL: Not all animals can purr.

  cout << endl << endl;
  
  Dog d("Spot", 5, 23.4, true);
  cout << "Information on Dog:" << endl;
  d.displayData();
  cout << "The dog says ";
  d.speak();
 // d.purr(); //ILLEGAL: Dogs can't purr.

  cout << endl << endl;

  c.setData("Fluffy", 3, 12.3);
  cout << "Information on Cat:" << endl;
  c.displayData();
  cout << "The cat says ";
  c.speak();
  c.purr();
  
  return 0;
}