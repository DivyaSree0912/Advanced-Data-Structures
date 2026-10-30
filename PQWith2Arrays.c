#include <stdio.h>

#define MAX 5

int data[MAX];
int priority[MAX];
int size = 0;

void insert(int value, int p)
{
    if (size == MAX)
    {
        printf("Priority Queue is Full!\n");
        return;
    }

    data[size] = value;
    priority[size] = p;
    size++;

    printf("Inserted: %d with priority %d\n", value, p);
}

void delete()
{
    if (size == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    int i, highest = 0;

    for (i = 1; i < size; i++)
    {
        if (priority[i] < priority[highest])
        {
            highest = i;
        }
    }

    printf("Deleted element: %d\n", data[highest]);

    for (i = highest; i < size - 1; i++)
    {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", data[i], priority[i]);
    }
}

int main()
{
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    insert(40, 2);

    display();

    delete();

    display();

    return 0;
}