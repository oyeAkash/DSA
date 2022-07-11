#include <iostream>
using namespace std;

void Method1(int a[], int n)
{
    int sum = 0, diff = 0, s = 0;
    for (int i = 0; i < n; i++)
        sum = sum + a[i];
    s = (n + 1) * (n + 2) / 2;
    diff = s - sum;
    cout << "Missing number is: " << diff << endl;
}
void Method2(int a[], int n)
{
    int diff = a[0] - 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            cout << "Missing number is: " << i + diff << endl;
            break;
        }
    }
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter number of elements of array: " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Method- 1" << endl;
    Method1(a, n);
    cout << "Method- 2" << endl;
    Method2(a, n);
    return 0;
}