/***************************************************************
CS211
Template prepared by Kazumi Slott
Dennise Arenas
1-28-2020

This program tests array.h
**************************************************

*************************************************/
#include <iostream>
#include "array1.h"
#include <iomanip>
using namespace std;

//void print(T ar[], int n);
void lowandHigh(int ar[],int n);

int main()
{
  //declare const called SZ_I set to 7
  const int SZ_I = 7;
  //declare const called SZ_D set to 3
  const int SZ_D = 3;
  //declare const called SZ_C set to 5
  const int SZ_C = 5;

  //create an integer array that has SZ_I slots
   int arrayI[SZ_I];
  //create a double array that has SZ_D slots
   double arrayD[SZ_D];
  //create a character array that has SZ_C slots
  char arrayC[SZ_C];
  cout << "-------Filling the Interger Array--------\n";
  //call fill with the integer array
  fill(arrayI,SZ_I);
  //call fill with the double array
  cout << "-------Filling the Double Array--------\n";
  fill(arrayD,SZ_D);
  //call fill with the character array
  cout << "-------Filling the Character Array--------\n";
  fill(arrayC,SZ_C);
  cout << endl << "Results of all the Integer, Double, and Character Array: "<< endl;

  //call print (with 2 parameters) with the integer array
  print(arrayI, SZ_I);
  cout <<endl;
 //call print with the double array
   print(arrayD,SZ_D);
  cout <<endl;
  //call print with the character array
  print(arrayC,SZ_C);
  cout << "---------------------------------------"<<endl;

  //call getHighest with the Integer array and show the highest value along w\ith its location
  int highIndex = getHigh(arrayI,SZ_I);
  cout <<"\n The highest Integer is " << arrayI[highIndex] << " found at " << highIndex << endl; 
  //call getLowest with the duoble and show the lowest value along with its loc\ation
  int low = getLow(arrayD,SZ_D);
  cout <<" The lowest is " << arrayD[low] << " found at " << low << endl; 

  //call getAvg with the integer array and show the returend value
  cout <<" The Integer Array Average is " << fixed << setprecision(2) <<
   getAvg(arrayI,SZ_I) << endl;

  //call unique with integer array and show unique array and the number of uniq\ue numbers
  int uniqAr[SZ_I];
   int unique_ = customUnique(arrayI, uniqAr, SZ_I);
   cout << "------------------------------------\n";
   cout <<setprecision(1);
   
   cout << "\nThe total number of unique integers is " << unique_ << endl;
   print(uniqAr,unique_);
  //call unique with character array and show unique array and the number of un\ique numbers
   char uniqueAr[SZ_C];
  int unique_c = customUnique(arrayC,uniqueAr,SZ_C);
  
  cout << "\nThe total number of unique characters is " << unique_c << endl;
  print(uniqueAr,unique_c);
cout << "---------------------------------------\n";
  //sort the double array and print it
  cout << "\n" << "Sorting the Double Array(Low to High): " << endl;
  bubbleSort(arrayD,SZ_D);
  // sort(arrayD,SZ_D);
  print(arrayD,SZ_D);

  //sort the character array and print it
  cout << "\n Sort the Character Array(Alphabetical Order): " << endl;
  bubbleSort(arrayC,SZ_C);
  // sort(arrayC,SZ_C);
  print(arrayC,SZ_C);
  cout << endl; 
  return 0;
}
