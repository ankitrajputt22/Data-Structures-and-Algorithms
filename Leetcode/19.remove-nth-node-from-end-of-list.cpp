#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 19: Remove Nth Node From End of List

    Problem:
    We are given the head of a linked list.
    We are also given an integer n.

    We have to remove the nth node from the end of the list.
    Return the head of the modified linked list.

    Example:
    head = 1 -> 2 -> 3 -> 4 -> 5
    n = 2

    Node from end:
    1st from end = 5
    2nd from end = 4

    After removing 4:
    1 -> 2 -> 3 -> 5
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
    Count the total number of nodes first.
    Then find the node position from the start.
    Delete that node.

    Step-by-step algorithm:
    1. Count total nodes in the linked list.
    2. Find the index to delete from start.
    3. Index to delete is length - n.
    4. If index is 0, delete the head node.
    5. Otherwise, go to the node before delete index.
    6. Change its next pointer.
    7. Delete the target node.
    8. Return head.

    Time complexity:
    O(length)

    Space complexity:
    O(1)

    Note:
    This solution uses two passes.
    First pass counts nodes.
    Second pass deletes the node.

------------------------------------------------------------*/
ListNode* removeNthFromEndBruteForce(ListNode* head, int n) {
    int length = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int deleteIndex = length - n;

    if (deleteIndex == 0) {
        ListNode* newHead = head->next;
        head->next = NULL;
        delete head;

        return newHead;
    }

    temp = head;

    for (int i = 0; i < deleteIndex - 1; i++) {
        temp = temp->next;
    }

    ListNode* deleteNode = temp->next;
    temp->next = temp->next->next;

    deleteNode->next = NULL;
    delete deleteNode;

    return head;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Array

    Basic idea:
    Store all nodes in an array.
    Then directly find the node to delete.

    Step-by-step algorithm:
    1. Create an array of ListNode pointers.
    2. Traverse the linked list.
    3. Store every node in the array.
    4. Find length using array size.
    5. Find delete index as length - n.
    6. If delete index is 0, delete head.
    7. Otherwise, use previous node from array.
    8. Change links and delete the target node.
    9. Return head.

    Time complexity:
    O(length)

    Space complexity:
    O(length)

    Note:
    This is easy to understand.
    But it uses extra space.
    Brute force is better in space.

------------------------------------------------------------*/
ListNode* removeNthFromEndBetterArray(ListNode* head, int n) {
    vector<ListNode*> nodes;

    ListNode* temp = head;

    while (temp != NULL) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    int length = nodes.size();
    int deleteIndex = length - n;

    if (deleteIndex == 0) {
        ListNode* newHead = head->next;
        head->next = NULL;
        delete head;

        return newHead;
    }

    ListNode* previousNode = nodes[deleteIndex - 1];
    ListNode* deleteNode = nodes[deleteIndex];

    previousNode->next = deleteNode->next;

    deleteNode->next = NULL;
    delete deleteNode;

    return head;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Fast and Slow Pointers

    Basic idea:
    Move fast pointer n steps ahead.
    Then move fast and slow together.
    When fast reaches the end, slow will be before
    the node that should be deleted.

    Step-by-step algorithm:
    1. Create fast pointer at head.
    2. Create slow pointer at head.
    3. Move fast n steps ahead.
    4. If fast becomes NULL, it means head should be deleted.
    5. Otherwise move fast and slow together
       until fast reaches the last node.
    6. Now slow is before the node to delete.
    7. Delete slow's next node.
    8. Return head.

    Time complexity:
    O(length)

    Space complexity:
    O(1)

    Note:
    This is the given solution idea.
    It removes the node in one pass after moving fast.
    It handles head deletion separately.

------------------------------------------------------------*/
ListNode* removeNthFromEndOptimalTwoPointer(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    if (fast == NULL) {
        ListNode* newHead = head->next;
        head->next = NULL;
        delete head;

        return newHead;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;

    deleteNode->next = NULL;
    delete deleteNode;

    return head;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Dummy Node

    Basic idea:
    Use a dummy node before head.
    This makes head deletion easy.
    We do not need a separate case for deleting head.

    Step-by-step algorithm:
    1. Create a dummy node.
    2. Connect dummy next to head.
    3. Put fast and slow at dummy.
    4. Move fast n steps ahead.
    5. Move fast and slow together until fast reaches last node.
    6. Now slow is before the node to delete.
    7. Delete slow's next node.
    8. Return dummy's next.

    Time complexity:
    O(length)

    Space complexity:
    O(1)

    Note:
    This is also an optimal approach.
    Dummy node makes the code cleaner.
    It avoids special handling for head deletion.

------------------------------------------------------------*/
ListNode* removeNthFromEndOptimalDummy(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;

    deleteNode->next = NULL;
    delete deleteNode;

    ListNode* newHead = dummy->next;
    delete dummy;

    return newHead;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal two pointer solution.

------------------------------------------------------------*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEndOptimalTwoPointer(head, n);
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
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head1 = createList(values);
    ListNode* head2 = createList(values);
    ListNode* head3 = createList(values);
    ListNode* head4 = createList(values);

    ListNode* ans1 = removeNthFromEndBruteForce(head1, n);
    ListNode* ans2 = removeNthFromEndBetterArray(head2, n);
    ListNode* ans3 = removeNthFromEndOptimalTwoPointer(head3, n);
    ListNode* ans4 = removeNthFromEndOptimalDummy(head4, n);

    cout << "Brute Force Solution:" << endl;
    printList(ans1);

    cout << "Better Solution using Array:" << endl;
    printList(ans2);

    cout << "Optimal Solution using Fast and Slow Pointers:" << endl;
    printList(ans3);

    cout << "Optimal Solution using Dummy Node:" << endl;
    printList(ans4);

    return 0;
}