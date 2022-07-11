// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {

        /* vector<int> v(arr, arr + n);
        auto it = v.begin() + 1;
        for (int i = 0; i < n; i++)
        {
            if(find(it+i, v.end(), arr[i])!=v.end())
        } */

        /*  for (int i = 0; i < n; i++)
         {
             if(find(arr+(i+1), arr+n, arr[i])!=(arr+n))
                 return i+1;
         }*/
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            int key = arr[i];
            umap[key]++; // formed a dictonary of all key with their count as value
        }
        for (int i = 0; i < n; i++)
        {
            if (umap[arr[i]] > 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends// { Driver Code Starts
// Initial template for C++
