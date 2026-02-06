#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        long long sum = nums1[i] + nums2[j] + nums3[k] + nums4[l];
                        if (sum == 0) {
                            cnt++;
                        }

                    }
                }
            }
        }

        return cnt;
    }
};

class Solution_2 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;

        for (int k : nums3) {
            for (int l : nums4) {
                mp[k+l]++;
            }
        }

        int cnt = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                cnt += mp[-(i+j)];
            }
        }
           
        return cnt;
    }
};

int main() {
    
    return 0;
}