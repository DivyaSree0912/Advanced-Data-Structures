
#include <stdio.h>

#define MAX 100

int data[MAX], priority[MAX];
int size = 0;

void insert(int value, int p)
{
    int i, temp;

    if (size == MAX) {
        printf("Priority Queue is Full\n");
        return;
    }

    i = size;
    data[i] = value;
    priority[i] = p;
    size++;

    while (i > 0 && priority[(i - 1) / 2] > priority[i]) {
        temp = priority[i];
        priority[i] = priority[(i - 1) / 2];
        priority[(i - 1) / 2] = temp;

        temp = data[i];
        data[i] = data[(i - 1) / 2];
        data[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void delete()
{
    int i = 0, left, right, smallest, temp;

    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", data[0]);

    data[0] = data[size - 1];
    priority[0] = priority[size - 1];
    size--;

    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < size && priority[left] < priority[smallest])
            smallest = left;

        if (right < size && priority[right] < priority[smallest])
            smallest = right;

        if (smallest == i)
            break;

        temp = priority[i];
        priority[i] = priority[smallest];
        priority[smallest] = temp;

        temp = data[i];
        data[i] = data[smallest];
        data[smallest] = temp;

        i = smallest;
    }
}

void display()
{
    int i;

    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Element\tPriority\n");

    for (i = 0; i < size; i++)
        printf("%d\t%d\n", data[i], priority[i]);
}

int main()
{
    int choice, value, p;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element and priority: ");
                scanf("%d %d", &value, &p);
                insert(value, p);
                break;

            case 2:
                delete();
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
