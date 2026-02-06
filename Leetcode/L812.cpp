#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Approach (Explore all triangles - Heron's Formula or Shoelace Formula for finding area)
//T.C : O(n^3)
//S.C : O(1)
class Solution_1 {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;
        

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    double x1 = points[i][0];
                    double y1 = points[i][1];

                    double x2 = points[j][0];
                    double y2 = points[j][1];

                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    double a = hypot(x2-x1, y2-y1);    //Math.hypot
                    double b = hypot(x2-x3, y2-y3);
                    double c = hypot(x3-x1, y3-y1);

                    double s = (a + b + c) * 0.5;

                    double heron = sqrt(s * (s-a) * (s-b) * (s-c));

                    double shoelace = 0.5 * abs(x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1 - y2));


                    maxArea = max({maxArea, heron, shoelace});
                }
            }
         }

         return maxArea;

    }
};

int main() {
    double x = 3, y = 4;
    cout << hypot(x, y); // Output: 5   --   Calculates hypotenuse: √(x² + y²)
    return 0;
}

