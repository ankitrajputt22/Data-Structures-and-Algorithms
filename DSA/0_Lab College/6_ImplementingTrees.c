/*
===============================================================================
EXPERIMENT – 6
IMPLEMENTING TREES & HEAPS
===============================================================================
Includes:
1. Binary Search Tree (BST)
   - Create, Insert
   - Recursive Traversals: Preorder, Inorder, Postorder
   - Search
   - Largest & Smallest Node
   - Count Nodes
2. Min Heap & Max Heap
   - Insert (Reheap Up)
   - Delete (Reheap Down)
3. Expression Tree (from postfix)
4. Heap Sort
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100


/*===============================================================================
SECTION 1 : BINARY SEARCH TREE (BST)
===============================================================================*/

/*---------------- ALGORITHM ----------------
BST_INSERT(root, key):
1. If root == NULL → create node
2. If key < root->data → insert left subtree
3. Else insert right subtree

TRAVERSALS:
Preorder:  Root → Left → Right
Inorder:   Left → Root → Right
Postorder: Left → Right → Root

SEARCH(key):
1. If root == NULL → not found
2. If key == root->data → found
3. Else search left or right subtree

FIND_MIN:
While left child exists → move left

FIND_MAX:
While right child exists → move right
---------------------------------------------*/

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insertBST(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* searchBST(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


/*===============================================================================
SECTION 2 : MIN HEAP AND MAX HEAP
===============================================================================*/

/*---------------- ALGORITHM ----------------
HEAP INSERT (Reheap Up):
1. Insert at end (heap[size])
2. Compare with parent
3. If violation → swap
4. Continue upward

DELETE ROOT (Reheap Down):
1. Replace root with last element
2. Compare with children
3. Swap with smaller child (min-heap)
4. Continue downward
---------------------------------------------*/

int minHeap[MAX], maxHeap[MAX];
int minSize = 0, maxSize = 0;

/*** MIN HEAP ***/
void reheapUpMin(int i) {
    if (i == 0) return;
    int parent = (i - 1) / 2;
    if (minHeap[i] < minHeap[parent]) {
        int t = minHeap[i]; minHeap[i] = minHeap[parent]; minHeap[parent] = t;
        reheapUpMin(parent);
    }
}

void insertMin(int val) {
    minHeap[minSize] = val;
    reheapUpMin(minSize);
    minSize++;
}

void reheapDownMin(int i) {
    int left = 2*i+1, right = 2*i+2, small = i;
    if (left < minSize && minHeap[left] < minHeap[small]) small = left;
    if (right < minSize && minHeap[right] < minHeap[small]) small = right;
    if (small != i) {
        int t = minHeap[i]; minHeap[i] = minHeap[small]; minHeap[small] = t;
        reheapDownMin(small);
    }
}

int deleteMin() {
    if (minSize == 0) return -1;
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    reheapDownMin(0);
    return root;
}

/*** MAX HEAP ***/
void reheapUpMax(int i) {
    if (i == 0) return;
    int parent = (i - 1) / 2;
    if (maxHeap[i] > maxHeap[parent]) {
        int t = maxHeap[i]; maxHeap[i] = maxHeap[parent]; maxHeap[parent] = t;
        reheapUpMax(parent);
    }
}

void insertMax(int val) {
    maxHeap[maxSize] = val;
    reheapUpMax(maxSize);
    maxSize++;
}

void reheapDownMax(int i) {
    int left = 2*i+1, right = 2*i+2, large = i;
    if (left < maxSize && maxHeap[left] > maxHeap[large]) large = left;
    if (right < maxSize && maxHeap[right] > maxHeap[large]) large = right;
    if (large != i) {
        int t = maxHeap[i]; maxHeap[i] = maxHeap[large]; maxHeap[large] = t;
        reheapDownMax(large);
    }
}

int deleteMax() {
    if (maxSize == 0) return -1;
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    reheapDownMax(0);
    return root;
}


/*===============================================================================
SECTION 3 : EXPRESSION TREE
===============================================================================*/

/*---------------- ALGORITHM ----------------
BUILD_EXPRESSION_TREE(postfix):
1. For each character:
   - If operand → push node
   - If operator → pop 2 nodes, make children, push new node
---------------------------------------------*/

struct ExpNode {
    char data;
    struct ExpNode *left, *right;
};

struct ExpNode* newExpNode(char c) {
    struct ExpNode* n = (struct ExpNode*)malloc(sizeof(struct ExpNode));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

struct ExpNode* buildET(char postfix[]) {
    struct ExpNode* stack[100];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = newExpNode(postfix[i]);
        } else {
            struct ExpNode* node = newExpNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}

void inorderET(struct ExpNode* r) {
    if (r) {
        inorderET(r->left);
        printf("%c ", r->data);
        inorderET(r->right);
    }
}


/*===============================================================================
SECTION 4 : HEAP SORT
===============================================================================*/

/*---------------- ALGORITHM ----------------
HEAPIFY(i):
1. Find left & right child
2. Compare with largest
3. Swap and continue

HEAP_SORT:
1. Build max heap
2. Swap root with last
3. Reduce heap size
4. Heapify again
---------------------------------------------*/

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0]; arr[0] = arr[i]; arr[i] = t;
        heapify(arr, i, 0);
    }
}


/*===============================================================================
MAIN FUNCTION — AUTO DEMO OF ALL OPERATIONS
===============================================================================*/
int main() {

    printf("\n==============================\n");
    printf("      BINARY SEARCH TREE\n");
    printf("==============================\n");

    struct Node* root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 80);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printf("Smallest: %d\n", findMin(root)->data);
    printf("Largest: %d\n", findMax(root)->data);
    printf("Total Nodes: %d\n", countNodes(root));


    printf("\n==============================\n");
    printf("           MIN HEAP\n");
    printf("==============================\n");

    insertMin(40); insertMin(20); insertMin(30); insertMin(10);
    printf("Deleted Min: %d\n", deleteMin());


    printf("\n==============================\n");
    printf("           MAX HEAP\n");
    printf("==============================\n");

    insertMax(40); insertMax(60); insertMax(20); insertMax(50);
    printf("Deleted Max: %d\n", deleteMax());


    printf("\n==============================\n");
    printf("        EXPRESSION TREE\n");
    printf("==============================\n");

    char postfix[] = "ab+c*";
    struct ExpNode* et = buildET(postfix);
    printf("Inorder Expression: ");
    inorderET(et);
    printf("\n");


    printf("\n==============================\n");
    printf("             HEAP SORT\n");
    printf("==============================\n");

    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    heapSort(arr, n);

    printf("\nSorted: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
