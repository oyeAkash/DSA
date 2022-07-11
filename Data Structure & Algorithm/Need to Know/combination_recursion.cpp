#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    else 
        return fact(n-1)*n;
}
int normal_C(int n, int r){
    int f1,f2,f3;
    f1=fact(n);
    f2=fact(r);
    f3=fact(n-r);
    return f1/(f2*f3);
}

int recurse_C(int n, int r){
    if(r==0 || n==r)
        return 1;
    else    
        return recurse_C(n-1, r-1) + recurse_C(n-1, r);
}

int main()
{
    cout << normal_C(3,2) << endl;
    cout << recurse_C(4,2) << endl;
    return 0;
}