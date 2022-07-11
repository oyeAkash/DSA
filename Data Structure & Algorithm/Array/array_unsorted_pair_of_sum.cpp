#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int h[15] = {0};
    int k = 10;
    cout << "1st METHOD        --> O(n^2)\n\n";
    // method-->> 1-->> It will take O(n^2) time
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (k - arr[i] == arr[j])
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
        }
    }
    cout << "\n2nd METHOD      --> O(n)\n\n";
    // method-->>2-->> It will take O(n) time
    for (int i = 0; i < 10; i++)
    {
        if (h[k - arr[i]] != 0)
        {
            cout << arr[i] << " + " << k - arr[i] << " = " << k << endl;
        }
            h[arr[i]]++;
    }
    return 0;
}