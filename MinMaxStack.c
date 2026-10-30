#include <stdio.h>
#define MAX 10

int stack[MAX], maxStack[MAX], minStack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else{
        if (top == -1){
            top++;
            stack[top] = x;
            maxStack[top] = x;
            minStack[top] = x;
        }
        else
        {
            if (x > maxStack[top - 1])
                maxStack[top] = x;
            else
                maxStack[top] = maxStack[top - 1];

            if (x < minStack[top - 1])
                minStack[top] = x;
            else
                minStack[top] = minStack[top - 1];

            printf("%d pushed\n", x);
        }
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int getMax()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return maxStack[top];
}

int getMin()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return minStack[top];
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\nMaximum element: %d\n", getMax());
    printf("Minimum element: %d\n", getMin());  
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Get Maximum\n4.Get Minimum\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                if (top != -1)
                    printf("Popped element: %d\n", pop());
                else
                    printf("Stack Underflow\n");
                break;

            case 3:
                if (top != -1)
                    printf("Maximum element: %d\n", getMax());
                else
                    printf("Stack is empty\n");
                break;

            case 4:
                if (top != -1)
                    printf("Minimum element: %d\n", getMin());
                else
                    printf("Stack is empty\n");
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
