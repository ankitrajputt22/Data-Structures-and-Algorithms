#include <stdio.h>
#include <stdlib.h>

#define newline1 printf("\n");
#define newline2 printf("\n\n");
#define newline3 printf("\n\n\n");

/*-------------------------------------------
                NODE STRUCTURE
-------------------------------------------*/
struct Node {
    int data;
    struct Node* next;
};

/* Head pointer for the linked list */
struct Node* head = NULL;

/*-------------------------------------------
        CREATE NODE (similar to constructor)
-------------------------------------------*/
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/*-------------------------------------------
        INSERT AT BEGINNING
-------------------------------------------*/
void insertAtBeginning(int val) {
    struct Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

/*-------------------------------------------
        ITERATIVE TRAVERSAL
-------------------------------------------*/
void traverseList() {
    struct Node* temp = head;

    printf("Singly LL (Iterative): ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }

    printf(" -> NULL\n");
}

/*-------------------------------------------
        RECURSIVE TRAVERSAL (helper)
-------------------------------------------*/
void traverseListRecursiveHelper(struct Node* node) {
    if (node == NULL) return;

    printf("%d", node->data);

    if (node->next != NULL) {
        printf(" -> ");
    }

    traverseListRecursiveHelper(node->next);
}

/*-------------------------------------------
        RECURSIVE TRAVERSAL (public)
-------------------------------------------*/
void traverseListRecursive() {
    printf("Singly LL (Recursive): ");
    traverseListRecursiveHelper(head);
    printf(" -> NULL\n");
}

/*-------------------------------------------
                    MAIN
-------------------------------------------*/
int main() {
    newline1;

    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);

    traverseList();
    traverseListRecursive();

    newline2;
    return 0;
}
