#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Head;

    Solution(ListNode* head) {
        Head = head;
        srand(time(0)); // seed random once
    }

    int getRandom() {
        int count = 1;
        int result = -1;

        ListNode* temp = Head;

        while (temp != NULL) {
            // Reservoir Sampling condition
            if (rand() % count == 0) {
                result = temp->val;
            }
            count++;
            temp = temp->next;
        }
        return result;
    }
};

/*
====================== DRY RUN ======================

Linked List:
10 -> 20 -> 30 -> 40 -> NULL

Initial:
count = 1
result = -1

Iteration 1:
temp->val = 10
rand() % 1 == 0  ✅ always true
result = 10
count = 2

Iteration 2:
temp->val = 20
rand() % 2 == 0  (50% chance)
If true -> result = 20
count = 3

Iteration 3:
temp->val = 30
rand() % 3 == 0  (33% chance)
If true -> result = 30
count = 4

Iteration 4:
temp->val = 40
rand() % 4 == 0  (25% chance)
If true -> result = 40

END LOOP

Each node has equal probability (1/4) of being chosen.
====================================================
*/

int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    Solution obj(head);

    // Call getRandom multiple times to see randomness
    for (int i = 0; i < 5; i++) {
        cout << obj.getRandom() << endl;
    }

    return 0;
}
