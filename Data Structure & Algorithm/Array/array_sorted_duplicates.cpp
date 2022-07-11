#include <iostream>
using namespace std;

void Duplicates_1(int sorted[], int size)
{
    int lastDuplicate = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (sorted[i] == sorted[i + 1] && sorted[i] != lastDuplicate)
            cout << "duplicates of " << sorted[i] << " is present." << endl;

        lastDuplicate = sorted[i];
    }
}
void Duplicates_2(int sorted[], int size)
{
    int hashing[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        hashing[sorted[i]]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (hashing[i] > 1)
            cout << "duplicates of " << i << " is present." << endl;
    }
}
void numOFduplicates_1(int sorted[], int size)
{
    int j, lastDuplicate = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (sorted[i] == sorted[i + 1])
        {
            j = i + 1;
            while (sorted[j] == sorted[i])
            {
                j++;
            }

            cout << sorted[j - 1] << " is appearing " << j - i << " times." << endl;
            i = j - 1;
        }
    }
}
void numOFduplicates_2(int sorted[], int size)
{
    int hashing[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        hashing[sorted[i]]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (hashing[i] > 1)
            cout << i << " has " << hashing[i] << " duplicates" << endl;
    }
}
void Duplicate_in_unsorted_arr(int unsorted_arr[], int size)
{
    for (int i = 0; i < 10; i++)
    {
        int count = 1;
        for (int j = 0; j < 10; j++)
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

int main()
{
    int size = 10;
    int sorted[] = {1, 2, 3, 3, 4, 8, 8, 8, 9, 10};
    cout << "+++====+++DUPLICATES in sorted sorted array+++===+++" << endl
         << "\t\nMEATHOD -->> 1\n\n";
    Duplicates_1(sorted, size);

    cout << "\t\nMEATHOD -->> 2\n\n";
    Duplicates_2(sorted, size);

    cout << "\n+++====+++Number of DUPLICATES in sorted array+++===+++" << endl
         << "\t\nMETHOD -->> 1\n\n";
    numOFduplicates_1(sorted, size);

    cout << "\t\nMETHOD -->> 2\n\n";
    numOFduplicates_2(sorted, size);
    return 0;
}