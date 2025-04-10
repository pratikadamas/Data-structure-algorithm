#include <stdio.h>
int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while(i <= j){
        while(arr[i] <= pivot) i++;
        while( arr[j] > pivot) j--;

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    return j; // return pivot index
}

void quicksort(int arr[], int start, int end){
    if(start < end){
        int index = partition(arr, start, end);
        quicksort(arr, start, index - 1);
        quicksort(arr, index + 1, end);
    }
}

int main(){
    printf("    QUICK SORT --------\n");
    int arr[7] = {1, 5, 8, 9, 4, 0, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    for(int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}
