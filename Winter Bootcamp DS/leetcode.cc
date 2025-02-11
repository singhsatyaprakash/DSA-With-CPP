#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} node;

void insertAtFront(node **head, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        (*head)->next = *head; // circular
        (*head)->prev = *head; // doubly circular
    } else {
        node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void insertAtBetween(node **head, int pos, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (pos == 1) {
        insertAtFront(head, val);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void insertAtLast(node **head, node **last, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (*head == NULL && *last == NULL) {
        *head = *last = newnode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newnode->prev = *last;
        newnode->next = *head;
        (*last)->next = newnode;
        *last = newnode;
        (*head)->prev = *last;
    }
}

void deleteAtPosition(node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = *head;
    if (pos == 1) {
        if ((*head)->next == *head) { // Single node in the list
            free(*head);
            *head = NULL;
            return;
        }
        node* last = (*head)->prev;
        *head = (*head)->next;
        last->next = *head;
        (*head)->prev = last;
        free(temp);
        return;
    }
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    node* head = NULL;
    node* last = NULL;
    int choice, value, pos;
    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at kth Position\n");
        printf("3. Delete at kth Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                insertAtLast(&head, &last, value);
                break;
            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBetween(&head, pos, value);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 4:
                printf("List: ");
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
