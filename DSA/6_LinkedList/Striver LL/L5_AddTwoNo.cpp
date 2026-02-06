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

class Solution_1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry = 0;
        int sum;
        while (l1 || l2 || carry) {
            sum = carry;

            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = node;
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;        
    }
};

class Solution_2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry = 0;
        int sum;
        while (t1 != NULL || t2 != NULL) {
            sum = carry;
            if (t1) sum += t1->val;
            if (t2) sum += t2->val;
        
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        if (carry) {
            ListNode* carryNode = new ListNode(carry);
            curr->next = carryNode;
        }

        ListNode* result = dummy->next;
        dummy->next = nullptr;
        delete dummy;        //Clean up dummy node
        return result;
    }
};

int main() {
    
    return 0;
}