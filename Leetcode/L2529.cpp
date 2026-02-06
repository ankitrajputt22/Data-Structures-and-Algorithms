#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int pos = 0;
        int neg = 0;
        for (auto &num : nums) {
            if (num > 0) pos++;
            else if (num < 0) neg++;
        }

        return max(pos, neg);
    }
};


/*
What is std::count_if?
It's an algorithm from the <algorithm> header that counts the number of elements in a range that satisfy a specific condition.
example-
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int count = std::count_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });                
    // count = 3 (2, 4, 6)

*/

//Approach-1 (Using STL count_if())
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaP = [](int num) {
            return num > 0;
        };

        auto lambdaN = [](int num) {
            return num < 0;
        };

        int countPositive = count_if(begin(nums), end(nums), lambdaP);
        int countNegative = count_if(begin(nums), end(nums), lambdaN);

        return max(countPositive, countNegative);
    }
};



//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution_3 {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n-firstP, firstN);
        
    }
};



int main() {
    
    return 0;
}