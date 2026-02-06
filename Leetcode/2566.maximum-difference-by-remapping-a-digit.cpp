/*
 * @lc app=leetcode id=2566 lang=cpp
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
class Solution {
public:
    int minMaxDifference(int num) {
        
    }
};
// @lc code=end



class Solution {
public:
    int minMaxDifference(int num) {
        int firstDigit = num;

        string max = to_string(num);
        string min = to_string(num);

        char fdMin = min[0];
        char fdMax = max[0];

        if (fdMax == '9') {
            int i = 0;
            while (fdMax == '9') {
                fdMax = max[i];
                i++;
            } 
        }

        for (int i = 0; i < max.size(); i++) {
            if (min[i] == fdMin) {
                min[i] = '0';
            }
            if (max[i] == fdMax) {
                max[i] = '9';
            }
        }


        return stoi(max) - stoi(min);


        /*

        while (firstDigit > 10) {
            firstDigit /= 10;
        }

        string numS1 = to_string(num);
        string numS2 = to_string(num);

        char fd = firstDigit + '0';
        for (int i = 0; i < numS1.size(); i++) {
            if (numS1[i] == fd) {
                numS1[i] = '9';
                numS2[i] = '0';
            }
        }

        return stoi(numS1) - stoi(numS2);

        */
    }
};





//Approach-1 (Simple iterating on digits)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string minNum = to_string(num);
        string maxNum = to_string(num);
        int n = minNum.length();

        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(maxNum[i] != '9') {
                ch = maxNum[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxNum[i] == ch) {
                maxNum[i] = '9';
            }
        }
        

        ch = minNum[0];
        for(int i = 0; i < n; i++) {
            if(minNum[i] == ch) {
                minNum[i] = '0';
            }
        }

        return stoi(maxNum) - stoi(minNum);

    }
};


//Approach-2 (Using C++ STLs)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        char ch = str2[0]; //given input will not have leading zero
        replace(begin(str2), end(str2), ch, '0');

        return stoi(str1) - stoi(str2);
    }
};