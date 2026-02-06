#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }

        int num2 = stoi(s);
        return num2;
    }
};


//Approach (Without converting to string)
//T.C : O(d) , d = number of dogits in num
//S.C : O(1)
class Solution_2 {
public:
    int maximum69Number (int num) {
        int place = 0;
        int index = -1;
        int temp = num;
        while(temp) {
            int remain = temp % 10;
            if (remain == 6)
                index = place;
            
            temp = temp/10;
            place++;
        }
        
        if (index == -1) return num;
        
        return num + 3 * pow(10, index);
        
    }
};

int main() {
    
    return 0;
}