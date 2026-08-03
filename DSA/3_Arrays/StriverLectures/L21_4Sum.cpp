#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

#include <bits/stdc++.h>
using namespace std;

/*
============================================================
                    LECTURE: 4 SUM PROBLEM
============================================================

PROBLEM:
Given an integer array nums and an integer target,
find all UNIQUE quadruplets:

nums[i] + nums[j] + nums[k] + nums[l] = target

Conditions:
i, j, k, l are distinct indices
No duplicate quadruplets allowed

------------------------------------------------------------
Example:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]
------------------------------------------------------------

============================================================
1. BRUTE FORCE APPROACH
============================================================

Idea:
Try all combinations of 4 elements using 4 loops.

Steps:
1. Pick i, j, k, l
2. Check if sum == target
3. Sort quadruplet
4. Store in set to remove duplicates

Time Complexity:
O(N^4)

Space Complexity:
O(number of quadruplets)

Too slow for large input.
*/

vector<vector<int>> fourSum_Brute(vector<int>& nums, int target) {

    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l < n; l++) {

                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/*
============================================================
2. BETTER APPROACH (HASHING)
============================================================

Idea:
Fix 3 elements and search 4th using hash set.

Required element:
target - (nums[i] + nums[j] + nums[k])

Time Complexity:
O(N^3 log M)

Space Complexity:
O(N)
*/

vector<vector<int>> fourSum_Better(vector<int>& nums, int target) {

    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {

            unordered_set<long long> hashset;

            for(int k = j+1; k < n; k++) {

                long long needed = (long long)target - nums[i] - nums[j] - nums[k];

                if(hashset.find(needed) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)needed};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashset.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/*
============================================================
3. OPTIMAL APPROACH (TWO POINTERS)
============================================================

MOST IMPORTANT INTERVIEW APPROACH

Steps:
1. Sort array
2. Fix i
3. Fix j
4. Use two pointers k and l

Duplicate handling:
Skip duplicate values for i, j, k, l

Time Complexity:
O(N^3)

Space Complexity:
O(1) extra (excluding output)
*/

vector<vector<int>> fourSum_Optimal(vector<int>& nums, int target) {

    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {

        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = i+1; j < n; j++) {

            if(j > i+1 && nums[j] == nums[j-1])
                continue;

            int k = j+1;
            int l = n-1;

            while(k < l) {

                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if(sum == target) {

                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                    k++;
                    l--;

                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
                else if(sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }

    return ans;
}

/*
============================================================
DRY RUN (IMPORTANT)
============================================================

nums = [1,0,-1,0,-2,2]
target = 0

Sorted:
[-2,-1,0,0,1,2]

Fix i = -2
Fix j = -1
pair (1,2) → sum 0

Fix i = -2
Fix j = 0
pair (0,2) → sum 0

Fix i = -1
Fix j = 0
pair (0,1) → sum 0

============================================================
DUPLICATE HANDLING RULES
============================================================

Skip duplicates for:
i
j
k
l

Always check previous element.

============================================================
WHY TWO POINTER WORKS?
============================================================

Array sorted → predictable sum movement.

Sum too small → move left pointer forward
Sum too big → move right pointer backward

============================================================
COMPLEXITY COMPARISON
============================================================

Brute Force → O(N^4)
Better      → O(N^3 log N)
Optimal     → O(N^3)  ⭐ interview standard

============================================================
INTERVIEW PATTERN (VERY IMPORTANT)
============================================================

This is extension of:

2 Sum
3 Sum
4 Sum
K Sum

General pattern:

Sort array
Fix K-2 elements
Use two pointers for remaining 2

============================================================
K-SUM GENERAL IDEA
============================================================

If k == 2 → two pointer
Else fix one element and recurse (k-1 sum)

============================================================
*/

void printResult(vector<vector<int>> &res) {
    for(auto &quad : res) {
        cout << "[ ";
        for(int x : quad) cout << x << " ";
        cout << "]\n";
    }
}

int main() {

    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    cout << "Brute Force:\n";
    auto r1 = fourSum_Brute(nums, target);
    printResult(r1);

    cout << "\nBetter (Hashing):\n";
    auto r2 = fourSum_Better(nums, target);
    printResult(r2);

    cout << "\nOptimal (Two Pointer):\n";
    auto r3 = fourSum_Optimal(nums, target);
    printResult(r3);

    return 0;
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {  
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        
                        if (sum == target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }
        
        return vector<vector<int>>(st.begin(), st.end());
    }
};





class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i-1 >= 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int l = j+1;
                int r = n-1;

                while (l < r) {
                    long long s = nums[i];
                    s += nums[j];
                    s += nums[l];
                    s += nums[r];

                    if (s == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if (s > target) {
                        r--;
                    }
                    else {
                        l++;
                    }

                    while (l < r && l > j+1 && nums[l] == nums[l-1]) {
                        l++;
                    }
                    while (r > l && r < n-2 && nums[r] == nums[r+1]) {
                        r--;
                    }
                }
            }
        }

        return res;
    }
};