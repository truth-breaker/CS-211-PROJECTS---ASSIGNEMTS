/*************************
Dennise Arenas
College.cpp
 Purpose: This program 
This student database allows an admin or student to access data. In order to gain access, users must enter correct password which was auto generated.
Admin Features:

Add students (max 100) manually or from a .txt, .dat, or .csv file ([firstname] [lastname] [gender]).
Drop students and view student details.
Student Features:

Add/drop courses ($50.14 per course).
Make payments ([dollar] [cent]).
View personal information.

***********************************/
#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "checkInput.h"
#include "student.h"
#include "array.h"
#include "price.h"
#include <fstream>
const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

//PROTOTYPES
int showMenu();
int showAdmMenu();
int showStuMenu();
void showStuInfo(const Student& g);
void addStu(Student ar[],int& count,int& curID);
void allStuInfo(const Student ar[], int c);
bool operator==(const Student& s, int id);
void removeStu(Student ar[],int& c);
void addStuFromFile(Student ar[],int& c, int& curID);
void addCourse(Student& s );
void dropCourse(Student& s);
void makePayment(Student& s);
bool checkPassword(int password);
int findStu(Student stuAR[], int s);
void viewStuInfo(Student& stuAR, int index);

int main() {
    Student stuAR[SIZE];  // array for storing students
    int count = 0;  // number of students in the array
    int curID = START;  // current student ID
    int choice;  // user choice for menu

    do {  // loop until the user chooses to exit
        choice = showMenu();  // show the main menu
        if (choice == 1) {  // Admin menu
            int pass;  // Admin password
            cout << "Enter your password: ";
            cin >> pass;

            if (pass == 123) {  // Admin password check
                int adm_choice;  // admin choice

                do {  // loop until admin chooses to quit (6)
                    adm_choice = showAdmMenu();  // show admin menu
                    switch (adm_choice) {
                        case 1: 
                            addStu(stuAR, count, curID); 
                            break;
                        case 2: 
                            addStuFromFile(stuAR, count, curID); 
                            break;
                        case 3: 
                            removeStu(stuAR, count); 
                            break;
                        case 4: {
                            int index;
                            cout << "Enter the student ID: ";
                            cin >> index;
                            int findId = find(stuAR, count, index);
                            if (findId == -1) {
                                cout << "The student ID doesn't exist" << endl;
                            } else {
                                showStuInfo(stuAR[findId]);
                            }
                            break;
                        }
                        case 5: 
                            allStuInfo(stuAR, count); 
                            break;
                        default: 
                            cout << endl; 
                            break;
                    }
                } while (adm_choice != 6);  // Admin menu loop, breaks when choosing option 6
            } else {
                cout << "Wrong password." << endl;
            }
        } else if (choice == 2) {  // Student menu
            int studentID;
            int password2;  // Password entered by the student
            int student_choice;

            cout << "Enter the student ID: ";
            cin >> studentID;

            int found = find(stuAR, count, studentID);

            if (found == -1) {  // If student ID doesn't exist
                cout << "The student ID doesn't exist." << endl << endl;
            } else {
                int pass_attempt;
                cout << "Enter the password: ";
                cin >> pass_attempt;  // Allow the user to enter the password

                // Generate the student's password based on their ID
                password2 = studentID % (PRIME1 * PRIME2); 

                if (password2 != pass_attempt) {  // Check if the entered password is correct
                    cout << "The password is wrong." << endl << endl;
                } else {  // If password matches
                    cout << "Welcome " << stuAR[found].getFirstName() << endl;

                    do {
                        student_choice = showStuMenu();  // Get the student's menu choice
                        
                        switch (student_choice) {
                            case 1:
                                addCourse(stuAR[found]);  // Add a course
                                break;
                            case 2:
                                dropCourse(stuAR[found]);  // Drop a course
                                break;
                            case 3:
                                makePayment(stuAR[found]);  // Make a payment
                                break;
                            case 4:
                                showStuInfo(stuAR[found]);  // Show student info
                                break;
                            case 5:
                                cout << "Exiting student menu..." << endl;  // Print a message and exit
                                break;
                            default:
                                cout << "Invalid choice, try again!" << endl;  // Handle invalid choices
                                break;
                        }
                    } while (student_choice != 5);  // Exit loop when student chooses option 5 (Quit)
                }
            }
        }
    } while (choice != 3);  // Loop until the user chooses to exit (option 3)

    return 0;
}





    





  // ************************  PHASE 1  ****************************
  /*****************************
  The goal of this function is to add a student
  into the student array by asking the user to enter the students first name,
  last name, and gender 
  ***********************************/



void addStu(Student ar[],int&count,int&curID)
{
string fn;//variable for first name
string ln; //variable for last name
char gen; // variable for gender
//case 1 of admission
 if(count == SIZE)
   cout << "The max of students enrolled has been reached" << endl;
 else{
cout << "Enter the first name: ";
cin >> fn; 
cout << "Enter the last name: ";
cin >> ln;
 cout << "Enter the Gender(F or M): ";
cin >> gen;
//create a student object. The first student created is given a stu id, 100000 (coming from const START).
//The second student gets 100001, the third student gets 100002, etc (notice curID in main).
 Student s(fn,ln,gen,curID);
//copy the info from the stu obj into the array at the appropriate slot
 ar[count]= s;
 count++; //incrementing count
 curID++; //incrementing curID

 }
}
 /**********************************
This function will print or show one of the
students information onto the screen  
 *****************************************/                                                                                                                                             
 void showStuInfo(const Student&g)                                                                                       
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 


  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " << g.getFirstName() << endl;                                                                                                 
 
  cout << "last name: " << g.getLastName() << endl;                                                                                                  
 
  cout << "gender: " << g.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << g.getStuID() << endl;                                                                                                      
 
  cout << "num classes: " << g.getNumClasses() << endl;                                                                                                  
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < g.getNumClasses() ; i++) //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
  {
  cout << g.getClassOf(i)  << ", "; //the number of classes                                                                                                         
  }
 
                                                                                                                                              
  cout << "\nAmount owed $" << g.getBalance() << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
  }


 void allStuInfo(const Student ar[],int c)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i = 0; i <c; i++)// this will got through array and print stu info
    {
      showStuInfo(ar[i]);
    }
}

 // operator==(const student& s, int id) 


 /****************************
The goal of this function is to remove a student 
from the student array depending on the student id we enter
 if the student id exists the we this function will find
that id and once it does it will remove that student from the student array
****************************/
 void removeStu(Student ar[],int&c)
{
  int deleteID; //the spot that will be remove
  int found; //variable that will hold if id found
  cout << "Enter the student id: "; // ask user to input id
  cin >> deleteID;
  found = find(ar,c,deleteID); // checks if id exists
  if(found == -1) // if id not found
    {
      cout << "student with id  doesn't exist" << endl;
    }
  //else- then id found and remove the student from array
  else{
    cout << ar[found].getFirstName() << " " << ar[found].getLastName();
    cout << "has been removed." << endl;
    remove(ar,c,deleteID);
    c--; //decrementing the counter b/c a student was removed
  }
//Case 3 of Admission

//2 different messages

     //"student with id " << id << " doesn't exist" << endl;
     // f << " " << l << " has been removed." << endl;


}
 /**********************************************************************
Goal: Function will read a file that has a certain amount of students and
would add them into the student array and output them to
 see if they got added successfully
 **********************************************************************/

 void addStuFromFile(Student ar[],int&c, int& curID)
{
//Case 2 of admission
  ifstream fin;
  string filename;
  string fn;//variable for first name
  string ln;//variable for last name
  char gen; //variable for gender
  
  cout << "Enter a file name:" ;
  cin >> filename;
  fin.open(filename.c_str());
  if(!fin)
    {
      cout << filename << " doesn't exist" << endl;
    }
  else
    {
      fin >> fn;
      fin >> ln;
      fin >> gen;
    
	  while(fin)
	    {
	      if(c == SIZE)
		{
		  cout << "the student array is full";
		}
	      else
		{

		  //create a student object \

		  Student s(fn,ln,gen,curID);

		  //copy the info from the stu obj into the array at the appropriate slot 

		  ar[c] = s;
		  c++;//incrementing count \

		  curID++;//incrementing curID
		  fin >> fn;
		  fin >> ln;
		  fin >> gen;
		}
	    }
	}
      fin.close();
}
  bool operator==(const Student& s, int id )
  {
    if(s.getStuID() == id){
      return true;
    }
    else{
      return false;
    }
  }





//*******************  PHASE 2 ****************************


void addCourse(Student& s )
{
//case 1 of student
//holds the value of the course number user inputs
  int crn; 
  cout << "Enter a crn: ";
  cin>> crn;
  //equal from what is returned from function
  int add = s.addCourse(crn);
//FYI, I am passing one student to this function not the array. 
  if(add == 1)
    {
      s.addFee(50,14);
      cout << crn << " has been added successfully" << endl;
    }
  //student had already had this class and can't be added again
  else if(add== 0)
    {
      cout << crn << " was not added because you have " << crn << " already." << endl;
    }
      else{
	cout << crn << " was not added because your schedule is full." << endl;//student already has reached its limit
          }
}

//3 different messages to show

  // " has been added successfully" << endl;
  // " was not added because you have " << crn << " already." <<  endl;
  // " was not added because your schedule is full." <<  endl;





void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int crn; //var for user input for course number
  cout << "Enter a crn: ";
  cin >> crn;

  int remove = s.dropCourse(crn);//is equal to what is returned from the dropCourse()function in student.cpp

  if(remove == false)//if remove is false we will give an error message saying we could not drop the course
    cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
  else//we could drop the course and so we give message saying we drop the course and reduce the students fee by $50.14
    {
      s.reduceFee(50,14);//reduce the fee because the class was successfully dropped from
      cout << crn << " has been dropped successfully." << endl;
    }
}






 
//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;




/***********************************************
this function will allow the students to make a payment towards their fee or,
how much they owe depending on how many classes they are taking and lets them
make a payment to reduce the amount they owe

int d - variable for dollars \

int c - variable for cents
***********************************************/

 
 

  





//******************** PHASE 3 ****************************


//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
void makePayment(Student& s)
{
 int d;//var for dollars
 int c; //var for cents
//case 3 of student
//FYI, I am passing one student to this function not the array.
 cout << "you owe $" << s.getBalance() << endl;//shows how much student owes
 cout << "Enter your payment dollars: ";
 cin >> d;//user input how much he would like to pay
  cout << "Enter your payment cents: ";

 cin >> c;


s.reduceFee(d,c);//we reduce the fee of the student depending on how much he wants to pay
// return ;
cout << "Updated balance: $" << s.getBalance() << endl; // Display updated balance

}




//Small function. You may choose not to use this function. That is OK.
 int findStu(Student stuAR[], int s)
{
    int id;
    cout << "Enter the student id: ";
    cin >> id;
    int finder = find(stuAR, s, id);  // Assuming you have a 'find' function
    if (finder != -1)  // If it is found
    {
        for (int i = finder; i < s - 1; i++)
        {
            return i;  // Return the index
        }
    }
    else  // If it isn't found
    {
        return -1;  // Return -1 if student not found
    }

    return -1;  // Ensure a return value if the loop doesn't return an index
}
//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1


/*
//did everything in main
void viewStuInfo(Student& stuAR, int index)
{
//Case 4 of admission
//Ask for the student id
  cout << "Enter the student ID: ";
  cin >> index;
  findId = find(stuAR,count,index);//finding the student with that ID in the stuAR
  if(findId == -1)
    cout << "The student ID doesn't exist" << endl << endl;
  else
    {
    showStuInfo(stuAR[findId]);//this function will show the specific students info that the id is assoc\iated with
    }
  break;
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}
*/

// verifyStu()
//{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
//}



int showMenu()
{

  
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");
  
  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



