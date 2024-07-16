#include "treap_tree.h"
#include "main.h"

Node *newNode(int key, int priority) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node) {
        node->key = key;
        if (RAND_PRIORITY)
            node->priority = rand() % 50;
        else
            node->priority = priority;
        node->left = node->right = NULL;
        node->parent = NULL;
//    printf("newNode key: %d (%d)\n", node->key, node->priority);
    }
    return node;
}


Node *rightRotate(Node *y) {
    Node *x = y->left, *T2 = x->right;
    y->left = T2;
    if (T2 != NULL) {
        T2->parent = y;
    }
    x->right = y;
    x->parent = y->parent;
    y->parent = x;
    return x;
}


Node *leftRotate(Node *x) {
    Node *y = x->right, *T2 = y->left;
    x->right = T2;

    if (T2 != NULL) {
        T2->parent = x;
    }
    y->left = x;
    y->parent = x->parent;
    x->parent = y;
    return y;
}


Node *search(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}


void insertNode(Node **root, int key, int priority) {
    Node *node = newNode(key, priority);
    if (*root == NULL) {
        *root = node;
        return;
    }
    Node *current = *root;
    while (current != NULL) {
        if (node->key <= current->key) {
            if (current->left == NULL) {
                current->left = node;
                node->parent = current;
                break;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = node;
                node->parent = current;
                break;
            } else {
                current = current->right;
            }
        }
    }

    current = node;
    Node *head_node = NULL, *old_head = NULL;
    while (current != NULL && current->parent != NULL && current->priority > current->parent->priority) {
        old_head = current->parent;
        {
            head_node = current->parent->left == current ? rightRotate(current->parent) : leftRotate(current->parent);
            if (head_node->parent) {
                if (head_node->key > head_node->parent->key)
                    head_node->parent->right = head_node;
                else
                    head_node->parent->left = head_node;
            }
            if (old_head == *root) {
                *root = head_node;
            }
        }
    }
    printf("\n");
}


Node *deleteNode(Node **root, int key) {
    if (*root == NULL)
        return *root;
    Node *current = *root, *parent = current->parent, *old_root = *root;
    int flag = 0;
    while (current != NULL) {
        if (key < current->key) {
            parent = current;
            current = current->left;
            flag = -1;
        } else if (key > current->key) {
            parent = current;
            current = current->right;
            flag = 1;
        } else if (current->left == NULL) {
            Node *temp = current->right;
            if (old_root == current)
                *root = temp;
            free(current);
            current = temp;
            if (flag == -1) {
                parent->left = NULL;
            } else if (flag == 1) {
                parent->right = NULL;
            }
            if (current && current->parent) {
                current->parent = parent;
                if (parent) {
                    if (flag == -1) {
                        parent->left = current;
                    } else {
                        parent->right = current;
                    }
                }
            }
        } else if (current->right == NULL) {
            Node *temp = current->left;
            if (old_root == current)
                *root = temp;
            free(current);
            current = temp;
            if (flag == -1) {
                parent->left = NULL;
            } else if (flag == 1) {
                parent->right = NULL;
            }
            if (current && current->parent) {
                current->parent = parent;
                if (parent) {
                    if (flag == -1) {
                        parent->left = current;
                    } else {
                        parent->right = current;
                    }
                }
            }
        } else if (current->left->priority < current->right->priority) {
            if (*root == current) {
                *root = current->right;
                old_root = *root;
            }
            current = leftRotate(current);
            parent = current;
            current = current->left;
            flag = -1;
        } else {
            if (*root == current) {
                *root = current->left;
                old_root = *root;
            }
            current = rightRotate(current);
            parent = current;
            current = current->right;
            flag = 1;
        }
    }
}

const int INDENT = 7;

void graphicalPrint(Node *root, int space) {
    if (root == NULL)
        return;
    space += INDENT;
    graphicalPrint(root->right, space);
//    printf("\n");
    for (int i = INDENT; i < space; i++) {
        printf("-");
    }
    printf("%d(%d)\n", root->key, root->priority);

    graphicalPrint(root->left, space);
}
