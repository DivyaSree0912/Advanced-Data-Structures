#include <stdio.h>
int a[20], n;
int recursive(int x, int low, int high){
    if (low > high || x < a[low] || x > a[high]){
        return -1;
    }
    if (a[high] == a[low]){
        if (a[low] == x){
            return low;
        }
        else{
            return -1;
        }
    }
    int pos = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);
                    
    if (x == a[pos]){
        return pos;
    }
    else if (x < a[pos]){
        return recursive(x, low, pos - 1);
    }
    else{
        return recursive(x, pos + 1, high);
    }
}

int nonrecursive(int x, int low, int high){
    while (low <= high && x >= a[low] && x <= a[high]){
        if (a[high] == a[low]){
            if (a[low] == x){
                return low;
            }
            else{
                return -1;
            }
        }

        int pos = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);

        if (x == a[pos]){
            return pos;
        }
        else if (x < a[pos]){
            high = pos - 1;
        }
        else{
            low = pos + 1;
        }
    }
    return -1;
}

int main(){
    int x, choice, result;

    printf("----- Interpolation Search -----\n");

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