#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    🔹 Approach 1: Greedy Counting (Optimal)
    ============================================================

    Algorithm:
    1. Count:
       - L = number of 'L'
       - R = number of 'R'
       - U = number of '_'

    2. Current position = R - L

    3. To maximize distance:
       - Assign all '_' in one direction
       - Either:
            final = (R + U) - L   → push right
            final = R - (L + U)   → push left

    4. Answer = max(abs(final1), abs(final2))

    Time Complexity: O(n)
    Space Complexity: O(1)
    */

    int furthestDistanceFromOrigin_greedy(string moves) {
        int L = 0, R = 0, U = 0;

        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else U++;
        }

        int option1 = abs((R + U) - L);   // all '_' → R
        int option2 = abs(R - (L + U));   // all '_' → L

        return max(option1, option2);
    }


    /*
    ============================================================
    🔹 Approach 2: Direct Formula Optimization
    ============================================================

    Insight:
    Final answer can be simplified as:

        abs(R - L) + U

    Why?
    - Existing imbalance = abs(R - L)
    - Each '_' adds +1 in the same direction → increases distance

    Algorithm:
    1. Count L, R, U
    2. Return abs(R - L) + U

    Time Complexity: O(n)
    Space Complexity: O(1)
    */

    int furthestDistanceFromOrigin_formula(string moves) {
        int L = 0, R = 0, U = 0;

        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else U++;
        }

        return abs(R - L) + U;
    }


    /*
    ============================================================
    🔹 Approach 3: Simulation (Brute Thought Process)
    ============================================================

    Idea:
    Try both possibilities:
        - Replace all '_' with 'L'
        - Replace all '_' with 'R'

    Compute final position for both and take max distance.

    Steps:
    1. Build two strings:
        s1 → all '_' = 'L'
        s2 → all '_' = 'R'

    2. Simulate movement for both

    3. Return max absolute position

    Time Complexity: O(n)
    Space Complexity: O(n) (due to new strings)
    */

    int simulate(string s) {
        int pos = 0;
        for (char c : s) {
            if (c == 'L') pos--;
            else pos++;
        }
        return abs(pos);
    }

    int furthestDistanceFromOrigin_simulation(string moves) {
        string s1 = moves, s2 = moves;

        for (char &c : s1) {
            if (c == '_') c = 'L';
        }

        for (char &c : s2) {
            if (c == '_') c = 'R';
        }

        return max(simulate(s1), simulate(s2));
    }
};


int main() {
    Solution sol;

    string moves = "L_RL__R";

    cout << "Greedy: " 
         << sol.furthestDistanceFromOrigin_greedy(moves) << endl;

    cout << "Formula: " 
         << sol.furthestDistanceFromOrigin_formula(moves) << endl;

    cout << "Simulation: " 
         << sol.furthestDistanceFromOrigin_simulation(moves) << endl;

    return 0;
}