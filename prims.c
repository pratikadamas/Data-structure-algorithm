#include <stdio.h>
#include <stdlib.h>
int main() {
    int cost[10][10], visited[10], i, j, n, min, u, v, ne = 1;
    int mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // 999 represents infinity
        }
        visited[i] = 0;
    }
    visited[1] = 1;

    printf("The edges of the Minimum Spanning Tree are:\n");
    while (ne <n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        ne++;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}