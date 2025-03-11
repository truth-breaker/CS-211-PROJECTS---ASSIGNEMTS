//INSERTION SORT EXAMPLE CODE

#include <iostream>

using namespace std;

const int SIZE = 10;

int main()
{
  int arr[SIZE] = {42, 17, 0, -1, -15, 12, -12, 1, 100, 44};

  cout << "Before sorting: ";
  for(int i = 0; i < SIZE; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  //**********INSERTION SORT STARTS HERE**************

  for(int i = 1; i < SIZE; i++)
  {
    int temp = arr[i];
    int pos;
    for(pos = i - 1; pos >= 0 && arr[pos] > temp; pos--)
    {
      arr[pos+1] = arr[pos];
    }
    arr[pos+1] = temp;
  }

  //************INSERTION SORT ENDS HERE**************

  cout << "After sorting: ";
  for(int i = 0; i < SIZE; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}