#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display(){
    struct node *ptr = head;

    if (head == NULL){
        printf("List is Empty!\n");
        return;
    }

    printf("List: ");

    while (ptr != NULL)
    {
        printf("%d", ptr->data);

        if (ptr->next != NULL){
            printf(" -> ");

        }
        ptr = ptr->next;
    }

    printf(" -> NULL\n");
}

void insert(int pos, int val){
    struct node *temp, *ptr;
    int i;

    if (pos < 0)
    {
        printf("Invalid Position!\n");
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;

    if (pos == 0)
    {
        temp->next = head;
        head = temp;
        printf("Element inserted successfully.\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is Empty! Insert at position 0 .\n");
        free(temp);
        return;
    }

    ptr = head;

    for (i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Invalid Position!\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    printf("Element inserted successfully.\n");
}


void deleteNode(int pos)
{
    struct node *ptr, *del;
    int i;

    if (pos < 0)
    {
        printf("Invalid Position!\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    // Delete first node
    if (pos == 0)
    {
        del = head;
        head = head->next;
        free(del);

        printf("Element deleted successfully.\n");
        return;
    }

    ptr = head;

    for (i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("Invalid Position!\n");
        return;
    }

    del = ptr->next;
    ptr->next = del->next;
    free(del);

    printf("Element deleted successfully.\n");
}

// Search
void search(int key)
{
    struct node *ptr = head;
    int pos = 0;

    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    printf("Element %d not found.\n", key);
}

// Count Nodes
void countNodes()
{
    struct node *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("Total Nodes = %d\n", count);
}

int main()
{
    int choice, pos, val, key;

    while (1)
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            printf("Enter Position: ");
            scanf("%d", &pos);

            printf("Enter Value: ");
            scanf("%d", &val);

            insert(pos, val);
            break;

        case 3:
            printf("Enter Position to Delete: ");
            scanf("%d", &pos);

            deleteNode(pos);
            break;

        case 4:
            printf("Enter Element to Search: ");
            scanf("%d", &key);

            search(key);
            break;

        case 5:
            countNodes();
            break;

        case 6:
            printf("Program Terminated Successfully.\n");
            return 0;

        default:
            printf("Invalid Choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}