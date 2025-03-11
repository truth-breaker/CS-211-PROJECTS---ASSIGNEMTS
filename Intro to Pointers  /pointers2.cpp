/***********************************
Dennise Arenas

*****************************/


#include <iostream>
using namespace std;
int main()
{
  int* Boss;//Pl pointing to a int
  int* GOD; //p2 pointing to a int
  
  Boss = new int; //make P1 point to a cell
  *Boss = 1;   //p1 point to a cell -put 1 in it
  cout << *Boss ; //display rhe cell content
  cout << endl;
  GOD = new int; // Make p2 point to a cell
  *GOD = 2; // put 2 in it
  cout << *GOD ; // display the cell content
  cout << endl;
  delete GOD;


  GOD = Boss; // make p2 point to the same cell as p1
  cout << *GOD; 
  cout << endl;
  delete Boss; // delete the cell 
  Boss = NULL; // initialize P1(to NULL)
  
  GOD = new int; // make p2(God) to a new cell;  
  *GOD = 3; // put 3 in it
  cout << *GOD;  // display the cell content
  cout << endl; 
}
