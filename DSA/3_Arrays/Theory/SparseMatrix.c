#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int value;
    struct node *next;
};

/* Insert node at end */
struct node* insert_end(struct node *head, int r, int c, int val) {
    struct node *newnode, *ptr;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->row = r;
    newnode->col = c;
    newnode->value = val;
    newnode->next = NULL;

    if(head == NULL)
        return newnode;

    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    return head;
}

/* Display sparse matrix */
void display(struct node *head) {
    printf("Row  Col  Value\n");
    while(head != NULL) {
        printf("%3d  %3d  %3d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int m, n, i, j, x;
    struct node *head = NULL;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &x);
            if(x != 0)
                head = insert_end(head, i, j, x);
        }
    }

    printf("\nSparse Matrix (Linked List Representation):\n");
    display(head);

    return 0;
}
