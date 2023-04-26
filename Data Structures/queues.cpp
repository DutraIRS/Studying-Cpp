#include <iostream>

using namespace std;

struct Node
{
    int iData;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int iVal)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->iData = iVal;
    temp->next = nullptr;

    return temp;
}

struct Queue* newQueue()
{
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = nullptr;
    temp->rear = nullptr;

    return temp;
}

void firstElement(struct Queue* queue)
{
    cout << "First element: " << ((queue->front != nullptr) ? (queue->front)->iData : -1) << endl;
}

void lastElement(struct Queue* queue)
{
    cout << "Last element: " << ((queue->rear != nullptr) ? (queue->rear)->iData : -1) << endl;
}

void enQueue(struct Queue* queue, int iVal)
{
    struct Node* temp = newNode(iVal);
    if (queue->rear == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        (queue->rear)->next = temp;
        queue->rear = temp;
    }

    cout << "Enqueued element: " << iVal << endl;
    return;
}

void deQueue(struct Queue* queue)
{
    if (queue->front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct Node* temp = queue->front;
        queue->front = (queue->front)->next;

        if (queue->front == nullptr) queue->rear = nullptr;

        cout << "Dequeued element: " << temp->iData << endl;
        free(temp);
    }
}

void printQueue(struct Queue* queue)
{
    if (queue->front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct Node* temp = queue->front;
        cout << "Queue: {";

        while (temp->next != nullptr)
        {
            cout << temp->iData << ", ";
            temp = temp->next;
        }

        cout << temp->iData << "}" << endl;
    }
}

int main()
{
    struct Queue* queue = newQueue();
    printQueue(queue);
    firstElement(queue);
    lastElement(queue);

    cout << "\n================\n" << endl;

    enQueue(queue, 1);
    printQueue(queue);
    firstElement(queue);
    lastElement(queue);

    cout << "\n================\n" << endl;

    enQueue(queue, 7);
    enQueue(queue, 42);
    enQueue(queue, 666);
    printQueue(queue);
    firstElement(queue);
    lastElement(queue);

    cout << "\n================\n" << endl;

    deQueue(queue);
    printQueue(queue);
    firstElement(queue);
    lastElement(queue);

    cout << "\n================\n" << endl;

    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    printQueue(queue);
    firstElement(queue);
    lastElement(queue);

    return 0;
}