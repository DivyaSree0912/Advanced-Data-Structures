#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void push(int val){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    head = temp;
    printf("Element pushed successfully.\n");
}
void pop(){
    struct node *temp;
    if (head == NULL){
        printf("Stack Underflow!\n");
        return;
    }
    temp = head;
    printf("Popped element: %d\n", temp->data);
    head = head->next;
    free(temp);
}
void traverse(){
    struct node *ptr;
    if (head == NULL){
        printf("Stack is empty!\n");
        return;
    }
    ptr = head;
    printf("Stack: ");
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
    int ch, val;
    while (1){
        printf("\n----- MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
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