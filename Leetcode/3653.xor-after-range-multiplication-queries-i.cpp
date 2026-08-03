#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
LeetCode 3653 : XOR After Range Multiplication Queries I
=========================================================

Problem:
For each query [l, r, k, v]:

Start from index l
Keep jumping by k
Until <= r:
    nums[i] = (nums[i] * v) % MOD

Finally return XOR of array.

---------------------------------------------------------
Key Observations:

1. Updates are NOT continuous
   → indices are: l, l+k, l+2k ...

2. Multiplication + XOR
   → cannot use prefix or difference tricks

3. So we must simulate updates

---------------------------------------------------------
Time Complexity:

Each query runs:
≈ (r - l) / k steps

Total:
O(sum of all steps across queries)

---------------------------------------------------------
Space Complexity:
O(1)

=========================================================
*/

class Solution {
public:

    int xorAfterQueries(vector<int>& nums,
                        vector<vector<int>>& queries)
    {
        const int MOD = 1e9 + 7;

        int n = nums.size();

        // Process each query
        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            /*
            -------------------------------------------------
            Jump with step k
            -------------------------------------------------
            */
            for (int idx = l; idx <= r; idx += k)
            {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        /*
        -------------------------------------------------
        Compute XOR of final array
        -------------------------------------------------
        */
        int result = 0;

        for (int num : nums)
        {
            result ^= num;
        }

        return result;
    }
};



/*
=========================================================
Driver Code
=========================================================
*/

int main()
{
    Solution obj;

    // Example 1
    vector<int> nums1 = {1,1,1};
    vector<vector<int>> queries1 = {{0,2,1,4}};

    cout << "Output 1: "
         << obj.xorAfterQueries(nums1, queries1)
         << endl;


    // Example 2
    vector<int> nums2 = {2,3,1,5,4};
    vector<vector<int>> queries2 = {
        {1,4,2,3},
        {0,2,1,2}
    };

    cout << "Output 2: "
         << obj.xorAfterQueries(nums2, queries2)
         << endl;

    return 0;
}