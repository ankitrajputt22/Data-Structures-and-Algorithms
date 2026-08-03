#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 11: Container With Most Water

    Problem:
    We are given an array height.
    height[i] represents the height of a vertical line at index i.

    We have to choose two lines.
    These two lines and the x-axis form a container.

    Water stored by two lines:
    width  = difference between indices
    height = minimum height of both lines
    area   = width * height

    We have to return the maximum water area.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try every possible pair of lines.
    Calculate the water area for each pair.
    Return the maximum area.

    Step-by-step algorithm:
    1. Create maxArea as 0.
    2. Run a loop for first line i.
    3. Run another loop for second line j.
    4. Find width as j - i.
    5. Find height as min(height[i], height[j]).
    6. Find area as width * height.
    7. Update maxArea.
    8. Return maxArea.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It checks every possible pair.

------------------------------------------------------------*/
int maxAreaBruteForce(vector<int>& height) {
    int n = height.size();

    int maxA = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int width = j - i;
            int smallHeight = min(height[i], height[j]);

            int area = width * smallHeight;

            if (area > maxA) {
                maxA = area;
            }
        }
    }

    return maxA;
}

/*------------------------------------------------------------

    Approach 2: Optimal Solution using Two Pointers

    Basic idea:
    Start with the widest container.
    Put one pointer at the start.
    Put one pointer at the end.

    The smaller height limits the water.
    So we move the pointer having smaller height.

    Why this works:
    Width decreases when we move pointers.
    To get a bigger area, we need a bigger height.
    The smaller height cannot help us anymore.
    So it is safe to move that pointer.

    Step-by-step algorithm:
    1. Create left pointer at index 0.
    2. Create right pointer at index n - 1.
    3. Create water as 0.
    4. While left is less than right:
       find width as right - left.
    5. Find height as min(height[left], height[right]).
    6. Calculate area.
    7. Update water.
    8. If height[left] is smaller, move left forward.
    9. Otherwise move right backward.
    10. Return water.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best simple approach.
    It checks each index at most once.

------------------------------------------------------------*/
int maxAreaOptimalTwoPointer(vector<int>& height) {
    int n = height.size();

    int left = 0;
    int right = n - 1;

    int water = 0;

    while (left < right) {
        int smallHeight = min(height[left], height[right]);
        int width = right - left;

        int area = smallHeight * width;

        water = max(water, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return water;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Two Pointers with Skipping

    Basic idea:
    This is similar to normal two pointer approach.
    But after finding current smaller height,
    skip all heights which are less than or equal to it.

    Why can we skip them:
    Current width is already larger.
    If a future height is not greater than current height,
    it cannot make a better area with smaller width.

    Step-by-step algorithm:
    1. Create left pointer at index 0.
    2. Create right pointer at index n - 1.
    3. Create water as 0.
    4. Find current smaller height.
    5. Calculate current area.
    6. Update water.
    7. Move left while height[left] is less than
       or equal to current height.
    8. Move right while height[right] is less than
       or equal to current height.
    9. Repeat until left is not less than right.
    10. Return water.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is also optimal.
    It skips useless heights at once.
    It is slightly faster in some cases.
    The normal two pointer approach is easier to remember.

------------------------------------------------------------*/
int maxAreaOptimalSkipping(vector<int>& height) {
    int n = height.size();

    int left = 0;
    int right = n - 1;

    int water = 0;

    while (left < right) {
        int smallHeight = min(height[left], height[right]);
        int width = right - left;

        int area = smallHeight * width;

        water = max(water, area);

        while (left < right && height[left] <= smallHeight) {
            left++;
        }

        while (left < right && height[right] <= smallHeight) {
            right--;
        }
    }

    return water;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal two pointer solution.

------------------------------------------------------------*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        return maxAreaOptimalTwoPointer(height);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints the answer.

------------------------------------------------------------*/
void printAnswer(int ans) {
    cout << ans << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int ans1 = maxAreaBruteForce(height);
    int ans2 = maxAreaOptimalTwoPointer(height);
    int ans3 = maxAreaOptimalSkipping(height);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Optimal Solution using Two Pointers:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Two Pointers with Skipping:" << endl;
    printAnswer(ans3);

    return 0;
}