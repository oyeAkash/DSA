#include <iostream>
using namespace std;

void perm(char s[], int l, int h)
{
    int i;
    if (l == h)
    {
        cout << s << ' ';
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            perm(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    char s[] = "ABC";
    perm(s, 0, 2);
    return 0;
}