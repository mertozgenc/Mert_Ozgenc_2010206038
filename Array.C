#include <stdio.h>

#define MAX 100

// Dizi yazdırma
void traverse(int arr[], int size) {
    int i;
    printf("Dizi: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Araya ekleme (belirli index'e)
void insert(int arr[], int *size, int index, int value) {
    int i;

    if (*size >= MAX) {
        printf("Dizi dolu!\n");
        return;
    }

    if (index < 0 || index > *size) {
        printf("Gecersiz index!\n");
        return;
    }

    // Saga kaydirma
    for (i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*size)++;
}

// Silme (belirli index'ten)
void delete(int arr[], int *size, int index) {
    int i;

    if (*size <= 0) {
        printf("Dizi bos!\n");
        return;
    }

    if (index < 0 || index >= *size) {
        printf("Gecersiz index!\n");
        return;
    }

    // Sola kaydirma
    for (i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int size = 4;

    traverse(arr, size);

    insert(arr, &size, 2, 25);   // index 2'ye ekle
    traverse(arr, size);

    delete(arr, &size, 1);       // index 1'i sil
    traverse(arr, size);

    return 0;
}
