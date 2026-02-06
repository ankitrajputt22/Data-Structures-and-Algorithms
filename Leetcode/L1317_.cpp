#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    bool check(int num) {
        while (num != 0) {
            int digit = num % 10;
            if (digit == 0) return false;

            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            a = i;
            b = n - i;

            if (check(a) && check(b)) {
                return {a, b};
            }
        }

        return {a, b};
    }
};


//Approach-1 (Brute Force - Try all possible numbers fro 1 to n-1 for a and thne b = n-a)
//T.C : O(n*logn)
//S.C : O(1)
class Solution_2 {
public:

    bool check(int num) {
        while(num) {
            if(num%10 == 0) {
                return false;
            }

            num /= 10;
        }   

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n-1; a++) {
            int b = n-a;

            if(check(a) && check(b)) {
                return {a, b};
            }
        }

        return {};
    }
};

/*

How It Works:
For each digit position, subtract take from a and add to b
Default: Take 1 (e.g., split 5 as 4 + 1)
Special case: If digit is 1, take 2 to avoid creating a 0 in the next higher digit
This ensures no digit becomes 0 in either number

*/

//Approach-2 (Fixing each digit and forming a and b digit by digit)
//T.C : O(logn)
//S.C : O(1)
class Solution_3 {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        //a+b == n
        while (n > 1) {
            int take = 1;

            if (n%10 == 1) {
                take = 2;
            }

            a = a - take*placeValue;
            b = b + take*placeValue;

            n = (n - take)/10; //moving to next digit
            placeValue *= 10;
        }

        return {a, b};
    }
};


vector<int> getNoZeroIntegers(int n) {
    int a = n, b = 0;
    int placeValue = 1;
    
    while (n > 0) {
        int digit = n % 10;
        int take = (digit == 1) ? 2 : 1;
        
        if (n < take) break;  // Safety check
        
        a -= take * placeValue;
        b += take * placeValue;
        n = (n - take) / 10;
        placeValue *= 10;
    }
    
    return {a, b};
}

int main() {
    
    return 0;
}