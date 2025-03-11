/*************************
Dennise Arenas
queue.cpp
****************************/
#include <cstdlib>
#include <string>
#include "queue.h"
#include <iostream>
using namespace std;


Queue::Queue(){
  front = 0;
  rear = -1; 
  count = 0;//keeps track of # of elements
}
//checks whether Queue is Empty or not
bool Queue::isEmpty()
{
  //if front  is = -1 returm true
  return (count== 0)? true : false;
}

bool Queue::isFull()
{
  return(count == QUEUE_SIZE)? true:false;


}


/********************************
The goal of this function is to add a element

************************************/
void Queue::add(el_t e)
{
  //when full state a overflow
    if(isFull())
     {
       queueError("Error: Overflow");
       cout << endl;
      }
       else
      {
        rear = (rear+1)%QUEUE_SIZE;
        el[rear] = e;
         count ++;
      }
      
}
el_t Queue::remove()
{
  el_t remove2;
  if(isEmpty())
  {
    queueError("Error: It's Empty");                 
  }
  else
  {
    remove2 = el[front];
    front = (front+1) % QUEUE_SIZE;
    count--;
    return remove2;
  }
  return el_t(); // FIX: Ensure function always returns a value
}
el_t Queue::getFront() 
{
  if(isEmpty())
  {
    queueError("stack underflow");
  }
  else
  {
    return el[front];
  }
  return el_t(); // FIX: Ensure function always returns a value
}


void Queue::goToBack()
{

  if(isEmpty())
    {
      queueError("Error");
    }
  else if (count > 1)
    {
      //dd(remove());
      //sfirst person is removed foom queue once helped
      el_t letter= remove();
      //adds other slott for another studnet/person
      add(letter);
    }
  // return count;
  
   


}
ostream& operator<<(ostream& out,expr& e)
{
  out << e.oprd1 << e.oprt << e.oprd2 ; // displays math equation ex: 5+8 
  return out; 

}
void Queue::displayAll()
{
  if(isEmpty())
   {
    cout << " Queue is Empty" << endl;
   }
  else {
    cout << "[";
    // oount = numbers of queue- Loop stops until reaches its capacity
    //i = determines = front
    for (int i = front; i !=  rear; i=(i+1)%QUEUE_SIZE)
    {
      
      //prints out elements if array is less than 5
      // if(i < QUEUE_SIZE)
       
	//holds indivual elements
        cout << "[" <<  el[i] << " ]" ;

    }
   
     cout << "[ " <<  el[rear] << "]" << endl;
       
  }

}
   int Queue::getSize()
   {
          
     return count; 
   
   

   } 

void Queue:: queueError(string msg)
{

  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors

}
