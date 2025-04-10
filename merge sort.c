#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
    int i = start, j = mid + 1, k = 0;
    int n = end - start + 1;
    int temp[n];

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= end){
        temp[k++] = arr[j++];
    }

    for(int i = 0; i < n; i++){
        arr[start + i] = temp[i];
    }
}

void mergesort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[7] = {1, 5, 8, 9, 4, 0, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    for(int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
    return 0;
}
