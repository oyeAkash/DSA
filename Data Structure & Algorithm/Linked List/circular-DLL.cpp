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
    head->next = head;
    head->prev = head;
    tail = head;

    for (int i = 0; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        t->prev = tail;
        tail->next = t;
        tail = t;
        tail->next->prev = tail;
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
    p->next->prev = t;
    p->next = t;
}

void doublyLL ::Delete(int key)
{
    Node *p = head;
    Node *q = NULL;
    while (p->data != key && p->next != head)
    {
        q = p;
        p = p->next;
    }
    if (p->next == head && p->prev == head)
    {
       delete head;
       return;
    }
    else
    {
        q->next = p->next;
        p->next->prev = q;
        delete p;
        return;
    }
    
    cout << key << " Doesn't exist in the list." << endl;
}

void doublyLL::Reverse()
{
    Node *p = head;
    Node *temp = NULL;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p->prev == head)
        {
            head = p;
            break;
        }
    }
}


void doublyLL ::Display()
{
    Node *p = head;
    cout << "Circular Doubly List: ";

    while (p->next != head)
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

    // dl.Insert(5, 4);
    dl.Delete(1);
    // dl.Reverse();

    dl.Display();
    return 0;
}