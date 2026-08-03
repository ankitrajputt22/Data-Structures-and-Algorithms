#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 56: MERGE INTERVALS
===========================================================

PROBLEM:
Given an array of intervals where intervals[i] = [start, end],
merge all overlapping intervals and return non-overlapping intervals.

Example:
Input:
[[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]

-----------------------------------------------------------
CORE IDEA:
Two intervals overlap if:
next.start <= current.end

-----------------------------------------------------------
APPROACHES COVERED:
-----------------------------------------------------------

1. 🔵 Optimal (Sorting + Greedy Merge)
2. 🟢 Brute Force (Check every interval)
3. 🟡 Using Stack (Alternative Greedy)

-----------------------------------------------------------
TIME & SPACE:
-----------------------------------------------------------

| Approach          | Time         | Space       |
|------------------|-------------|------------|
| Sorting + Merge  | O(n log n)  | O(n)       |
| Brute Force      | O(n^2)      | O(n)       |
| Stack            | O(n log n)  | O(n)       |

===========================================================
*/


/*
===========================================================
🔵 APPROACH 1: SORTING + GREEDY (BEST APPROACH)
===========================================================

IDEA:
1. Sort intervals by start time
2. Start with first interval
3. For each next interval:
   - If overlapping → merge
   - Else → add new interval

WHY IT WORKS:
Sorting ensures overlapping intervals come together.

-----------------------------------------------------------
TIME: O(n log n)
SPACE: O(n)
-----------------------------------------------------------
*/

vector<vector<int>> merge_optimal(vector<vector<int>>& intervals) {

    // Step 1: Sort intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (auto interval : intervals) {

        // If ans is empty OR no overlap
        if (ans.empty() || interval[0] > ans.back()[1]) {
            ans.push_back(interval);
        }
        else {
            // Overlap → merge
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}



/*
===========================================================
🟢 APPROACH 2: BRUTE FORCE
===========================================================

IDEA:
- Compare each interval with others
- Merge overlapping ones manually

NOTE:
Inefficient, rarely used in interviews.

-----------------------------------------------------------
TIME: O(n^2)
SPACE: O(n)
-----------------------------------------------------------
*/

vector<vector<int>> merge_bruteforce(vector<vector<int>>& intervals) {

    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        int start = intervals[i][0];
        int end = intervals[i][1];

        // Skip already merged intervals
        if (!ans.empty() && end <= ans.back()[1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            } else {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}



/*
===========================================================
🟡 APPROACH 3: USING STACK
===========================================================

IDEA:
- Sort intervals
- Use stack to merge intervals

-----------------------------------------------------------
TIME: O(n log n)
SPACE: O(n)
-----------------------------------------------------------
*/

vector<vector<int>> merge_stack(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    stack<vector<int>> st;
    st.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        vector<int> top = st.top();

        if (intervals[i][0] <= top[1]) {
            st.pop();
            top[1] = max(top[1], intervals[i][1]);
            st.push(top);
        }
        else {
            st.push(intervals[i]);
        }
    }

    vector<vector<int>> ans;

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}



/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };

    vector<vector<int>> result = merge_optimal(intervals);

    cout << "Merged Intervals:\n";
    for (auto &it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }

    cout << endl;

    return 0;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        int i = 0;
        
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            
            while (j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]); 
                j++;
            }
            
            res.push_back({start, end});
            i = j; 
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for (auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};


