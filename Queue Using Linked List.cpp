#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty(void) {
    return front == NULL;
}

void enqueue(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow (memory allocation failed)\n");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d\n", val);
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void peek(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *ptr = front;
    printf("Queue (front -> rear): ");

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(void) {
    int choice, val;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                while (front != NULL) {
                    struct Node *temp = front;
                    front = front->next;
                    free(temp);
                }
                rear = NULL;
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}