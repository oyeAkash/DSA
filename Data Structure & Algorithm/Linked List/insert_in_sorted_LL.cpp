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

bool is_sorted(Node *ptr)
{
    int x = -65536;
    while (ptr != NULL)
    {
        if (ptr->data < x)
            return false;

        x = ptr->data;
        ptr = ptr->next;
    }
    return true;
}
void insert_in_sortedLL(Node *ptr, int val)
{
    if (!is_sorted(ptr))
    {
        cout << "List is not sorted" << endl;
        return;
    }
    Node *t, *q = NULL;
    t = new Node;
    t->data = val;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (ptr->data < val)
        {
            q = ptr;
            ptr = ptr->next;
        }
        t->next = q->next;
        q->next = t;
    }
}
int main()
{
    int list_ele[] = {1, 3, 5, 7, 9, 10};

    create_LL(list_ele, sizeof(list_ele) / sizeof(list_ele[0]));
    cout << "Sorted ";
    display(first);

    insert_in_sortedLL(first, 2);
    insert_in_sortedLL(first, 4);
    display(first);

    return 0;
}