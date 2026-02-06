#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Approach-1 (Using O(n) space - Do as asked)
//T.C : O(n^2)
//S.C : O(n)
class Solution_1 {
public:
    int triangularSum(vector<int>& nums) {

        while (nums.size() > 1) {
            vector<int> temp;
            for (int i = 0; i < nums.size() - 1; ++i) {
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            }
            //std::move - avoids copying and is faster and more memory-efficient.
            nums = move(temp);
        }

        return nums[0];
    }
};


//Approach-2 (O(1) space using two pointers)
//T.C : O(n^2)
//S.C : O(1)
class Solution_2 {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int size = n - 1; size >= 1; size--) {

            for (int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            
        }
        return nums[0];
    }
};



int main() {
    
    return 0;
}