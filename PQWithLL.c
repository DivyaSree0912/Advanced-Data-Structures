#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void insert(int value, int p)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->priority = p;
    newNode->next = NULL;

    if (front == NULL || p < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= p)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Inserted: %d with priority %d\n", value, p);
}

void delete()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;
    free(temp);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");

    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    insert(50, 3);
    insert(60, 1);
    insert(70, 2);
    insert(80, 1);

    display();

    delete();

    display();

    return 0;
}
