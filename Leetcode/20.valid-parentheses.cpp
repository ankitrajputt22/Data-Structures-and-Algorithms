/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


// more optimal 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s){
            if (ch == '(') {
                st.push(')');
            } 
            else if (ch == '{') {
                st.push('}');
            } 
            else if (ch == '[') {
                st.push(']');
            } 
            else if (st.empty() || st.top() != ch) {
                return false;
            }
            else st.pop();
        }

        return st.empty();
    }
};