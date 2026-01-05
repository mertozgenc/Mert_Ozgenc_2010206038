#include <stdio.h>
#include <stdlib.h>

// Node tanımı
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Baştan sona traversal
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("Ileri traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Sondan başa traversal
void traverseBackward(struct Node* tail) {
    struct Node* temp = tail;
    printf("Geri traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Araya ekleme (belirli bir elemandan sonra)
void insertAfter(struct Node** head, int key, int value) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Eleman bulunamadi!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Silme (istenen eleman)
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Silinecek eleman bulunamadi!\n");
        return;
    }

    // Baş düğüm siliniyorsa
    if (*head == temp)
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

int main() {
    struct Node* head = NULL;
    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;

    // Node oluşturma
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    // Bağlantılar
    n1->prev = NULL;
    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = NULL;

    head = n1;

    traverseForward(head);
    traverseBackward(n3);

    insertAfter(&head, 20, 25);
    traverseForward(head);

    deleteNode(&head, 10);
    traverseForward(head);

    return 0;
}
