#include<stdio.h>
void quickSort(int arr[], int low, int high){
    if(low < high){
        int i = low+1; 
        int j = high;
        int pivot = arr[low];
        while(i <= j){
            while(i<=high && arr[i] <= pivot){
                i++;
            }
            while(j>=low && arr[j] >= pivot){
                j--;
            }
            if(i <= j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}
void quickL(int arr[], int low, int high){
    if(low < high){
        int i = low-1;
        int j = low;
        int pivot = arr[high];
        while(j < high){
            if(arr[j] <= pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
        int p = arr[i];
        arr[i] = arr[high];
        arr[high] = p;
        quickL(arr, low, i-1);
        quickL(arr, i+1, high);
    }
}
void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    int arr[n];
    int arr1[n];
    printf("Enter the elements : ");
    int y;
    for(int i = 0; i<n; i++){
        scanf("%d",&y);
        arr[i] = y;
        arr1[i] = y;
    }
    quickSort(arr, 0, n-1);
    quickL(arr1, 0, n-1);
    display(arr, n);
    display(arr1, n);
    return 0;
}