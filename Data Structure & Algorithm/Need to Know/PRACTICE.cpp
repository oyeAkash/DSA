// { Driver Code Starts
// Initial template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        int count = 0, i = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }

            if (j == n - 1 && i != n - 1)
            {
                i++;
                j = 0;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     int arr[n];
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     Solution ob;
    //     auto ans = ob.getPairsCount(arr, n, k);
    //     cout << ans << "\n";
    // }
    int count = 0, i = 0, k = 2;
    int n = 4;
    int arr[n] = {1, 1, 1, 1};
    for (int j = i + 1; j < n; j++)
    {
        if (arr[i] + arr[j] == k)
        {
            count++;
        }

        if (j == n - 1 && i != n - 1)
        {
            i++;
            j = i + 1;
        }
    }
    cout << count;
    return 0;
} // } Driver Code Ends