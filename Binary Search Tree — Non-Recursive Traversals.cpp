#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[MAX];
int top = -1;

void push(struct Node *node) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = node;
}

struct Node *pop(void) {
    if (top == -1)
        return NULL;

    return stack[top--];
}

int isEmpty(void) {
    return top == -1;
}

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    struct Node *current = root;
    top = -1;

    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(struct Node *root) {
    if (root == NULL)
        return;

    top = -1;
    push(root);

    while (!isEmpty()) {
        struct Node *current = pop();
        printf("%d ", current->data);

        if (current->right != NULL)
            push(current->right);

        if (current->left != NULL)
            push(current->left);
    }
}

void postorder(struct Node *root) {
    if (root == NULL)
        return;

    top = -1;

    struct Node *current = root;
    struct Node *lastVisited = NULL;

    while (current != NULL || !isEmpty()) {
        if (current != NULL) {
            push(current);
            current = current->left;
        } else {
            current = stack[top];

            if (current->right != NULL &&
                lastVisited != current->right) {
                current = current->right;
            } else {
                printf("%d ", current->data);
                lastVisited = current;
                pop();
                current = NULL;
            }
        }
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    struct Node *root = NULL;

    int elements[] = {
        6, 9, 5, 2, 8, 15,
        24, 14, 7, 8, 5, 2
    };

    int n = sizeof(elements) / sizeof(elements[0]);
    int choice;

    do {
        printf("\n\n----- BINARY SEARCH TREE -----");
        printf("\n1. Create BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                freeTree(root);
                root = NULL;

                for (int i = 0; i < n; i++)
                    root = insert(root, elements[i]);

                printf("\nBST created successfully.");
                break;

            case 2:
                if (root == NULL) {
                    printf("\nPlease create the BST first.");
                } else {
                    printf("\nInorder Traversal: ");
                    inorder(root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("\nPlease create the BST first.");
                } else {
                    printf("\nPreorder Traversal: ");
                    preorder(root);
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("\nPlease create the BST first.");
                } else {
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                }
                break;

            case 5:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}