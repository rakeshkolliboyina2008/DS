#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isFull(void) {
    return top == MAX - 1;
}

int isEmpty(void) {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = val;
    printf("Pushed %d\n", val);
}

void pop(void) {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped %d\n", stack[top--]);
}

void peek(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void display(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (bottom -> top): ");

    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    printf("\n");
}

int main(void) {
    int choice, val;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}