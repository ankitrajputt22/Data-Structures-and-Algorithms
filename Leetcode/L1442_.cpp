#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = 0;
                for (int p = i; p < j; p++) {
                    a ^= arr[p];
                }

                for (int k = j; k < n; k++) {
                    int b = 0;
                    for (int q = j; q <= k; q++) {
                        b ^= arr[q];
                    }

                    if (a == b) cnt++;
                }
            }
        }

        return cnt;
    }
};


class Solution_2 {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int xora = 0;
            for (int j = i+1; j < n; j++) {
                xora ^= arr[j-1];
                
                int xorb = 0;
                for (int k = j; k < n; k++) {
                    xorb ^= arr[k];

                    if (xora == xorb) cnt++;
                }
            }
        }

        return cnt;
    }
};


class Solution_3 {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i+1; k < n; k++) {
                int xorr = 0;
                for (int p = i; p <= k; p++) {
                    xorr ^= arr[p];
                }

                if (xorr == 0) cnt += k-i;
            }
        }

        return cnt;
    }
};

//Approach (Better than brute force)
//T.C : O(n^2)
//S.C : O(n)
class Solution_4 {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(begin(arr), end(arr));

        prefixXor.insert(prefixXor.begin(), 0); //initially the xor cumulative will be 0
        int n = prefixXor.size();

        for(int i = 1; i < n; i++) {
            prefixXor[i] ^= prefixXor[i-1];
        }

        int triplets = 0;

        for(int i = 0; i < n; i++) {
            for(int k = i+1; k < n; k++) {

                if (prefixXor[k] == prefixXor[i]) {
                    triplets += k-i-1;
                }

            }
        }

        return triplets;
    }
};

class Solution_5 {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> count, sum;
        
        count[0] = 1;
        sum[0] = 0;
        int ans = 0;
        
        for (int k = 1; k <= n; k++) {
            prefix[k] = prefix[k - 1] ^ arr[k - 1];
            int x = prefix[k];
            
            if (count.find(x) != count.end()) {
                ans += (k - 1) * count[x] - sum[x];
            }
            
            count[x]++;
            sum[x] += k;
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}