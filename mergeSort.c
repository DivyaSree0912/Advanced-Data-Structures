#include<stdio.h>

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = 0;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }
    int f = 0;
    for(int m = low; m<=high; m++){
        arr[m] = temp[f++];
    }
}
void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n, arr[n];
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n-1);
    display(arr, n);
    return 0;
}