#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node *p);
    Node *getHead() { return head; }
    void Insert(int pos, int val);
    void Delete(int key);
    int Length(Node *p);
    ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int *A, int n)
{

    Node *t;
    Node *tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

int CircularLinkedList ::Length(Node *p)
{
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}
void CircularLinkedList::Display()
{
    cout << "List: ";
    Node *p = head;
    do
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

void CircularLinkedList::recursiveDisplay(Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

void CircularLinkedList ::Insert(int pos, int val)
{
    Node *p = head;
    Node *t = new Node;
    t->data = val;

    if (pos < 0 || pos > Length(head))
    {
        cout << pos << " position doesn't exist in the list." << endl;
        return;
    }
    if (pos == 0)
    {
        if (head = NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void CircularLinkedList ::Delete(int key)
{
    Node *p = head;
    Node *q = NULL;

    /* do
    {
        q = p;
        p = p->next;
        if(p->data == key){
            q->next = p->next;
            cout << key << " has deleted from the list..." << endl;
            return;
        }
    } while (q->next != head);
    cout << key << " doesn't exist in the list..." << endl; */
    if (p->data == key)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        if(p == head)
        {
            delete head;
            head = nullptr;
            cout << key << " has deleted from the list..." << endl;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
            cout << key << " has deleted from the list..." << endl;
        }
        return;
    }
    while (p->data != key)
    {
        q = p;
        p = p->next;
        if (p == head)
        {
            cout << key << " doesn't exist in the list." << endl;
            return;
        }
    }
    q->next = p->next;
    delete p;
    cout << key << " has deleted from the list..." << endl;
}

CircularLinkedList::~CircularLinkedList()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head)
    {
        delete head;
        head = nullptr;
    }
}

int main()
{

    int A[] = {1, 3, 5, 7, 9};
    CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));
    cl.Display();

    Node *h = cl.getHead();

    cl.Delete(1);
    cl.Display();
    return 0;
}