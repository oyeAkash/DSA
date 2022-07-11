#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class Sparse
{
private:
    int m, n, num;
    Element *ele;

public:
    void Create();
    void Display();
};

void Sparse ::Create()
{
    cout << "Enter Dimension: ";
    cin >> m >> n;
    cout << "Number of non-zero element: ";
    cin >> num;
    ele = new Element[num];
    cout << "Enter row, column & element: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }
}

void Sparse ::Display()
{
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == ele[k].i && j == ele[k].j)
            {
                cout << ele[k++].x << ' ';
            }
            else
            {
                cout << "0" << ' ';
            }
        }
        cout << endl;
    }
}
int main()
{
    Sparse s1;
    s1.Create();
    s1.Display();
    return 0;
}