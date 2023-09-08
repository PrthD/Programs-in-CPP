#include <iostream>
using namespace std;

int main()
{
	// Declare your variables
	int n, m, array[100000];
	cin >> n >> m;

	long long mult_prod = 1;
	long long *left_bound = new long long[n];
	long long *right_bound = new long long[n];

	// Read the input
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	// Solve the problem. Output the answer
	for (int i = 0; i < (n - 1 - m); i++)
	{
		mult_prod *= array[n - 1 - i];
		left_bound[n - m - i - 2] = mult_prod;
	}

	for (int i = (n - 1 - m); i < n; i++)
	{
		left_bound[i] = 0;
	}

	for (int i = 0; i <= m; i++)
	{
		right_bound[i] = 0;
	}

	mult_prod = 1;

	for (int i = (m + 1); i < n; i++)
	{
		mult_prod *= array[i - 1 - m];
		right_bound[i] = mult_prod;
	}

	for (int i = 0; i < n; i++)
	{

		if (i <= m)
		{
			mult_prod = left_bound[i];
		}
		else if (i >= (n - 1 - m))
		{
			mult_prod = right_bound[i];
		}
		else
		{
			mult_prod = left_bound[i] * right_bound[i];
		}

		if ((m == i) && (i == (n - 1) / 2))
		{

			if (n - 1 != 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (n - 1 == i)
		{
			cout << mult_prod << endl;
		}
		else
		{
			cout << mult_prod << " ";
		}
	}

	return 0;
}