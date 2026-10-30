#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot insert %d\n", value);
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element = %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");

    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void isEmpty() {
    if (top == -1)
        printf("Stack is Empty.\n");
    else
        printf("Stack is Not Empty.\n");
}

void isFull() {
    if (top == MAX - 1)
        printf("Stack is Full.\n");
    else
        printf("Stack is Not Full.\n");
}

int main() {

    int choice, value;

    while (1) {

        printf("\n----- STACK USING ARRAY -----\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Is Empty\n");
        printf("6.Is Full\n");
        printf("7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            isEmpty();
            break;

        case 6:
            isFull();
            break;

        case 7:
            printf("Program exited.\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}