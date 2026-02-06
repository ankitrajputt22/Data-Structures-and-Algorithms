/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxA = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int l = j - i;
                int b = min(height[i], height[j]);

                int area = l * b;
                if (area > maxA) {
                    maxA = area;
                }
            }
        }

        return maxA;
    }
};

// @lc code=end


//Approach-1 (Two pointer Greedy (O(N))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        
        int water = 0;
        while(i<j) {
            
            //start from the smallest one and calculate water
            int h = min(height[i], height[j]);
            int w = j-i;
            int area = h*w;
            water = max(water, area);
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        
        return water;
    }
};

//Approach-2 (Two pointer Greedy (O(N)) (It's similar to Approach-1)
//Just that we are eliminating heights at one go
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        
        int water = 0;
        while(i<j) {
            
            //start from the smallest one and calculate water
            int h = min(height[i], height[j]);
            int w = j-i;
            int area = h*w;
            water = max(water, area);
            
            //Then move towards large one because we can have better answer
            if(height[i] <
            while(i < j && height[i] <= h)
                i++;
            //Same,  move towards large one because we can have better answer
            while(i < j && height[j] <= h)
                j--;
        }
        
        return water;
    }
};

