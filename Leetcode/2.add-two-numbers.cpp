#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    LeetCode 2: Add Two Numbers

    Problem:
    We are given two non-empty linked lists.
    Each linked list represents a non-negative number.
    The digits are stored in reverse order.

    Example:
    l1 = 2 -> 4 -> 3
    l2 = 5 -> 6 -> 4

    Number 1 = 342
    Number 2 = 465

    Sum = 807

    Answer = 7 -> 0 -> 8
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
    Convert both linked lists into numbers.
    Add both numbers.
    Create a new linked list from the sum.

    Step-by-step algorithm:
    1. Create num1 and num2 as 0.
    2. Traverse the first linked list.
    3. Convert it into a number.
    4. Traverse the second linked list.
    5. Convert it into a number.
    6. Add both numbers.
    7. Create a linked list from the sum.
    8. Return the head of the new linked list.

    Time complexity:
    O(n + m)

    Space complexity:
    O(1)

    Note:
    n is the length of first linked list.
    m is the length of second linked list.
    This approach is simple.
    But it can fail for large input.
    The number can become bigger than long long.
    So this is not safe for LeetCode constraints.

------------------------------------------------------------*/
long long convertListToNumber(ListNode* head) {
    long long number = 0;
    long long place = 1;

    while (head != NULL) {
        number = number + head->val * place;
        place = place * 10;
        head = head->next;
    }

    return number;
}

ListNode* createListFromNumber(long long number) {
    if (number == 0) {
        return new ListNode(0);
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (number > 0) {
        int digit = number % 10;
        number = number / 10;

        tail->next = new ListNode(digit);
        tail = tail->next;
    }

    return dummy->next;
}

ListNode* addTwoNumbersBruteForce(ListNode* l1, ListNode* l2) {
    long long num1 = convertListToNumber(l1);
    long long num2 = convertListToNumber(l2);

    long long sum = num1 + num2;

    return createListFromNumber(sum);
}

/*------------------------------------------------------------

    Approach 2: Better Solution using String

    Basic idea:
    Convert both linked lists into strings.
    Add both strings like normal addition.
    Create answer linked list from the sum string.

    Step-by-step algorithm:
    1. Convert first linked list into string.
    2. Convert second linked list into string.
    3. Reverse both strings.
    4. Add both strings digit by digit.
    5. Store the sum in another string.
    6. Create linked list in reverse order from sum string.
    7. Return the head of the new linked list.

    Time complexity:
    O(n + m)

    Space complexity:
    O(n + m)

    Note:
    This avoids integer overflow.
    But it uses extra string space.
    This is better than brute force.

------------------------------------------------------------*/
string convertListToString(ListNode* head) {
    string number = "";

    while (head != NULL) {
        char digit = head->val + '0';
        number.push_back(digit);
        head = head->next;
    }

    reverse(number.begin(), number.end());

    return number;
}

string addStrings(string num1, string num2) {
    string ans = "";

    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum = sum + (num1[i] - '0');
            i--;
        }

        if (j >= 0) {
            sum = sum + (num2[j] - '0');
            j--;
        }

        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit + '0');
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

ListNode* createListFromString(string number) {
    ListNode* head = NULL;

    for (int i = 0; i < number.size(); i++) {
        int digit = number[i] - '0';

        ListNode* newNode = new ListNode(digit);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

ListNode* addTwoNumbersBetter(ListNode* l1, ListNode* l2) {
    string num1 = convertListToString(l1);
    string num2 = convertListToString(l2);

    string sum = addStrings(num1, num2);

    return createListFromString(sum);
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    Add digits one by one.
    This is the same as normal addition.
    Use carry while adding.

    Step-by-step algorithm:
    1. Create a dummy node.
    2. Create carry as 0.
    3. Traverse both linked lists.
    4. Add current digit of l1 if it exists.
    5. Add current digit of l2 if it exists.
    6. Add carry also.
    7. Create a new node with sum % 10.
    8. Update carry as sum / 10.
    9. Move l1 and l2 forward.
    10. Repeat until both lists are finished and carry is 0.
    11. Return dummy's next.

    Time complexity:
    O(max(n, m))

    Space complexity:
    O(max(n, m))

    Note:
    n is the length of first linked list.
    m is the length of second linked list.
    This is the best approach.
    It does not convert the full list into a number.
    It handles large input safely.

------------------------------------------------------------*/
ListNode* addTwoNumbersOptimal(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum = sum + l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum = sum + l2->val;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        tail->next = new ListNode(digit);
        tail = tail->next;
    }

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
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    ListNode* ans1 = addTwoNumbersBruteForce(l1, l2);
    ListNode* ans2 = addTwoNumbersBetter(l1, l2);
    ListNode* ans3 = addTwoNumbersOptimal(l1, l2);

    cout << "Brute Force Solution:" << endl;
    printList(ans1);

    cout << "Better Solution:" << endl;
    printList(ans2);

    cout << "Optimal Solution:" << endl;
    printList(ans3);

    return 0;
}