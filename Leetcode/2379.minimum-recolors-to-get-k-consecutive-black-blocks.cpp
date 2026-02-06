/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
    }
};
// @lc code=end

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int ans = INT_MAX;
        for (int i = 0; i <= n-k; i++) {
            int blacks = 0;
            for (int j = i; j < i+k; j++) {
                if (blocks[j] == 'B') {
                    blacks++;
                }
            }

            if (blacks >= k) {
                return 0;
            }

            ans = min(ans, k - blacks);
        }

        return ans;
    }
};


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int ans = INT_MAX;
        int i = 0, j = 0;
        int blacks = 0;
        while (j < n) {
            if (blocks[j] == 'B') {
                blacks++;
            }

            if (j - i + 1 >= k) {
                ans = min(ans, k - blacks);

                if (blocks[i] == 'B') {
                    blacks--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};


//Approach-1 (Brute Force)
//T.C : O(n*k)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = k;

        for (int i = 0; i <= n - k; i++) {
            int W = 0;
            for (int j = i; j-i+1 <= k; j++) {
                if (blocks[j] == 'W') {
                    W++;
                }
            }
            result = min(result, W);
        }

        return result;
    }
};



//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;

        int ops = k;
        int W = 0;

        while(j < n) {
            if(blocks[j] == 'W') {
                W++;
            }

            if(j - i + 1 == k) {
                ops = min(ops, W);

                if(blocks[i] == 'W') {
                    W--;
                }
                i++;
            }
            j++;
        }

        return ops;
    }
};