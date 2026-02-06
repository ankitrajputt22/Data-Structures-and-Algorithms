/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
    }
};
// @lc code=end

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(), capacity.end(), greater<int>());
        int totalApples = accumulate(apple.begin(), apple.end(), 0);

        int sum = 0;
        int boxInd = 0;
        while (sum < totalApples) {
            sum += capacity[boxInd];
            boxInd++;
        }

        return boxInd;
    }
};



//Approach-1 (Using std::sort so that we can Simply assign the apples to largest boxes first)
//T.C : O(n + mlogm) 
//S.C : O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(capacity), end(capacity), greater<int>()); //H.W : Counting Sort

        int totalApple = accumulate(begin(apple), end(apple), 0);

        int count = 0;
        int i = 0;
        while(totalApple > 0) {
            totalApple -= capacity[i];
            count++;
            i++;
        }

        return count; //total number of boxes used
    }
};



//Approach-2 (Using counting sort so that we can Simply assign the apples to largest boxes first)
//T.C : O(n + m) 
//S.C : O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(begin(apple), end(apple), 0);

        // Counting sort frequency array
        vector<int> freq(51, 0);
        for (int cap : capacity) {
            freq[cap]++;
        }

        int count = 0;

        // Start using boxes with largest capacity
        for (int cap = 50; cap >= 1 && totalApple > 0; cap--) {
            while (freq[cap] > 0 && totalApple > 0) {
                totalApple -= cap;
                freq[cap]--;
                count++;
            }
        }

        return count;
    }
};
