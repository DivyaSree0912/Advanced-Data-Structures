#include <stdio.h>

void radixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    for (int place = 1; max / place > 0; place *= 10){
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++){
            count[(a[i] / place) % 10]++;
        }
        for (int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            int digit = (a[i] / place) % 10;
            output[count[digit] - 1] = a[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++){
            a[i] = output[i];
        }
    }
}
int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    radixSort(a, n);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}