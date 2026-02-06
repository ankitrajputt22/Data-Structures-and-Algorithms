/*
===============================================================================
EXPERIMENT: Implementing Stacks:
1. Stack using Array
2. Stack using Linked List
3. Evaluation of Postfix Expression
4. Balancing of Parentheses
5. Conversion of Infix to Postfix
===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

/*===============================================================================
 🔹 STACK USING ARRAY — ALGORITHM
---------------------------------
PUSH(item):
1. If top == MAX-1 → Overflow
2. Else top = top + 1
3. stack[top] = item

POP():
1. If top == -1 → Underflow
2. Else return stack[top--]
===============================================================================*/

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

void displayArrayStack() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack (Array) (top → bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}


/*===============================================================================
 🔹 STACK USING LINKED LIST — ALGORITHM
----------------------------------------
PUSH_LL(item):
1. Create new node
2. newNode->next = head
3. head = newNode

POP_LL():
1. If head == NULL → Underflow
2. Else pop head and move pointer
===============================================================================*/

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void pushLL(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

int popLL() {
    if (head == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = head->data;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return val;
}

void displayLinkedListStack() {
    struct Node* temp = head;
    if (!temp) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (Linked List) (top → bottom): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/*===============================================================================
 🔹 EVALUATE POSTFIX — ALGORITHM
---------------------------------
1. For each char:
   - If operand → push
   - If operator → pop two values, apply operator, push result
2. Final value = top of stack
===============================================================================*/
int evaluatePostfix(char* exp) {
    int evalStack[MAX], topEval = -1;

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            evalStack[++topEval] = exp[i] - '0';
        } else {
            int b = evalStack[topEval--];
            int a = evalStack[topEval--];

            switch (exp[i]) {
                case '+': evalStack[++topEval] = a + b; break;
                case '-': evalStack[++topEval] = a - b; break;
                case '*': evalStack[++topEval] = a * b; break;
                case '/': evalStack[++topEval] = a / b; break;
            }
        }
    }
    return evalStack[topEval];
}


/*===============================================================================
 🔹 CHECK BALANCED PARENTHESES — ALGORITHM
-------------------------------------------
1. Scan each char:
   - Push if opening bracket
   - Pop if closing bracket and check pair
2. If stack empty → Balanced
===============================================================================*/
int isBalanced(char* exp) {
    char stk[MAX];
    int topB = -1;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[')
            stk[++topB] = c;

        else if (c == ')' || c == '}' || c == ']') {
            if (topB == -1) return 0;

            char ch = stk[topB--];
            if ((c == ')' && ch != '(') ||
                (c == '}' && ch != '{') ||
                (c == ']' && ch != '['))
                return 0;
        }
    }
    return topB == -1;
}


/*===============================================================================
 🔹 INFIX → POSTFIX — ALGORITHM
--------------------------------
1. Operand → output
2. '(' → push
3. ')' → pop until '('
4. Operator → pop while precedence(top) ≥ precedence(current)
5. Pop remaining operators at end
===============================================================================*/

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    int topP = -1, k = 0;
    char stk[MAX];

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c))
            postfix[k++] = c;

        else if (c == '(')
            stk[++topP] = c;

        else if (c == ')') {
            while (stk[topP] != '(')
                postfix[k++] = stk[topP--];
            topP--; // remove '('
        }

        else {
            while (topP != -1 && precedence(stk[topP]) >= precedence(c))
                postfix[k++] = stk[topP--];
            stk[++topP] = c;
        }
    }

    while (topP != -1)
        postfix[k++] = stk[topP--];

    postfix[k] = '\0';
}


/*===============================================================================
 🔹 MAIN FUNCTION — NO MENU, AUTO RUN ALL OPERATIONS
===============================================================================*/
int main() {

    printf("\n==============================\n");
    printf("      STACK USING ARRAY\n");
    printf("==============================\n");

    push(10); 
    push(20); 
    push(30);
    displayArrayStack();
    printf("Popped: %d\n", pop());
    displayArrayStack();


    printf("\n==============================\n");
    printf("   STACK USING LINKED LIST\n");
    printf("==============================\n");

    pushLL(5);
    pushLL(15);
    pushLL(25);
    displayLinkedListStack();
    printf("Popped: %d\n", popLL());
    displayLinkedListStack();


    printf("\n==============================\n");
    printf("     POSTFIX EVALUATION\n");
    printf("==============================\n");

    char postfixExp[] = "23*54*+";
    printf("Postfix Expression: %s\n", postfixExp);
    printf("Evaluated Result: %d\n", evaluatePostfix(postfixExp));


    printf("\n==============================\n");
    printf("  BALANCED PARENTHESES TEST\n");
    printf("==============================\n");

    char exp1[] = "{(a+b)*[c-d]}";
    char exp2[] = "((a+b]*c)";

    printf("%s --> %s\n", exp1, isBalanced(exp1) ? "Balanced" : "Not Balanced");
    printf("%s --> %s\n", exp2, isBalanced(exp2) ? "Balanced" : "Not Balanced");


    printf("\n==============================\n");
    printf("     INFIX TO POSTFIX\n");
    printf("==============================\n");

    char infix[] = "(a+b)*c-d";
    char postfix[100];

    infixToPostfix(infix, postfix);

    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
