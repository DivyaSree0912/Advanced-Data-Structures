#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(int val){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    printf("Element inserted successfully.\n");
}
void dequeue(){
    struct node *temp;
    if (front == NULL){
        printf("Queue Underflow!\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}
void traverse(){
    struct node *ptr;
    if (front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    ptr = front;
    printf("Queue: ");
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
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
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