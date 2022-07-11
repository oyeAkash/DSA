#include <iostream>
using namespace std;

class Term
{
public:
    int coeff, exp;
};
class Poly
{
public:
    int n;
    Term *t;
    friend istream &operator<<(istream &is, Poly &p);
    friend ostream &operator>>(ostream &os, Poly &p);
    Poly operator+(Poly &p);
};
istream &operator<<(istream &is, Poly &p)
{
    cout << "Enter no. of terms: ";
    cin >> p.n;
    p.t = new Term[p.n];
    for(int i=0; i<p.n; i++)
    {
        cin >> p.t[i].coeff >> p.t[i].exp;
    }
    return is;
}
ostream &operator>>(ostream &os, Poly &p)
{
    for(int i=0; i<p.n; i++)
    {
        cout << p.t[i].coeff << "x" << p.t[i].exp;
        if(i != p.n-1)
            cout << " + ";
    }
}

Poly Poly :: operator+(Poly &p)
{
    Poly *sum = new Poly;
    this->n = p.n + n;
    int i = 0, j=0;
    while(i <  && j <)
    {
        if()
    }
}
int main()
{

    return 0;
}