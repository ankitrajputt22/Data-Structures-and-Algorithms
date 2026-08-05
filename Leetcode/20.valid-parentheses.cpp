#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
    LeetCode 20: Valid Parentheses

    Problem:
    We are given a string s.
    It contains only these characters:
    '(', ')', '{', '}', '[' and ']'

    We have to check if the parentheses are valid.

    A string is valid if:
    1. Every opening bracket has a matching closing bracket.
    2. Brackets are closed in the correct order.
    3. Every closing bracket has a matching opening bracket.

    Example:
    s = "()[]{}"
    Answer = true

    Example:
    s = "(]"
    Answer = false
*/

/*------------------------------------------------------------

    Helper function:
    This function checks if two brackets make a valid pair.

------------------------------------------------------------*/
bool isPair(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    }

    if (open == '{' && close == '}') {
        return true;
    }

    if (open == '[' && close == ']') {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Keep removing valid adjacent pairs.
    If the string becomes empty, it is valid.
    If no pair can be removed, it is invalid.

    Step-by-step algorithm:
    1. Repeat the process while string is changing.
    2. Traverse the string.
    3. Find any adjacent valid pair like (), {}, [].
    4. Remove that pair from the string.
    5. Start checking again.
    6. If the string becomes empty, return true.
    7. If no pair can be removed, return false.

    Time complexity:
    O(n^2)

    Space complexity:
    O(n)

    Note:
    This solution can be slow for large input.
    It repeatedly creates new strings.

------------------------------------------------------------*/
bool isValidBruteForce(string s) {
    bool changed = true;

    while (changed == true) {
        changed = false;

        string temp = "";

        int i = 0;

        while (i < s.size()) {
            if (i + 1 < s.size() && isPair(s[i], s[i + 1])) {
                changed = true;
                i = i + 2;
            } else {
                temp.push_back(s[i]);
                i++;
            }
        }

        s = temp;
    }

    if (s.size() == 0) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Stack

    Basic idea:
    Use a stack to store opening brackets.
    When a closing bracket comes, check the top of stack.

    Step-by-step algorithm:
    1. Create an empty stack.
    2. Traverse every character in the string.
    3. If character is opening bracket, push it.
    4. If character is closing bracket:
       check if stack is empty.
    5. If stack is empty, return false.
    6. If top opening bracket does not match,
       return false.
    7. Otherwise pop the stack.
    8. At the end, return true only if stack is empty.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    It checks the string only once.
    Stack helps to check the latest opened bracket.

------------------------------------------------------------*/
bool isValidBetterStack(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }

            char topChar = st.top();

            if (isPair(topChar, ch) == false) {
                return false;
            }

            st.pop();
        }
    }

    if (st.empty()) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Expected Closing Bracket

    Basic idea:
    Push the expected closing bracket into stack.
    When we see a closing bracket, it should match stack top.

    Example:
    If we see '(':
    Push ')' into stack.

    If we see '{':
    Push '}' into stack.

    Step-by-step algorithm:
    1. Create an empty stack.
    2. Traverse every character.
    3. If character is '(' push ')'.
    4. If character is '{' push '}'.
    5. If character is '[' push ']'.
    6. Otherwise it is a closing bracket.
    7. If stack is empty, return false.
    8. If stack top is not current character, return false.
    9. Otherwise pop the stack.
    10. At the end, return true if stack is empty.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is the best approach.
    It is clean and avoids extra pair checking.
    It checks each character only once.

------------------------------------------------------------*/
bool isValidOptimalExpected(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(') {
            st.push(')');
        } else if (ch == '{') {
            st.push('}');
        } else if (ch == '[') {
            st.push(']');
        } else {
            if (st.empty()) {
                return false;
            }

            if (st.top() != ch) {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using String as Stack

    Basic idea:
    Use a string like a stack.
    Push opening brackets into the string.
    Remove the last character when matching closing bracket comes.

    Step-by-step algorithm:
    1. Create an empty string as stack.
    2. Traverse every character.
    3. If character is opening bracket, push it.
    4. If character is closing bracket:
       check if string stack is empty.
    5. If empty, return false.
    6. Check if last character matches current closing bracket.
    7. If not matched, return false.
    8. Otherwise remove last character.
    9. At the end, return true if string stack is empty.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is also optimal.
    It avoids using STL stack.
    It works because string supports push_back and pop_back.

------------------------------------------------------------*/
bool isValidOptimalStringStack(string s) {
    string st = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push_back(ch);
        } else {
            if (st.size() == 0) {
                return false;
            }

            char topChar = st[st.size() - 1];

            if (isPair(topChar, ch) == false) {
                return false;
            }

            st.pop_back();
        }
    }

    return st.size() == 0;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal expected closing bracket solution.

------------------------------------------------------------*/
class Solution {
public:
    bool isValid(string s) {
        return isValidOptimalExpected(s);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints boolean answer.

------------------------------------------------------------*/
void printAnswer(bool ans) {
    if (ans == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    string s = "()[]{}";

    bool ans1 = isValidBruteForce(s);
    bool ans2 = isValidBetterStack(s);
    bool ans3 = isValidOptimalExpected(s);
    bool ans4 = isValidOptimalStringStack(s);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Stack:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Expected Closing Bracket:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using String as Stack:" << endl;
    printAnswer(ans4);

    return 0;
}