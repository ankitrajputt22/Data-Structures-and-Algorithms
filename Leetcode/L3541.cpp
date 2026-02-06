#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    bool checkVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
    }

    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char, int> vowels;
        unordered_map<char, int> cons;

        for (int i = 0; i < n; i++) {
            if (checkVowel(s[i])) {
                vowels[s[i]]++;
            }
            else {
                cons[s[i]]++;
            }
        }

        int maxV = 0;
        int maxC = 0;
        for (auto &it : vowels) {
            if (it.second > maxV) {
                maxV = it.second;
            }
        }

        for (auto &it : cons) {
            if (it.second > maxC) {
                maxC = it.second;
            }
        }

        return maxV + maxC;
    }
};


class Solution_2 {
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxCons = 0;
        int arr[26] = {0};

        for (char &ch : s) {
            arr[ch - 'a']++;
            if (string("aeiou").find(ch) != string::npos) {
                maxVowel = max(maxVowel, arr[ch - 'a']);
            } else {
                maxCons = max(maxCons, arr[ch - 'a']);
            }
        }
        return maxCons + maxVowel;
    }
};

int main() {
    
    return 0;
}