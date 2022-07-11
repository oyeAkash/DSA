#include <iostream>
using namespace std;

void Multi_ele_sorted(int a[], int size)
{
    int diff = a[0] - 0;
    cout << "Missing numbers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        if (a[i] - i != diff)
        {
            while (diff < a[i] - i)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}
void Multi_ele_Unsorted(int a[], int size) /* size-->> number of elements in 'a[]' */
{
    int h[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; /* size is equal to max value of array 'a[]' i.e. 12 */
    int l = 1;                                        /* lowest value of 'a[]' */

    for (int i = 0; i < size; i++)
        h[a[i]]++;
    for (int i = l; i<12; i++){
        if(h[i]==0)
        cout <<"Missing nymber is: "<<i<<endl;
    }
}
int main()
{
    int n,size=0,a[50];
    cout<<"Find multiple missing number" <<endl
        <<"1- In Sorted array"<<endl
        <<"2- In unsorted array"<<endl<<endl
        <<"Enter your choice: ";
    cin>>n;
    switch(n){
        case 1:
            cout << "Enter size of array: ";
            cin >> size;
            cout << "Enter number of elements of array: " << endl;
            for (int i = 0; i < size; i++)
                cin >> a[i];
            Multi_ele_sorted(a, size);
            break;
        case 2:
            cout << "Enter size of array: ";
            cin >> size;
            cout << "Enter number of elements of array: " << endl;
            for (int i = 0; i < size; i++)
                cin >> a[i];
            Multi_ele_Unsorted(a, size);
            break;
    }
    
    return 0;
}