/******************************************************
Dennise Arenas
2-18-2022
Lab Operators
This program allows operates addition and substraction to find the total of two
items/prices being added togther. As well finding the difference of two prices with the correct price format
 ***************************************/



#include "price.h"
#include <iostream>
using namespace std;

//default constructor
Price ::Price()
{
  dollar = 0;
  cent = 0;
}

//Constructor with arguments
Price ::Price(int d, int c)
{
  this->dollar = d;
  this->cent = c;
}

//overloading plus operator '+'
//returns an object of type Price
Price Price::operator+( Price  Pr)
{             
  int centSum = Pr.cent + this->cent; //find the sum of cents
  //when numbers are added togther a num is carried  example .50 + .50 = 1.00 (carries a 1)
  int carry = centSum / 100;          //find the carry to bet generated
  int newCent = centSum % 100;        //find the value of cent that actually
  //create a new price object
  Price newObj;
  newObj.cent = newCent;                              //set the cent of it
  newObj.dollar = (this->dollar + carry + Pr.dollar); //set the dollar
   
  return newObj; //return the newly created object
}

//overloading minus operator '-'
//returns an object of type Price

Price Price::operator-( Price  Pr)
{  
  //new Obj to acess cent from Price class
  Price newObj;
  //subtract the dollar and cent
  newObj.cent = this->cent - Pr.cent;
  newObj.dollar = this->dollar - Pr.dollar;
  //increase num to dollar and make it positive
  //If cent is negative meaning cent is less than 0 then- adjust it by adding 100
  if (newObj.cent < 0)
    {
      newObj.cent = 100 + newObj.cent;
      //subtracting numbers
      newObj.dollar--;
    }
  //return the newly created object
  return newObj;
}

//overloading assignment operator '='
void Price::operator=( Price  Pr)
{
  this->dollar = Pr.dollar;

  this->cent = Pr.cent;
}

/***************************
Goal: The purpose of this function is to out put the currency in its actual price form EX: $   5.00 ( if cents added EX:(5.50 +5.50) 50 +50 = 100 = 6.00 )
 ***************************/
//overloading insertion operator <<
ostream &operator<<(ostream &out, Price Pr)
{
  //print the price    
  // printd dollar following along with the dot 
  out << Pr.dollar << ".";
  // if cents are added up to 10 convert to dollar so add 00's
  if (Pr.cent < 10)
    {
      out << "0";
    }

  out << Pr.cent;
  return out;
}
