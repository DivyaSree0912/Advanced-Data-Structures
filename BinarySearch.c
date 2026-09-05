#include <stdio.h>
int a[20], n;

int recursive(int x, int low, int high){
    if (low > high){
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (a[mid] == x){
        return mid;
    }
    else if (x < a[mid]){
        return recursive(x, low, mid - 1);
    }
    else{
        return recursive(x, mid + 1, high);
    }
}

int nonrecursive(int x, int low, int high){
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (a[mid] == x){
            return mid;
        }
        else if (x < a[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    int x, choice, result;

    printf("----- Binary Search -----\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    printf("\n1. Recursive\n");
    printf("2. Non-Recursive\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = recursive(x, 0, n - 1);
            break;

        case 2:
            result = nonrecursive(x, 0, n - 1);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    if (result != -1){
        printf("Element found at index %d\n", result);
        printf("Position = %d\n", result + 1);
    }
    else{
        printf("Element %d not found\n", x);
    }

    return 0;
}