#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp_x;
    int exp_y;
    struct node *next;
};

// Create node
struct node* createNode(int c, int ex, int ey) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = c;
    newNode->exp_x = ex;
    newNode->exp_y = ey;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (simple creation, no sorting)
struct node* insertTerm(struct node* start, int c, int ex, int ey) {
    struct node* newNode = createNode(c, ex, ey);

    if (start == NULL)
        return newNode;

    struct node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

// Display two variable polynomial
void display(struct node* start) {
    struct node* temp = start;
    while (temp != NULL) {
        printf("%dx^%dy^%d", temp->coef, temp->exp_x, temp->exp_y);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct node* poly = NULL;
    int n, c, ex, ey;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coef, exp_x, exp_y: ");
        scanf("%d %d %d", &c, &ex, &ey);

        poly = insertTerm(poly, c, ex, ey);
    }

    printf("\nPolynomial: ");
    display(poly);

    return 0;
}
