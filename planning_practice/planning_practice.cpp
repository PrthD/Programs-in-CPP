#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// Declare your variables
	int neighbors, time;
	int leave, arrive;
	vector<int> leave_sch_day, arrive_sch_day;
	vector<int> leave_sch_nig, arrive_sch_nig;
	int practice;
	int arrive_day, arrive_nig, leave_day, leave_nig;

	// Read the input
	cin >> neighbors >> time;
	for (int i = 0; i < neighbors; i++)
	{
		cin >> leave >> arrive;
		if (leave >= 12)
		{
			leave_sch_nig.push_back(leave);
			arrive_sch_nig.push_back(arrive);
		}
		else
		{
			leave_sch_day.push_back(leave);
			arrive_sch_day.push_back(arrive);
		}
	}

	// Solve the problem. Good luck! :)
	if (!leave_sch_day.empty())
	{
		leave_day = *max_element(leave_sch_day.begin(), leave_sch_day.end());
		arrive_day = *min_element(arrive_sch_day.begin(), arrive_sch_day.end());
	}
	if (!leave_sch_nig.empty())
	{
		leave_nig = *max_element(leave_sch_nig.begin(), leave_sch_nig.end());
		arrive_nig = *min_element(arrive_sch_nig.begin(), arrive_sch_nig.end());
	}

	// Output the answer
	if ((arrive_day <= leave_nig) && (arrive_nig <= leave_day))
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else if (leave_sch_nig.empty())
	{
		practice = arrive_day - leave_day;
		if (time % practice == 0)
		{
			cout << time / practice << endl;
		}
		else
		{
			cout << time / practice + 1 << endl;
		}
	}
	else if (leave_sch_day.empty())
	{
		practice = 24 - leave_nig + arrive_nig;
		if (time % practice == 0)
		{
			cout << time / practice << endl;
		}
		else
		{
			cout << time / practice + 1 << endl;
		}
	}
	else if ((arrive_day > leave_nig) && (!leave_sch_nig.empty()) && (!leave_sch_day.empty()))
	{
		practice = arrive_day - leave_nig;
		if (time % practice == 0)
		{
			cout << time / practice << endl;
		}
		else
		{
			cout << time / practice + 1 << endl;
		}
	}
	else if ((arrive_nig > leave_day) && (!leave_sch_nig.empty()) && (!leave_sch_day.empty()))
	{
		practice = arrive_nig - leave_day;
		if (time % practice == 0)
		{
			cout << time / practice << endl;
		}
		else
		{
			cout << time / practice + 1 << endl;
		}
	}
	return 0;
}