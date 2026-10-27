#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node {
    int key;
    struct Node *next;
};

struct Node *chainTable[TABLE_SIZE];

int hashFunction(int key) {
    int index = key % TABLE_SIZE;
    return index < 0 ? index + TABLE_SIZE : index;
}

void initLinear(void) {
    for (int i = 0; i < TABLE_SIZE; i++)
        linearTable[i] = -1;
}

void insertLinear(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;

        if (linearTable[probe] == -1) {
            linearTable[probe] = key;
            printf("Key %d inserted at index %d (linear probing).\n",
                   key, probe);
            return;
        }
    }

    printf("Hash table is full! Cannot insert key %d.\n", key);
}

void displayLinear(void) {
    printf("\nLinear Probing Table:\nIndex\tValue\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, linearTable[i]);
    }
}

void initQuadratic(void) {
    for (int i = 0; i < TABLE_SIZE; i++)
        quadraticTable[i] = -1;
}

void insertQuadratic(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i * i) % TABLE_SIZE;

        if (quadraticTable[probe] == -1) {
            quadraticTable[probe] = key;
            printf("Key %d inserted at index %d (quadratic probing).\n",
                   key, probe);
            return;
        }
    }

    printf("Hash table is full or no free slot found for key %d.\n", key);
}

void displayQuadratic(void) {
    printf("\nQuadratic Probing Table:\nIndex\tValue\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (quadraticTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, quadraticTable[i]);
    }
}

void initChaining(void) {
    for (int i = 0; i < TABLE_SIZE; i++)
        chainTable[i] = NULL;
}

void insertChaining(int key) {
    int index = hashFunction(key);
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chainTable[index] == NULL) {
        chainTable[index] = newNode;
    } else {
        struct Node *temp = chainTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Key %d inserted at index %d (separate chaining).\n",
           key, index);
}

void displayChaining(void) {
    printf("\nSeparate Chaining Table:\nIndex\tChain\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        struct Node *temp = chainTable[i];

        if (temp == NULL) {
            printf("-");
        } else {
            while (temp != NULL) {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("NULL");
        }

        printf("\n");
    }
}

int main(void) {
    int choice, key;

    initLinear();
    initQuadratic();
    initChaining();

    while (1) {
        printf("\n----- HASHING - COLLISION RESOLUTION TECHNIQUES -----\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Separate Chaining\n");
        printf("4. Display Linear Probing Table\n");
        printf("5. Display Quadratic Probing Table\n");
        printf("6. Display Separate Chaining Table\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertLinear(key);
                break;
            case 2:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertQuadratic(key);
                break;
            case 3:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertChaining(key);
                break;
            case 4:
                displayLinear();
                break;
            case 5:
                displayQuadratic();
                break;
            case 6:
                displayChaining();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}