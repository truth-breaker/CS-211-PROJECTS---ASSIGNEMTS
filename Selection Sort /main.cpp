#include <iostream>

using namespace std;

const int SIZE = 5;

int main()  {

  int arr[SIZE] = {4,10,8,2,6};
 cout << " Before Sorting" << endl;
  //display array
  for(int i = 0; i < SIZE; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl << endl;
  
//**** SELECTION SORT STARTS HERE ****
  
  for(int startPos = 0; startPos < SIZE-1; startPos++) //loop through each element of array (except last)
  {
    int smallestPos = startPos; //starting element begins as smallest
    for(int currentPos = startPos + 1; currentPos < SIZE; currentPos++) //for each element to the right
      {
        if(arr[currentPos] < arr[smallestPos]) //if smaller than smallest so far
        {
          smallestPos = currentPos; //becomes smallest so far
        }
      }
    //swap elements of array at smallest position (arr[smallestPos]) and start position (arr[startPos])
    int temp = arr[startPos];
    arr[startPos] = arr[smallestPos];
    arr[smallestPos] = temp;
    //swap(arr[startPos], arr[smallestPos]); //or call built in swap instead
  }
  
//**** SELECTION SORT ENDS HERE ****
 cout << " After Sorting" << endl;

    //display array
  for(int i = 0; i < SIZE; i++)
  {
    cout << arr[i] << " ";
  }
  
  return 0;
}