#include <iostream>
#include <algorithm>
using namespace std;

int main()
{   
    // take input
    int numLoads, numMachines, dryingTime;
    cin >> numLoads >> numMachines >> dryingTime;

    int machineTimes[numMachines];
    for (int i = 0; i < numMachines; i++)
    {
        cin >> machineTimes[i];
    }
    sort(machineTimes, machineTimes + numMachines);

    // solving problem
    int minTime = 1, maxTime = 10000000;
    while (minTime < maxTime)
    {
        int midTime = (minTime + maxTime) / 2;
        int completedLoads = 0;
        for (int i = 0; i < numMachines && completedLoads < numLoads; i++)
        {
            int loadsPerMachine = (midTime - dryingTime) / machineTimes[i];
            completedLoads += loadsPerMachine;
        }
        if (completedLoads < numLoads)
        {
            minTime = midTime + 1;
        }
        else
        {
            maxTime = midTime;
        }
    }

    // printing results
    cout << minTime << endl;

    return 0;
}