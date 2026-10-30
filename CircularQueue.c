
#include <stdio.h>
#define MAX 5

int a[MAX], f = -1, r = -1;

void enqueue(int x)
{
    if ((r + 1) % MAX == f)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (f == -1)
            f = 0;

        r = (r + 1) % MAX;
        a[r] = x;
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", a[f]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if (f == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        i = f;

        while (i != r)
        {
            printf("%d ", a[i]);
            i = (i + 1) % MAX;
        }

        printf("%d\n", a[r]);
    }
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
