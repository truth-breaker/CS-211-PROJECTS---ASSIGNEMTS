#include <iostream>
#include <string>
#include <cstdlib>
#include "DLL.h"
using namespace std;



//constructor
DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
  // prev = NULL;
}

//Constructor to have a seperate list that consists of the same elements from source
DLL::DLL(const DLL& source)
{
  //at the beginning this object has no elements in the list
  this -> front = this->rear = NULL;
  this-> count = 0;
  //p starts at front
  node *p  = source.front;
  //make sure visists every node in source
  while( p!= NULL)
    {
      //continur orginal order of elememts
      this-> addRear(p->elem);
      p = p  -> next;
  
    }


}

bool DLL::isEmpty()const
{
//check front,rear, and alos counr 0
  return(count == 0&&front == NULL && rear== NULL)?true:false; 
}
//Adds a new node at the front- 
void DLL::addFront(el_t el)
{
  if (isEmpty())
    {
      addRear(el);
    }
  else
    {
      node *p = front;
      front = new node;
      front -> elem = el;

      front -> next = p;
      p -> prev = front;

      front -> prev = NULL;
      count ++;
    }
}


/********************
Goal: This function allows to add a item
at the end of rear
**********************/
void DLL::addRear(el_t el)
{
  if (count == 0)
    {
      front = rear = new node;
      front -> next = NULL;
      front -> prev = NULL;
      front -> elem = el;  // Add this line to initialize the element
    }
  else
    {
      rear -> next = new node;
      rear -> next -> prev = rear;
      rear = rear -> next;
      rear -> elem = el;  // Add this line to initialize the element
    }
  rear -> next = NULL;
  count++;
}
/********************
Goal: This function deletes the front 
***********************/
el_t DLL::deleteFront()
{
  el_t e;
  if (isEmpty())
    {
      queueError("Error: list is empty.");
    }
  else if (count == 1)
    {
      e = front -> elem;
      delete front;
      front = rear = NULL;
    }
  else
    {
      e = front -> elem;
      front = front -> next;

      delete front -> prev;
      front -> prev = NULL;
    }
  count --;
  return e;
}
 
 


/*******************************
Goal: 



*************************/
el_t DLL::deleteRear()
{
  el_t e;
  if (isEmpty())
    {
      queueError("Error: list is empty.");
      return e;  // Make sure to return a value even after an error
    }
  else if (count == 1)
    {
      return deleteFront();
    }
  else
    {
      e =  rear -> elem;
      rear = rear -> prev;
      
      delete rear -> next;
      rear -> next = NULL;

      count--;
      return e;
    }
}









/******************************************************************************
The deleteNode function will look for the element and verify to see if it is ready to be deleted. It will be using test cases to check for the element inside of the function, whether if the function is empty, the pointer that scans through the for \
  loop to see if the element exists, whether if the node is located at the rear and if the node is located at the front. It will also decrement throughout the process since the node will be deleted and is logical to do so.
******************************************************************************/
void DLL::deleteNode(el_t e)
{
  if (isEmpty())
    {
      return;
    }
  if (e == front -> elem)
    {
      deleteFront();
    }
  else
    {
      node* del;
      for (del = front -> next; del != NULL && del -> elem != e; del = del -> next)
	{
	  ;
	}
      if (del == NULL)
	{
	  return;
	}
      else if (del == rear)
	{
	  rear =  del -> prev;
	  rear -> next = NULL;
	}
      else if (del != NULL)
	{
	  del -> prev -> next = del -> next;
	  del -> next -> prev = del -> prev;
	}
      delete del;
      count --;
    }
}

 
/*********************************
AddInorderAscend Goal:
**********************************/	
void DLL::addInOrderAscend(el_t e)
{
  if (isEmpty())
    {
      addRear(e);
    }
  else if (e <= front -> elem)
    {
      addFront(e);
    }
  else if (e >= rear -> elem)
    {
      addRear(e);
    }
  else
    {
      node* p = front;
      
      while(p -> next != NULL && p -> next -> elem < e)
	{
	  p = p -> next;
	}
      
      node* f = new node;
      f -> next = p -> next;
      f -> prev = p;

      p -> next -> prev = f;
      p -> next = f;
      
      f -> elem = e;
      count ++;
    }
}
























  



 
bool DLL::search(el_t e)
{
  node *p;
  
  for(p = front;p != NULL;p =p->next)
 
    {
      if(p->elem==e)
	return true;
    }
  return false;


}
  
 
void DLL::queueError(string msg)
{

  cout << msg << endl;
    exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors

}

DLL::~DLL()
{
  while (!isEmpty())
    {
      deleteFront();
    }
}
 
/*

void DLL::displayAll()const
{
  if(isEmpty())
    {
      cout << "[EMPTY]" << endl;
      // queueError("[EMPTY]");
    }
  else{
    // cout << "This is not empty" << endl;
    node*p = front;
    //counts the number of items in queue
    while(p!=NULL)
      {
	cout << p->elem << " " ;
	p = p-> next;
      }
    cout << endl;
  }
}


*/



void DLL::printAllReverseDLL()
{
  if (isEmpty()) {
    cout << "[empty]" << endl;
    return;
  }
  
  node* p = rear;
  while (p != NULL)
  {
    cout << p->elem << " ";  // Add space between elements
    p = p->prev;
  }
  cout << endl;  // Add newline after printing all elements
}




























/*
void DLL::addInOrderAscend(el_t e)
{
  node* p = front;
  if(front == NULL && rear == NULL)//if there are no elements inside of the heap memory. IT IS IMPORTANT THAT THERE ARE TWO ASSIGNMENT OPERATORS AND NOT ONE!
    {
      front = rear = new node;//front and rear will have the same node
      front->elem = e;//the front element or rear element would be set to the new added element in the linked list
      count++;//increment the heap memory
    }
  else//there are nodes inside of the heap memory
    {
      if(e < front->elem)//the node is less than the front element
        {
          node* newFront = new node;//to add a new front node
          newFront->elem = e;//set the element being passed to its assigned position
          newFront->next = front;//since it is ahead, it will be set previous to the front of the "original" node
          front = newFront;//since the front is new, it will be set to the newFront
          count++;//increment the heap memory
        }
      else if(e > rear->elem)//if the element is greater than the tail
        {
          rear->next = new node;//the new node after rear
          rear = rear->next;//the rear will now be set to the new node
          rear->elem = e;//add the element to its correct position
          rear->next = NULL;//the rear will now be NULL since it is now the new additional rear
          count++;//increment the count
        }
      else//if the node is inside the range rather than outside the rear/front
        {
          node* newNode = new node;//the node that will be entered within the range
          newNode->elem = e;//the new node element
          //newNode->next = NULL;
          while(p->next != NULL && p->next->elem < e)//this will verify when the node of the pointed front of the next elem is less than e and when it does not hit null
            {
              p = p->next;//this is when the pointed front will be set to the pointed next since I am adding the element in between two elements.
            }
          newNode->next = p->next;//this is to set the newNode's next into the pointed next to set the address
          p->next = newNode;//then the pointed next will be set to the NewNode's address and continues from there
        }
    }
}

*/




void DLL::displayAll()const
{
  if (isEmpty())
    {
    cout << "EMPTY";
    }
  node* p = front;
  while (p != NULL)
    {
    cout << p -> elem << ' ';
      p = p -> next;
    }
    cout << endl;
}







