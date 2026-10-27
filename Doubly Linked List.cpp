#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteAtBeginning(void) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd(void) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;

    if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from the end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

void displayForward(void) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(void) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(void) {
    int choice, value, pos;

    do {
        printf("\n===== DOUBLY LINKED LIST OPERATIONS =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                displayForward();
                break;
            case 8:
                displayBackward();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}