#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;
int V;


void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = vertex;
}


int dequeue() {
    if (front == -1 || front > rear) {
        return -1; 
    }
    int vertex = queue[front];
    front++;
    return vertex;
}


void BFS(int start) {
    int current, i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while ((current = dequeue()) != -1) {
        printf("%d ", current);

        for (i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    
    for (i = 0; i < V; i++) visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}

