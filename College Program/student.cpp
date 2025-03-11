#include "student.h"
#include "price.h" 
#include "array.h"
#include <iostream>
using namespace std;

Student::Student(){
  FN=" unknown"; //first name variable from class is set equal to f
  LN = "unknown"; //last name is set equal to l
  gen = 'x'; // gen is set equal to g
  num = 0; // initial value of # of  courses in array
  stuId = -1;

}

Student::Student(string f, string l, char g,int i){
 
  FN= f; //first name variable from class is set equal to f
  LN = l; //last name is set equal to l
  gen = g; // gen is set equal to g
  num = 0; // initial value of # of  courses in array
 stuId= i ;
}
string Student::getFirstName()const{
  return FN;

}
string Student::getLastName()const{
  return LN;

}

char Student::getGender()const{
  return gen;

}
int Student::getNumClasses()const{

  return num;

}
int Student::getStuID()const{
  return stuId;
}
int Student::getClassOf(int i)const{
  return classAr[i];
  


}
Price Student::getBalance()const{

  return balance;

}
/***************
This function will  add a fee to the studets balance

 ************/
void Student::addFee(int d,int c)
{
  Price p(d,c);//make a new price from d and c
                     //add it to the balance 
  balance = balance+ p;
 

}
/***************
This function will reduce a fee from student's balance
********************/
void Student::reduceFee(int d,int c){
  Price p(d,c); 
  balance = balance-p;

}


//Goal:This function allows to add courses until it reaches it capacity 
//As well checks if course exists already in the array
int Student::addCourse(int crn){
    if (num < MAX)
    {
      // function call Find from array.h
      if (find(classAr,MAX,crn) == -1)
	{
 //crn stores the course into the array- num++ increments to add another course 
	  classAr[num++] = crn;
	  return 1;//class was added
	}
      else
	{
	  return 0;//class already exists 
	}
    }
    else
      return -1;//class array is full, no more classes to be added
    // classAr[num++] = crn
}
/********************************
 Goal: This function prints all courses in the array
******************************/
void Student::viewAllCourses()const{
  print(classAr,num);

}
/*******************************
Goal: This function removes or drops a course one wishes
**********************************/
bool Student:: dropCourse(int crn){
  if (remove(classAr, num, crn)== false){
     return false;
  }
  else{
    //calls remove function in array.h
    remove(classAr,num,crn);
    // decrease slot from the array
    num --;
    return true;
  }

}
 