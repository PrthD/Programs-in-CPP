// -------------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #2 - Idols
// -------------------------------------------------------

#include <iostream>

/*
    Description: Reverses all entries (of an array) between
                 two pointers (input arguments) including the
                 entry pointed to by "begin" but not the entry
                 pointed to by "end".

    Arguments:
        begin (pointer): pointer pointing an integer entry of
                         an array.
        end (pointer): pointer pointing an integer entry of an
                       array that has an index greater than or
                       equal to that of "begin".

    Returns: This function returns NOTHING.
*/
void reverse(int *begin, int *end)
{
    while (begin < end - 1)
    {
        /* assigning the value stored by the "begin" pointer
           to a temporary variable new_end */
        int new_end = *begin;
        /* reversing the order of entries by assigning the
           value stored by the later pointers to the earlier
           pointers */
        *begin = *(end - 1);
        *(end - 1) = new_end;
        /* accessing all entries (between the original pointers)
           by increasing and decreasing the pointers by 1 */
        begin++, end--;
    }
}

int main()
{
    int n;
    int entry;
    int *begin;
    int *end;

    std::cin >> n;
    int arr[n];

    for (int k = 0; k < n; k++)
    {
        std::cin >> entry;
        arr[k] = entry;
    }

    /* checking for idols by iterating over the array
       and confirming the conditions of an idol with
       the help of nested for loops */
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            /* starting point of the group before the first idol */
            begin = arr;
        }
        for (int j = i + 1; j < n; j++)
        {
            /* checking for the idol conditions */
            if (arr[j] >= arr[i])
            {
                break;
            }
            else if (j == n - 1)
            {
                /* printing out the current idol if all entries of the
                   array on its right are smaller than itself */
                std::cout << arr[i] << ' ';
                /* assigning the current idol as the end point of the
                   group if all entries of the array on its right are
                   smaller than itself */
                end = &arr[i];
                /* calling the reverse function to reverse the entries
                   betwen "begin" and "end" */
                reverse(begin, end);
                /* the (*end+1) of a previous group is the *begin of the
                   next group */
                begin = &arr[i + 1];
            }
        }
        if (i == n - 1)
        {
            /* the last entry of the array is always an idol */
            std::cout << arr[i] << std::endl;
            /* assigning the last entry of the array as the
               endpoint of the LAST group */
            end = &arr[i];
            /* reversing the last group of the array */
            reverse(begin, end);
        }
    }
    /* printing the new array after all groups are reversed */
    for (int l = 0; l < n; l++)
    {
        if (l != n - 1)
        {
            std::cout << arr[l] << ' ';
        }
        else
        {
            std::cout << arr[l] << std::endl;
        }
    }
    return 0;
}