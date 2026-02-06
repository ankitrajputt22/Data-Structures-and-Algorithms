#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowOnes;
        vector<int> colOnes;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowOnes.push_back(i);
                    colOnes.push_back(j);
                }
            }
        }
        sort(rowOnes.begin(), rowOnes.end());
        sort(colOnes.begin(), colOnes.end());
        
        int a = colOnes.size();
        int length = colOnes[a - 1] - colOnes[0] + 1;

        int b = rowOnes.size();
        int breadth = rowOnes[b - 1] - rowOnes[0] + 1;

        return length * breadth;
    }
};


class Solution_2 {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int r1 = m, r2 = -1;
        int c1 = n, c2 = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    r1 = min(r1, i);
                    r2 = max(r2, i);

                    c1 = min(c1, j);
                    c2 = max(c2, j);
                }
            }
        }
        
        int length = c2 - c1 + 1;
        int breadth = r2 - r1 + 1;

        return length * breadth;
    }
};

//Approach (Just find the minRow, maxRow, minCol and maxCol where we see 1)
//T.C : O(m * m)
//S.C : O(1)
class Solution_1 {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }       
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};





int main() {
    
    return 0;
}