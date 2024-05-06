#include "pch.h"
#include "gtest/gtest.h"

extern "C" {
#include "../treap_tree.h"
}

#include "main.h"
#include "treap_tree.h"

#ifndef RAND_PRIORITY
#define RAND_PRIORITY 0
#endif //RAND_PRIORITY


void test_empty_tree(){
    Node *root = NULL;
    EXPECT_EQ("", graphicalPrint(root,0));
}

void test_insert_tree(){
    Node* root = NULL;
    insertNode(&root, 1, 2);
    EXPECT_EQ("1(2)", graphicalPrint(root,0));
}

void test_insert_delete_valid_tree(){
    Node* root = NULL;
    insertNode(&root, 1, 2);
    deleteNode(&root,1);
    EXPECT_EQ("", graphicalPrint(root,0));
}

void test_insert_delete_valid_tree(){
    Node* root = NULL;
    insertNode(&root, 1, 2);
    deleteNode(&root,3);
    EXPECT_EQ("1(2)", graphicalPrint(root,0));
}