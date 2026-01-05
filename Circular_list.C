#include <stdio.h>
#include <stdlib.h>

// Node tanımı
struct Node {
    int data;
    struct Node* next;
};

// Traversal (dairesel liste)
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Araya ekleme (belirli bir elemandan sonra)
void insertAfter(struct Node** head, int key, int value) {
    if (*head == NULL) {
        printf("Liste bos, ekleme yapilamadi!\n");
        return;
    }

    struct Node* temp = *head;

    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Eleman bulunamadi!\n");
}

// Silme (istenen eleman)
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    // Tek eleman varsa
    if (curr->next == *head && curr->data == key) {
        free(curr);
        *head = NULL;
        return;
    }

    // Head siliniyorsa
    if (curr->data == key) {
        while (curr->next != *head)
            curr = curr->next;

        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    // Ortadaki veya sondaki eleman
    prev = *head;
    curr = prev->next;

    while (curr != *head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Silinecek eleman bulunamadi!\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;

    // Node olusturma
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    // Circular baglantilar
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    head = n1;

    traverse(head);

    insertAfter(&head, 20, 25);
    traverse(head);

    deleteNode(&head, 10);
    traverse(head);

    return 0;
}
