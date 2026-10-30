
#include <stdio.h>
#define MAX 5

int undo_stack[MAX], redo_stack[MAX];
int tu = -1, tr = -1;

void push_undo(int x)
{
    if (tu == MAX - 1)
        printf("Undo stack overflow\n");
    else
        undo_stack[++tu] = x;
}

void push_redo(int x)
{
    if (tr == MAX - 1)
        printf("Redo stack overflow\n");
    else
        redo_stack[++tr] = x;
}

void insert(int x)
{
    if (tu == MAX - 1)
        printf("Stack overflow\n");
    else
    {
        push_undo(x);
        tr = -1;
    }
}

void undo()
{
    int x;

    if (tu == -1)
        printf("Undo not possible\n");
    else
    {
        x = undo_stack[tu];
        tu--;
        push_redo(x);
    }
}

void redo()
{
    int x;

    if (tr == -1)
        printf("Redo not possible\n");
    else
    {
        x = redo_stack[tr];
        tr--;
        push_undo(x);
    }
}

void display()
{
    int i;

    printf("Undo stack: ");
    for (i = 0; i <= tu; i++)
        printf("%d ", undo_stack[i]);

    printf("\nRedo stack: ");
    for (i = 0; i <= tr; i++)
        printf("%d ", redo_stack[i]);

    printf("\n");
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1. Insert\n2. Undo\n3. Redo\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                undo();
                break;

            case 3:
                redo();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
