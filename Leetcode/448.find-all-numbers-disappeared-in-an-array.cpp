/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    }
};
// @lc code=end


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};


/*
Time Complexity : O(n2), we iterate over the range [1, n] which takes O(n) and for each iteration, we check if that element occurs in nums which takes another O(n) giving total time of O(n2)

Space Complexity : O(1), excluding the space required for the output vector, we only use constant extra space. The output space is generally not included in the space complexity.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 1; i <= size(nums); i++) 
            if(find(begin(nums), end(nums), i) == end(nums))  // linear search in nums for each i
                ans.push_back(i);
        return ans;
    }
};



/*
Time Complexity : O(nlogn), we iterate over the range [1, n] which takes O(n) and for each iteration, we check if that element occurs in nums using binary search which takes another O(logn) giving a total time of O(nlogn)

Space Complexity : O(sort), the only extra space required is the one used in internal sorting algorithm. Ignoring that space, we can say it to be O(1)
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> ans;
        for(int i = 1; i <= size(nums); i++) 
            if(!binary_search(begin(nums), end(nums), i))   // binary search in nums for each i
                ans.push_back(i);
        return ans;
    }
};




/*
Time Complexity : O(n), we require O(n) time to insert all elements into hashset and another O(n) time to iterate over range and insert elements not present in hashset into ans, thus giving a total time of O(n).

Space Complexity : O(n), required to maintain the hashset.

*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));   // insert every nums[i] in hashset
        vector<int> ans(size(nums) - size(s));
        for(int i = 1, j = 0; i <= size(nums); i++)  
            if(!s.count(i)) ans[j++] = i;               // add all elements not found in hashset to ans
        return ans;
    }
};



/*
Time Complexity : O(n)
Space Complexity : O(n)

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> seen(size(nums)+1);
        vector<int> ans;
        for(auto c : nums) seen[c] = true;
        for(int i = 1; i <= size(nums); i++)
            if(!seen[i]) ans.push_back(i);
        return ans;
    }





/*
Time Complexity : O(n), the first loop places each possible element at its correct index place only once. Thus the for loop and its inner while loop run for atmost O(n).

Space Complexity : O(1), only constant extra space is being used except for the output ans.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto& c : nums) 
            while(nums[c-1] != c) 
				swap(c, nums[c-1]);               // swap till correct index place of c is not occupied by c itself
        for(int i = 1; i <= size(nums); i++)
            if(i != nums[i-1]) ans.push_back(i);  // correct index place of i is not occupied by i itself
        return ans;
    }
};
};




/*
Time Complexity : O(n), we only iterate nums twice each taking O(n) time atmost.
Space Complexity : O(1), only constant extra space is being used except for the output ans.

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto c : nums)
            nums[abs(c)-1] = -abs(nums[abs(c)-1]);   // mark c is present by negating nums[c-1]
        for(int i = 0; i < size(nums); i++) 
            if(nums[i] > 0) ans.push_back(i+1);      // nums[i] > 0 means i+1 isnt present in nums
        return ans;
    }
};