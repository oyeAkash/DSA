#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first;

void create_LL(int arr[], int size)
{
    Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i <= size; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count()
{
    int coun = 0;
    while(!first)
    {
        first =  first->next;
        coun++;
    }
    return coun;
}

void display(Node *ptr)
{
    if (ptr)
    {
        cout << "List: ";
        while (ptr->next != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    else
        cout << "List doesn't exist" << endl;

    cout << endl;
}

void reverse_1(Node *ptr, int size)
{
    int i=0;
    int A[size];
    // A = new int[size];
    while (ptr->next != NULL)
    {
        A[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    ptr = first;
    i--;
    while (ptr != NULL)
    {
        ptr->data = A[i];
        ptr = ptr->next;
        i--;
    }
}

void reverse_2(Node *ptr)
{
    Node *q = NULL, *r = NULL;
    while (ptr != NULL)
    {
        r = q;
        q = ptr;
        ptr = ptr->next;
        q->next = r;
    }
    first = q;
}

void reverse_3(Node *p, Node *ptr)
{
    if (ptr)
    {
        reverse_3(ptr, ptr->next);
        ptr->next = p;
    }
    else
    {
        first = p; 
    }
}

int main()
{
    int A[] = {1,2,3,4};
    int size = sizeof(A)/sizeof(A[0]);
    create_LL(A, size);
    display(first);

    // reverse_1(first, size);
    // display(first);

    // reverse_2(first);
    // display(first);

    reverse_3(NULL, first);
    display(first);

    return 0;
}