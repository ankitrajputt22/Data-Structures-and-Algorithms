#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void iterativeInorder(struct node* root) {
    struct node* stack[50];

    int top = -1;
    struct node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}


int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);
    root->left->right->right = createNode(7);


    iterativeInorder(root);

    return 0;
}