#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n; // Dugum sayisi

// ---------------- DFS ----------------
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// ---------------- BFS ----------------
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    // visited sifirla
    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Dugum sayisini girin: ");
    scanf("%d", &n);

    printf("Adjacency matrix girin:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Baslangic dugumunu girin: ");
    scanf("%d", &start);

    // DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    // BFS
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
