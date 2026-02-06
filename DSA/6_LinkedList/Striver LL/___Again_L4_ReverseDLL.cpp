#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


// Definition for doubly-linked list
struct ListNode {
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode() : val(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next)
        : val(x), prev(prev), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        stack<int> st;
        ListNode* temp = head;

        // Step 1: Push all values into stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2: Replace values in reverse order
        temp = head;
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};


ListNode* reverseDLL(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* curr = head;
    ListNode* last = NULL;

    while (curr != NULL) {
        last = curr->prev;

        // swap prev and next
        curr->prev = curr->next;
        curr->next = last;

        // move to next node (original next)
        curr = curr->prev;
    }

    // last is pointing to the old head's prev
    return last->prev;
}





int main() {
    newline2;

    


    newline2;
    return 0;
}