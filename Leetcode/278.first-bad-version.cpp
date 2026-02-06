/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
    }
};
// @lc code=end

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int result = -1;

        while (l <= r) {
            int m = r + (l - r) / 2;

            if (isBadVersion(m)) { // inbuilt function in question
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return result; // l
    }
};

