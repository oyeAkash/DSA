#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *arr;

public:
    Stack(int x);
    ~Stack();
    void isEmpty();
    void isFull();
    void push(int x);
    void pop();
    void peek(int index);
    void stackTop();
    void display();
};

Stack::Stack(int x)
{
    size = x;
    arr = new int[size];
    top = -1;
}

Stack ::~Stack()
{
    delete[] arr;
}

void Stack::isEmpty()
{
    if (top == -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void Stack ::isFull()
{
    if (top == size - 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void Stack ::push(int x)
{
    if ( top == size-1)
    {
        cout << "\nStack overflow..!" << endl; 
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

void Stack ::pop()
{
    if (top > -1)
        cout << arr[top--] << " is poped" << endl;
    else
        cout << "Stack is underflow...!" << endl;
}

void Stack ::peek(int index)
{
    if (index <= top + 1 && index > -1)
        cout << "Stack(" << index << "): " << arr[top-index+1] << endl;
}

void Stack ::stackTop()
{
    if (top > -1)
        cout << "Top: " << arr[top] << endl;
}

void Stack ::display()
{
    cout << "Stack: ";
    for (int i = top; i > -1; i--)
        cout << arr[i] << " ";
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int size;
    cout << "Enter size: ";
    cin >> size;
    Stack st(size);

    for(int i=0; i<size; i++)
        st.push(a[i]);
    st.display();

    st.push(8);

    cout << endl;
    st.peek(3);

    st.stackTop();

    st.isEmpty();
    st.isFull();

    for(int i=0; i<size; i++)
        st.pop();

    st.pop();
    st.display();
    return 0;
}