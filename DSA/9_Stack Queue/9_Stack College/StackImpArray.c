/*
---------------------------------------------------------
                STACK IMPLEMENTATION USING ARRAY
---------------------------------------------------------
Stack follows LIFO (Last In, First Out)

Operations:
• PUSH     → Insert element
• POP      → Remove element
• PEEK     → View top element
• isEmpty  → Check if stack is empty
• isFull   → Check if stack is full
• size     → Total elements
• display  → Print all elements
---------------------------------------------------------
Algorithm: PUSH(stack, top, item)
1. If top == MAX-1 → Overflow
2. Else top = top + 1
3.      stack[top] = item

Algorithm: POP(stack, top)
1. If top == -1 → Underflow
2. Else item = stack[top]
3.      top = top - 1
4.      return item
---------------------------------------------------------
*/

#include <stdio.h>
#define MAXSIZE 100

/*---------------------------------------------------------
                GLOBAL STACK VARIABLES
---------------------------------------------------------*/
int stack[MAXSIZE];
int top = -1;

/*---------------------------------------------------------
                       PUSH OPERATION
---------------------------------------------------------*/
void push(int val) {
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = val;
}

/*---------------------------------------------------------
                       POP OPERATION
---------------------------------------------------------*/
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

/*---------------------------------------------------------
                       PEEK OPERATION
---------------------------------------------------------*/
int peek() {
    if (top == -1) {
        printf("Stack Empty!\n");
        return -1;
    }
    return stack[top];
}

/*---------------------------------------------------------
                    CHECK EMPTY / FULL
---------------------------------------------------------*/
int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAXSIZE - 1;
}

/*---------------------------------------------------------
                        SIZE OF STACK
---------------------------------------------------------*/
int stackSize() {
    return top + 1;
}

/*---------------------------------------------------------
                        DISPLAY STACK
---------------------------------------------------------*/
void display() {
    if (isEmpty()) {
        printf("Stack Empty!\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/*---------------------------------------------------------
                            MAIN
---------------------------------------------------------*/
int main() {

    printf("----- STACK OPERATIONS USING ARRAY -----\n");

    push(44);
    push(10);
    push(62);
    push(123);
    push(15);

    printf("\nCurrent Stack:\n");
    display();

    printf("\nTop Element (peek): %d\n", peek());
    printf("Stack Size: %d\n", stackSize());
    printf("Is Stack Full?  %s\n", isFull() ? "Yes" : "No");

    printf("\nPopping all elements:\n");
    while (!isEmpty())
        printf("Popped: %d\n", pop());

    printf("\nIs Stack Empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
