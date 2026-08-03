#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;

/*
    LeetCode 373: Find K Pairs with Smallest Sums

    Problem:
    We are given two sorted arrays nums1 and nums2.
    We need to return k pairs with the smallest sums.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Make all possible pairs.
    Sort all pairs by their sum.
    Take the first k pairs.

    Step-by-step algorithm:
    1. Create an empty list to store all pairs.
    2. Run a loop on nums1.
    3. Run another loop on nums2.
    4. Store every pair in the list.
    5. Sort the list by pair sum.
    6. Add the first k pairs to the answer.
    7. Return the answer.

    Time complexity:
    O(n * m * log(n * m))

    Space complexity:
    O(n * m)

    Note:
    This solution can give TLE for large input.
    It creates too many pairs.

------------------------------------------------------------*/
vector<vector<int>> kSmallestPairsBruteForce(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> allPairs;
    vector<vector<int>> ans;

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            allPairs.push_back({nums1[i], nums2[j]});
        }
    }

    sort(allPairs.begin(), allPairs.end(), [](vector<int>& a, vector<int>& b) {
        return (long long)a[0] + a[1] < (long long)b[0] + b[1];
    });

    for (int i = 0; i < allPairs.size() && i < k; i++) {
        ans.push_back(allPairs[i]);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Use a max heap of size k.
    Store only k smallest pairs seen so far.

    Step-by-step algorithm:
    1. Create a max heap.
    2. Run a loop on nums1.
    3. Run another loop on nums2.
    4. Find the sum of the current pair.
    5. If heap size is less than k, push the pair.
    6. Else compare with the largest sum in heap.
    7. If current sum is smaller, remove top and push current pair.
    8. Take all pairs from heap.
    9. Sort the answer by sum.
    10. Return the answer.

    Time complexity:
    O(n * m * log k)

    Space complexity:
    O(k)

    Note:
    This is better than brute force.
    It does not store all pairs.
    But it still checks all possible pairs.

------------------------------------------------------------*/
vector<vector<int>> kSmallestPairsBetter(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;

    priority_queue<pair<long long, pair<int, int>>> pq;

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            long long sum = (long long)nums1[i] + nums2[j];

            if (pq.size() < k) {
                pq.push({sum, {nums1[i], nums2[j]}});
            } else if (sum < pq.top().first) {
                pq.pop();
                pq.push({sum, {nums1[i], nums2[j]}});
            }
        }
    }

    while (!pq.empty()) {
        int first = pq.top().second.first;
        int second = pq.top().second.second;
        pq.pop();

        ans.push_back({first, second});
    }

    sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b) {
        return (long long)a[0] + a[1] < (long long)b[0] + b[1];
    });

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    Use a min heap.
    Since both arrays are sorted, the smallest pair from each row
    starts with nums2[0].

    Step-by-step algorithm:
    1. Create a min heap.
    2. Push pairs (nums1[i], nums2[0]) for first k elements of nums1.
    3. Each heap item stores sum, index i, and index j.
    4. Remove the smallest sum from heap.
    5. Add that pair to answer.
    6. Push the next pair from the same row.
    7. Repeat until k pairs are found or heap becomes empty.
    8. Return the answer.

    Time complexity:
    O(k log min(k, n))

    Space complexity:
    O(min(k, n))

    Note:
    This is the best approach.
    It avoids checking all pairs.

------------------------------------------------------------*/
vector<vector<int>> kSmallestPairsOptimal(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;

    if (nums1.size() == 0 || nums2.size() == 0 || k == 0) {
        return ans;
    }

    priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
    > pq;

    int limit = min(k, (int)nums1.size());

    for (int i = 0; i < limit; i++) {
        long long sum = (long long)nums1[i] + nums2[0];
        pq.push({sum, i, 0});
    }

    while (!pq.empty() && ans.size() < k) {
        auto current = pq.top();
        pq.pop();

        int i = get<1>(current);
        int j = get<2>(current);

        ans.push_back({nums1[i], nums2[j]});

        if (j + 1 < nums2.size()) {
            long long nextSum = (long long)nums1[i] + nums2[j + 1];
            pq.push({nextSum, i, j + 1});
        }
    }

    return ans;
}




/*------------------------------------------------------------

    Approach: Min Heap With Visited Set

    Basic idea:
    Think of all pairs as a grid.

    Example:
    nums1 = [1, 7, 11]
    nums2 = [2, 4, 6]

    Grid of pair sums:

            2    4    6

    1       3    5    7
    7       9    11   13
    11      13   15   17

    Since both arrays are sorted:
    - Moving right increases or keeps the sum same.
    - Moving down increases or keeps the sum same.

    So we start from the top-left pair.
    That pair has the smallest sum.

    Then we use a min heap to always pick the next smallest pair.

    Step-by-step algorithm:
    1. If any array is empty or k is zero, return empty answer.
    2. Create a min heap.
    3. Create a visited set.
    4. Push the first pair index (0, 0) into the heap.
    5. Mark (0, 0) as visited.
    6. While heap is not empty and answer size is less than k:
       a. Remove the smallest sum pair from heap.
       b. Add that pair to the answer.
       c. Move down to (i + 1, j), if valid and not visited.
       d. Move right to (i, j + 1), if valid and not visited.
    7. Return the answer.

    Time complexity:
    O(k log k)

    Space complexity:
    O(k)

    Note:
    The visited set is important.
    Without it, the same index pair may be inserted many times.

------------------------------------------------------------*/
vector<pair<int, int>> kSmallestPairs(
    const vector<int>& nums1,
    const vector<int>& nums2,
    int k
) {
    vector<pair<int, int>> answer;

    if (nums1.empty() || nums2.empty() || k <= 0) {
        return answer;
    }

    /*
        State stores:
        1. sum of pair
        2. index i from nums1
        3. index j from nums2

        We use long long for sum.
        This avoids overflow for large values.
    */
    using State = tuple<long long, int, int>;

    /*
        This is a min heap.

        The smallest sum will stay at the top.
    */
    priority_queue<State, vector<State>, greater<State>> pq;

    /*
        This set stores visited index pairs.

        Example:
        If pair (1, 2) is already pushed into heap,
        we will not push it again.
    */
    set<pair<int, int>> visited;

    pq.push({(long long)nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    while (!pq.empty() && (int)answer.size() < k) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        answer.push_back({nums1[i], nums2[j]});

        /*
            Move down in the grid.

            Current index is (i, j).
            Down index is (i + 1, j).

            This means:
            Use next element from nums1.
            Keep the same element from nums2.
        */
        if (i + 1 < (int)nums1.size() && visited.count({i + 1, j}) == 0) {
            long long nextSum = (long long)nums1[i + 1] + nums2[j];

            pq.push({nextSum, i + 1, j});
            visited.insert({i + 1, j});
        }

        /*
            Move right in the grid.

            Current index is (i, j).
            Right index is (i, j + 1).

            This means:
            Keep the same element from nums1.
            Use next element from nums2.
        */
        if (j + 1 < (int)nums2.size() && visited.count({i, j + 1}) == 0) {
            long long nextSum = (long long)nums1[i] + nums2[j + 1];

            pq.push({nextSum, i, j + 1});
            visited.insert({i, j + 1});
        }
    }

    return answer;
}




/*------------------------------------------------------------

    Helper function:
    This function prints the list of pairs.

------------------------------------------------------------*/
void printPairs(vector<vector<int>>& pairs) {
    for (int i = 0; i < pairs.size(); i++) {
        cout << "[" << pairs[i][0] << ", " << pairs[i][1] << "] ";
    }
    cout << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> ans1 = kSmallestPairsBruteForce(nums1, nums2, k);
    vector<vector<int>> ans2 = kSmallestPairsBetter(nums1, nums2, k);
    vector<vector<int>> ans3 = kSmallestPairsOptimal(nums1, nums2, k);

    cout << "Brute Force Solution:" << endl;
    printPairs(ans1);

    cout << "Better Solution:" << endl;
    printPairs(ans2);

    cout << "Optimal Solution:" << endl;
    printPairs(ans3);

    return 0;
}