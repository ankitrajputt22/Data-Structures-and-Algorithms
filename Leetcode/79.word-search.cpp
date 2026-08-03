#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
LeetCode 79 : Word Search
=========================================================

Goal:
Check if a word exists in a 2D grid.

Rules:
- Can move in 4 directions (up, down, left, right)
- Cannot reuse same cell

=========================================================

Approach : Backtracking (DFS)

---------------------------------------------------------
Intuition:

1. Start from every cell
2. If first character matches → start DFS
3. Try all 4 directions
4. Mark visited cells
5. Backtrack after exploring

---------------------------------------------------------
Time Complexity:
O(M * N * 3^L)

Why 3^L?
- At each step, we have at most 3 choices
  (excluding the direction we came from)

---------------------------------------------------------
Space Complexity:
O(L) recursion stack

=========================================================
*/

class Solution {
public:

    int rows, cols, len;

    // Directions → right, left, down, up
    vector<vector<int>> directions {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };


    /*
    -----------------------------------------------------
    DFS Function
    -----------------------------------------------------

    i, j  → current cell
    idx   → current character index in word
    */

    bool dfs(vector<vector<char>>& board,
             int i,
             int j,
             string &word,
             int idx)
    {
        // If all characters matched
        if (idx == len)
            return true;

        // Boundary + mismatch check
        if (i < 0 || i >= rows ||
            j < 0 || j >= cols ||
            board[i][j] != word[idx])
            return false;


        /*
        -------------------------------------------------
        Mark cell as visited
        -------------------------------------------------
        */
        char temp = board[i][j];
        board[i][j] = '#';


        /*
        -------------------------------------------------
        Explore all 4 directions
        -------------------------------------------------
        */
        for (auto &dir : directions) {

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (dfs(board, new_i, new_j, word, idx + 1))
                return true;
        }


        /*
        -------------------------------------------------
        Backtrack (restore cell)
        -------------------------------------------------
        */
        board[i][j] = temp;

        return false;
    }



    /*
    -----------------------------------------------------
    Main Function
    -----------------------------------------------------
    */

    bool exist(vector<vector<char>>& board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        len  = word.length();

        // Quick check
        if (rows * cols < len)
            return false;


        /*
        Try starting from every cell
        */
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};



/*
=========================================================
Driver Code
=========================================================
*/

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    cout << "Exists: "
         << obj.exist(board, word);

    return 0;
}


/*Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). 
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).
*/
class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if(idx >= l)
            return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if(m*n < l)
            return false;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

