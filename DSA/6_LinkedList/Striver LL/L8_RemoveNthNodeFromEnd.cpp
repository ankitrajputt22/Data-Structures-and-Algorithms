#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
============================================================
REMOVE Nth NODE FROM END OF LINKED LIST
============================================================

PROBLEM
------------------------------------------------------------
Given the head of a singly linked list and an integer N,
remove the Nth node from the END of the list.

Return the updated head.

Since singly linked list cannot move backward,
we must use special logic.

============================================================
APPROACH 1 — BRUTE FORCE (TWO PASSES)
============================================================

STEP 1:
Find total length of list = L

STEP 2:
Node to delete from start = (L - N + 1)

STEP 3:
Go to node before it = (L - N)
Change pointer to skip target node

------------------------------------------------------------
EDGE CASE:
If N == L → delete head
Return head->next

------------------------------------------------------------
TIME COMPLEXITY:
O(L) + O(L-N) ≈ O(2L)

SPACE:
O(1)

------------------------------------------------------------
INTUITION:
Convert "from end" problem → "from start"

============================================================
APPROACH 2 — OPTIMAL (FAST & SLOW POINTERS)
============================================================

CORE IDEA:
Maintain gap of N nodes between fast and slow.

STEP 1:
Move fast pointer N steps ahead.

STEP 2:
If fast becomes NULL
→ delete head (N == length)

STEP 3:
Move both pointers together
until fast reaches last node.

STEP 4:
Slow is just before node to delete.

Delete node:
slow->next = slow->next->next

------------------------------------------------------------
TIME COMPLEXITY:
O(L) (single traversal)

SPACE:
O(1)

------------------------------------------------------------
WHY IT WORKS?
Because distance between fast and slow is N.
When fast reaches end,
slow is positioned perfectly before target.

============================================================
INTERVIEW TIP
============================================================

Whenever problem says:
"from end of linked list"

Think:
FAST–SLOW POINTER GAP METHOD

============================================================
IMPLEMENTATION
============================================================
*/


/*=============================
   LINKED LIST NODE
=============================*/
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


/*==================================================
APPROACH 1 — BRUTE FORCE
==================================================*/
ListNode* removeNthFromEnd_Brute(ListNode* head, int n) {

    if (!head) return NULL;

    int len = 0;
    ListNode* temp = head;

    while (temp) {
        len++;
        temp = temp->next;
    }

    if (n == len)
        return head->next;

    int pos = len - n;

    temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->next = temp->next->next;

    return head;
}


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = 0;
        ListNode* temp = head;

        // find length
        while (temp != NULL) {
            L++;
            temp = temp->next;
        }

        int k = L - n;

        // remove head
        if (k == 0) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        // move to (k-1)th node
        temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        return head;
    }
};

/*==================================================
APPROACH 2 — OPTIMAL FAST & SLOW
==================================================*/
ListNode* removeNthFromEnd_Optimal(ListNode* head, int n) {

    if (!head) return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (!fast)
        return head->next;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}


/*==================================================
UTILITY — CREATE LIST
==================================================*/
ListNode* createList(vector<int> v) {

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    return head;
}


/*==================================================
UTILITY — PRINT LIST
==================================================*/
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


/*==================================================
MAIN
==================================================*/
int main() {

    vector<int> arr = {1,2,3,4,5};
    ListNode* head1 = createList(arr);
    ListNode* head2 = createList(arr);

    int n = 2;

    cout << "Original List:\n";
    printList(head1);

    cout << "\nAfter Brute Force Removal:\n";
    head1 = removeNthFromEnd_Brute(head1, n);
    printList(head1);

    cout << "\nAfter Optimal Removal:\n";
    head2 = removeNthFromEnd_Optimal(head2, n);
    printList(head2);

    return 0;
}