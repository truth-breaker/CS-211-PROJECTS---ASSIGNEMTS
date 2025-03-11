#include<iostream>
#include <assert.h>
using namespace std;

int binarySearchAscend(const int a[], int s, int key);
int main()

{

const int SIZE = 10;

int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
assert(SIZE!= 0); //passed - no output to screen

 //a.out: assert.cpp:10: int main(): Assertion `n == 0' failed.
//Aborted
 assert(SIZE > 0 );
for(int i = 0; i < SIZE; i++){
  
  assert(binarySearchAscend(ar,SIZE,ar[i]) != -1);
    assert(binarySearchAscend(ar,SIZE,100));
  cout<< ar[i]<<" was found at "<< binarySearchAscend(ar, SIZE, ar[i])<<endl;

  }


return 0;

}

int binarySearchAscend(const int a[], int s, int key)
{
   int l = 0; //left boudary starts at first index
   int r = s - 1; //right boundary starts at last index
   int m; //middle point between left and right.
   //When l and r cross over, search ends. --> key was not found.
   while(l <= r)
   {
       //calculate the middle point between l and r
       m = (l + r) / 2;
       if(a[m] == key) //key was found
           return m;
       else if(a[m] > key)
           r = m - 1;
       else
           l = m + 1;
   }
   return -1; //key wasn't found
}