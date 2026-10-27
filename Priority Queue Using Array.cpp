#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct PriorityQueue {
    int data;
    int priority;
};

struct PriorityQueue pq[MAX];
int size = 0;

void enqueue(int data, int priority) {
    if (size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    pq[size].data = data;
    pq[size].priority = priority;
    size++;

    printf("Element inserted successfully.\n");
}

void dequeue(void) {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i].priority < pq[highest].priority)
            highest = i;
    }

    printf("Deleted element: %d\n", pq[highest].data);

    for (int i = highest; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

void display(void) {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nPriority Queue:\n");
    printf("Data\tPriority\n");

    for (int i = 0; i < size; i++)
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
}

int main(void) {
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (smaller number = higher priority): ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}