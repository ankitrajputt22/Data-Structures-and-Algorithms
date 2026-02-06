/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
    }
};
// @lc code=end



//Approach-1 (Brute Force) - TC : O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        for (int i = 0; i < n; i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }

        return letters[0];
    }
};



//Approach-2 (Using Own Binary Search) - TC : O(log(n))
class Solution {
public:
    
    int binarySearch(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n-1;
        
        int position = n;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(letters[mid] > target) {
                position = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return position;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int idx = binarySearch(letters, target);
        
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
        
    }
};


//Approach-3 (Using C++ STL upper_bound (binary search internally)) - TC : O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(begin(letters), end(letters), target) - begin(letters);
        
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
    }
};