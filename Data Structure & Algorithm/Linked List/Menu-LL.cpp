#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int count(Node *ptr)
{
    int count = 0;
    while (!ptr)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
void insert_end(Node **first, int val)
{
    Node *temp = new Node;
    Node *ptr;

    temp->data = val;
    temp->next = NULL;

    if (*first == NULL)
        *first = temp;
    else
    {
        ptr = *first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_beg(Node **first, int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->next = *first;
    *first = temp;
}

void insert_nth(Node *ptr, int val, int index)
{
    Node *t;
    if (index < 0)
        return;

    t = new Node;
    t->data = val;

    if (index == 0)
    {
        t->next = ptr;
        ptr = t;
    }
    else
    {
        for (int i = 1; i < index; i++)
            ptr = ptr->next;

        t->next = ptr->next;
        ptr->next = t;
    }
}
void display(Node *first)
{
    if (first == NULL)
        cout << "No list found." << endl;
    else
    {
        cout << "List: ";
        while (first != NULL)
        {
            cout << first->data << " ";
            first = first->next;
        }
    }
    cout << endl
         << endl;
}

int Length(Node *first)
{
    int len = 0;
    while (first)
    {
        len++;
        first = first->next;
    }
    return len;
}
int Sum(Node *first)
{
    int sum = 0;
    while (first)
    {
        sum += first->data;
        first = first->next;
    }
    return sum;
}

int Largest_ele(Node *first)
{
    int largest = INT_MIN;
    if (first == 0)
        return INT_MIN;
    else
    {
        while (first)
        {
            if (first->data > largest)
                largest = first->data;

            first = first->next;
        }
    }
    return largest;
}

void Search_Normal(Node *first, int val)
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

void Search_moveToHead(Node *first, int val)
{
    Node *temp = NULL;
    Node *t = first;
    if (first == NULL || first->next == NULL)
        return;

    while (t->next != NULL)
    {
        if (val == t->data)
        {
            temp->next = t->next;
            t->next = first;
            first = t;
            cout << "\nKey found" << endl;
            break;
        }
        else
        {
            temp = t;
            t = t->next;
        }
    }
}

void delete_(Node *ptr, int val)
{
    Node *p = ptr;
    Node *q = NULL;
    while (p->data != val)
    {
        q = p;
        p = p->next;
        if (p == NULL)
        {
            cout << "Data is out of the list" << endl;
            return;
        }
    }
    q->next = p->next;
    delete p;
}

void delete_duplicate(Node *ptr)
{
    Node *p = ptr;
    ptr = ptr->next;

    while (ptr != NULL)
    {
        if (p->data != ptr->data)
        {
            p = ptr;
            ptr = ptr->next;
        }
        else
        {
            p->next = ptr->next;
            delete ptr;
            ptr = p->next;
        }
    }
}

void reverse_1(Node *first, int size)
{
    Node *p = first;
    int i = 0;
    int *A = new int[size];
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    first = p;
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}

void reverse_2(Node *first)
{
    Node *q = NULL, *r = NULL;
    while (first != NULL)
    {
        r = q;
        q = first;
        first = first->next;
        q->next = r;
    }
    first = q;
}

void reverse_3(Node *p, Node *first)
{
    if (first != NULL)
    {
        reverse_3(first, first->next);
        first->next = p;
    }
    else
        first = p;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *first = NULL;
    char optn;
    while (optn != '0')
    {
        cout << "\n\nEnter your choice" << endl
             << "0- EXIT" << endl
             << "1- Insertion" << endl
             << "2- Lenght of list" << endl
             << "3- Sum of all elements" << endl
             << "4- Largest element" << endl
             << "5- Searching" << endl
             << "6- Delete" << endl
             << "7- Delete Duplicate" << endl
             << "8- *Reverse" << endl;
        cin >> optn;
        switch (optn)
        {
        case '1':
            cout << "\na- At end" << endl
                 << "b- At begining" << endl
                 << "c- *At nth position" << endl;
            cin >> optn;
            switch (optn)
            {
            case 'a':
                for (int i = 0; i < size; i++)
                {
                    insert_end(&first, arr[i]);
                }
                display(first);
                break;
            case 'b':
                for (int i = 0; i < size; i++)
                {
                    insert_beg(&first, arr[i]);
                }
                display(first);
                break;
            case 'c':
                int index, val;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> val;
                insert_nth(first, val, index);
                display(first);
                break;
            default:
                cout << "Wrong choice 😛😛" << endl;
                break;
            }
            break;
        case '2':
            cout << "Length of list: " << Length(first);
            break;
        case '3':
            cout << "Sum of all elements: " << Sum(first);
            break;
        case '4':
            cout << "Largest element in the list is: " << Largest_ele(first);
            break;
        case '5':
            cout << "\n1- Normal Search" << endl
                 << "2- Move to Head Search" << endl;
            cin >> optn;
            switch (optn)
            {
            case '1':
                int val1;
                cout << "Enter the key: ";
                cin >> val1;
                Search_Normal(first, val1);
                display(first);
                break;
            case '2':
                int val2;
                cout << "Enter the key: ";
                cin >> val2;
                Search_moveToHead(first, val2);
                display(first);
                break;
            default:
                break;
            }
            break;
        case '6':
            int val;
            cout << "Value of list to be deleted: ";
            cin >> val;
            delete_(first, val);
            display(first);
            break;
        case '7':
            delete_duplicate(first);
            display(first);
            break;
        case '8':
            cout << "\n\nThere are three methods of reverseing *(b) is preffered mostly." << endl
                 << endl
                 << "a- Reverse by reversing element" << endl
                 << "b- Reverse by reversing links" << endl
                 << "c- Recursive method of *b" << endl;
            cin >> optn;
            switch (optn)
            {
            case 'a':
                reverse_1(first, size);
                display(first);
                break;
            case 'b':
                reverse_2(first);
                display(first);
                break;
            case 'c':
                reverse_3(NULL, first);
                display(first);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}