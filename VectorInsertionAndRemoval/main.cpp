#include <iostream>
#include <vector>

using namespace std;


int main()  {

  vector<int> nums;

  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(6);
  nums.push_back(8);
  nums.push_back(10);

  
  int new_num, pos = 0;

  cout << "Enter number to insert into vector: ";
  cin >> new_num;

  while(new_num > nums[pos] && pos < nums.size())  {
    pos++;
  }
  
  if(pos == nums.size())  {
    nums.push_back(new_num);
  }  else  {
    nums.insert(nums.begin() + pos, new_num);
  }


  cout << "Size: " << nums.size() << endl;
  
  for(int i = 0; i < nums.size(); i++)  {
    cout << nums[i] << endl;
  }


  int remove_num, loc = -1;
  cout << "Enter number to remove from vector: ";
  cin >> remove_num;
  
  for(int i = 0; i < nums.size() && loc == -1; i++)  {
    if(nums[i] == remove_num)  {
      loc = i;
    }
  }

  if(loc != -1)  {
    nums.erase(nums.begin() + loc);
  }  else  {
    cout << remove_num << " not found in the vector.\n";
  }
  
  cout << "Size: " << nums.size() << endl;
  
  for(int i = 0; i < nums.size(); i++)  {
    cout << nums[i] << endl;
  }
  
  return 0;
}

