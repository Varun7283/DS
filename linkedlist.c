#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("How many elements do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("List after insertion: ");
    displayList(head);

    printf("Enter element to delete: ");
    scanf("%d", &value);
    head = deleteNode(head, value);

    printf("List after deletion: ");
    displayList(head);

    return 0;
}

