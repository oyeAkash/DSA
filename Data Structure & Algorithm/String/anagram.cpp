#include <iostream>
using namespace std;

int main()
{
    char a[] = "verbose";
    char b[] = "observe";
    int size1 = 0, size2 = 0, i, h[26] = {0};
    for (i = 0; a[i] != '\0'; i++)
    {
        size1++;
    }
    for (i = 0; b[i] != '\0'; i++)
    {
        size2++;
    }
    if (size1 == size2)
    {
        for (i = 0; a[i] != '\0'; i++)
        {
            h[(a[i] - 97)]++;
        }
        for (i = 0; b[i] != '\0'; i++)
        {
            h[(b[i] - 97)]--;
            if (h[(b[i] - 97)] < 0)
            {
                cout << "It's not Anagram." << endl;
                break;
            }
        }
        if (b[i] == '\0')
        cout << "It's Anagram." << endl;
    }
    else
        cout << "It's not Anagram." << endl;
    return 0;
}