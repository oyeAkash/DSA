#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int n = 10, k = 10;
    int i = 0, j = n - 1;

    for (i = 0, j = n - 1; i < j;)
        // while (i < j)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                i++;
                j--;
            }
            else if (arr[i] + arr[j] < k)
                i++;
            else
                j--;
        }
    return 0;
}