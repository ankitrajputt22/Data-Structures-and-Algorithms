#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2095: Delete the Middle Node of a Linked List

    Problem:
    We are given the head of a linked list.
    We have to delete the middle node of the linked list.
    Return the head of the modified linked list.

    Middle node:
    If the length of linked list is n,
    then the middle node is at index n / 2.

    Indexing starts from 0.

    Example:
    head = 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6

    n = 7
    middle index = 7 / 2 = 3

    Node at index 3 is 7.
    After deleting it:

    1 -> 3 -> 4 -> 1 -> 2 -> 6
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
    First count the total number of nodes.
    Then go to the node before the middle node.
    Delete the middle node.

    Step-by-step algorithm:
    1. If head is NULL, return NULL.
    2. If head has only one node, return NULL.
    3. Count total number of nodes.
    4. Find middle index as n / 2.
    5. Traverse to the node before middle node.
    6. Delete the middle node by changing links.
    7. Return head.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    n is the number of nodes.
    This solution uses two passes.
    First pass counts nodes.
    Second pass deletes the middle node.

------------------------------------------------------------*/
ListNode* deleteMiddleBruteForce(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    int n = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int middleIndex = n / 2;

    temp = head;

    for (int i = 0; i < middleIndex - 1; i++) {
        temp = temp->next;
    }

    ListNode* nodeToDelete = temp->next;
    temp->next = temp->next->next;

    delete nodeToDelete;

    return head;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Array

    Basic idea:
    Store all nodes in an array.
    Then directly find the middle node.
    Delete it using the previous node.

    Step-by-step algorithm:
    1. If head is NULL, return NULL.
    2. Store all linked list nodes in an array.
    3. If array size is 1, return NULL.
    4. Find middle index as size / 2.
    5. Get the previous node from array.
    6. Connect previous node to middle node's next.
    7. Delete the middle node.
    8. Return head.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This approach is easy to understand.
    But it uses extra array space.
    For this problem, brute force is better in space.

------------------------------------------------------------*/
ListNode* deleteMiddleBetter(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    vector<ListNode*> nodes;
    ListNode* temp = head;

    while (temp != NULL) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    int n = nodes.size();

    if (n == 1) {
        delete head;
        return NULL;
    }

    int middleIndex = n / 2;

    ListNode* previousNode = nodes[middleIndex - 1];
    ListNode* nodeToDelete = nodes[middleIndex];

    previousNode->next = nodeToDelete->next;

    delete nodeToDelete;

    return head;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Slow and Fast Pointers

    Basic idea:
    Use slow and fast pointers.
    When fast reaches the end,
    slow reaches the middle node.

    Step-by-step algorithm:
    1. If head is NULL, return NULL.
    2. If head has only one node, return NULL.
    3. Create slow pointer at head.
    4. Create fast pointer at head.
    5. Create prev pointer as NULL.
    6. Move slow by 1 step.
    7. Move fast by 2 steps.
    8. Keep prev before slow.
    9. When fast reaches end, slow is middle node.
    10. Delete slow by linking prev to slow's next.
    11. Return head.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It deletes the middle node in one pass.
    It does not use extra space.

------------------------------------------------------------*/
ListNode* deleteMiddleOptimal(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    delete slow;

    return head;
}



class SolutionMy {
public:

    /*------------------------------------------------------------

        Approach 1: Delete Middle using Length Count

        Basic idea:
        First count the length of the linked list.
        Then go to the node before the middle node.
        Delete the middle node.

        Step-by-step algorithm:
        1. If list is empty or has only one node, return nullptr.
        2. Count the total length of the linked list.
        3. Find the middle index using length / 2.
        4. Start again from head.
        5. Move to the node just before the middle node.
        6. Store the middle node in delNode.
        7. Connect previous node to the next node of delNode.
        8. Delete delNode.
        9. Return head.

        Time complexity:
        O(n)

        Space complexity:
        O(1)

        Note:
        This approach uses two passes.
        First pass counts the length.
        Second pass deletes the middle node.

    ------------------------------------------------------------*/
    ListNode* deleteMiddle(ListNode* head) {
        /*
            If list is empty or has only one node,
            after deleting middle node, list becomes empty.
        */
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        /*
            Count total number of nodes.
        */
        ListNode* temp = head;
        int len = 0;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        /*
            Middle index is len / 2.

            We need to stop at the node before middle.
            So we move len / 2 - 1 steps.
        */
        int middleIndex = len / 2;

        temp = head;

        for (int i = 0; i < middleIndex - 1; i++) {
            temp = temp->next;
        }

        /*
            temp is now previous node of middle node.
        */
        ListNode* prev = temp;
        ListNode* delNode = prev->next;

        /*
            Skip the middle node.
        */
        prev->next = delNode->next;

        /*
            Delete the middle node.
        */
        delNode->next = nullptr;
        delete delNode;

        return head;
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

    return dummy->next;
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
    vector<int> values = {1, 3, 4, 7, 1, 2, 6};

    ListNode* head1 = createList(values);
    ListNode* head2 = createList(values);
    ListNode* head3 = createList(values);

    ListNode* ans1 = deleteMiddleBruteForce(head1);
    ListNode* ans2 = deleteMiddleBetter(head2);
    ListNode* ans3 = deleteMiddleOptimal(head3);

    cout << "Brute Force Solution:" << endl;
    printList(ans1);

    cout << "Better Solution:" << endl;
    printList(ans2);

    cout << "Optimal Solution:" << endl;
    printList(ans3);

    return 0;
}