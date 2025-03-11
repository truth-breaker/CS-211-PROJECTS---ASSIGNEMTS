#include <iostream>
#include <algorithm> 
#include <string>
#include <iomanip>
#include <fstream>
#include "checkInput.h"
#include "array.h"
//reference the struct //definitions and function prototypes
const int MAX = 100; //capacity of array
int age[MAX]; 
string country[MAX];
double hours[MAX];


void getVisitorInfo(string country[],int age[],double hours[],int index);
bool checkPassword();
template <class T>
void showStatistic(string country[],int age[],double hours[], int amount,T& out);
int showMenu();
int main() {
  /*
    Declare and initialize related variables 
  */
  int num = 0; //companion variable to save amount of visitors
  unsigned interest_num =0;
   int action_choice;
  int code;
  char input;
  
   
   do{
      interest_num++;
  action_choice = showMenu();
   
  if(action_choice == 1){
    getVisitorInfo(country,age,hours,num);
    num++;//keeps track of num of visitor
   }
     if(action_choice == 2){
    bool password = checkPassword();
    if(password == true){
      
    
    showStatistic( country,age,hours,num,cout);
    cout << "Do you want to close the museum? Y or N: ";
    input = getYN("Invalid answer");
    //cout << input << endl;//test
    //opening text file
    if(input == 'Y'){
    ofstream file;
    string date, file_name;
     cout << "Enter today's date: ";
      cin >> date;
     file_name = date + ".txt";//filename gets date
     file.open(file_name.c_str());//create and open file with the date
     showStatistic( country,age,hours,num,file);
     file.close();
     return 0;
    }
   
  } 
    
    
     }
     
   
 
    

  }while(input != 'Y');
  
}
//Goal: This function allows to display the options for the user to select  and stores the choice they select-outputting if its invalid
int showMenu() {
cout << "\n======================================\n";
cout <<" 1. Visitor\n 2. Museum Staff\n";
cout << "Enter your choice: ";
int choice = getData(1, 2, "Invalid choice. Enter 1 or 2:");
//cout << "choice = " << choice << endl << endl;
return choice;  
}
//**************************************************
  //Goal:
//*******************************************************
void getVisitorInfo(string country[],int age[],double hours[], int index){
//When choice is 1, this function is called.
  //int num = 0;
  //index keeps track of number of visitors
  if(index<= MAX){
   cout << "\nEnter your country: ";
   cin >> country[index];
   cout << "Enter your age: " ;
   cin >> age[index];
   //ages must be 0 to 200 
   if(age[index] < 0 || age[index] >= 200){
   cout <<" The age has to be between 0 and 200. Enter again: ";
   
   }
   cout << "Enter the number of hours you explored: ";
   cin >> hours[index];
   cout << endl;
   //hours must btwn 0 and 10
   if(hours[index] >= 10 || hours[index] <0){
   cout <<"The number of hours has to be between 0 and 10.0. Enter again: ";
   cin >> hours[index];
   }
  //increments if user wants to enter more info
   index++;
}
  }   

//Goal: This function checks if user enters the correct password in order to access the stats 
bool checkPassword(){
  int password; //variable to collect or save users input
  cout << "What is the Password: ";
  cin >> password;
if(password == 5678){
return true;  
}
else{
  cout << "The password is wrong" << endl;

  return false;
}

  
}
//*************************************
//Goal: This function allows to display the stats of user's inputs
//When the password was verified, this function is called.
//Show the statistic about visitors.
//*****************************************
 template <class T>
   //out to the screen and file -T& out;
  
 void showStatistic(string country[],int age[],double hours[], int amount,T& out){
   string country_c[MAX]; //string that u can fill with the unique countries
   out <<  "\nThe total number of visitors is " << amount << endl;
   out << "-------- The names of the countries of visitors -------"<< endl;
   copy(country, country + amount, country_c); // Copy country array
   sort(country_c, country_c + amount);        // Sort before using unique
   int new_size = unique(country_c, country_c + amount) - country_c; // Remove duplicates

   //loop to display all the users input for country
    for (int i = 0; i < new_size; i++)
    {
     //sort each country alphabetically.
     //sort(country_c,amount);
      out << country_c[i] << " ";
     }
   //getlow and getHigh function saves the age of user's input into a  variable
   int low =  getLow(age, amount);
   int high = getHigh(age,amount);
   
   out <<"\nThe age of the youngest visitor: " << age[low] << endl; 
   out << "The age of the oldest visitor: "<< age[high]<< endl;
   out << "The average age of the visitors: " ; 
   
   out << getAvg(age,amount) << endl;

   int high_ = getHigh(hours,amount);
   int low_ = getLow(hours,amount);
   out << "The shortest visit hours: " << hours[low_] << endl;
   out << "The longest visit hours: " << hours [high_] << endl;
   out <<" The average visit hours: ";
   out << getAvg(hours,amount) << endl;
   //cout <<"The average visit hours:" << hours[average] << endl;
  


   

  
 }