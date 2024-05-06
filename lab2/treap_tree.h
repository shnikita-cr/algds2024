#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key, priority;
    struct Node *left, *right, *parent;
} Node;

Node *newNode(int key, int priority);

Node *rightRotate(Node *y);

Node *leftRotate(Node *x);

Node *search(Node *root, int key);

void insertNode(Node **root, int key, int priority);

Node* deleteNode(Node ** root, int key);

void graphicalPrint(Node *root,
                    int space);
