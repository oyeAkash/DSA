#include <iostream>
using namespace std;

class Term
{
    public:
        int coeff, exp;
};

class Poly
{
        int n;
    public:
        Term *t;
        void create();
        void display();
};

void Poly :: create()
{
    cout << "Enter no. of terms: ";
    cin >> n;
    t = new Term[n];
    cout << "Enter terms" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> t[i].coeff >> t[i].exp;
    }
}

void Poly :: display()
{
    for(int i=0; i<n; i++)
    {
        cout << t[i].coeff << "x^" << t[i].exp;
        if(i != n-1)
            cout << " + ";
    }
}

int main()
{
    Poly p1;
    p1.create();
    p1.display();   
    return 0;
}