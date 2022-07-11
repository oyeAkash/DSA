#include<iostream>
using namespace std;

double exp(int x, int n){
    static double p=1, f=1;
    double temp;
    if(n==0)
        return 1;
    temp = exp(x, n-1);
    p = p*x;
    f = f*n;
    return temp+p/f;
}
int main()
{
    cout << exp(3,10);
    return 0;
}