#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * first, *second, *third;

struct Node *create_LL(int arr[], int size)
{
    Node *list, *t, *last;
    list = new Node;
    list->data = arr[0];
    list->next = NULL;
    last = list;

    for (int i = 1; i <= size; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return list;
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

void merge(Node *p, Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        last = third = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        last = third = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {5, 15, 25, 35, 45};
    int Asize = sizeof(A) / sizeof(A[0]);
    int Bsize = sizeof(B) / sizeof(B[0]);
    first = create_LL(A, Asize);
    cout << "First ";
    display(first);

    cout << "Second ";
    second = create_LL(B, Bsize);
    display(second);

    merge(first, second);
    cout << "Merged ";
    display(first);

    return 0;
}