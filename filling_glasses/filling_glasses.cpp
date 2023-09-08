#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_glass, kth_glass, unit_time, index, time;
    cin >> num_glass >> kth_glass >> unit_time;
    vector<int> capacity(num_glass), source(num_glass);

    // taking input
    for (int i = 0; i < num_glass; i++)
    {
        cin >> capacity[i] >> source[i];
    }

    // solving problem
    if (kth_glass == 0)
    {
        cout << unit_time << endl;
    }
    else
    {
        index = kth_glass;
        time = capacity[0] * unit_time;
        while (index != 0)
        {
            time += capacity[index] * unit_time;
            index = source[index];
        }
        cout << time << endl;
    }

    return 0;
}