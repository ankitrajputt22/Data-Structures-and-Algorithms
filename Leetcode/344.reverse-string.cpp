/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        
    }
};
// @lc code=end


// solution using stack
#define MAX 100001
char stack[MAX];
int top;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return -1;
    
    char popped = stack[top];
    top--;

    return popped;
}

void reverseString(char* s, int sSize) {
    top = -1;
    for (int i = 0; i < sSize; i++) {
        push(s[i]);
    }

    for (int i = 0; i < sSize; i++) {
        s[i] = pop();
    }
}



// solution - 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st = 0;
        int end = n - 1;
        while(st < end){
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0, end = n - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++,  end--;
        }
    }
};