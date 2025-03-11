#include "LL.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
  //make an object of lqueue class
  LL q;
  // call isEmpty()--> make sure it returns true

 
 //cout << "-----ADDING" << endl;
   q.addFront(1);
   q.addFront(2);
  q.addFront(3);
  q.addRear(4);
  q.addRear(5);
 cout << endl; 
 

 q.displayAll();
 //cout <<"DELETING" << endl;
 cout <<"The number has been deleted   " << q.deleteFront()<< endl;
 cout << "The number has been deleted " << q.deleteRear()<< endl;
 q.displayAll();
 cout << "------" << endl; 
 
 q.displayAll(); // 2 1 4

  cout << "The number has been deleted " << q.deleteFront() << endl;
  cout << "The number has been deleted " << q.deleteRear() << endl;
  q.displayAll();
  
  cout << "The number has been deleted " << q.deleteFront()<< endl;
  q.displayAll();

  q.addRear(10);
  q.addFront(11);
  q.displayAll();

  cout << "The number has been deleted " <<  q.deleteRear() << endl;
  cout <<"The number has been deleted " <<  q.deleteRear() << endl;
  q.displayAll();
 
   cout << endl;
   //test your copy Constructor
   LL a;
   a.addFront(1);
   a.addRear(2);
   LL b(a);
   
   b.displayAll(); // 1 2
   a.deleteFront();
    a.displayAll(); // 2
   b.displayAll(); // 1 2
  return 0;
 
}
