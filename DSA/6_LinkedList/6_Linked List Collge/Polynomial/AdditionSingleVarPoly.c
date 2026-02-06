#include <stdio.h>
#include <stdlib.h>


/*

📌 Algorithm for Addition------->

Create result = NULL
Let p = start of first polynomial
Let q = start of second polynomial

WHILE p != NULL AND q != NULL:
    IF p.expo == q.expo:
        sum = p.coef + q.coef
        if sum != 0 insert (sum, expo) in result
        move p and q forward

    ELSE IF p.expo > q.expo:
        insert p.term in result
        move p forward

    ELSE:
        insert q.term in result
        move q forward

WHILE p != NULL:
    insert p.term in result
    move p forward

WHILE q != NULL:
    insert q.term in result
    move q forward



*/

struct node {
    int coef;
    int expo;
    struct node *next;
};

// Create a node
struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
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

// Polynomial Addition
struct node* addPoly(struct node* p, struct node* q) {
    struct node* result = NULL;

    while (p != NULL && q != NULL) {
        if (p->expo == q->expo) {
            int sum = p->coef + q->coef;
            if (sum != 0)
                result = insertEnd(result, sum, p->expo);

            p = p->next;
            q = q->next;
        }
        else if (p->expo > q->expo) {
            result = insertEnd(result, p->coef, p->expo);
            p = p->next;
        }
        else {
            result = insertEnd(result, q->coef, q->expo);
            q = q->next;
        }
    }

    // remaining terms
    while (p != NULL) {
        result = insertEnd(result, p->coef, p->expo);
        p = p->next;
    }

    while (q != NULL) {
        result = insertEnd(result, q->coef, q->expo);
        q = q->next;
    }

    return result;
}

int main() {
    struct node *P = NULL, *Q = NULL, *R = NULL;
    int n, c, e;

    // Input polynomial P
    printf("Enter number of terms in P(x): ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent (sorted by exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        P = insertEnd(P, c, e);
    }

    // Input polynomial Q
    printf("Enter number of terms in Q(x): ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent (sorted by exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        Q = insertEnd(Q, c, e);
    }

    printf("\nP(x) = ");
    display(P);

    printf("Q(x) = ");
    display(Q);

    R = addPoly(P, Q);

    printf("\nResult R(x) = P(x) + Q(x) = ");
    display(R);

    return 0;
}
