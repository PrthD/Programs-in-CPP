#include <iostream>
#include <map>
using namespace std;

int main()
{
	// Read in the input
	int west, east, time, tot_time = 0;
	char curr_bank = 'w';
	map<int, char> arrival_time;

	cin >> west >> east;

	for (int i = 0; i < west; i++)
	{
		cin >> time;
		arrival_time[time] = 'w';
	}
	for (int i = 0; i < east; i++)
	{
		cin >> time;
		arrival_time[time] = 'e';
	}

	// Solve the problem
	auto iter = arrival_time.begin();
	while (iter != arrival_time.end())
	{
		if (tot_time < iter->first)
		{
			if (iter == arrival_time.begin())
			{
				tot_time += iter->first;
			}
			else
			{
				tot_time += iter->first - tot_time;
			}
		}
		if (iter->second != curr_bank)
		{
			tot_time += 200;
		}
		else
		{
			tot_time += 100;
			if (curr_bank == 'w')
			{
				curr_bank = 'e';
			}
			else
			{
				curr_bank = 'w';
			}
		}
		iter++;
	}

	// Output the result
	cout << tot_time << endl;

	return 0;
}