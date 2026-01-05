#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n; // Dugum sayisi

// DFS fonksiyonu
void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    int clusterCount = 0;

    printf("Dugum sayisini girin: ");
    scanf("%d", &n);

    printf("Adjacency matrix girin:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // visited dizisini sifirla
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nClusterlar:\n");

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            dfs(i);
            printf("\n");
        }
    }

    printf("\nToplam cluster sayisi: %d\n", clusterCount);

    return 0;
}
