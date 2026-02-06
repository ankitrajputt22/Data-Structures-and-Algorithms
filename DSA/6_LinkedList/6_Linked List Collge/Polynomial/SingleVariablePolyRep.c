/*
🚀 C Program: Create and Display Polynomial

This program:

Creates a polynomial using linked list

Inserts terms in descending exponent order

Displays the polynomial

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int expo;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

// Insert term in descending order of exponents
struct node* insertTerm(struct node* start, int coef, int expo) {
    struct node *newNode = createNode(coef, expo);

    // if list is empty OR new term has highest exponent
    if (start == NULL || expo > start->expo) {
        newNode->next = start;
        return newNode;
    }

    struct node *temp = start;

    // find correct position
    while (temp->next != NULL && temp->next->expo >= expo)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return start;
}

// Display polynomial
void display(struct node* start) {
    struct node *temp = start;

    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->expo);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct node* poly = NULL;
    int n, coef, expo;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &expo);
        poly = insertTerm(poly, coef, expo);
    }

    printf("\nPolynomial: ");
    display(poly);

    return 0;
}
