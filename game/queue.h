//define the rNum class here. The data members are top and bottom.
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string> //for the string class
using namespace std;
const int QUEUE_SIZE = 10;
//queue class
enum op{ADD, SUB, MULT, DIVI};

struct expr
{
  int oprd1;
  op oprt;
  int oprd2;


};
ostream& operator<<(ostream& o, const expr& e);



typedef expr el_t; //define el_t to be int for now
//const int QUEUE_SIZE = 10;

class Queue
{
   private:
  //Data members are:
  

  el_t el[QUEUE_SIZE]; //an array  called el. Currently it is a character array
  int count; // the number of elements the queue contains
  int front; // where the front element of the queue is.
  int rear; // where the rear element of the queue is.
  void queueError(string msg);

  // a private utility function for fatal error cases
  // This displays an error messages passed to it and does exit(1);
  //  void queueError(string msg); 



   public:
  // constructor
  Queue();
  // returns true if queue is empty, otherwise false
  bool isEmpty();
  // returns true if queue is full, otherwise false
  bool isFull();
  // if full, calls an emergency exit routine
  // if not full, changes rear to the next slot and enters an element at rear
  void add(el_t e);
  // if empty, calls an emergency exit routine
  // if not empty, remove(return) the front element and change front to the next slot
  el_t remove();
  // if empty, calls an emergency exit routine
  // if not empty, return the front element (but does not remove it)
  el_t getFront();
  //if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();
  // [Hint: use remove() and add()]
    //returns the current size
    int getSize();
  //display everything in the queue from front to rear, each item enclosed in []. E.g. [a][b][c]

  //Do not call the emergency exit routine when the queue is empty. Instead display [empty]
  void displayAll();

};
#endif
