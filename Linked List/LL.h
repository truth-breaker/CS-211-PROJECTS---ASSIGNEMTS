#ifndef LL_H
#define LL_H
#include <string>
#include <iostream>
using namespace std;
typedef int el_t;


struct node
{
   el_t elem; //element at this node is an integer
  node * next; //a link(pointer) to the next node 
  node* prev; // a link for previoud
};


class LL
{
 private:
  
  node* rear;
  node* front;
  int count;
  public:
  LL();
  LL(const LL& source);
  bool isEmpty();
  void addRear(el_t el);
  void addFront(el_t el);
  void queueError(string msg);
  void displayAll();
  el_t deleteFront();
  el_t deleteRear();
  void deleteNode(el_t el);
  void addInOrderAscend(el_t e);
  bool search(el_t e);
  void deleteNodes(el_t n); 
};
#endif
