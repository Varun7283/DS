#include <stdio.h>

int parent[20];


int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}


void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

int main() {
    int n, i, j, u, v, min, ne = 1;
    int cost[20][20], total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;   
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        
        if (find(u) != find(v)) {
            printf("%d -> %d  Cost = %d\n", u, v, min);
            total += min;
            union_set(u, v);
            ne++;
        }

        cost[u][v] = cost[v][u] = 999; 
    }

    printf("\nTotal Cost of Minimum Spanning Tree = %d\n", total);

    return 0;
}


