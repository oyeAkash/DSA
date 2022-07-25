#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    void Search(int val);
    int Delete(int index);
    void Delete_duplicate();
    int Length();
    int Sum();
    void Middle_ele();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length()
{
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void LinkedList ::Search(int val)
{
    int i = 0;
    while (first != NULL)
    {
        if (val == first->data)
        {
            i++;
            cout << "Key has found" << endl;
        }
        first = first->next;
    }
    if (i == 0)
        cout << "Key not found" << endl;
}
int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

void LinkedList ::Delete_duplicate()
{
    Node *p = first;
    first = first->next;

    while (first != NULL)
    {
        if (p->data != first->data)
        {
            p = first;
            first = first->next;
        }
        else
        {
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }
}
int LinkedList :: Sum()
{
    int sum = 0;
    while (first)
    {
        sum += first->data;
        first = first->next;
    }
    return sum;
}

void LinkedList ::Middle_ele()
{
    Node *p = first;
    while(p)
    {
        p = p->next;
        if(p)
            p = p->next;
        if(p)
            first = first->next;
    }
    cout << "Middle Element: " << first->data << endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    
    l.Display();
    l.Middle_ele();
    return 0;
}