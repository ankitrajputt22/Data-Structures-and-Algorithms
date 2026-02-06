/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
    }
};
// @lc code=end


class Solution {
public: 
    int maxEl(vector<vector<int>>& grid, int i, int j) {
        int maxE = INT_MIN;
        for (int a = i; a < i+3; a++) {
            for (int b = j; b < j+3; b++) {
                maxE = max(maxE, grid[a][b]);
            }
        }

        return maxE;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2, 0));

        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                ans[i][j] = maxEl(grid, i, j);
            }
        }

        return ans;
    }
};


//Approach(Simply traversing and finding the result)
//T.C : O(n*n)
//S.C : O(n*n) for thr result but you can ignore it because it's the result that we have to return
class Solution {
public:
    int findLocalMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                maxLocal[i][j] = findLocalMax(grid, i, j);
            }
        }
        return maxLocal;
    }
};