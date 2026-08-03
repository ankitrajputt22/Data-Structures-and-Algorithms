#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    LeetCode 23: Merge k Sorted Lists

    Problem:
    We are given k sorted linked lists.
    Each linked list is sorted in ascending order.
    We have to merge all lists into one sorted linked list.
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
    Store all node values in an array.
    Sort the array.
    Create a new linked list from sorted values.

    Step-by-step algorithm:
    1. Create an empty array.
    2. Traverse every linked list.
    3. Store every node value in the array.
    4. Sort the array.
    5. Create a new linked list using sorted values.
    6. Return the head of the new list.

    Time complexity:
    O(N log N)

    Space complexity:
    O(N)

    Note:
    N is the total number of nodes.
    This solution is simple.
    But it uses extra space.
    It can be slow because of sorting.

------------------------------------------------------------*/
ListNode* mergeKListsBruteForce(vector<ListNode*>& lists) {
    vector<int> values;

    for (int i = 0; i < lists.size(); i++) {
        ListNode* temp = lists[i];

        while (temp != NULL) {
            values.push_back(temp->val);
            temp = temp->next;
        }
    }

    sort(values.begin(), values.end());

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
    This function merges two sorted linked lists.

------------------------------------------------------------*/
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
    }

    if (list2 != NULL) {
        tail->next = list2;
    }

    return dummy->next;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Merge lists one by one.
    Keep one answer list.
    Merge the answer with every list.

    Step-by-step algorithm:
    1. Create answer as NULL.
    2. Traverse all linked lists.
    3. Merge answer with current list.
    4. Store the merged list in answer.
    5. Return answer.

    Time complexity:
    O(k * N)

    Space complexity:
    O(1)

    Note:
    N is the total number of nodes.
    k is the number of linked lists.
    This uses less extra space.
    But it can be slow when k is large.

------------------------------------------------------------*/
ListNode* mergeKListsBetter(vector<ListNode*>& lists) {
    ListNode* ans = NULL;

    for (int i = 0; i < lists.size(); i++) {
        ans = mergeTwoLists(ans, lists[i]);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Divide and Conquer

    Basic idea:
    Merge lists in pairs.
    This works like merge sort.
    It reduces repeated work.

    Step-by-step algorithm:
    1. If the list array is empty, return NULL.
    2. Merge lists in pairs.
    3. Store merged lists back in the array.
    4. Repeat until only one list remains.
    5. Return the final list.

    Time complexity:
    O(N log k)

    Space complexity:
    O(1)

    Note:
    N is the total number of nodes.
    k is the number of linked lists.
    This is an optimal approach.
    It does not use a heap.

------------------------------------------------------------*/
ListNode* mergeKListsDivideAndConquer(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return NULL;
    }

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists;

        for (int i = 0; i < lists.size(); i = i + 2) {
            ListNode* list1 = lists[i];
            ListNode* list2 = NULL;

            if (i + 1 < lists.size()) {
                list2 = lists[i + 1];
            }

            ListNode* merged = mergeTwoLists(list1, list2);
            mergedLists.push_back(merged);
        }

        lists = mergedLists;
    }

    return lists[0];
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Min Heap

    Basic idea:
    Use a min heap.
    Always pick the smallest current node.

    Step-by-step algorithm:
    1. Create a min heap.
    2. Push the head of every non-empty list into the heap.
    3. Create a dummy node for the answer.
    4. Remove the smallest node from the heap.
    5. Add that node to the answer list.
    6. If that node has a next node, push it into the heap.
    7. Repeat until the heap becomes empty.
    8. Return dummy's next.

    Time complexity:
    O(N log k)

    Space complexity:
    O(k)

    Note:
    N is the total number of nodes.
    k is the number of linked lists.
    This is also an optimal approach.
    It is easy to understand with priority queue.

------------------------------------------------------------*/
class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKListsOptimal(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL) {
            pq.push(lists[i]);
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (!pq.empty()) {
        ListNode* smallNode = pq.top();
        pq.pop();

        tail->next = smallNode;
        tail = tail->next;

        if (smallNode->next != NULL) {
            pq.push(smallNode->next);
        }
    }

    tail->next = NULL;

    return dummy->next;
}

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
    This function creates test linked lists.

------------------------------------------------------------*/
vector<ListNode*> createTestLists() {
    vector<ListNode*> lists;

    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    return lists;
}

/*------------------------------------------------------------

    Helper function:
    This function prints a linked list.

------------------------------------------------------------*/
void printList(ListNode* head) {
    ListNode* temp = head;

    if (temp == NULL) {
        cout << "Empty List";
    }

    while (temp != NULL) {
        cout << temp->val;

        if (temp->next != NULL) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}


class SolutionOneMoreSolution {
public:

    /*------------------------------------------------------------

        Approach: Divide and Conquer

        Basic idea:
        Merge lists like merge sort.

        We divide the list array into two halves.
        Then we merge the left half.
        Then we merge the right half.
        At the end, we merge both sorted linked lists.

        Example:
        lists = [L1, L2, L3, L4]

        First divide:
        [L1, L2] and [L3, L4]

        Then merge:
        merge(L1, L2)
        merge(L3, L4)

        Final merge:
        merge(left merged list, right merged list)

        Step-by-step algorithm:
        1. If lists array is empty, return nullptr.
        2. Use a function partitionAndMerge().
        3. In partitionAndMerge(), find the middle index.
        4. Recursively solve the left part.
        5. Recursively solve the right part.
        6. Merge both sorted linked lists.
        7. Return the merged list.

        Time complexity:
        O(N log k)

        Where:
        N = total number of nodes in all linked lists
        k = total number of linked lists

        Why:
        At each level, all nodes are processed once.
        There are log k levels.
        So total time is O(N log k).

        If each list has average length n:
        N = k * n
        So time complexity is O(k * n * log k).

        Space complexity:
        O(N)

        Why:
        We are using recursion in mergeTwoSortedLists().
        The recursion stack can go up to the length of the merged list.

        Note:
        This approach is better than merging lists one by one.
        It keeps the merging balanced.

    ------------------------------------------------------------*/
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        /*
            If one list is empty,
            return the other list.
        */
        if (l1 == nullptr) {
            return l2;
        }

        if (l2 == nullptr) {
            return l1;
        }

        /*
            Pick the smaller node.

            Then merge the remaining part recursively.
        */
        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        /*
            If only one list is left,
            return that list.
        */
        if (start == end) {
            return lists[start];
        }

        /*
            If range is invalid,
            return empty list.
        */
        if (start > end) {
            return nullptr;
        }

        /*
            Divide the range into two parts.
        */
        int mid = start + (end - start) / 2;

        /*
            Merge all lists in the left half.
        */
        ListNode* leftList = partitionAndMerge(start, mid, lists);

        /*
            Merge all lists in the right half.
        */
        ListNode* rightList = partitionAndMerge(mid + 1, end, lists);

        /*
            Merge both sorted lists.
        */
        return mergeTwoSortedLists(leftList, rightList);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        /*
            If there are no lists,
            return empty list.
        */
        if (k == 0) {
            return nullptr;
        }

        /*
            Merge all lists from index 0 to k - 1.
        */
        return partitionAndMerge(0, k - 1, lists);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function creates a linked list from an array.

------------------------------------------------------------*/
ListNode* createList(vector<int> values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;

    for (int i = 1; i < (int)values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    return head;
}

/*------------------------------------------------------------

    Helper function:
    This function prints a linked list.

------------------------------------------------------------*/
void printList(ListNode* head) {
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val;

        if (temp->next != nullptr) {
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
    vector<ListNode*> lists1 = createTestLists();
    vector<ListNode*> lists2 = createTestLists();
    vector<ListNode*> lists3 = createTestLists();
    vector<ListNode*> lists4 = createTestLists();

    ListNode* ans1 = mergeKListsBruteForce(lists1);
    ListNode* ans2 = mergeKListsBetter(lists2);
    ListNode* ans3 = mergeKListsDivideAndConquer(lists3);
    ListNode* ans4 = mergeKListsOptimal(lists4);

    cout << "Brute Force Solution:" << endl;
    printList(ans1);

    cout << "Better Solution:" << endl;
    printList(ans2);

    cout << "Optimal Solution using Divide and Conquer:" << endl;
    printList(ans3);

    cout << "Optimal Solution using Min Heap:" << endl;
    printList(ans4);

    return 0;
}




