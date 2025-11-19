#include <stdio.h>

int main() {
    int n, i, j;
    int cost[10][10];
    int visited[10] = {0};
    int min, u, v, total = 0, ne = 1;  

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // treat 0 as infinity
        }
    }

    visited[0] = 1;  // start from vertex 0

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d  Cost = %d\n", u, v, min);
        visited[v] = 1;
        total += min;
        ne++;
    }

    printf("\nTotal Cost of MST = %d\n", total);

    return 0;
}


