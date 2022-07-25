#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    ~Stack();
    void push(int x);
    void pop();
    int isEmpty();
    int isFull();
    void stackTop();
    void peek(int index);
    void Display();
};

Stack ::Stack()
{
    top = nullptr;
}
Stack ::~Stack()
{
    Node *p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack ::push(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    {
        cout << "Stack overflow." << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

void Stack ::pop()
{
    int x = -1;
    Node *p;
    if (top == nullptr)
    {
        cout << "Stack underflow.....!" << endl;
    }
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
        cout << x << " is poped." << endl;
    }
    
}

int Stack::isEmpty()
{
    return top ? 0 : 1;
}

int Stack::isFull()
{
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

void Stack ::peek(int index)
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *p = top;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        if(p)
            cout << "Stack(" << index << "): " << p->data << endl;
        else    
            cout << "Stack(" << index <<") doesn't exist." << endl;
    }
}

void Stack::stackTop()
{
    if(top)
        cout << top->data << endl;
    else
        cout << "Stack is empty." << endl;
}

void Stack ::Display()
{
    Node *p = top;
    cout << "Stack: ";
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
}

int main()
{
    Stack st;
    int arr[] = {1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    /* PUSH() */
    for(int i=0; i<size; i++)
        st.push(arr[i]);

    /* isFull or isEmpty */
    if(st.isEmpty())
        cout << "NO" << endl;
    else    
        cout << "YES" << endl;

    if(st.isFull())
        cout << "NO" << endl;
    else    
        cout << "YES" << endl;

    /* stackTOP */
    st.stackTop();

    /* PEEK */
    st.
    peek(1);

    /* DISPLAY */
    st.Display();

    /* POP */
    cout <<endl;
    st.pop(); st.pop(); st.pop(); st.pop();
}