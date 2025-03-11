#ifndef PRICE_H
#define PRICE_H

#include <iostream>
using namespace std;

//Class Price
class Price
{
 private: //private data members
  int dollar;
  int cent;

 public:
  //constructors
  Price();
  Price(int, int); 

  ///operator overloading functions
  Price operator+(Price);
  Price operator-(Price);
  void operator=(Price);
  //friend function for overloading insertion operator
  // since function is outside of class must use friend to acess to class
  friend ostream &operator<<(ostream &out,Price Pr);
};

#endif

