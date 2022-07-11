#include <iostream>
using namespace std;

void method_1(int unsorted_arr[], int size)
{
    for (int i = 0; i < 9; i++)
    {
        int count = 1;
        for (int j = 1; j < 10; j++)
        {
            if (unsorted_arr[i] == unsorted_arr[j])
            {
                count++;
                unsorted_arr[j] = -1;
            }
        }
        if (count < 1)
            cout << unsorted_arr[i] << " has " << count << "duplicates" << endl;
    }
}
void method_2(int sorted[], int size)
{
    int hashing[9] = {0};
    for (int i = 0; i <9 ; i++)
    {
        hashing[sorted[i]]++;
    }
    for (int i = 0; i < 9; i++)
    {
        if (hashing[i] > 1)
            cout << i << " has " << hashing[i] << " duplicates" << endl;
    }
}

int main()
{
    int size = 10;
    int unsorte_arr[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    cout << "\n+++====+++Number of DUPLICATES in unsorted_arr array+++===+++" << endl
         << "\t\nMETHOD -->> 1\n\n";
    method_1(unsorte_arr, size);

    cout << "\t\nMETHOD -->> 2\n\n";
    method_2(unsorte_arr, size);
    return 0;
}