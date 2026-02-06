/*
📌 Algorithm for Polynomial Multiplication

For each term in P:
    For each term in Q:
        Multiply coefficients
        Add exponents
        Insert into result polynomial (combine like terms)

result = empty
FOR each term p in P:
    FOR each term q in Q:
        coef = p.coef * q.coef
        expo = p.expo + q.expo
        insert or add into result polynomial



*/



#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int expo;
    struct node *next;
};

// Create node
struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

// Insert term by combining like exponents
struct node* insertCombine(struct node* start, int coef, int expo) {
    if (coef == 0) return start;

    struct node *temp = start, *prev = NULL;

    // Insert in sorted order (descending exponent)
    while (temp != NULL && temp->expo > expo) {
        prev = temp;
        temp = temp->next;
    }

    // If same exponent found → add coefficients
    if (temp != NULL && temp->expo == expo) {
        temp->coef += coef;

        // If coefficient becomes zero, delete node
        if (temp->coef == 0) {
            if (prev == NULL)
                start = temp->next;
            else
                prev->next = temp->next;
            free(temp);
        }

        return start;
    }

    // Create new node if no like term
    struct node* newNode = createNode(coef, expo);

    if (prev == NULL) { // insert at beginning
        newNode->next = start;
        return newNode;
    }

    newNode->next = temp;
    prev->next = newNode;

    return start;
}

// Multiply two polynomials
struct node* multiply(struct node* P, struct node* Q) {
    struct node* result = NULL;

    for (struct node* p = P; p != NULL; p = p->next) {
        for (struct node* q = Q; q != NULL; q = q->next) {
            int coef = p->coef * q->coef;
            int expo = p->expo + q->expo;

            result = insertCombine(result, coef, expo);
        }
    }

    return result;
}

// Insert at end (used only for creation input)
struct node* insertEnd(struct node* start, int c, int e) {
    struct node* newNode = createNode(c, e);

    if (start == NULL)
        return newNode;

    struct node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

// Display polynomial
void display(struct node* start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }

    struct node* temp = start;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->expo);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Main
int main() {
    struct node *P = NULL, *Q = NULL, *R = NULL;
    int n, c, e;

    printf("Enter number of terms in P(x): ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        P = insertEnd(P, c, e);
    }

    printf("Enter number of terms in Q(x): ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        Q = insertEnd(Q, c, e);
    }

    printf("\nP(x) = ");
    display(P);

    printf("Q(x) = ");
    display(Q);

    R = multiply(P, Q);

    printf("\nR(x) = P(x) * Q(x) = ");
    display(R);

    return 0;
}
