#include<iostream>
using namespace std;

double e(int x, int n){
    static double result = 1;
    if(n==0)
        return result;
    result = 1+(double)x*result/n;
    return e(x, n-1);
}
double Itr_e(int x, int n){
    double result = 1;
    for(; n>0; n--){
        result = 1+(double)x*result/n;
    }
    return result;
}
int main()
{
    cout << e(2,10) << endl;
    cout << Itr_e(2,10);
    return 0;
}