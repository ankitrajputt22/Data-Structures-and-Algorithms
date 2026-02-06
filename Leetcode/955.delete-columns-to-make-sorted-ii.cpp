/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
    }
};
// @lc code=end

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(); 
        int cols = strs[0].size(); 

        int deletion = 0;
        vector<bool> alreadySorted(rows, false);

        int row = 0;
        int col = 0;
        
        for(col = 0; col < cols; col++) {
            bool deleted = false;

            for (row = 0; row < rows-1; row++) {
                if (!alreadySorted[row] && strs[row][col] > strs[row+1][col]) {
                    deletion++;
                    deleted = true;
                    break;
                }
            }

            if (deleted) continue;

            for (int i = 0; i < rows-1; i++) {
                alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
            }

        }

        return deletion;
    }
};



/*
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();

        int strLen = strs[0].length();
        int ind = 0;
        int deleted = 0;
        while (ind < strLen) {
            int ok = true;
            for (int i = 1; i < n; i++) {
                if (strs[i][ind] < strs[i-1][ind]) {
                    deleted += 1;
                    ok = false;
                    break;
                }
            }

            if (ok) {
                break;
            }
            
            ind++;
        }

        return deleted;
    }
*/



//Approach (Iterate while keeping a check if it's safe to delete the column or not)
//T.C : O(rows * cols)
//S.C : O(rows)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(); //Number of rows
        int cols = strs[0].size(); //Number of columns

        int deletion = 0;

        vector<bool> alreadySorted(rows, false);

        int row = 0;
        int col = 0;
        //to iterate in the strs
        
        for(col = 0; col < cols; col++) {
            bool deleted = false;

            for(row = 0; row < rows-1; row++) {
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]) {
                    deletion++;
                    deleted = true;
                    break;
                }
            }

            if(deleted) {
                continue;
            }

            for(int i = 0; i < rows-1; i++) {
                alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
            }

        }

        return deletion;
    }
};


