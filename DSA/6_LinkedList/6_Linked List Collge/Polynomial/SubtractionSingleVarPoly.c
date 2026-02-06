/*
📌 Algorithm for Subtraction


Create result list = NULL
p = P, q = Q

WHILE p != NULL AND q != NULL:
    IF p.expo == q.expo:
        diff = p.coef - q.coef
        if diff != 0 insert(diff, expo) into result
        move p and q forward

    ELSE IF p.expo > q.expo:
        insert p.term into result
        move p forward

    ELSE:
        insert (-q.coef, q.expo) into result
        move q forward

WHILE p != NULL:
    insert p.term into result
    p = p->next

WHILE q != NULL:
    insert (-q.coef, q.expo) into result
    q = q->next

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

// Insert at end
struct node* insertEnd(struct node* start, int coef, int expo) {
    struct node* newNode = createNode(coef, expo);

    if (start == NULL)
        return newNode;

    struct node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

// Display
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

// Subtraction: P - Q
struct node* subtractPoly(struct node* P, struct node* Q) {
    struct node *result = NULL;

    while (P != NULL && Q != NULL) {
        if (P->expo == Q->expo) {
            int diff = P->coef - Q->coef;
            if (diff != 0)
                result = insertEnd(result, diff, P->expo);
            P = P->next;
            Q = Q->next;
        }
        else if (P->expo > Q->expo) {
            result = insertEnd(result, P->coef, P->expo);
            P = P->next;
        }
        else { // Q->expo > P->expo
            result = insertEnd(result, -Q->coef, Q->expo);
            Q = Q->next;
        }
    }

    // Remaining P terms
    while (P != NULL) {
        result = insertEnd(result, P->coef, P->expo);
        P = P->next;
    }

    // Remaining Q terms (subtract)
    while (Q != NULL) {
        result = insertEnd(result, -Q->coef, Q->expo);
        Q = Q->next;
    }

    return result;
}

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

    R = subtractPoly(P, Q);

    printf("\nR(x) = P(x) - Q(x) = ");
    display(R);

    return 0;
}
