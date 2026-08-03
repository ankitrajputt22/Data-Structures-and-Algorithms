#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
LeetCode 1608 : Special Array With X Elements ≥ X
=========================================================

Goal:
Find integer x such that exactly x elements
in array are >= x.

If such x exists return it
else return -1.

Example:
nums = [3,5]

x = 2
because 2 elements >= 2

Output = 2

=========================================================
*/



/*
=========================================================
Approach 1 : Brute Force
=========================================================

Try every possible x from 0 → n.

For each x count elements ≥ x.

If count == x → answer found.

Time Complexity : O(n²)
Space Complexity : O(1)
*/

class Solution1 {
public:

    int specialArray(vector<int>& nums) {

        int n = nums.size();

        for (int x = 0; x <= n; x++) {

            int count = 0;

            for (int i = 0; i < n; i++) {

                if (nums[i] >= x)
                    count++;
            }

            if (count == x)
                return x;
        }

        return -1;
    }
};




/*
=========================================================
Approach 2 : Sorting + lower_bound
=========================================================

Sort the array first.

Use lower_bound(x) to find first element ≥ x.

Number of elements ≥ x:

n - index

If that count == x → answer.

Time Complexity : O(n log n)
Space Complexity : O(1)
*/

class Solution2 {
public:

    int specialArray(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int x = 0; x <= 100; x++) {

            int lb = lower_bound(nums.begin(),
                                 nums.end(),
                                 x) - nums.begin();

            int count = n - lb;

            if (count == x)
                return x;
        }

        return -1;
    }
};




/*
=========================================================
Approach 3 : Sorting + Direct Check (Better)
=========================================================

Sort the array.

For each position i:

Elements ≥ nums[i] = n - i

Check if that value satisfies condition.

Time Complexity : O(n log n)
Space Complexity : O(1)
*/

class Solution3 {
public:

    int specialArray(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            int x = n - i;

            if (nums[i] >= x && (i == 0 || nums[i - 1] < x))
                return x;
        }

        return -1;
    }
};




/*
=========================================================
Driver Code
=========================================================
*/

int main() {

    vector<int> nums = {3,5};

    Solution3 obj;

    cout << "Special Value: "
         << obj.specialArray(nums) << endl;

    return 0;
}

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        for (int x = 0; x <= n; x++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x) {
                    count++;
                }
            }

            if (count == x) {
                return x;
            }
        }

        return -1;
    }
};



//Approach-1 (Using binary search)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int x = 0; x <=n; x++) {
            
            int i = lower_bound(begin(nums), end(nums), x) - begin(nums);

            if(n-i == x) {
                return x;
            }
        }

        return -1;
    }
};


//Approach-2 (Binary search on answer)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int l = 0, r = n;
        while(l <= r) {
            int mid_x = l + (r-l)/2;

            int i = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);

            if(n-i == mid_x) {
                return mid_x;
            } else if(n-i > mid_x) {
                l = mid_x+1;
            } else {
                r = mid_x-1;
            }
        }

        return -1;
    }
};


//Approach-3 (Using counting Sort + Prefix Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        /*
            Every number larger than N is useless for our purpose,
            and we can treat those numbers as N. 
        */
        vector<int> freq(n+1);

        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }

        int c_sum = 0;
        for(int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if(i == c_sum) {
                return i;
            }
        }
        
        return -1;
    }
};
