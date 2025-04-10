#include <stdio.h>
#define MAX 100
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to perform job sequencing
void jobSequencing(int jobs, char jobId[], int deadline[], int profit[]) {
    // Step 1: Sort jobs in descending order of profit
    for (int i = 0; i < jobs - 1; i++) {
        for (int j = i + 1; j < jobs; j++) {
            if (profit[i] < profit[j]) {
                swap(&profit[i], &profit[j]);
                swap(&deadline[i], &deadline[j]);
                char temp = jobId[i];
                jobId[i] = jobId[j];
                jobId[j] = temp;
            }
        }
    }
    // Step 2: Find max deadline to create time slots
    int maxDeadline = 0;
    for (int i = 0; i < jobs; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }
    // Step 3: Create time slots and initialize to empty
    int slot[MAX] = {0};   // 0 means free
    char result[MAX];      // To store scheduled jobs
    int totalProfit = 0;

    for (int i = 0; i < jobs; i++) {
        for (int j = deadline[i]; j > 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobId[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    // Step 4: Print result
    printf("Selected Jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i])
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int jobs = 5;
    char jobId[] = {'A', 'B', 'C', 'D', 'E'};
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};

    jobSequencing(jobs, jobId, deadline, profit);

    return 0;
}
