#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: RECURSION APPLICATIONS
   → REVERSING ARRAY
   → CHECKING PALINDROME
===========================================================

-----------------------------------------------------------
🔹 SHIFT IN THINKING
-----------------------------------------------------------

Earlier:
✔ Void recursion (perform actions)

Now:
✔ Functional recursion (return values)

-----------------------------------------------------------
🧠 KEY IDEA:
-----------------------------------------------------------

These problems follow SAME PATTERN:
👉 Compare or swap symmetric elements

===========================================================
🔴 1. REVERSING AN ARRAY
===========================================================

Goal:
Reverse array using recursion

-----------------------------------------------------------
🟠 METHOD A: TWO POINTERS
-----------------------------------------------------------

LOGIC:
- Use left (L) and right (R)
- Swap arr[L] and arr[R]
- Move inward: L+1, R-1

BASE CASE:
if (L >= R) → stop

-----------------------------------------------------------
TIME: O(N)
SPACE: O(N)
-----------------------------------------------------------
*/

void reverse_two_pointer(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    swap(arr[l], arr[r]);

    reverse_two_pointer(arr, l + 1, r - 1);
}



/*
===========================================================
🟡 METHOD B: SINGLE POINTER (OPTIMIZED)
===========================================================

LOGIC:
- Use index i
- Swap with symmetric index: n - i - 1

BASE CASE:
if (i >= n/2) → stop

WHY n/2?
👉 Only half array needed

-----------------------------------------------------------
TIME: O(N)
SPACE: O(N)
-----------------------------------------------------------
*/

void reverse_single_pointer(vector<int>& arr, int i) {
    int n = arr.size();

    if (i >= n / 2) return;

    swap(arr[i], arr[n - i - 1]);

    reverse_single_pointer(arr, i + 1);
}



/*
===========================================================
🟢 2. CHECK PALINDROME (FUNCTIONAL RECURSION)
===========================================================

DEFINITION:
A string that reads same forward & backward

-----------------------------------------------------------
LOGIC:
- Compare s[i] and s[n-i-1]
- If not equal → return false
- Else → check next

BASE CASE:
if (i >= n/2) → return true

-----------------------------------------------------------
IMPORTANT:
👉 This is FUNCTIONAL recursion (returns value)

-----------------------------------------------------------
TIME: O(N)
SPACE: O(N)
-----------------------------------------------------------
*/

bool isPalindrome(string &s, int i) {
    int n = s.size();

    if (i >= n / 2) return true;

    if (s[i] != s[n - i - 1]) return false;

    return isPalindrome(s, i + 1);
}



/*
===========================================================
🧠 VISUAL UNDERSTANDING
===========================================================

Example: "MADAM"

Compare:
M == M
A == A
D == D

All match → TRUE

-----------------------------------------------------------
Example: "HELLO"

H != O → FALSE immediately

===========================================================
*/


/*
===========================================================
🔥 VOID vs FUNCTIONAL RECURSION (IMPORTANT)
===========================================================

| Type        | Example             | Returns |
|-------------|--------------------|---------|
| Void        | Reverse Array      | No      |
| Functional  | Palindrome Check   | Yes     |

-----------------------------------------------------------
🧠 RULE:
-----------------------------------------------------------

✔ If problem asks to MODIFY → use void recursion  
✔ If problem asks to CHECK/RETURN → use functional  

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original Array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Method A: Two Pointer
    reverse_two_pointer(arr, 0, arr.size() - 1);

    cout << "Reversed (Two Pointer):\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Reset array
    arr = {1, 2, 3, 4, 5};

    // Method B: Single Pointer
    reverse_single_pointer(arr, 0);

    cout << "Reversed (Single Pointer):\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Palindrome Check
    string s = "MADAM";

    if (isPalindrome(s, 0))
        cout << s << " is a Palindrome\n";
    else
        cout << s << " is NOT a Palindrome\n";

    return 0;
}






#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📘 LEETCODE 125: VALID PALINDROME — COMPLETE NOTES
===========================================================

PROBLEM:
Given a string s, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

-----------------------------------------------------------
EXAMPLES:
-----------------------------------------------------------
Input:  "A man, a plan, a canal: Panama"
Output: true

Input:  "race a car"
Output: false

-----------------------------------------------------------
KEY OBSERVATIONS:
-----------------------------------------------------------
1. Ignore special characters (like ',', ' ', ':', etc.)
2. Compare characters case-insensitively
3. Only consider [a-z, A-Z, 0-9]

-----------------------------------------------------------
APPROACHES INCLUDED:
-----------------------------------------------------------
1. 🔵 Two Pointer (Optimal - Best for interviews)
2. 🟢 Recursion (Basic Palindrome Check)
3. 🟡 Cleaner Two Pointer Version

-----------------------------------------------------------
TIME & SPACE:
-----------------------------------------------------------
| Approach        | Time   | Space |
|----------------|--------|-------|
| Two Pointer    | O(n)   | O(1)  |
| Recursion      | O(n)   | O(n)  |
| Cleaner 2Ptr   | O(n)   | O(1)  |

===========================================================
*/


/*
===========================================================
🔵 APPROACH 1: TWO POINTER (OPTIMAL)
===========================================================

IDEA:
- Use two pointers from start and end
- Skip non-alphanumeric characters
- Compare lowercase characters

WHY BEST?
- No extra space
- Single pass
- Most interview-friendly

-----------------------------------------------------------
*/

class Solution_1 {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            // Skip invalid characters
            if (!isalnum(s[left])) {
                left++;
            } 
            else if (!isalnum(s[right])) {
                right--;
            }

            // Compare characters
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } 
            else {
                left++;
                right--;
            }
        }

        return true;
    }
};



/*
===========================================================
🟢 APPROACH 2: RECURSION (BASIC PALINDROME)
===========================================================

IDEA:
- Compare first and last characters recursively

LIMITATION:
❌ Does NOT ignore special characters
❌ Does NOT handle case-insensitive comparison

👉 Only works for clean strings like "madam"

-----------------------------------------------------------
*/

bool isPalindrome_recursive(int i, string s) {
    int n = s.length();

    // Base case
    if (i >= n / 2) return true;

    // Mismatch
    if (s[i] != s[n - i - 1]) return false;

    // Recursive call
    return isPalindrome_recursive(i + 1, s);
}



/*
===========================================================
🟡 APPROACH 3: CLEANER TWO POINTER
===========================================================

IDEA:
- Same as Approach 1
- Uses nested loops to skip characters
- More readable

-----------------------------------------------------------
*/

class Solution_2 {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        int l = 0, r = n - 1;

        while (l < r) {

            // Move left to valid char
            while (l < n && !isalnum(s[l])) {
                l++;
            }

            // Move right to valid char
            while (r >= 0 && !isalnum(s[r])) {
                r--;
            }

            if (l >= r) break;

            // Compare
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};



/*
===========================================================
🚀 DRIVER CODE (TESTING ALL APPROACHES)
===========================================================
*/

int main() {

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = "madam";

    Solution_1 obj1;
    Solution_2 obj2;

    cout << "Approach 1 (Optimal):\n";
    cout << obj1.isPalindrome(s1) << endl; // 1 (true)
    cout << obj1.isPalindrome(s2) << endl; // 0 (false)

    cout << "\nApproach 2 (Recursion - basic):\n";
    cout << isPalindrome_recursive(0, s3) << endl; // 1

    cout << "\nApproach 3 (Cleaner Two Pointer):\n";
    cout << obj2.isPalindrome(s1) << endl; // 1
    cout << obj2.isPalindrome(s2) << endl; // 0

    return 0;
}