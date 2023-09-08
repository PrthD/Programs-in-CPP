// --------------------------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #3: Interview Question (Sales Assistant)
// --------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declaring variables
    int num_prod, trgt_price;
    // Getting input for the number of products and target price
    cin >> num_prod >> trgt_price;
    vector<int> prices(num_prod);
    int left = 0, right = num_prod - 1;

    // Receiving the individual prices of all products as input
    for (int i = 0; i < num_prod; i++)
        cin >> prices[i];

    // Using two shifting indices to check if there are two prices
    // in the provided input that add up to target price until the
    // two indices meet
    while (left < right)
    {
        // Calculating the sum of prices at indices "left" and "right"
        int sum = prices[left] + prices[right];
        if (sum == trgt_price)
        {
            // If the sum equals the target price, "YES" is printed
            // and 0 is returned
            cout << "YES" << endl;
            return 0;
        }
        else if (sum < trgt_price)
        {
            // shifting the left index further right by 1 if the sum
            // calculated is less the than the target price which will
            // now increase the sum since the input is sorted
            left++;
        }
        else
        {
            // shifting the right index further left by 1 if the sum
            // calculated is more the than the target price which will
            // now reduce the sum since the input is sorted
            right--;
        }
    }
    // If no two prices add up to the target price, "NO" is printed and
    // o is returned
    cout << "NO" << endl;
    return 0;
}