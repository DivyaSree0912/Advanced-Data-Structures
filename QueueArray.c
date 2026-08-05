#include <stdio.h>

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    q[++rear] = val;
    printf("Element inserted successfully.\n");
}

// Dequeue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", q[front++]);

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Traverse
void traverse()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", q[i]);
    }

    printf("\n");
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}