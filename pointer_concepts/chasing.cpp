#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  // declare variables
  int start, size;
  int index;
  cin >> start >> size;
  vector<int> memory(size);
  unordered_map<int, int> ind_ref;
  bool flag = false;

  // read the input
  for (int i = 0; i < size; i++)
  {
    cin >> memory[i];
  }

  // solve the problem and print the output
  ind_ref[0] = 1;
  if (memory[0] < 0)
  {
    cout << memory[0] << endl;
  }
  else
  {
    index = memory[0] - start;
    ind_ref[index] = 1;
    while (!flag)
    {
      if (memory[index] < 0)
      {
        cout << memory[index] << endl;
        flag = true;
      }
      else
      {
        index = memory[index] - start;
        ind_ref[index]++;
        if (ind_ref[index] == 2)
        {
          cout << "There was a cycle" << endl;
          flag = true;
        }
      }
    }
  }
  return 0;
}