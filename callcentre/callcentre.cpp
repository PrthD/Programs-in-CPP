#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q, s, t;
    cin >> n >> q;
    vector<int> new_calls(n), calls_vec(q), cum_sum(n+1);

    // Read in the inputs
    for (int i = 0; i < n; i++)
    {
        cin >> new_calls[i];
    }
    cum_sum[0] = 0;
    cum_sum[1] = new_calls[0];
    for (int i = 2; i < n+1; i++)
    {
        cum_sum[i] = cum_sum[i-1]+ new_calls[i-1];
    }

    // Solve the problem
    for (int i = 0; i < q; i++)
    {
        cin >> s >> t;
        calls_vec[i] = cum_sum[t] - cum_sum[s-1];
    }

    // Output the result
    for (int i : calls_vec)
    {
        cout << i << endl;
    }
    return 0;
}