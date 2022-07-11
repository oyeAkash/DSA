#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        // code here
        int start = 0;
        int end = n - 1;
        sort(arr, arr + n);
        while (start < end)
        {
            int sum = arr[start] + arr[end];
            if (sum == x)
            {
                return true;
            }
            if (sum > x)
                end--;
            else
                start++;
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}