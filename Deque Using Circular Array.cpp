#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull(void) {
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

int isEmpty(void) {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full! Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = value;
    printf("Inserted %d at front.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full! Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(void) {
    if (isEmpty()) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }

    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear(void) {
    if (isEmpty()) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }

    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display(void) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n----- DEQUE MENU (Circular Array) -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}