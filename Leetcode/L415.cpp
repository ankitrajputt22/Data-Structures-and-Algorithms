#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 { // gives runtime error 
/*

stoi() only works for small numbers (≤ 2,147,483,647)

It converts the string to a 32-bit int.

If the input number is larger than that, it causes integer overflow or throws an exception (std::out_of_range).

*/


public:
    string addStrings(string num1, string num2) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);

        return to_string(n1 + n2);
    }
};


class Solution_2 {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    string str1 = "123";
    string str2 = "45.67";
    
    // Method 1: stoi, stod
    int num1 = stoi(str1);
    double num2 = stod(str2);
    cout << num1 << ", " << num2 << endl;  // 123, 45.67
    
    // Method 2: stringstream
    stringstream ss(str1);
    int num3;
    ss >> num3;
    cout << num3 << endl;  // 123
    
    return 0;
}

/*

int main() {

    string str = "12345";

    int num_int = stoi(str);      // String to int
    long num_long = stol(str);    // String to long
    long long num_ll = stoll(str); // String to long long

    string str_float = "123.45";

    float num_float = stof(str_float);    // String to float
    double num_double = stod(str_float);  // String to double

    int num;

    stringstream ss(str);
    ss >> num;  // num = 12345
    
    return 0;
}


*/