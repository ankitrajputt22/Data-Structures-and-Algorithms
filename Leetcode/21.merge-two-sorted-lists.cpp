#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 21: Merge Two Sorted Lists

    Problem:
    We are given the heads of two sorted linked lists.
    We have to merge both lists into one sorted linked list.
    Return the head of the merged linked list.

    Example:
    list1 = 1 -> 2 -> 4
    list2 = 1 -> 3 -> 4

    Answer:
    1 -> 1 -> 2 -> 3 -> 4 -> 4
*/

/*------------------------------------------------------------

    ListNode structure

------------------------------------------------------------*/
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Store all values from both linked lists in an array.
    Sort the array.
    Create a new linked list from sorted values.

    Step-by-step algorithm:
    1. Create an empty array.
    2. Traverse list1 and store all values.
    3. Traverse list2 and store all values.
    4. Sort the array.
    5. Create a new linked list using sorted values.
    6. Return the head of the new list.

    Time complexity:
    O((n + m) log(n + m))

    Space complexity:
    O(n + m)

    Note:
    n is the length of list1.
    m is the length of list2.
    This solution is simple.
    But it does not use the fact that both lists are already sorted.

------------------------------------------------------------*/
ListNode* mergeTwoListsBruteForce(ListNode* list1, ListNode* list2) {
    vector<int> values;

    ListNode* temp = list1;

    while (temp != NULL) {
        values.push_back(temp->val);
        temp = temp->next;
    }

    temp = list2;

    while (temp != NULL) {
        values.push_back(temp->val);
        temp = temp->next;
    }

    sort(values.begin(), values.end());

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    for (int i = 0; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}

/*------------------------------------------------------------

    Approach 2: Better Solution by Creating New Nodes

    Basic idea:
    Both linked lists are already sorted.
    Compare the current nodes of both lists.
    Create a new node with the smaller value.

    Step-by-step algorithm:
    1. Create a dummy node.
    2. Create tail pointer at dummy.
    3. Traverse both lists while both are not NULL.
    4. Compare list1 value and list2 value.
    5. Add the smaller value as a new node.
    6. Move the pointer of the chosen list.
    7. Add remaining nodes from list1 if any.
    8. Add remaining nodes from list2 if any.
    9. Return dummy's next.

    Time complexity:
    O(n + m)

    Space complexity:
    O(n + m)

    Note:
    This is better than brute force.
    It uses sorted property.
    But it creates a new linked list.

------------------------------------------------------------*/
ListNode* mergeTwoListsBetterNewNodes(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            tail->next = new ListNode(list2->val);
            list2 = list2->next;
        }

        tail = tail->next;
    }

    while (list1 != NULL) {
        tail->next = new ListNode(list1->val);
        tail = tail->next;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        tail->next = new ListNode(list2->val);
        tail = tail->next;
        list2 = list2->next;
    }

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Iteration

    Basic idea:
    Reuse the existing nodes.
    Attach the smaller node to the answer list.
    Move that list pointer forward.

    Step-by-step algorithm:
    1. Create a dummy node.
    2. Create tail pointer at dummy.
    3. While both lists are not NULL:
       compare list1 and list2 values.
    4. Attach the smaller node to tail.
    5. Move the selected list pointer forward.
    6. Move tail forward.
    7. After loop, attach the remaining list.
    8. Return dummy's next.

    Time complexity:
    O(n + m)

    Space complexity:
    O(1)

    Note:
    This is the best iterative approach.
    It does not create new nodes.
    It only changes links.

------------------------------------------------------------*/
ListNode* mergeTwoListsOptimalIterative(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Recursion

    Basic idea:
    Compare the first nodes of both lists.
    The smaller node becomes the current head.
    Recursively merge the remaining list.

    Step-by-step algorithm:
    1. If list1 is NULL, return list2.
    2. If list2 is NULL, return list1.
    3. If list1 value is smaller or equal:
       list1 should come first.
    4. Set list1 next as merge of list1 next and list2.
    5. Return list1.
    6. Otherwise list2 should come first.
    7. Set list2 next as merge of list1 and list2 next.
    8. Return list2.

    Time complexity:
    O(n + m)

    Space complexity:
    O(n + m)

    Note:
    This is also optimal in time.
    But it uses recursion stack space.
    Iterative solution is better in space.

------------------------------------------------------------*/
ListNode* mergeTwoListsOptimalRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    if (list1->val <= list2->val) {
        list1->next = mergeTwoListsOptimalRecursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoListsOptimalRecursive(list1, list2->next);
        return list2;
    }
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal iterative solution.

------------------------------------------------------------*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeTwoListsOptimalIterative(list1, list2);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function creates a linked list from an array.

------------------------------------------------------------*/
ListNode* createList(vector<int> values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    for (int i = 0; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}

/*------------------------------------------------------------

    Helper function:
    This function prints a linked list.

------------------------------------------------------------*/
void printList(ListNode* head) {
    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val;

        if (temp->next != NULL) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};

    ListNode* list1A = createList(values1);
    ListNode* list2A = createList(values2);

    ListNode* list1B = createList(values1);
    ListNode* list2B = createList(values2);

    ListNode* list1C = createList(values1);
    ListNode* list2C = createList(values2);

    ListNode* list1D = createList(values1);
    ListNode* list2D = createList(values2);

    ListNode* ans1 = mergeTwoListsBruteForce(list1A, list2A);
    ListNode* ans2 = mergeTwoListsBetterNewNodes(list1B, list2B);
    ListNode* ans3 = mergeTwoListsOptimalIterative(list1C, list2C);
    ListNode* ans4 = mergeTwoListsOptimalRecursive(list1D, list2D);

    cout << "Brute Force Solution:" << endl;
    printList(ans1);

    cout << "Better Solution by Creating New Nodes:" << endl;
    printList(ans2);

    cout << "Optimal Solution using Iteration:" << endl;
    printList(ans3);

    cout << "Optimal Solution using Recursion:" << endl;
    printList(ans4);

    return 0;
}