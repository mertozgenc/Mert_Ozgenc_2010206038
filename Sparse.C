#include <stdio.h>

int main() {
    int matrix[10][10];
    int sparse[50][3];
    int row, col;
    int i, j;
    int k = 1; // sparse index

    printf("Satir sayisini girin: ");
    scanf("%d", &row);

    printf("Sutun sayisini girin: ");
    scanf("%d", &col);

    printf("Matrisi girin:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sparse matrix olusturma
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // İlk satır: satır, sütun, sıfır olmayan eleman sayısı
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = k - 1;

    printf("\nSparse Matrix (3-Tuple Form):\n");
    printf("Row Col Value\n");

    for (i = 0; i < k; i++) {
        printf("%d   %d   %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}
