#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

/*
============================================================
                LECTURE: 3 SUM PROBLEM
============================================================

PROBLEM:
Given an integer array nums,
find all UNIQUE triplets (i, j, k) such that:

nums[i] + nums[j] + nums[k] = 0
and i != j != k

Return all distinct triplets.
Duplicate triplets are NOT allowed.

------------------------------------------------------------
Example:
nums = [-1, 0, 1, 2, -1, -4]

Output:
[-1, -1, 2]
[-1, 0, 1]
------------------------------------------------------------

============================================================
1. BRUTE FORCE APPROACH
============================================================

Idea:
Check every possible triplet using 3 loops.

Steps:
1. Pick i, j, k
2. Check if sum == 0
3. Sort triplet
4. Store in set to remove duplicates

Time Complexity:
O(N^3 * log(unique triplets))

Space Complexity:
O(number of triplets)

Not efficient for large input.
*/

vector<vector<int>> threeSum_Brute(vector<int>& nums) {

    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {

                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
============================================================
2. BETTER APPROACH (HASHING)
============================================================

Idea:
Fix i and j.
Find required third element using hash set.

Third element = -(nums[i] + nums[j])

Steps:
1. Fix i
2. Maintain set for remaining elements
3. Check if required third element exists

Time Complexity:
O(N^2 log M)

Space Complexity:
O(N)
*/

vector<vector<int>> threeSum_Better(vector<int>& nums) {

    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {

        unordered_set<int> hashset;

        for(int j = i+1; j < n; j++) {

            int third = -(nums[i] + nums[j]);

            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

/*
============================================================
3. OPTIMAL APPROACH (TWO POINTERS)
============================================================

MOST IMPORTANT APPROACH

Steps:
1. Sort array
2. Fix index i
3. Use two pointers:
   j = i+1
   k = n-1

Move pointers based on sum.

Duplicate handling:
- Skip duplicate i
- Skip duplicate j and k

Time Complexity:
Sorting = O(N log N)
Two pointer = O(N^2)

Overall = O(N^2)

Space Complexity:
O(1) extra (excluding output)
*/

vector<vector<int>> threeSum_Optimal(vector<int>& nums) {

    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {

        if(i > 0 && nums[i] == nums[i-1])
            continue;   // skip duplicate i

        int j = i + 1;
        int k = n - 1;

        while(j < k) {

            long long sum = (long long)nums[i] + nums[j] + nums[k];

            if(sum < 0) {
                j++;
            }
            else if(sum > 0) {
                k--;
            }
            else {

                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                // skip duplicate j
                while(j < k && nums[j] == nums[j-1]) j++;

                // skip duplicate k
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }

    return ans;
}

/*
============================================================
DRY RUN (IMPORTANT)
============================================================

Input:
[-1, 0, 1, 2, -1, -4]

After sorting:
[-4, -1, -1, 0, 1, 2]

i = -4
no valid pair

i = -1
pair (-1,2) → sum 0
pair (0,1) → sum 0

Answer:
[-1,-1,2]
[-1,0,1]

============================================================
HOW TWO POINTER WORKS?
============================================================

Array sorted → increasing order.

If sum too small → move left pointer right
If sum too big → move right pointer left

This works because sorted order guarantees
sum movement predictability.

============================================================
DUPLICATE HANDLING RULES
============================================================

1. Skip same i
2. After finding triplet:
   skip equal j values
   skip equal k values

This ensures UNIQUE triplets.

============================================================
COMPLEXITY COMPARISON
============================================================

Brute Force → O(N^3)
Better      → O(N^2 log N)
Optimal     → O(N^2)

============================================================
INTERVIEW PATTERN
============================================================

This belongs to:

Two Pointer + Sorting Pattern

Used when:
• Find pair/triplet sum
• Need unique combinations
• Array can be sorted

Related problems:
2 Sum
3 Sum Closest
4 Sum
K Sum

============================================================
*/

void printResult(vector<vector<int>> &res) {
    for(auto &triplet : res) {
        cout << "[ ";
        for(int x : triplet) cout << x << " ";
        cout << "]\n";
    }
}

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};

    cout << "Brute Force:\n";
    auto res1 = threeSum_Brute(nums);
    printResult(res1);

    cout << "\nBetter (Hashing):\n";
    auto res2 = threeSum_Better(nums);
    printResult(res2);

    cout << "\nOptimal (Two Pointer):\n";
    auto res3 = threeSum_Optimal(nums);
    printResult(res3);

    return 0;
}





class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (auto it : nums) {
            cout << it << " ";
        }
        cout << endl;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i-1 >= 0 && nums[i] == nums[i-1]) continue;
            int req = -nums[i];

            int j = i+1;
            int k = n-1;

            while (j < k) {
                int s = nums[j] + nums[k];
                
                if (j > i+1) {
                    if (nums[j] == nums[j-1]) {
                        j++;
                        continue;
                    }
                }
                if (k < n-1) {
                    if (nums[k] == nums[k+1]) {
                        k--;
                        continue;
                    }
                }

                if (s == req) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                }
                else if (s < req) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};


