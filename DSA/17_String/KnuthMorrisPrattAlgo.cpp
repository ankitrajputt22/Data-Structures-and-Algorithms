#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
LECTURE NOTES: KMP STRING MATCHING ALGORITHM
===============================================================================

Lecture Reference:
https://youtu.be/qases-9gOpk

Source Transcript:
:contentReference[oaicite:0]{index=0}

Topic:
Knuth-Morris-Pratt String Matching Algorithm

Purpose:
- Search a pattern inside a text efficiently.
- Find all starting positions where the pattern occurs.
- Understand why brute force repeats unnecessary comparisons.
- Learn how to build the LPS array.
- Learn how the LPS array helps during pattern matching.
- Prepare for coding problems based on string searching.

Main Topics:
1. Text and pattern
2. Brute-force pattern matching
3. Problem with brute force
4. Main idea of KMP
5. Prefix and suffix
6. Proper prefix and proper suffix
7. LPS array
8. Building the LPS array
9. Using LPS during matching
10. Finding all pattern occurrences
11. Overlapping matches
12. Time and space complexity
13. GFG-style implementation

===============================================================================
1. STRING MATCHING PROBLEM
===============================================================================

We are given two strings:

    1. Text
    2. Pattern

We need to determine:

- Whether the pattern is present inside the text.
- Where the pattern starts inside the text.
- All positions where the pattern occurs.

Example:

    text    = "geeksforgeeks"
    pattern = "geek"

The pattern occurs at:

    0-based indexes: 0 and 8
    1-based indexes: 1 and 9

The GFG problem discussed in the lecture expects 1-based indexes.

===============================================================================
2. BASIC TERMINOLOGY
===============================================================================

Text:
The larger string in which we search.

Pattern:
The smaller string that we want to find.

Example:

    text    = "ABABDABACDABABCABAB"
    pattern = "ABABCABAB"

Let:

    n = Length of the text
    m = Length of the pattern

===============================================================================
3. BRUTE-FORCE APPROACH
===============================================================================

The first simple idea is to try matching the pattern from every possible
starting index of the text.

For every possible start:

    1. Place pattern[0] below text[start].
    2. Compare characters one by one.
    3. If every character matches, record the start.
    4. If a mismatch occurs, shift the pattern by one position.
    5. Start again from pattern[0].

Example:

    text    = "ABABXABABD"
    pattern = "ABABD"

Start matching from index 0:

    Text:       A B A B X A B A B D
    Pattern:    A B A B D

The first four characters match.

Then:

    text[4]    = 'X'
    pattern[4] = 'D'

They do not match.

Brute force now shifts the pattern and starts again from its beginning.

-------------------------------------------------------------------------------
3.1 BRUTE-FORCE CODE IDEA
-------------------------------------------------------------------------------

    for every possible start index:
        compare the complete pattern

-------------------------------------------------------------------------------
3.2 BRUTE-FORCE TIME COMPLEXITY
-------------------------------------------------------------------------------

In the worst case, we may compare m characters for many text positions.

Therefore:

    Time Complexity = O(n * m)

This becomes expensive when both strings are large.

===============================================================================
4. MAIN PROBLEM WITH BRUTE FORCE
===============================================================================

The biggest problem is repeated work.

Suppose several characters have already matched:

    Text part:      A B A B
    Pattern part:   A B A B

A mismatch occurs at the next character.

Brute force forgets all previous matches and starts pattern matching again
from pattern index 0.

But some matched information may still be useful.

KMP asks:

    Can we reuse the characters that have already matched?

The answer is yes.

===============================================================================
5. MAIN IDEA OF KMP
===============================================================================

KMP stands for:

    Knuth-Morris-Pratt

The main idea is:

    Do not move the text pointer backward.

During matching:

    i = Pointer for text
    j = Pointer for pattern

The text pointer i always moves forward.

When a mismatch occurs, KMP uses information from the pattern to decide where
the pattern pointer j should move.

It does not always reset j to 0.

This useful information is stored in the LPS array.

===============================================================================
6. PREFIX
===============================================================================

A prefix is a part of a string that starts from index 0.

For the string:

    "ABCD"

Prefixes are:

    "A"
    "AB"
    "ABC"
    "ABCD"

===============================================================================
7. SUFFIX
===============================================================================

A suffix is a part of a string that ends at the last index.

For the string:

    "ABCD"

Suffixes are:

    "D"
    "CD"
    "BCD"
    "ABCD"

===============================================================================
8. PROPER PREFIX AND PROPER SUFFIX
===============================================================================

A proper prefix cannot be the complete string.

A proper suffix also cannot be the complete string.

For:

    string = "ABCD"

Proper prefixes:

    "A"
    "AB"
    "ABC"

Proper suffixes:

    "D"
    "CD"
    "BCD"

The complete string "ABCD" is not considered a proper prefix or proper suffix.

Extra Note:
The empty string is sometimes considered a prefix and suffix in theory.

For LPS calculation, when no non-empty proper prefix and suffix match, we store:

    0

===============================================================================
9. WHAT IS LPS?
===============================================================================

LPS means:

    Longest Proper Prefix which is also a Suffix

For every index i of the pattern:

    lps[i]

stores the length of the longest proper prefix of:

    pattern[0 ... i]

that is also a suffix of:

    pattern[0 ... i]

Important:

    LPS stores a length, not an index.

===============================================================================
10. MEANING OF lps[i]
===============================================================================

Suppose:

    pattern = "ABABA"

At index i = 4, the considered substring is:

    pattern[0 ... 4] = "ABABA"

Proper prefixes:

    "A"
    "AB"
    "ABA"
    "ABAB"

Proper suffixes:

    "A"
    "BA"
    "ABA"
    "BABA"

The longest equal proper prefix and suffix is:

    "ABA"

Its length is:

    3

Therefore:

    lps[4] = 3

===============================================================================
11. WHY lps[0] IS ALWAYS 0
===============================================================================

Consider a string containing only one character:

    "A"

The complete string cannot be used because LPS requires a proper prefix and a
proper suffix.

There is no non-empty proper prefix and suffix.

Therefore:

    lps[0] = 0

This is why LPS construction starts from index 1.

===============================================================================
12. LPS EXAMPLE 1
===============================================================================

Pattern:

    "ABABD"

Indexes:

    Index:    0  1  2  3  4
    Pattern:  A  B  A  B  D

Now calculate LPS.

-------------------------------------------------------------------------------
INDEX 0
-------------------------------------------------------------------------------

Substring:

    "A"

No proper prefix and suffix.

    lps[0] = 0

-------------------------------------------------------------------------------
INDEX 1
-------------------------------------------------------------------------------

Substring:

    "AB"

Proper prefix:

    "A"

Proper suffix:

    "B"

They are not equal.

    lps[1] = 0

-------------------------------------------------------------------------------
INDEX 2
-------------------------------------------------------------------------------

Substring:

    "ABA"

Proper prefix:

    "A"

Proper suffix:

    "A"

They are equal.

    lps[2] = 1

-------------------------------------------------------------------------------
INDEX 3
-------------------------------------------------------------------------------

Substring:

    "ABAB"

Proper prefix:

    "AB"

Proper suffix:

    "AB"

They are equal.

    lps[3] = 2

-------------------------------------------------------------------------------
INDEX 4
-------------------------------------------------------------------------------

Substring:

    "ABABD"

The substring ends with 'D'.

No proper prefix ending with 'D' matches its suffix.

    lps[4] = 0

-------------------------------------------------------------------------------
FINAL LPS ARRAY
-------------------------------------------------------------------------------

    Pattern:  A  B  A  B  D
    Index:    0  1  2  3  4
    LPS:      0  0  1  2  0

===============================================================================
13. LPS EXAMPLE 2
===============================================================================

Pattern:

    "AAACAAAA"

Indexes:

    Index:    0  1  2  3  4  5  6  7
    Pattern:  A  A  A  C  A  A  A  A

The LPS values are:

    Index 0: "A"
             lps[0] = 0

    Index 1: "AA"
             Prefix "A" equals suffix "A"
             lps[1] = 1

    Index 2: "AAA"
             Prefix "AA" equals suffix "AA"
             lps[2] = 2

    Index 3: "AAAC"
             No matching proper prefix and suffix
             lps[3] = 0

    Index 4: "AAACA"
             Prefix "A" equals suffix "A"
             lps[4] = 1

    Index 5: "AAACAA"
             Prefix "AA" equals suffix "AA"
             lps[5] = 2

    Index 6: "AAACAAA"
             Prefix "AAA" equals suffix "AAA"
             lps[6] = 3

    Index 7: "AAACAAAA"
             Longest equal prefix and suffix is "AAA"
             lps[7] = 3

Final array:

    Pattern:  A  A  A  C  A  A  A  A
    LPS:      0  1  2  0  1  2  3  3

===============================================================================
14. VARIABLES USED TO BUILD LPS
===============================================================================

We use two variables:

    i
    length

i:
The current pattern index whose LPS value is being calculated.

length:
The length of the previous longest proper prefix which is also a suffix.

Initialization:

    lps[0] = 0
    length = 0
    i = 1

Why does i start from 1?

Because:

    lps[0] is always 0

===============================================================================
15. CASE 1: CHARACTERS MATCH WHILE BUILDING LPS
===============================================================================

Compare:

    pattern[i]
    pattern[length]

If they are equal:

    1. Increase length.
    2. Store length in lps[i].
    3. Move i forward.

Code:

    if (pattern[i] == pattern[length]) {
        length++;
        lps[i] = length;
        i++;
    }

Example:

    pattern = "AAA"

Initially:

    i = 1
    length = 0

Compare:

    pattern[1] == pattern[0]
    'A' == 'A'

Match:

    length = 1
    lps[1] = 1
    i = 2

Again:

    pattern[2] == pattern[1]
    'A' == 'A'

Match:

    length = 2
    lps[2] = 2

===============================================================================
16. CASE 2: MISMATCH AND length IS NOT 0
===============================================================================

If:

    pattern[i] != pattern[length]

and:

    length != 0

we do not immediately set lps[i] to 0.

We try a smaller possible prefix length.

Update:

    length = lps[length - 1];

Important:

    Do not increment i in this case.

Why?

Because the same pattern[i] must be tested again with a smaller possible
prefix.

Code:

    else if (length != 0) {
        length = lps[length - 1];
    }

===============================================================================
17. WHY length = lps[length - 1]?
===============================================================================

Suppose a prefix of length "length" was previously matching.

A new character causes a mismatch.

The complete prefix of the current length cannot be extended.

However, that matched prefix may itself contain a smaller proper prefix which
is also a suffix.

The LPS array already stores this information.

Therefore:

    lps[length - 1]

gives the next smaller valid prefix length to try.

This avoids checking all smaller lengths manually.

Example idea:

    Current known matching prefix length = 3

On mismatch:

    length = lps[2]

If:

    lps[2] = 2

then try extending a prefix of length 2.

If that also fails, fallback again.

===============================================================================
18. WHY i IS NOT INCREMENTED DURING LPS FALLBACK
===============================================================================

When a mismatch occurs and length is not zero:

    length = lps[length - 1];

Only the possible prefix length changes.

The current character pattern[i] has not yet been solved.

Therefore, we must compare the same character again.

Wrong:

    length = lps[length - 1];
    i++;

Correct:

    length = lps[length - 1];

===============================================================================
19. CASE 3: MISMATCH AND length IS 0
===============================================================================

If:

    pattern[i] != pattern[length]

and:

    length == 0

there is no smaller prefix left to try.

Therefore:

    lps[i] = 0;
    i++;

Code:

    else {
        lps[i] = 0;
        i++;
    }

===============================================================================
20. COMPLETE LPS CONSTRUCTION LOGIC
===============================================================================

    lps[0] = 0
    length = 0
    i = 1

    while i < pattern length:

        if pattern[i] == pattern[length]:
            length++
            lps[i] = length
            i++

        else:
            if length != 0:
                length = lps[length - 1]

            else:
                lps[i] = 0
                i++

===============================================================================
21. LPS CONSTRUCTION CODE
===============================================================================

    vector<int> buildLPS(const string& pattern) {
        int m = pattern.length();

        vector<int> lps(m, 0);

        int length = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            }
            else {
                if (length != 0) {
                    length = lps[length - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

===============================================================================
22. LPS CONSTRUCTION COMPLEXITY
===============================================================================

Although length can move backward, index i never moves backward.

Every character is handled a limited number of times.

Time Complexity:

    O(m)

Space Complexity:

    O(m)

where:

    m = Length of pattern

===============================================================================
23. USING LPS IN KMP SEARCH
===============================================================================

After building the LPS array, we search the pattern inside the text.

Pointers:

    i = Index in text
    j = Index in pattern

Initialization:

    i = 0
    j = 0

Run while:

    i < n

where:

    n = Length of text

===============================================================================
24. CASE 1: TEXT AND PATTERN CHARACTERS MATCH
===============================================================================

If:

    text[i] == pattern[j]

then:

    i++;
    j++;

Code:

    if (text[i] == pattern[j]) {
        i++;
        j++;
    }

This means one more pattern character has matched.

===============================================================================
25. COMPLETE PATTERN MATCH
===============================================================================

If:

    j == m

then the entire pattern has matched.

At this point:

    i

is one position after the last matched text character.

The pattern length is:

    m

Therefore, the 0-based starting index is:

    i - m

Since:

    j == m

we can also write:

    i - j

For 1-based indexing:

    i - m + 1

or:

    i - j + 1

===============================================================================
26. EXAMPLE OF MATCH INDEX
===============================================================================

Text:

    "ABCDEF"

Pattern:

    "CDE"

Indexes:

    Text:     A  B  C  D  E  F
    Index:    0  1  2  3  4  5

After matching "CDE":

    i = 5
    j = 3
    m = 3

0-based starting index:

    i - m
    = 5 - 3
    = 2

1-based starting index:

    i - m + 1
    = 5 - 3 + 1
    = 3

===============================================================================
27. WHAT TO DO AFTER FINDING A MATCH
===============================================================================

After a complete match, do not always reset j to 0.

There may be another occurrence, including an overlapping occurrence.

Set:

    j = lps[j - 1];

This reuses the longest prefix that is also a suffix of the matched pattern.

Code:

    if (j == m) {
        result.push_back(i - j);
        j = lps[j - 1];
    }

===============================================================================
28. OVERLAPPING MATCHES
===============================================================================

Text:

    "AAAAA"

Pattern:

    "AAA"

Matches begin at 0-based indexes:

    0
    1
    2

They overlap.

If j were reset to 0 after every match, useful information would be lost.

Using:

    j = lps[j - 1];

allows KMP to find overlapping occurrences efficiently.

For pattern:

    "AAA"

LPS:

    [0, 1, 2]

After a match:

    j = lps[2]
      = 2

Two matched characters can be reused.

===============================================================================
29. CASE 2: MISMATCH DURING KMP AND j IS NOT 0
===============================================================================

If:

    text[i] != pattern[j]

and:

    j != 0

then update:

    j = lps[j - 1];

Important:

    Do not increment i.

Why?

The text character text[i] has not yet been matched.

We only change the position in the pattern.

Code:

    else if (j != 0) {
        j = lps[j - 1];
    }

===============================================================================
30. WHY THE TEXT POINTER DOES NOT MOVE BACKWARD
===============================================================================

Suppose pattern[0 ... j - 1] already matched the text.

A mismatch occurs at pattern[j].

The LPS value tells us that some suffix of the matched pattern portion is also
a prefix of the pattern.

Those characters are already known to match.

Therefore:

    - Keep i at the same text position.
    - Move j to the next possible pattern position.
    - Continue matching.

This is the main optimization of KMP.

===============================================================================
31. CASE 3: MISMATCH DURING KMP AND j IS 0
===============================================================================

If:

    text[i] != pattern[0]

there is no matched prefix to reuse.

Move the text pointer forward:

    i++;

Code:

    else {
        i++;
    }

We cannot use:

    lps[j - 1]

because:

    j - 1 = -1

which is outside the array.

===============================================================================
32. COMPLETE KMP SEARCH LOGIC
===============================================================================

    Build the LPS array.

    i = 0
    j = 0

    while i < text length:

        if text[i] == pattern[j]:
            i++
            j++

        if j == pattern length:
            record i - j
            j = lps[j - 1]

        else if i < text length and text[i] != pattern[j]:

            if j != 0:
                j = lps[j - 1]

            else:
                i++

===============================================================================
33. IMPORTANT POINTER RULES
===============================================================================

On character match:

    i++
    j++

On mismatch when j > 0:

    j = lps[j - 1]

Do not increment i.

On mismatch when j == 0:

    i++

After complete match:

    Record the answer.
    j = lps[j - 1]

===============================================================================
34. KMP DRY RUN
===============================================================================

Text:

    "ABABXABABD"

Pattern:

    "ABABD"

LPS:

    Pattern: A B A B D
    LPS:     0 0 1 2 0

Start:

    i = 0
    j = 0

-------------------------------------------------------------------------------
MATCHING FIRST PART
-------------------------------------------------------------------------------

    text[0] = A
    pattern[0] = A

Match:

    i = 1
    j = 1

    text[1] = B
    pattern[1] = B

Match:

    i = 2
    j = 2

    text[2] = A
    pattern[2] = A

Match:

    i = 3
    j = 3

    text[3] = B
    pattern[3] = B

Match:

    i = 4
    j = 4

Now:

    text[4] = X
    pattern[4] = D

Mismatch.

Since:

    j = 4

Update:

    j = lps[3]
      = 2

Do not change i.

Compare again:

    text[4] = X
    pattern[2] = A

Mismatch.

Since:

    j = 2

Update:

    j = lps[1]
      = 0

Compare again:

    text[4] = X
    pattern[0] = A

Mismatch and j is 0.

Therefore:

    i = 5

-------------------------------------------------------------------------------
MATCHING SECOND PART
-------------------------------------------------------------------------------

Now the substring beginning at text index 5 is:

    "ABABD"

It matches the complete pattern.

When the match completes:

    i = 10
    j = 5

Starting index:

    i - j
    = 10 - 5
    = 5

Pattern found at 0-based index:

    5

===============================================================================
35. GFG EXAMPLE
===============================================================================

Text:

    "geeksforgeeks"

Pattern:

    "geek"

0-based occurrences:

    0
    8

GFG expects 1-based positions.

Therefore, return:

    1
    9

Formula:

    1-based position = i - j + 1

after j reaches the pattern length.

===============================================================================
36. BRUTE FORCE VS KMP
===============================================================================

Brute Force:

    - Restarts the pattern after mismatch.
    - May recheck previously matched text characters.
    - Worst-case time is O(n * m).

KMP:

    - Uses the LPS array.
    - Does not move the text pointer backward.
    - Reuses previous match information.
    - Runs in O(n + m).

===============================================================================
37. KMP TIME COMPLEXITY
===============================================================================

Building LPS:

    O(m)

Searching the text:

    O(n)

Total:

    O(n + m)

where:

    n = Length of text
    m = Length of pattern

===============================================================================
38. KMP SPACE COMPLEXITY
===============================================================================

The LPS array contains m integers.

Space Complexity:

    O(m)

The result vector may contain occurrence positions.

If output space is not counted:

    Auxiliary Space = O(m)

===============================================================================
39. COMMON MISTAKES
===============================================================================

Mistake 1:
Resetting j to 0 on every mismatch.

Wrong:

    j = 0;

Correct when j > 0:

    j = lps[j - 1];

-------------------------------------------------------------------------------

Mistake 2:
Incrementing i during pattern fallback.

Wrong:

    j = lps[j - 1];
    i++;

Correct:

    j = lps[j - 1];

The same text character must be compared again.

-------------------------------------------------------------------------------

Mistake 3:
Using lps[j] instead of lps[j - 1].

Wrong:

    j = lps[j];

Correct:

    j = lps[j - 1];

The already matched pattern portion ends at j - 1.

-------------------------------------------------------------------------------

Mistake 4:
Accessing lps[-1].

Always check:

    if (j != 0)

before using:

    lps[j - 1]

-------------------------------------------------------------------------------

Mistake 5:
Incrementing i while falling back during LPS construction.

When:

    length != 0

do only:

    length = lps[length - 1];

Do not increment i.

-------------------------------------------------------------------------------

Mistake 6:
Forgetting to update j after finding a complete match.

Correct:

    j = lps[j - 1];

This is required to find later and overlapping matches.

-------------------------------------------------------------------------------

Mistake 7:
Confusing length with an index.

LPS stores a length.

If the current valid prefix length is:

    length

then the next character to compare is:

    pattern[length]

-------------------------------------------------------------------------------

Mistake 8:
Using the complete substring as both prefix and suffix.

LPS requires a proper prefix and proper suffix.

The complete string is not allowed.

-------------------------------------------------------------------------------

Mistake 9:
Returning the wrong indexing format.

0-based:

    i - j

1-based:

    i - j + 1

Always check the problem statement.

===============================================================================
40. QUICK REVISION
===============================================================================

1. KMP searches a pattern inside a text.

2. Brute force may take O(n * m) time.

3. KMP avoids repeated comparisons.

4. KMP does not move the text pointer backward.

5. LPS means:

       Longest Proper Prefix which is also a Suffix.

6. lps[i] is calculated for pattern[0 ... i].

7. lps[0] is always 0.

8. LPS construction begins from i = 1.

9. During LPS construction, compare:

       pattern[i]
       pattern[length]

10. On LPS match:

       length++;
       lps[i] = length;
       i++;

11. On LPS mismatch with length > 0:

       length = lps[length - 1];

12. On LPS mismatch with length == 0:

       lps[i] = 0;
       i++;

13. During KMP, compare:

       text[i]
       pattern[j]

14. On match:

       i++;
       j++;

15. When j reaches pattern length:

       Pattern found at i - j.

16. For 1-based indexing:

       Pattern found at i - j + 1.

17. After a match:

       j = lps[j - 1];

18. On mismatch with j > 0:

       j = lps[j - 1];

19. On mismatch with j == 0:

       i++;

20. Total time complexity:

       O(n + m)

21. Auxiliary space:

       O(m)

===============================================================================
END OF LECTURE NOTES
===============================================================================
*/


// ============================================================================
// APPROACH 1: BRUTE-FORCE PATTERN SEARCH
// ============================================================================

vector<int> bruteForceSearch(
    const string& text,
    const string& pattern
) {
    vector<int> occurrences;

    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    if (m == 0 || m > n) {
        return occurrences;
    }

    for (int start = 0; start + m <= n; start++) {
        int j = 0;

        while (j < m && text[start + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            occurrences.push_back(start);
        }
    }

    return occurrences;
}


/*
Brute-Force Complexity:

    Time  = O(n * m)
    Space = O(1), excluding the result
*/


// ============================================================================
// BUILD THE LPS ARRAY
// ============================================================================

vector<int> buildLPS(const string& pattern) {
    const int m = static_cast<int>(pattern.size());

    vector<int> lps(m, 0);

    /*
    length stores the length of the longest proper prefix which is also a
    suffix for the previously processed substring.
    */
    int length = 0;

    /*
    lps[0] is always 0, so processing starts from index 1.
    */
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            /*
            We successfully extended the previous matching prefix-suffix.
            */
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                /*
                The prefix of the current length cannot be extended.

                Try the next smaller prefix that may also be a suffix.

                Do not increment i because pattern[i] must be compared again.
                */
                length = lps[length - 1];
            }
            else {
                /*
                No non-empty proper prefix can match the suffix ending at i.
                */
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


// ============================================================================
// KMP SEARCH: RETURN ALL 0-BASED OCCURRENCES
// ============================================================================

vector<int> kmpSearchZeroBased(
    const string& text,
    const string& pattern
) {
    vector<int> occurrences;

    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    if (m == 0 || m > n) {
        return occurrences;
    }

    vector<int> lps = buildLPS(pattern);

    int i = 0;  // Pointer for text
    int j = 0;  // Pointer for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            /*
            Complete pattern matched.

            i is one position after the match.
            j equals m.

            Starting index = i - j
            */
            occurrences.push_back(i - j);

            /*
            Continue searching for later and overlapping matches.
            */
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                /*
                Reuse the longest valid prefix-suffix.

                Keep i unchanged.
                */
                j = lps[j - 1];
            }
            else {
                /*
                Nothing has matched in the pattern.
                Move to the next text character.
                */
                i++;
            }
        }
    }

    return occurrences;
}


// ============================================================================
// KMP SEARCH: RETURN ALL 1-BASED OCCURRENCES
// ============================================================================

vector<int> kmpSearchOneBased(
    const string& text,
    const string& pattern
) {
    vector<int> zeroBased = kmpSearchZeroBased(text, pattern);

    vector<int> oneBased;
    oneBased.reserve(zeroBased.size());

    for (int index : zeroBased) {
        oneBased.push_back(index + 1);
    }

    return oneBased;
}


// ============================================================================
// CHECK WHETHER A PATTERN EXISTS
// ============================================================================

bool containsPattern(
    const string& text,
    const string& pattern
) {
    return !kmpSearchZeroBased(text, pattern).empty();
}


// ============================================================================
// RETURN THE FIRST 0-BASED OCCURRENCE
// ============================================================================

int firstOccurrence(
    const string& text,
    const string& pattern
) {
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    if (m == 0) {
        return 0;
    }

    if (m > n) {
        return -1;
    }

    vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;
        }

        if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return -1;
}


// ============================================================================
// GFG-STYLE SOLUTION
// ============================================================================

class Solution {
private:
    void computeLPS(
        const string& pattern,
        vector<int>& lps
    ) {
        const int m = static_cast<int>(pattern.size());

        int length = 0;
        int i = 1;

        lps[0] = 0;

        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            }
            else {
                if (length != 0) {
                    length = lps[length - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    /*
    GFG-style function:

    Returns all starting positions using 1-based indexing.

    Example:

        pattern = "geek"
        text    = "geeksforgeeks"

    Output:

        1 9
    */
    vector<int> search(string& pattern, string& text) {
        vector<int> result;

        const int n = static_cast<int>(text.size());
        const int m = static_cast<int>(pattern.size());

        if (m == 0 || m > n) {
            return result;
        }

        vector<int> lps(m, 0);

        computeLPS(pattern, lps);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                /*
                0-based starting index:

                    i - j

                GFG requires 1-based indexing:

                    i - j + 1
                */
                result.push_back(i - j + 1);

                /*
                Continue searching for additional and overlapping matches.
                */
                j = lps[j - 1];
            }
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return result;
    }
};


// ============================================================================
// HELPER FUNCTION: PRINT A VECTOR
// ============================================================================

void printVector(const vector<int>& values) {
    if (values.empty()) {
        cout << "No occurrence found.\n";
        return;
    }

    for (int value : values) {
        cout << value << ' ';
    }

    cout << '\n';
}


// ============================================================================
// MAIN FUNCTION FOR LEARNING AND TESTING
// ============================================================================

int main() {
    /*
    Example 1:

        text    = "geeksforgeeks"
        pattern = "geek"

    Expected:

        0-based indexes: 0 8
        1-based indexes: 1 9
    */

    string text = "geeksforgeeks";
    string pattern = "geek";

    vector<int> lps = buildLPS(pattern);

    cout << "Pattern: " << pattern << '\n';

    cout << "LPS: ";
    printVector(lps);

    cout << "\nBrute-force 0-based occurrences: ";
    printVector(bruteForceSearch(text, pattern));

    cout << "KMP 0-based occurrences: ";
    printVector(kmpSearchZeroBased(text, pattern));

    cout << "KMP 1-based occurrences: ";
    printVector(kmpSearchOneBased(text, pattern));

    cout << "\nFirst occurrence: "
         << firstOccurrence(text, pattern)
         << '\n';

    cout << "Pattern exists: "
         << boolalpha
         << containsPattern(text, pattern)
         << '\n';

    /*
    Example 2: Overlapping occurrences

        text    = "AAAAA"
        pattern = "AAA"

    Expected 0-based indexes:

        0 1 2
    */

    string overlappingText = "AAAAA";
    string overlappingPattern = "AAA";

    cout << "\nOverlapping example: ";
    printVector(
        kmpSearchZeroBased(
            overlappingText,
            overlappingPattern
        )
    );

    /*
    Example 3: LPS demonstration

        pattern = "AAACAAAA"

    Expected LPS:

        0 1 2 0 1 2 3 3
    */

    string lpsExample = "AAACAAAA";

    cout << "\nLPS for " << lpsExample << ": ";
    printVector(buildLPS(lpsExample));

    return 0;
}