#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
using namespace std;



//constructor
LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//Constructor to have a seperate list that consists of the same elements from source
LL::LL(const LL& source)
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

bool LL::isEmpty()
{
//check front,rear, and alos counr 0
  return(count == 0&&front == NULL && rear== NULL)?true:false; 
}
//Adds a new node at the front- 
void LL::addFront(el_t el)
{
  if(isEmpty()){
    rear= front=new node;
    front ->next= NULL;
  }
  else{
    node*p = new node;
    p-> next = front;
    front = p; 
    // front-> next = new node;
    // front = front-> next;
  }
  front-> elem = el;
  count++;
}




void LL::addRear(el_t el)
{
  if(isEmpty()){
    front=rear=new node;
  }
  else{
    rear-> next = new node;
    rear = rear-> next;
  }
  rear->elem = el;
  rear->next= NULL;
  count++;
}
el_t LL::deleteFront(){
  if(isEmpty()){
    queueError("Error: List is empty.");
  }
  el_t front1 = front -> elem;

  if(count == 1){
    delete front;
    front = rear = NULL;
    count = 0;
  }
else{
      //saves the fonr elem
  //    el_t front1 = front -> elem;
      node *p;       ;
      p =front->next;
      delete front;                 	
      front = p;
      count--;
      //    return front1;

    }
  return front1;

}

el_t LL::deleteRear() {
  if (isEmpty()) {
    queueError("Error: List is empty.");
    // Ensure the function returns a value in this case, even after the error
    el_t emptyValue;  // Define a return value to return after the error
    return emptyValue;  // Return an empty value (or an error value)
  } else {
    el_t temp;
    temp = rear->elem;
    
    // If there is only one element in the queue
    if (count == 1) {
      delete rear;
      front = rear = NULL;
    } else {
      // Iterate through nodes to find the second-to-last node (just before rear)
      node* p;
      for (p = front; p->next != rear; p = p->next) {
        ;
      }
      delete rear;
      rear = p;
      rear->next = NULL;
    }
    
    count--;
    return temp;
  }
}


void LL::deleteNode(el_t el)
{
  //node for previous num
  node *pre;
  //node for delete
  node* del;
  //must be outside the forloop
  if(isEmpty())
    {
      return;
      //cout <<"[EMPTY]" << endl;
    }  
  else if(el == front -> elem)
    {
      deleteFront();
    }
  else
    {
 
 for(pre = front,del= front->next;del!=NULL&&del->elem!=el;pre=del,del=del->next)
    ;
  if(del !=NULL) //nodes exists 
    {
      pre-> next = del->next;
      if(del == rear){
	rear= pre;
	}
      delete del;
      count --;
    } 
    }
}




void LL::deleteNodes(el_t n)
{
  while(front->next != NULL)
    {
      node *tmp;
      // int n;
      n=front->elem;
      tmp=front;
      front=front->next;
      delete tmp;
    }
  if (front !=NULL)
    {
      deleteFront();
    }
}



   /*
   //in order for the for loop to work if there was only one node
   if(el== front->elem){
     deleteFront();
   } 
    for(pre = front,del= front->next;del!=NULL&&del->elem!=e;pre=del,del=del->next){
     ;
    }
 //delete the nod pointed to by del -if del is NULL-no nodes have e 
  if(del !=NULL)
   {
     delete del;
   
   }
        
 
   }
   */
/*
void LL::deleteNodes(el_t el){
  node temp = new node;
   
 if(!isEmpty())
{
   while(el== front->elem){
    delete front;

    }
    for(pre = front,del= front->next;del!=NULL&&del->elem!=e;pre=del,del=del->next){
     ;
     }
  //delete the nod pointed to by del -if del is NULL-no nodes have e
    if(del !=NULL)
    {
      delete del;

    }
 }
} 
*/

void LL::addInOrderAscend(el_t e){
  node *p;
  // node* temp = new node;
  if(isEmpty())
 {
   addFront(e);
 }
  else if(e <= front-> elem){
    addFront(e);


  }
  else{

    p = front;
    
   while(p->next!= NULL&&p->next->elem<e){
    //new node pointing to p-> 
     p = p-> next;
    }
   node *next;

   next = p-> next;
   p -> next = new node;
   p-> next ->next = next;
   p-> next-> elem = e;
   count++;
  }



  // p->next =temp;
  //we want to add a new element in btwn the rear and the number before
  
}


 
bool LL::search(el_t e)
{
  node *p;
  int counter = 0;  
  for(p = front;p != NULL;p =p->next)
   
    {
      if(p->elem==e)
	
	//ut<< counter << " Nodes checked" << endl;
	return true;
      counter++;
      //	cout<< counter << " Nodes checked" << endl;

    }
  //ounter ++;
  cout<< counter << " Nodes checked" << endl;
   return false;


}
  
 
void LL::queueError(string msg)
{

  cout << msg << endl;
    exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors

}




void LL::displayAll()
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
  }
}
