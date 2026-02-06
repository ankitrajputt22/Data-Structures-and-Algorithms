/*
✅ ALGORITHM 1: Addition of Two Two-Variable Polynomials
Input:
Two polynomials P and Q (linked lists)
Output:
Polynomial R = P + Q

1. Initialize R = NULL
2. Set p = P, q = Q

3. WHILE p ≠ NULL AND q ≠ NULL DO

       IF (p.expx == q.expx AND p.expy == q.expy) THEN
            coef_sum = p.coef + q.coef
            IF coef_sum ≠ 0 THEN
                 Insert (coef_sum, p.expx, p.expy) into R
            ENDIF
            Move p = p.next AND q = q.next

       ELSE IF (p.expx > q.expx) OR 
               (p.expx == q.expx AND p.expy > q.expy) THEN
            Insert (p.coef, p.expx, p.expy) into R
            Move p = p.next

       ELSE
            Insert (q.coef, q.expx, q.expy) into R
            Move q = q.next

   ENDWHILE

4. WHILE p ≠ NULL DO
       Insert (p.coef, p.expx, p.expy) into R
       Move p = p.next
   ENDWHILE

5. WHILE q ≠ NULL DO
       Insert (q.coef, q.expx, q.expy) into R
       Move q = q.next
   ENDWHILE

6. RETURN R





✅ ALGORITHM 2: Subtraction of Two Two-Variable Polynomials
Input:
Two polynomials P and Q (linked lists)

Output:
Polynomial R = P − Q

1. Initialize R = NULL
2. Set p = P, q = Q

3. WHILE p ≠ NULL AND q ≠ NULL DO

       IF (p.expx == q.expx AND p.expy == q.expy) THEN
            coef_diff = p.coef - q.coef
            IF coef_diff ≠ 0 THEN
                 Insert (coef_diff, p.expx, p.expy) into R
            ENDIF
            Move p = p.next AND q = q.next

       ELSE IF (p.expx > q.expx) OR
               (p.expx == q.expx AND p.expy > q.expy) THEN
            Insert (p.coef, p.expx, p.expy) into R
            Move p = p.next

       ELSE
            Insert ( -q.coef, q.expx, q.expy ) into R
            Move q = q.next

   ENDWHILE

4. WHILE p ≠ NULL DO
       Insert (p.coef, p.expx, p.expy) into R
       Move p = p.next
   ENDWHILE

5. WHILE q ≠ NULL DO
       Insert (-q.coef, q.expx, q.expy) into R
       Move q = q.next
   ENDWHILE

6. RETURN R




✅ ALGORITHM 3: Multiplication of Two Two-Variable Polynomials
Input:
Two polynomials P and Q

Output:
Polynomial R = P × Q


1. Initialize R = NULL

2. FOR each term p in P DO

       FOR each term q in Q DO

            new_coef = p.coef × q.coef
            new_expx = p.expx + q.expx
            new_expy = p.expy + q.expy

            Insert (new_coef, new_expx, new_expy) into R  
                • If a term with same (new_expx, new_expy) exists,
                  add coefficients (combine like terms)

       ENDFOR

   ENDFOR

3. RETURN R


*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, expx, expy;
    struct node *next;
};

// Create a new node
struct node* createNode(int c, int ex, int ey) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coef = c;
    temp->expx = ex;
    temp->expy = ey;
    temp->next = NULL;
    return temp;
}

// Insert term in sorted order OR combine like terms
struct node* insertCombine(struct node* start, int c, int ex, int ey) {
    if (c == 0) return start;

    struct node *temp = start, *prev = NULL;

    // Find correct position (sort by expx DESC, then expy DESC)
    while (temp != NULL &&
          (temp->expx > ex || (temp->expx == ex && temp->expy > ey))) {
        prev = temp;
        temp = temp->next;
    }

    // If like term exists → combine
    if (temp != NULL && temp->expx == ex && temp->expy == ey) {
        temp->coef += c;

        // If coefficient becomes 0 → delete node
        if (temp->coef == 0) {
            if (prev == NULL) start = temp->next;
            else prev->next = temp->next;
            free(temp);
        }

        return start;
    }

    // Insert new node
    struct node* newNode = createNode(c, ex, ey);

    if (prev == NULL) {   // insert at beginning
        newNode->next = start;
        return newNode;
    }

    newNode->next = temp;
    prev->next = newNode;

    return start;
}

// Insert at end (only used for initial creation)
struct node* insertEnd(struct node* start, int c, int ex, int ey) {
    struct node *newNode = createNode(c, ex, ey);

    if (start == NULL)
        return newNode;

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return start;
}

// Display polynomial
void display(struct node *start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }

    struct node *t = start;
    while (t != NULL) {
        printf("%dx^%dy^%d", t->coef, t->expx, t->expy);
        t = t->next;
        if (t != NULL) printf(" + ");
    }
    printf("\n");
}

/* ----------------------------------------------------------
                ADDITION :  P + Q
-----------------------------------------------------------*/

struct node* addPoly(struct node* P, struct node* Q) {
    struct node* R = NULL;

    while (P != NULL && Q != NULL) {
        if (P->expx == Q->expx && P->expy == Q->expy) {
            R = insertCombine(R, P->coef + Q->coef, P->expx, P->expy);
            P = P->next;
            Q = Q->next;
        }
        else if (P->expx > Q->expx ||
                (P->expx == Q->expx && P->expy > Q->expy)) {
            R = insertCombine(R, P->coef, P->expx, P->expy);
            P = P->next;
        }
        else {
            R = insertCombine(R, Q->coef, Q->expx, Q->expy);
            Q = Q->next;
        }
    }

    while (P != NULL) {
        R = insertCombine(R, P->coef, P->expx, P->expy);
        P = P->next;
    }

    while (Q != NULL) {
        R = insertCombine(R, Q->coef, Q->expx, Q->expy);
        Q = Q->next;
    }

    return R;
}

/* ----------------------------------------------------------
                SUBTRACTION :  P - Q
-----------------------------------------------------------*/

struct node* subtractPoly(struct node* P, struct node* Q) {
    struct node* R = NULL;

    while (P != NULL && Q != NULL) {
        if (P->expx == Q->expx && P->expy == Q->expy) {
            R = insertCombine(R, P->coef - Q->coef, P->expx, P->expy);
            P = P->next;
            Q = Q->next;
        }
        else if (P->expx > Q->expx ||
                (P->expx == Q->expx && P->expy > Q->expy)) {
            R = insertCombine(R, P->coef, P->expx, P->expy);
            P = P->next;
        }
        else {
            R = insertCombine(R, -Q->coef, Q->expx, Q->expy);
            Q = Q->next;
        }
    }

    while (P != NULL) {
        R = insertCombine(R, P->coef, P->expx, P->expy);
        P = P->next;
    }

    while (Q != NULL) {
        R = insertCombine(R, -Q->coef, Q->expx, Q->expy);
        Q = Q->next;
    }

    return R;
}

/* ----------------------------------------------------------
                MULTIPLICATION :  P * Q
-----------------------------------------------------------*/

struct node* multiplyPoly(struct node* P, struct node* Q) {
    struct node* R = NULL;

    for (struct node* p = P; p != NULL; p = p->next) {
        for (struct node* q = Q; q != NULL; q = q->next) {
            int c = p->coef * q->coef;
            int ex = p->expx + q->expx;
            int ey = p->expy + q->expy;

            R = insertCombine(R, c, ex, ey);
        }
    }

    return R;
}

/* ----------------------------------------------------------
                        MAIN PROGRAM
-----------------------------------------------------------*/

int main() {
    struct node *P = NULL, *Q = NULL, *A = NULL, *S = NULL, *M = NULL;
    int n, c, ex, ey;

    printf("Enter number of terms in P(x,y): ");
    scanf("%d", &n);
    printf("Enter coef, expx, expy:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &c, &ex, &ey);
        P = insertEnd(P, c, ex, ey);
    }

    printf("Enter number of terms in Q(x,y): ");
    scanf("%d", &n);
    printf("Enter coef, expx, expy:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &c, &ex, &ey);
        Q = insertEnd(Q, c, ex, ey);
    }

    printf("\nP(x,y) = ");
    display(P);

    printf("Q(x,y) = ");
    display(Q);

    // Perform operations
    A = addPoly(P, Q);
    S = subtractPoly(P, Q);
    M = multiplyPoly(P, Q);

    printf("\nP + Q = ");
    display(A);

    printf("P - Q = ");
    display(S);

    printf("P * Q = ");
    display(M);

    return 0;
}
