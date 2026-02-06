/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    }
};
// @lc code=end

class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != val) {
                arr[count] = arr[i];
                count++;
            }
        }

        return count;


        /*
        int i = 0; 
        int j = n-1;
        // if (n == 1 && arr[i] == val) {
        //     return {};
        // }

        while (i < n && i < j) {
            while (arr[j] == val) {
                j--;
            }
            if (j == -1) return {};

            while (arr[i] != val) {
                i++;
            }


            if (arr[i] == val) {


                swap(arr[i], arr[j]);
                j--;
            }

            i++;
        }

        return j+1;
        */



        /*
        int cnt = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (arr[j] != val) {
                arr[ind] = arr[j];
                ind++;
                j++;
            }
  
            while (j < n && arr[j] == val) {
                j++;
            }
            if (j < n) arr[ind] = arr[j];
            ind++;

            i = j;
        }

        return ind+1;
        */
    }
};



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int i = 0;
        int j = n-1;
        while (i <= j) {
            if (nums[i] != val) {
                i++;
            }
            else {
                swap(nums[i], nums[j]);
                j--;
            }
        }

        return i;
    }
};