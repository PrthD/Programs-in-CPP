// --------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #7: Divide and Conquer
// --------------------------------------------------

#include <iostream>

using namespace std;

typedef unsigned int uint;

/*
    Description: Function calculates the maximum difference between two consecutive heights of the ledges of a cliff in
                 a dynamically allocated array in ascending order.

    Arguments:
        heights (const uint*): pointer pointing to the dynamically allocated array of heights
        length (uint): the length of the array

    Returns:
        max_Diff (uint): the maximum difference between two consecutive ledges (i.e., the burst needed to climb the cliff)
*/
uint calculate_Max_Burst(const uint *heights, uint length)
{
    uint max_Diff = 0;   // Variable to store the maximum difference between two consecutive ledges
    uint crrnt_Diff = 0; // Variable to store the difference between the current and previous ledge

    for (int i = length - 1; i >= 0; i--)
    {
        crrnt_Diff = heights[i] - heights[i - 1]; // Calculate the difference between the current and previous ledge
        if (crrnt_Diff > max_Diff)
        {
            max_Diff = crrnt_Diff; // Update the maximum difference if a larger difference is found
        }
    }

    return max_Diff; // Return the maximum difference (i.e., burst needed to climb the cliff)
}

/*
    Description: Given a specific burst value, the function calculates the amount of time it takes to travel up the cliff,
                 taking into account the burst value, rest time, and the heights of the ledges.

    Arguments:
        heights (const uint*): pointer pointing to a dynamically allocated array filled with ascending order of ledge heights
        length (uint): the length of the array
        burst (uint): the maximum distance that can be travelled before rest is needed
        rest (uint): time it takes per rest

    Returns:
        time (uint): the time it takes to get to the peak of the cliff
*/
uint calculate_Time(uint burst, const uint *heights, uint rest, uint length)
{
    uint time = 0;                  // Variable to store the total time taken to reach the peak of the cliff
    uint height = 0;                // Variable to store the current height during the climb
    uint num_rest = 0;              // Variable to store the number of rests taken during the climb
    uint index = 0;                 // Variable to store the current index in the array of heights
    uint max = heights[length - 1]; // Variable to store the maximum height (i.e., the peak of the cliff)
    uint init_brst = burst;         // A copy of the variable burst

    while (height < max)
    {
        if (burst > max)
        { // If our burst gets us above the max ledge, we're at the peak ledge
            height = max;
            break;
        }

        if (heights[index] > burst)
        {
            height = heights[index - 1]; // Go to the previous ledge
            burst = height + init_brst;  // Burst goes to our ledge height + our initial burst value
            num_rest++;
        }

        if (heights[index] == burst)
        {
            if (index == length - 1)
            {
                height = heights[index]; // we're at the peak ledge
            }
            else
            {
                height = heights[index];
                burst = height + init_brst;
                num_rest++;
            }
        }
        index++;
    }

    time = height + rest * num_rest; // Calculate the total time taken, including rests
    return time;
}

/*
    Description: Binary search algorithm to find the minimum burst value that allows for cliff traversal within the given
                 time limit.

    Arguments:
        heights (const uint*): pointer pointing to a dynamically allocated array filled with ascending order of ledge heights.
        length (uint): the length of the array
        rest (uint): time it takes per rest
        limit (uint): largest possible time for cliff traversal

    Returns:
        upper_bound (uint): the minimum burst value for the given time limit.
*/
uint climbing(const uint *heights, uint length, uint rest, uint limit)
{
    uint upper_bound = heights[length - 1];                      // Variable to store the upper bound of the burst value
    uint lower_bound = calculate_Max_Burst(heights, length) - 1; // Variable to store the lower bound of the burst value
    uint min_burst = 0;                                          // Variable to store the minimum burst value found

    while (lower_bound + 1 < upper_bound)
    {
        min_burst = (upper_bound + lower_bound) / 2; // Calculate the mid-point burst value

        if (calculate_Time(min_burst, heights, rest, length) <= limit)
        {
            upper_bound = min_burst; // Update the upper bound to search for a lower burst value
        }
        else
        {
            lower_bound = min_burst; // Update the lower bound to search for a higher burst value
        }
    }

    return upper_bound; // Return the minimum burst value found
}

int main()
{
    uint length, rest, limit;
    cin >> length >> rest >> limit;

    uint *heights = new uint[length]; // Dynamically allocate an array to store ledge heights
    for (uint i = 0; i < length; i++)
    {
        cin >> heights[i];
    }

    uint burst = climbing(heights, length, rest, limit); // Call climbing function to find minimum burst value
    cout << burst << endl;

    return 0;
}