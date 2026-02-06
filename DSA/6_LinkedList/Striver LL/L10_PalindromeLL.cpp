#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Definition for singly-linked list in Leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        stack<ListNode*> st;
        ListNode* temp = head;
        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        temp = head;
        bool isP = true;
        while (temp != NULL) {
            if (temp->val != st.top()->val) {
                isP = false;
                break;
            }

            temp = temp->next;
            st.pop();
        }

        return isP;
    }
};


class Solution2 {
public:
    ListNode* reverseLL(ListNode* node) {
        ListNode* last = NULL;
        while (node != NULL) {
            ListNode* front = node->next;
            node->next = last;
            last = node;
            node = front;
        }
        return last;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* mid = findMid(head);
        ListNode* secondHead = reverseLL(mid->next);

        ListNode* first = head;
        ListNode* second = secondHead;

        bool isPal = true;
        while (second != NULL) {
            if (first->val != second->val) {
                isPal = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        mid->next = reverseLL(secondHead);

        return isPal;
    }
};



int main() {
    newline2;

    

    newline2;
    return 0;
}