

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } 
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;            
        }
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }
        nums1 = ans;
    }
};


class Solution_2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = 0;
        while (i >= 0 && j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                j++;
                i--;
            } 
            else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        int ind = m;
        for (int i = 0; i < n; i++) {
            nums1[ind] = nums2[i];
            ind++;
        }
    }
};


/*
3. Why It Works for Merging:
The gap method effectively sorts the combined array by:

Early stages (large gap): Move large elements from nums2 to the end of nums1 and small elements from nums1 to the beginning of nums2

Later stages (small gap): Fine-tune the positions and complete the sorting

Final stage (gap=1): Performs a final pass to ensure all adjacent elements are in order
*/


class Solution_3 {
public:
    void swapIfGreater(vector<int>& arr1, int i, vector<int>& arr2, int j) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            
            while (right < len) {
                // left in nums1, right in nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, left, nums2, right - m);
                }
                // both in nums2
                else if (left >= m) {
                    swapIfGreater(nums2, left - m, nums2, right - m);
                }
                // both in nums1
                else {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                left++;
                right++;
            }
            
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

int main() {
    
    return 0;
}