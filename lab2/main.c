#include "treap_tree.h"


int main() {
    srand(time(NULL));
    Node *root = NULL;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("before delete\n");
    insert(&root, 10, 11);
    graphicalPrint(root,0);
    deleteNode(&root,10);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("after delete\n");
    graphicalPrint(root,0);
    return 0;
}