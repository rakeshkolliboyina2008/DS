#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;
    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

void insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    if (head == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (pos > 2 && temp->next == head && pos != 2) {
        printf("Position out of range\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBeginning(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

void deleteEnd(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;
    free(last);
}

void deletePosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main(void) {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}