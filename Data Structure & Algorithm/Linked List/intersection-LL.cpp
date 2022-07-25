#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first, *second;

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

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {5, 15, 25};
    int Asize = sizeof(A) / sizeof(A[0]);
    int Bsize = sizeof(B) / sizeof(B[0]);
    first = create_LL(A, Asize);
    cout << "First ";
    display(first);

    second = create_LL(B, Bsize);
    Node *p = first;
    for(int i=1; i<3; i++)
    {
        p = p->next;
    }
    Node *q = second;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    cout << "Second ";
    display(second);

    return 0;
}