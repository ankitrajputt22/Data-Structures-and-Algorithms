#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) cnt++;
            }
        }

        return cnt;
    }
};

class Solution_2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; //prefixSum and freq of prefixSum
        int preSum = 0;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];

            int rem = preSum - k;
            if (mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }

            mp[preSum]++;
        }

        return cnt;
    }
};


class Solution_3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; //prefixSum and freq of prefixSum
        int preSum = 0;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];

            int rem = preSum - k;
            cnt += mp[rem];

            mp[preSum]++;
        }

        return cnt;
    }
};

int main() {
    
    return 0;
}