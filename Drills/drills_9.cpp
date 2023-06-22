#include <iostream>

using namespace std;

/*
Circular Lists

Problem 1: Previously, we implemented for the other structures the insert function, which
adds a certain element to the list. This time, assume that the list can only receive integers,
and implement another version of insert, so that it inserts the elements not at the end of the
list, but in its correct position in ascending order (that is, in a list 1 -> 3 -> 7, when inserting
the number 5, this function would insert it between 3 and 7). Don't forget that the list must
be circular.

Problem 2: The circular list and the linked list are very similar, make a verification function
that, given a pointer to the first element of a list, check (returning a bool) if the given list is
circular or not.

Problem 3: Given a linked list, suppose we want to rotate k elements in this list (for example,
a rotation of 2 elements transforms "1 -> 4 -> 3 -> 8 -> 2 -> nullptr" into "3 -> 8 -> 2 -> 1 ->
4 -> nullptr".). Create a function that performs this operation, using the concept of a circular
list, and returning a pointer that will point to the new head of the linked list, without creating
a new list.

Problem 4: Inspired by the soldier problem presented in question 2 of list 2.
Build a circular list with the nodes as follows:

struct Node
{
    int id;
    bool is_alive;
    Node* next;
};

with n soldiers numbered from 1 to n, and the "is_alive" variables being True. Then, use
this list to create a function that will solve the same problem as list 2.
(https://en.wikipedia.org/wiki/Josephus_problem).
*/

struct Node
{
    int data;
    Node* next;
};

struct Soldier
{
    int id;
    bool isAlive;
    Soldier* next;
};

void printList(Node* head)
{
    if (head == nullptr) cout << "Empty list" << endl;
    else
    {
        Node* temp = head;

        cout << "{";

        cout << temp->data << " ";
        temp = temp->next;

        while (temp != nullptr && temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "}" << endl;
    }
}

void printList(Soldier* head)
{
    if (head == nullptr) cout << "Empty list" << endl;
    else
    {
        Soldier* temp = head;

        cout << "{";

        cout << temp->id << " ";
        temp = temp->next;

        while (temp != nullptr && temp != head)
        {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << "}" << endl;
    }
}

bool isCircular(Node* head)
{
    if (head == nullptr) cout << "Empty list" << endl;
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next == head) return true;
            temp = temp->next;
        }
    }
    return false;
}

bool isCircular(Soldier* head)
{
    if (head == nullptr) cout << "Empty list" << endl;
    else
    {
        Soldier* temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next == head) return true;
            temp = temp->next;
        }
    }
    return false;
}

void insert(Node** head, Node* node)
{
    Node* temp = *head;
    
    if (temp == nullptr)
    // if empty
    {
        *head = node;
        node->next = node;
    }
    else if (temp->next == nullptr)
    // if only one element (not circular)
    {
        temp->next = node;
        node->next = temp;
    }
    else if (temp->next == temp)
    // if only one element (circular)
    {
        temp->next = node;
        node->next = temp;
    }
    else if (isCircular(*head))
    // if circular
    {
        while (temp->next->data < node->data && temp->next != *head)
        {
            temp = temp->next;
        }

        Node* temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
    else
    // if not circular
    {
        // make circular and insert
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = *head;
        insert(head, node);
    }
}

void insert(Soldier** head, Soldier* node)
{
    Soldier* temp = *head;
    
    if (temp == nullptr)
    // if empty
    {
        *head = node;
        node->next = node;
    }
    else if (temp->next == nullptr)
    // if only one element (not circular)
    {
        temp->next = node;
        node->next = temp;
    }
    else if (temp->next == temp)
    // if only one element (circular)
    {
        temp->next = node;
        node->next = temp;
    }
    else if (isCircular(*head))
    // if circular
    {
        while (temp->next->id < node->id && temp->next != *head)
        {
            temp = temp->next;
        }

        Soldier* temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
    else
    // if not circular
    {
        // make circular and insert
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = *head;
        insert(head, node);
    }
}

Node* rotate(Node** head, int k)
{
    Node* temp = *head;
    int iSize = 0;

    while (temp->next != nullptr)
    {
        temp = temp->next;
        iSize++;
    }

    temp->next = *head;

    for (int i = 0; i < k; i++)
    {
        (*head) = (*head)->next;
    }

    temp = *head;// remove if you want to keep it circular
    for (int i = 0; i < iSize; i++)
    {
        temp = temp->next;
    }
    temp->next = nullptr; 

    return *head;
}

int numAlive(Soldier* head)
{
    int numAlive = 0;

    if (head->isAlive) numAlive++;

    Soldier* temp = head->next;

    while (temp != head)
    {
        if (temp->isAlive) numAlive++;
        temp = temp->next;
    }

    return numAlive;
}

int solveJosephus(Soldier** head, int k)
{
    Soldier* curr = *head;
    int stepsTaken = 0;

    while (numAlive(curr) > 1)
    {
        while (stepsTaken < k - 1)
        {
            curr = curr->next;
            if (curr->isAlive) stepsTaken++;
        }

        curr->isAlive = false;

        while (!(curr->isAlive))
        {
            curr = curr->next;
        }
        stepsTaken = 0;
    }

    while (!(curr->isAlive))
    {
        curr = curr->next;
    }

    return curr->id;
}

int main()
{
    Node* head1 = new Node;
    head1->data = 1;
    head1->next = nullptr;

    Node* head2 = new Node;
    head2->data = 1;
    head2->next = nullptr;

    Node* node1 = new Node;
    node1->data = 2;
    node1->next = nullptr;

    Node* node2 = new Node;
    node2->data = 3;
    node2->next = nullptr;

    Node* node3 = new Node;
    node3->data = 4;
    node3->next = nullptr;

    Node* node4 = new Node;
    node4->data = 2;
    node4->next = nullptr;

    cout << "============= Testing insert =============" << endl;
    insert(&head1, node1);
    insert(&head1, node2);

    insert(&head2, node3);
    insert(&head2, node4);

    printList(head1);
    printList(head2);

    cout << "============= Testing isCircular =============" << endl;
    cout << isCircular(head1) << endl;
    cout << isCircular(head2) << endl;

    node3->next = nullptr;
    cout << isCircular(head2) << endl;

    cout << "============= Testing rotate =============" << endl;
    printList(head2);
    rotate(&head2, 1);
    printList(head2);

    cout << "============= Testing solveJosephus =============" << endl;
    Soldier* head3 = new Soldier;
    head3->id = 1;
    head3->isAlive = true;
    head3->next = nullptr;

    Soldier* soldier1 = new Soldier;
    soldier1->id = 2;
    soldier1->isAlive = true;
    soldier1->next = nullptr;

    Soldier* soldier2 = new Soldier;
    soldier2->id = 3;
    soldier2->isAlive = true;
    soldier2->next = nullptr;

    Soldier* soldier3 = new Soldier;
    soldier3->id = 4;
    soldier3->isAlive = true;
    soldier3->next = nullptr;

    Soldier* soldier4 = new Soldier;
    soldier4->id = 5;
    soldier4->isAlive = true;
    soldier4->next = nullptr;

    insert(&head3, soldier1);
    insert(&head3, soldier2);
    insert(&head3, soldier3);
    insert(&head3, soldier4);

    cout << numAlive(head3) << endl;
    cout << isCircular(head3) << endl;
    printList(head3);

    cout << "\n" << solveJosephus(&head3, 2) << endl;
    cout << numAlive(head3) << "\n" << endl;

    for (int i = 0; i < 5; i++)
    {
        head3->isAlive = true;
        head3 = head3->next;
    }
    cout << numAlive(head3) << endl;
    cout << head3->id << "\n "<< endl;

    cout << solveJosephus(&head3, 3) << endl; // number 2 commits suicide
    cout << numAlive(head3) << endl;

    return 0;
}