#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class doublyLL
{
private:
    Node *head;
    Node *tail;

public:
    doublyLL(int *A, int n);
    void Insert(int index, int val);
    void Delete(int key);
    void Reverse();
    void Display();
};

doublyLL ::doublyLL(int *A, int n)
{
    Node *t = NULL;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    for (int i = 0; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        t->prev = tail;
        tail->next = t;
        tail = t;
    }
}

void doublyLL ::Insert(int index, int val)
{
    Node *p = head;
    Node *t = NULL;
    if (index < 0)
    {
        cout << "index- " << index << " doesn't exist..." << endl;
        return;
    }

    if (index == 0)
    {
        t = new Node;
        t->data = val;
        t->prev = head->prev;
        t->next = head;
        head->prev = t;
        head = t;
        return;
    }
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
    }
    t = new Node;
    t->data = val;
    t->prev = p;
    t->next = p->next;
    if (p->next)
    {
        p->next->prev = t;
    }
    p->next = t;
}

void doublyLL ::Delete(int key)
{
    Node *p = head;
    Node *q;
    while (p->data != key && p != NULL)
    {
        q = p;
        p = p->next;
    }
    if (p == head)
    {
        if (p->next)
        {
            p = p->next;
            p->prev = NULL;
            delete head;
            head = p;
        }
        else
        {
            delete head;
        }
    }
    else
    {
        q->next = p->next;
        if (p->next)
            p->next->prev = q;
        delete p;
    }
}

void doublyLL::Reverse()
{
    Node *p = head;
    Node *temp = NULL;
    while(p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL)
        {
            head = p;
        }
    }
}


void doublyLL ::Display()
{
    Node *p = head;
    cout << "Doubly List: ";

    /* ----->>****Display from head****<<----- */

    while (p != NULL)
    {
        p = p->next;
        cout << p->data << " <-> ";
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);
    doublyLL dl(A, n);

    dl.Reverse();
    // dl.Insert(5, 4);
    // dl.Delete(4);
    dl.Display();
    return 0;
}