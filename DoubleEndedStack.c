#include <stdio.h>
#define MAX 10

int stack[MAX];
int top1 = -1, top2 = MAX;

void push1(int x)
{
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
        stack[++top1] = x;
        printf("%d pushed from left side\n", x);
}

void push2(int x)
{
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
        stack[--top2] = x;
        printf("%d pushed from right side\n", x);
}

void pop1()
{
    if (top1 == -1)
        printf("Left Stack Underflow\n");
    else
        printf("Popped element: %d\n", stack[top1--]);
}

void pop2()
{
    if (top2 == MAX)
        printf("Right Stack Underflow\n");
    else
        printf("Popped element: %d\n", stack[top2++]);
}

void display()
{
    int i;

    printf("Left Stack: ");
    if(top1 == -1){
        printf("Empty");
    }
    else{
        for (i = 0; i <= top1; i++){
            printf("%d ", stack[i]);
        }
    }
    printf("\nRight Stack: ");
    if(top2 == MAX){
        printf("Empty");
    }
    else{
        for (i = MAX - 1; i >= top2; i--){
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1.Push Left\n2.Push Right\n3.Pop Left\n4.Pop Right\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push1(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                push2(x);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
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
