#include <iostream>
#include <string>

using namespace std;

/*
==========================================================
LeetCode 1784
Check if Binary String Has at Most One Segment of Ones
==========================================================

Goal:
Check if the binary string contains only ONE segment of '1's.

Example:

Valid:
"111000"
"110"

Invalid:
"101"
"110011"

----------------------------------------------------------
Approaches
1) Traverse and count segments
2) Look for pattern "01"
3) Flag based scanning
----------------------------------------------------------
*/


/*
==========================================================
Approach 1
Traverse and Count Segments
==========================================================

Idea:
Whenever we encounter a group of '1's,
increase segment count.

If segment count > 1 → return false.
*/

class Solution1
{
public:

    bool checkOnesSegment(string s)
    {
        int n = s.length();
        int count = 0;

        int i = 0;

        while (i < n)
        {
            if (s[i] == '1')
            {
                count++;

                // Skip all continuous 1's
                while (i < n && s[i] == '1')
                {
                    i++;
                }
            }
            else
            {
                i++;
            }

            // More than one segment found
            if (count > 1)
                return false;
        }

        return true;
    }
};



/*
==========================================================
Approach 2
Look for substring "01"
==========================================================

Observation:

If "01" exists, it means:

1's ended
then started again later.

Example:
"1101"

So if "01" exists → multiple segments
*/

class Solution2
{
public:

    bool checkOnesSegment(string s)
    {
        return s.find("01") == string::npos;
    }
};



/*
==========================================================
Approach 3
Flag Based Traversal
==========================================================

Idea:

Once we see '0' after a segment of '1's,
if we see another '1' later → invalid.

Steps:
1. Track if first segment ended.
2. If '1' appears again → return false.
*/

class Solution3
{
public:

    bool checkOnesSegment(string s)
    {
        bool zeroSeen = false;

        for (char c : s)
        {
            if (c == '0')
            {
                zeroSeen = true;
            }
            else
            {
                if (zeroSeen)
                    return false;
            }
        }

        return true;
    }
};



/*
==========================================================
Driver Code
==========================================================
*/

int main()
{
    string s = "110";

    Solution1 obj1;
    Solution2 obj2;
    Solution3 obj3;

    cout << "Approach 1: "
         << obj1.checkOnesSegment(s) << endl;

    cout << "Approach 2: "
         << obj2.checkOnesSegment(s) << endl;

    cout << "Approach 3: "
         << obj3.checkOnesSegment(s) << endl;

    return 0;
}