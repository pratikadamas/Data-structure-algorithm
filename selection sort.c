#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        int min = i; // Assume current i is the minimum

        // Find index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[min]) {
                min = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 1, 10, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
