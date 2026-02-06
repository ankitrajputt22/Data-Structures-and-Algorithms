/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    }
};
// @lc code=end

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* head = NULL;
        ListNode* temp = head;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                if (head == NULL) {
                    head = list1;
                    temp = head;
                }
                else {
                    temp->next = list1;
                    temp = temp->next;
                }

                list1 = list1->next;
            }
            else {
                if (head == NULL) {
                    head = list2;
                    temp = head;
                }  
                else {
                    temp->next = list2;
                    temp = temp->next;
                }              

                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }

        return head;
    }
};



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);       // dummy starter node
    ListNode* tail = &dummy; // tail builds the list

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = list1 ? list1 : list2;

    return dummy.next;
}
