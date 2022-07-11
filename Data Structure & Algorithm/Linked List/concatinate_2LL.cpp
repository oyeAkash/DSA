#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
} *first, *second, *third;

struct Node* create_LL(int arr[], int size)
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

void concatinate(Node *p, Node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}
int main()
{
    int A[] = {1,2,3,4,5};
    int B[] = {11,12,13,14,15,16};
    int Asize = sizeof(A)/sizeof(A[0]);
    int Bsize = sizeof(B)/sizeof(B[0]);
    first = create_LL(A, Asize);
    cout << "First ";
    display(first);

    cout << "Second ";
    second = create_LL(B, Bsize);
    display(second);
    
    concatinate(first, second);
    cout << "Concatinated ";
    display(third);
    return 0;
}