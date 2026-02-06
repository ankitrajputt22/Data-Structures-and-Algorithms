/*
===============================================================================
EXPERIMENT – 5
IMPLEMENTING LINKED LISTS
===============================================================================
Includes:
1. Singly Linked List (Insert, Display, Delete, Search, Count, Reverse)
2. Circular Linked List (Insert, Display, Delete)
3. Doubly Linked List (Insert, Display, Delete)
4. Polynomial Representation & Addition
5. Comparative Study: Array vs Linked List
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*===============================================================================
SECTION 1 : SINGLY LINKED LIST (SLL)
===============================================================================*/

/*---------------- ALGORITHM ----------------
SLL_INSERT_BEGIN(x):
1. Create node
2. new->next = head
3. head = new

SLL_DELETE(x):
1. Traverse until node found
2. Adjust pointers & free node

SLL_SEARCH(x):
1. Traverse list
2. If found → return position

SLL_COUNT():
1. Traverse and count nodes

SLL_REVERSE():
1. Use 3 pointers: prev, curr, next
---------------------------------------------*/

struct SNode {
    int data;
    struct SNode* next;
};
struct SNode* head = NULL;

void insertSLL(int val) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void displaySLL() {
    printf("SLL: ");
    struct SNode* temp = head;
    if (!temp) { printf("Empty\n"); return; }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteSLL(int key) {
    struct SNode *temp = head, *prev = NULL;

    if (temp && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;

    prev->next = temp->next;
    free(temp);
}

void searchSLL(int key) {
    struct SNode* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Found %d at position %d\n", key, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Element %d NOT found\n", key);
}

int countSLL() {
    int c = 0;
    struct SNode* temp = head;
    while (temp) { c++; temp = temp->next; }
    return c;
}

void reverseSLL() {
    struct SNode *prev = NULL, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


/*===============================================================================
SECTION 2 : CIRCULAR LINKED LIST (CLL)
===============================================================================*/

/*---------------- ALGORITHM ----------------
CLL_INSERT_END(x):
1. Create node
2. If last == NULL → new->next = new
3. Else insert after last
4. last = new

CLL_DELETE(x):
1. Traverse circular list until found
2. Adjust links and free node
---------------------------------------------*/

struct CNode {
    int data;
    struct CNode* next;
};
struct CNode* last = NULL;

void insertCLL(int val) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = val;

    if (!last) {
        last = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void displayCLL() {
    if (!last) { printf("CLL: Empty\n"); return; }

    printf("CLL: ");
    struct CNode* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(head)\n");
}

void deleteCLL(int key) {
    if (!last) return;

    struct CNode *temp = last->next, *prev = last;

    while (temp->data != key) {
        if (temp == last) return;  
        prev = temp;
        temp = temp->next;
    }

    if (temp == last && temp->next == last) {
        last = NULL;
    } 
    else {
        if (temp == last) last = prev;
        prev->next = temp->next;
    }
    free(temp);
}


/*===============================================================================
SECTION 3 : DOUBLY LINKED LIST (DLL)
===============================================================================*/

/*---------------- ALGORITHM ----------------
DLL_INSERT_BEGIN(x):
1. Create node
2. new->next = start
3. start->prev = new
4. start = new

DLL_DELETE(x):
1. Traverse until key found
2. Adjust prev & next links
3. Free node
---------------------------------------------*/

struct DNode {
    int data;
    struct DNode *prev, *next;
};
struct DNode* start = NULL;

void insertDLL(int val) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = start;

    if (start) start->prev = newNode;
    start = newNode;
}

void displayDLL() {
    printf("DLL: ");
    struct DNode* temp = start;
    if (!temp) { printf("Empty\n"); return; }

    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteDLL(int key) {
    struct DNode* temp = start;

    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) return;

    if (temp->prev) temp->prev->next = temp->next;
    else start = temp->next;

    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
}


/*===============================================================================
SECTION 4 : POLYNOMIAL ADDITION USING LINKED LIST
===============================================================================*/

struct Poly {
    int coeff, pow;
    struct Poly* next;
};

struct Poly* createPolyNode(int c, int p, struct Poly* poly) {
    struct Poly* newNode = (struct Poly*)malloc(sizeof(struct Poly));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;

    if (!poly) return newNode;

    struct Poly* temp = poly;
    while (temp->next) temp = temp->next;
    temp->next = newNode;

    return poly;
}

void displayPoly(struct Poly* p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->pow);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

struct Poly* addPoly(struct Poly* p1, struct Poly* p2) {
    struct Poly *res = NULL;

    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            res = createPolyNode(p1->coeff, p1->pow, res);
            p1 = p1->next;
        }
        else if (p2->pow > p1->pow) {
            res = createPolyNode(p2->coeff, p2->pow, res);
            p2 = p2->next;
        }
        else {
            res = createPolyNode(p1->coeff + p2->coeff, p1->pow, res);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) { res = createPolyNode(p1->coeff, p1->pow, res); p1 = p1->next; }
    while (p2) { res = createPolyNode(p2->coeff, p2->pow, res); p2 = p2->next; }

    return res;
}


/*===============================================================================
SECTION 5 : COMPARISON — ARRAYS vs LINKED LISTS
===============================================================================*/

void comparison() {
    printf("\nCOMPARATIVE STUDY\n");
    printf("ARRAYS vs LINKED LISTS\n");
    printf("-------------------------------------\n");
    printf("Arrays:\n");
    printf("- Fixed size\n");
    printf("- Direct Access O(1)\n");
    printf("- Expensive insertion/deletion\n\n");

    printf("Linked Lists:\n");
    printf("- Dynamic size\n");
    printf("- Sequential Access O(n)\n");
    printf("- Easy insertion/deletion\n");
}


/*===============================================================================
MAIN FUNCTION — AUTO RUN ALL OPERATIONS
===============================================================================*/
int main() {

    /* ---------- SLL DEMO ---------- */
    printf("\n=== SINGLY LINKED LIST ===\n");
    insertSLL(10);
    insertSLL(20);
    insertSLL(30);
    displaySLL();
    printf("Count = %d\n", countSLL());
    searchSLL(20);
    reverseSLL();
    printf("Reversed: ");
    displaySLL();
    deleteSLL(20);
    displaySLL();

    /* ---------- CLL DEMO ---------- */
    printf("\n=== CIRCULAR LINKED LIST ===\n");
    insertCLL(5);
    insertCLL(15);
    insertCLL(25);
    displayCLL();
    deleteCLL(15);
    displayCLL();

    /* ---------- DLL DEMO ---------- */
    printf("\n=== DOUBLY LINKED LIST ===\n");
    insertDLL(100);
    insertDLL(200);
    insertDLL(300);
    displayDLL();
    deleteDLL(200);
    displayDLL();

    /* ---------- POLYNOMIAL ---------- */
    printf("\n=== POLYNOMIAL ADDITION ===\n");
    struct Poly *p1 = NULL, *p2 = NULL, *res = NULL;

    p1 = createPolyNode(3, 2, p1);
    p1 = createPolyNode(4, 1, p1);
    p1 = createPolyNode(2, 0, p1);

    p2 = createPolyNode(5, 1, p2);
    p2 = createPolyNode(6, 0, p2);

    printf("P1(x) = "); displayPoly(p1);
    printf("P2(x) = "); displayPoly(p2);

    res = addPoly(p1, p2);
    printf("Result = "); displayPoly(res);

    /* ---------- COMPARISON ---------- */
    comparison();

    return 0;
}
