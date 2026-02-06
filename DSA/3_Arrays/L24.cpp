

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
Approach Strategy
Sorting + While Loop Merge approach
Time Complexity: O(n log n) (sorting dominated)
Space Complexity: O(1) (excluding output)

Key Steps
Sort intervals by start time

Initialize result vector and index i = 0
While loop through intervals:
Track current interval: start = intervals[i][0], end = intervals[i][1]

Merge forward: While next intervals overlap (end >= intervals[j][0])
Update end = max(end, intervals[j][1])
Increment j++

Add merged interval to result
Jump index: i = j (skip merged intervals)
*/

class Solution_1 {
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
            
            // Merge overlapping intervals
            while (j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]); // Update end to maximum
                j++;
            }
            
            res.push_back({start, end});
            i = j; // Move to next unmerged interval
        }
        
        return res;
    }
};


class Solution_2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            for (int j = i+1; j < n; j++) {
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
};

/*
Approach Strategy
Sorting + Single Pass Merge
Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(1) (excluding output)

Key Steps
Sort intervals by start time

Initialize empty result vector merged

Iterate through each interval:

If no overlap: merged.empty() OR last_end < current_start
→ Add new interval to result

If overlap exists: last_end >= current_start
→ Merge by updating last_end = max(last_end, current_end)

*/

class Solution_3 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for (auto& interval : intervals) {
            // If merged is empty or current interval doesn't overlap with last merged
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Merge with the last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};

int main() {
    
    return 0;
}