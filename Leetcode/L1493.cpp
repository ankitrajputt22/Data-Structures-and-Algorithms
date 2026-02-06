#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 { // by me
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == n) {
            return n-1;
        }

        if (sum == 0) {
            return 0;
        }
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int len = 0;
                for (int j = 0; j < n; j++) {
                    if (j == i) {
                        continue;
                    }

                    if (nums[j] == 1) {
                        len++;
                    } else {
                        len = 0;
                    }
                    
                    maxLen = max(len, maxLen);
                }
            }
        }

        return maxLen;
    }
};

//Approach-1 (Simple Brute Force) - T.C : O(n^2)
class Solution_2 {
public:
    int n;
    
    int findMax(vector<int>& nums, int skip_idx) {
        
        int currLength = 0;
        int maxLength  = 0;
        
        for(int i = 0; i<n; i++) {
            if(i == skip_idx)
                continue;
            
            if(nums[i] == 1) {
                currLength++;
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 0;
            }
        }
        
        return maxLength;
        
    }
    
    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        
        int countZero = 0;
        for(int i = 0; i<n; i++) {
            
            if(nums[i] == 0) {
                countZero++;
                result = max(result, findMax(nums, i));
            }
            
        }
        
        if(countZero == 0)
            return n-1;
        
        return result;
        
    }
};


class Solution_3 { // using sliding window mechanism and return len-1 which is max length of subarray having 1 zero and rest all as 1
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int len = 0;
        int cnt = 0;
        while (i < n && j < n) {
            if (nums[j] == 0) {
                cnt++;
            }

            while (cnt > 1) {
                if (nums[i] == 0) {
                    cnt--;
                }
                i++;
            } 

            len = max(len, j - i + 1);
            
            j++;
        }

        return len-1;
    }
};

//Approach-2 (Using Traditional Sliding Window) - O(n)
class Solution_4 {
public:
    int longestSubarray(vector<int>& nums) {

        int zeroCount = 0;
        int longestWindow = 0;

        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[i] == 0);
                i++;
            }
              
            longestWindow = max(longestWindow, j - i);
        }

        return longestWindow;
    }
};


//Approach-3 (Using Better Sliding Window) - O(n))
class Solution_5 {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        
        int last_zero_idx = -1;
        
        int result = 0;
        
        while(j < nums.size()) {
            
            if(nums[j] == 0) {
                i = last_zero_idx+1;
                last_zero_idx = j;
            }
            
            result = max(result, j-i);
            j++;
        }
        
        return result;
    }
};

int main() {
    
    return 0;
}