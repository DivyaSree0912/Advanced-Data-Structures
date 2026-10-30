#include <stdio.h>
int arr[100];
int n;

void display(){
    printf("Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int x, int pos){
    if (n == 100){
        printf("array is full\n");
        return;
    }
    if (pos < 1 || pos > n+1){
        printf("invalid position\n");
        return;
    }

    for (int i = n - 1; i >= pos - 1; i--){
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = x;
    n++;
}

void delete(int pos){
    if (n == 0){
        printf("Array is Empty\n");
        return;
    }
    if (pos < 1 || pos > n){
        printf("Invalid Position\n");
        return;
    }
    for (int i = pos; i < n; i++){
        arr[i - 1] = arr[i];
    }
    n--;
}

int search(int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int choice, x, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("\n1.Display\n2.Insert Beginning\n3.Insert End\n4.Insert Position\n");
        printf("5.Delete Beginning\n6.Delete End\n7.Delete Position\n");
        printf("8.Search\n9.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){

        case 1:
            display();
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            insert(x, 1);
            display();
            break;

        case 3:
            printf("Enter element: ");
            scanf("%d", &x);
            insert(x, n + 1);
            display();
            break;

        case 4:
            printf("Enter element and position: ");
            scanf("%d%d", &x, &pos);
            insert(x, pos);
            display();
            break;

        case 5:
            delete(1);
            display();
            break;

        case 6:
            delete(n);
            display();
            break;

        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete(pos);
            display();
            break;

        case 8:
            printf("Enter element to search: ");
            scanf("%d", &x);
            pos = search(x);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element found at position %d\n", pos);
            break;

        case 9:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
}