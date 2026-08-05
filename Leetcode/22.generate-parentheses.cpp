#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    LeetCode 22: Generate Parentheses

    Problem:
    We are given an integer n.
    We have to generate all combinations of well-formed parentheses.

    Well-formed parentheses:
    Every opening bracket should have a matching closing bracket.
    At any point, closing brackets should not be more than opening brackets.

    Example:
    n = 3

    Answer:
    ["((()))", "(()())", "(())()", "()(())", "()()()"]
*/

/*------------------------------------------------------------

    Helper function:
    This function checks if a parentheses string is valid.

------------------------------------------------------------*/
bool isValidParentheses(string s) {
    int balance = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Generate all possible strings of length 2 * n.
    Each position can be '(' or ')'.
    Then check which strings are valid.

    Step-by-step algorithm:
    1. Create answer vector.
    2. Generate all strings of length 2 * n.
    3. At every position, try '('.
    4. At every position, try ')'.
    5. When string length becomes 2 * n,
       check if it is valid.
    6. If valid, add it to answer.
    7. Return answer.

    Time complexity:
    O(2^(2n) * n)

    Space complexity:
    O(n)

    Note:
    This solution can give TLE for large input.
    It creates many invalid strings also.

------------------------------------------------------------*/
void generateBruteForce(int index, int totalLength, string current, vector<string>& ans) {
    if (index == totalLength) {
        if (isValidParentheses(current)) {
            ans.push_back(current);
        }

        return;
    }

    generateBruteForce(index + 1, totalLength, current + '(', ans);
    generateBruteForce(index + 1, totalLength, current + ')', ans);
}

vector<string> generateParenthesisBruteForce(int n) {
    vector<string> ans;

    generateBruteForce(0, 2 * n, "", ans);

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Recursion and Pruning

    Basic idea:
    Build only possible valid strings.
    Do not add ')' if closing count is already equal
    to opening count.

    Step-by-step algorithm:
    1. Create answer vector.
    2. Start with empty string.
    3. Keep count of opening brackets used.
    4. Keep count of closing brackets used.
    5. Add '(' if open count is less than n.
    6. Add ')' if close count is less than open count.
    7. If string length becomes 2 * n,
       add it to answer.
    8. Return answer.

    Time complexity:
    O(Catalan(n) * n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    It avoids invalid strings early.
    But string is copied in recursive calls.

------------------------------------------------------------*/
void generateBetter(int n, int open, int close, string current, vector<string>& ans) {
    if (current.size() == 2 * n) {
        ans.push_back(current);
        return;
    }

    if (open < n) {
        generateBetter(n, open + 1, close, current + '(', ans);
    }

    if (close < open) {
        generateBetter(n, open, close + 1, current + ')', ans);
    }
}

vector<string> generateParenthesisBetter(int n) {
    vector<string> ans;

    generateBetter(n, 0, 0, "", ans);

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Backtracking

    Basic idea:
    Use the same valid-building idea.
    But use one string and modify it using push and pop.
    This avoids creating many copied strings.

    Step-by-step algorithm:
    1. Create answer vector.
    2. Create current string.
    3. If current size is 2 * n, add it to answer.
    4. If open count is less than n:
       add '(' and recurse.
    5. Remove '(' while backtracking.
    6. If close count is less than open count:
       add ')' and recurse.
    7. Remove ')' while backtracking.
    8. Return answer.

    Time complexity:
    O(Catalan(n) * n)

    Space complexity:
    O(n)

    Note:
    This is the best common approach.
    We must generate all valid answers.
    So output size is unavoidable.

------------------------------------------------------------*/
void generateOptimal(int n, int open, int close, string& current, vector<string>& ans) {
    if (current.size() == 2 * n) {
        ans.push_back(current);
        return;
    }

    if (open < n) {
        current.push_back('(');

        generateOptimal(n, open + 1, close, current, ans);

        current.pop_back();
    }

    if (close < open) {
        current.push_back(')');

        generateOptimal(n, open, close + 1, current, ans);

        current.pop_back();
    }
}

vector<string> generateParenthesisOptimal(int n) {
    vector<string> ans;
    string current = "";

    generateOptimal(n, 0, 0, current, ans);

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Dynamic Programming Solution

    Basic idea:
    Use previously generated answers.
    A valid parentheses string can be made like this:

    "(" + leftPart + ")" + rightPart

    leftPart has some pairs.
    rightPart has remaining pairs.

    Step-by-step algorithm:
    1. Create dp array of vector strings.
    2. dp[0] contains empty string.
    3. For pairs from 1 to n:
       try all left pair counts.
    4. Right pair count is pairs - 1 - left.
    5. For every left string and right string:
       make "(" + left + ")" + right.
    6. Store it in dp[pairs].
    7. Return dp[n].

    Time complexity:
    O(Catalan(n) * n)

    Space complexity:
    O(Catalan(n) * n)

    Note:
    This is another good approach.
    It uses the structure of valid parentheses.
    Backtracking is easier to write for this problem.

------------------------------------------------------------*/
vector<string> generateParenthesisDP(int n) {
    vector<vector<string>> dp(n + 1);

    dp[0].push_back("");

    for (int pairs = 1; pairs <= n; pairs++) {
        for (int leftCount = 0; leftCount < pairs; leftCount++) {
            int rightCount = pairs - 1 - leftCount;

            for (int i = 0; i < dp[leftCount].size(); i++) {
                for (int j = 0; j < dp[rightCount].size(); j++) {
                    string current = "(" + dp[leftCount][i] + ")" + dp[rightCount][j];

                    dp[pairs].push_back(current);
                }
            }
        }
    }

    return dp[n];
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal backtracking solution.

------------------------------------------------------------*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesisOptimal(n);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints all strings.

------------------------------------------------------------*/
void printAnswer(vector<string>& ans) {
    cout << "[";

    for (int i = 0; i < ans.size(); i++) {
        cout << "\"" << ans[i] << "\"";

        if (i != ans.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    int n = 3;

    vector<string> ans1 = generateParenthesisBruteForce(n);
    vector<string> ans2 = generateParenthesisBetter(n);
    vector<string> ans3 = generateParenthesisOptimal(n);
    vector<string> ans4 = generateParenthesisDP(n);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Recursion and Pruning:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Backtracking:" << endl;
    printAnswer(ans3);

    cout << "Dynamic Programming Solution:" << endl;
    printAnswer(ans4);

    return 0;
}