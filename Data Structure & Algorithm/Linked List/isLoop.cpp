#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * first;

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

int isLoop(Node *p)
{
    Node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    Node *t1, *t2;
    int A[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(A) / sizeof(A[0]);

    create_LL(A, size);
    display(first);

    t1 = first;
    t2 = first->next->next->next->next->next;
    t2->next = t1;

    cout << isLoop(first);
    return 0;
}