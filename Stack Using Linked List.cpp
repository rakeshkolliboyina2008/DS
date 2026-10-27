#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(void) {
    return top == NULL;
}

void push(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow (memory allocation failed)\n");
        return;
    }

    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", val);
}

void pop(void) {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct Node *ptr = top;
    printf("Stack (top -> bottom): ");

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(void) {
    int choice, val;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                while (top != NULL) {
                    struct Node *temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}