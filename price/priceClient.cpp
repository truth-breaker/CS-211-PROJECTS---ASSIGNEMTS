#include <iostream>
#include "price.h"
using namespace std;

int main()
{
  //creating 4 Price class objects as mentioned.
  Price p1(2, 50), p2(3, 75), p3(1, 99), p4(1, 58);
    
  Price total1 = p1 + p2;
  Price total2 = p1 + p1;
  Price total3 = p1 + p4;
  Price diff1 = p2 - p1;
  Price diff2 = p1 - p3;

  //driver code
  cout << "$" << p1 << "+$" << p2 << "=$" << total1 << endl; //$2.50+$3.75=$6.25
  cout << "$" << p1 << "+$" << p1 << "=$" << total2 << endl; //$2.50+$2.50=$5.00
  cout << "$" << p1 << "+$" << p4 << "=$" << total3 << endl; //$2.50+$1.58=$4.08
  cout << "$" << p2 << "-$" << p1 << "=$" << diff1 << endl; //$3.75-$2.50=$1.25
  cout << "$" << p1 << "-$" << p3 << "=$" << diff2 << endl; //$2.50-$1.99=$0.51
  return 0;
}
