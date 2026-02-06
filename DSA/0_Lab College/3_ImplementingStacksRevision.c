/*
===============================================================================
                    STACK IMPLEMENTATION USING ARRAY & LINKED LIST
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

/*===============================================================================
                    STACK USING ARRAY
===============================================================================*/

int stackArr[MAXSIZE];
int topArr = -1;

/* ARRAY PUSH */
void pushArr(int val) {
    if (topArr == MAXSIZE - 1) {
        printf("Array Stack Overflow!\n");
        return;
    }
    stackArr[++topArr] = val;
}

/* ARRAY POP */
int popArr() {
    if (topArr == -1) {
        printf("Array Stack Underflow!\n");
        return -1;
    }
    return stackArr[topArr--];
}

/* ARRAY PEEK */
int peekArr() {
    if (topArr == -1) {
        printf("Array Stack is Empty!\n");
        return -1;
    }
    return stackArr[topArr];
}

/* ARRAY isEmpty */
int isEmptyArr() {
    return topArr == -1;
}

/* ARRAY isFull */
int isFullArr() {
    return topArr == MAXSIZE - 1;
}

/* ARRAY SIZE */
int sizeArr() {
    return topArr + 1;
}

/* ARRAY DISPLAY */
void displayArr() {
    if (isEmptyArr()) {
        printf("Array Stack Empty!\n");
        return;
    }
    printf("Array Stack (top → bottom): ");
    for (int i = topArr; i >= 0; i--)
        printf("%d ", stackArr[i]);
    printf("\n");
}



/*===============================================================================
                    STACK USING LINKED LIST
===============================================================================*/

struct Node {
    int data;
    struct Node* next;
};

struct Node* topLL = NULL;

/* LL isEmpty */
int isEmptyLL() {
    return topLL == NULL;
}

/* LL PUSH */
void pushLL(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Linked List Stack Overflow (Memory Full)!\n");
        return;
    }

    newNode->data = val;
    newNode->next = topLL;
    topLL = newNode;

    printf("Pushed (LL): %d\n", val);
}

/* LL POP */
int popLL() {
    if (isEmptyLL()) {
        printf("Linked List Stack Underflow!\n");
        return -1;
    }

    struct Node* temp = topLL;
    int value = temp->data;
    topLL = topLL->next;
    free(temp);

    return value;
}

/* LL PEEK */
int peekLL() {
    if (isEmptyLL()) {
        printf("Linked List Stack Empty!\n");
        return -1;
    }
    return topLL->data;
}

/* LL DISPLAY */
void displayLL() {
    if (isEmptyLL()) {
        printf("Linked List Stack Empty!\n");
        return;
    }

    struct Node* temp = topLL;
    printf("Linked List Stack (top → bottom): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



/*===============================================================================
                                MAIN FUNCTION
===============================================================================*/

int main() {

    printf("==========================================\n");
    printf("       STACK IMPLEMENTATION USING ARRAY   \n");
    printf("==========================================\n");

    pushArr(44);
    pushArr(10);
    pushArr(62);
    pushArr(123);
    pushArr(15);

    displayArr();
    printf("Top (Array): %d\n", peekArr());
    printf("Size (Array): %d\n", sizeArr());

    printf("\nPopping Array Stack:\n");
    while (!isEmptyArr())
        printf("Popped: %d\n", popArr());



    printf("\n\n==========================================\n");
    printf("     STACK IMPLEMENTATION USING LINKED LIST\n");
    printf("==========================================\n");

    pushLL(50);
    pushLL(20);
    pushLL(100);
    pushLL(7);

    displayLL();
    printf("Top (LL): %d\n", peekLL());

    printf("\nPopping Linked List Stack:\n");
    while (!isEmptyLL())
        printf("Popped: %d\n", popLL());

    return 0;
}
