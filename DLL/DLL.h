#ifndef DLL_H
#define DLL_H
#include <string>
#include <iostream>
using namespace std;
typedef int el_t;

struct node
{
  el_t elem; //element at this node is an integer
  node* next; //a link(pointer) to the next node 
  node* prev;
};


class DLL
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);
  public:
 DLL();
 ~DLL();
  DLL(const DLL& source);
  bool isEmpty()const;
  void addRear(el_t el);
  void addFront(el_t el);
  // void queueError(string msg);
  void displayAll()const;
  el_t deleteFront();
  el_t deleteRear();
  void deleteNode(el_t e);
  void addInOrderAscend(el_t e);
  bool search(el_t e);
  void printAllReverseDLL(); 
  // void deleteNodes(el_t n); 
};
#endif
