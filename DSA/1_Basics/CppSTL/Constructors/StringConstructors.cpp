// File: string_constructor_char_to_string.cpp

#include <iostream>
#include <string>
using namespace std;

int main() {

    // Original string
    string say = "hello";

    // Access a single character from the string
    char ch = say[1];   // 'e'

    // Create a string with 1 copy of the character
    // string(count, character)
    string s = string(1, ch);

    // Print results
    cout << "Original string: " << say << endl;
    cout << "Character selected: " << ch << endl;
    cout << "Converted to string using string(1, ch): " << s << endl;

    // Another example: repeat character multiple times
    string repeated = string(5, 'A');   // creates "AAAAA"
    cout << "Repeated string: " << repeated << endl;

    return 0;
}