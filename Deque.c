#include <stdio.h>
#define MAX 5

int a[MAX], f = -1, r = -1;

void insert_rear(int x)
{
    if ((f == 0 && r == MAX - 1) || f == r + 1)
        printf("Queue overflow\n");
    else
    {
        if (f == -1)
            f = r = 0;
        else if (r == MAX - 1)
            r = 0;
        else
            r++;

        a[r] = x;
    }
}

void insert_front(int x)
{
    if ((f == 0 && r == MAX - 1) || f == r + 1)
        printf("Queue overflow\n");
    else
    {
        if (f == -1)
            f = r = 0;
        else if (f == 0)
            f = MAX - 1;
        else
            f--;

        a[f] = x;
    }
}

void del_rear()
{
    if (f == -1)
        printf("Queue underflow\n");
    else
    {
        printf("Deleted: %d\n", a[r]);

        if (f == r)
            f = r = -1;
        else if (r == 0)
            r = MAX - 1;
        else
            r--;
    }
}

void del_front()
{
    if (f == -1)
        printf("Queue underflow\n");
    else
    {
        printf("Deleted: %d\n", a[f]);

        if (f == r)
            f = r = -1;
        else if (f == MAX - 1)
            f = 0;
        else
            f++;
    }
}

void display()
{
    int i;

    if (f == -1)
        printf("Queue is empty\n");
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
        printf("\n1. Insert Rear\n2. Insert Front\n");
        printf("3. Delete Rear\n4. Delete Front\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert_rear(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insert_front(x);
                break;

            case 3:
                del_rear();
                break;

            case 4:
                del_front();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}