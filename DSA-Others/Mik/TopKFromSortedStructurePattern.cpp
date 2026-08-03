/*
================================================================================
LECTURE NOTES FOR REVISION
================================================================================

Topic:
    Introduction | Top K from Sorted Structures Pattern | Concepts & Questions


================================================================================
TABLE OF CONTENTS
================================================================================

    1. What is the Top K from Sorted Structures Pattern?
    2. Why do we use a Heap / Priority Queue?
    3. General Template
    4. How to Recognize This Pattern
    5. Example 1: Merge K Sorted Lists / Arrays
    6. Example 2: K Smallest Pairs
    7. Example 3: Kth Smallest in a Sorted Matrix
    8. Important Rule: Do Not Push Everything
    9. When to Use a Visited Set
   10. Common C++ Min-Heap Syntax
   11. Common Complexity Patterns
   12. Main Takeaway
   13. Beginner-Friendly C++ Examples
   14. main() Function

================================================================================
1. WHAT IS THE TOP K FROM SORTED STRUCTURES PATTERN?
================================================================================

The "Top K from Sorted Structures" pattern is used when:

    - We are given one or more sorted structures.
    - We need to find only the best K results.

Here, "best" can mean:

    - K smallest elements
    - K largest elements
    - Kth smallest element
    - Kth largest element
    - Top K pairs
    - Top K sums
    - Merged sorted output from many sorted lists

Examples of sorted structures:

    - Sorted array
    - Sorted linked list
    - K sorted arrays
    - K sorted linked lists
    - Sorted matrix
    - Sorted rows or columns
    - Sorted combinations generated from arrays

--------------------------------------------------------------------------------
Core Idea
--------------------------------------------------------------------------------

Do NOT generate all possible elements or combinations.

Instead:

    1. Start from the smallest or largest possible candidate.
    2. Use a heap to get the next best candidate.
    3. Push only the next useful candidates.
    4. Stop when we have found K answers.

This saves time and memory.

--------------------------------------------------------------------------------
Simple Example
--------------------------------------------------------------------------------

Suppose we have two sorted arrays:

    A = [1, 7, 11]
    B = [2, 4, 6]

All possible pair sums are:

    (1,2)  = 3
    (1,4)  = 5
    (1,6)  = 7
    (7,2)  = 9
    (7,4)  = 11
    (7,6)  = 13
    (11,2) = 13
    ...

If we only need the 3 smallest pairs, it is wasteful to generate all pairs.

Better idea:
    Use a heap and explore only the next possible smallest pairs.

================================================================================
2. WHY DO WE USE A HEAP / PRIORITY QUEUE?
================================================================================

A heap helps us repeatedly get the current best candidate.

    - Min-heap gives the smallest candidate first.
    - Max-heap gives the largest candidate first.

In C++, priority_queue is used for heap operations.

--------------------------------------------------------------------------------
Min-Heap
--------------------------------------------------------------------------------

A min-heap keeps the smallest element at the top.

Example:

    Heap contains: 5, 2, 8, 1

    Top element = 1

This is useful when we want:

    - K smallest elements
    - Kth smallest element
    - Merge sorted lists in increasing order

--------------------------------------------------------------------------------
Max-Heap
--------------------------------------------------------------------------------

A max-heap keeps the largest element at the top.

Example:

    Heap contains: 5, 2, 8, 1

    Top element = 8

This is useful when we want:

    - K largest elements
    - Kth largest element
    - Top K maximum sums

--------------------------------------------------------------------------------
Why heap is better than sorting everything
--------------------------------------------------------------------------------

Bad method:

    Generate all candidates.
    Sort them.
    Take first K.

This can be very expensive.

Better method:

    Push only useful candidates into heap.
    Pop the best candidate.
    Push the next possible candidates.
    Stop after K answers.

================================================================================
3. GENERAL TEMPLATE
================================================================================

This is the general pattern:

    1. Create a heap.
    2. Push initial candidates.
    3. Repeat until K answers are found:
        - Pop the best candidate.
        - Add it to answer.
        - Push its next valid candidates.

Pseudo-code:

    priority_queue<State, vector<State>, comparator> pq;
    set<pair<int, int>> visited; // only if duplicate states are possible

    push initial candidates into pq;

    while (!pq.empty() && need more answers) {
        State cur = pq.top();
        pq.pop();

        use cur as next answer;

        push valid next candidates derived from cur;
    }

--------------------------------------------------------------------------------
What is State?
--------------------------------------------------------------------------------

A State stores all information needed for one candidate.

It may contain:

    - value
    - index
    - row
    - column
    - list number
    - sum
    - pair indices
    - any extra information needed to generate next candidates

Example state for matrix:

    value = matrix[row][col]
    row   = current row
    col   = current column

Example state for pair sum:

    sum = nums1[i] + nums2[j]
    i   = index in nums1
    j   = index in nums2

================================================================================
4. HOW TO RECOGNIZE THIS PATTERN
================================================================================

Think of this pattern when the problem says:

    - Given sorted arrays...
    - Given K sorted lists...
    - Find K smallest pairs...
    - Find K largest pairs...
    - Find kth smallest element...
    - Find kth largest element...
    - Find top K sums...
    - Merge K sorted structures...
    - Matrix rows are sorted...
    - Matrix rows and columns are sorted...

--------------------------------------------------------------------------------
Important clue
--------------------------------------------------------------------------------

The input is already sorted, or part of the input is sorted.

This sorted property helps us avoid generating all candidates.

================================================================================
5. EXAMPLE 1: MERGE K SORTED LISTS / ARRAYS
================================================================================

Problem:
    Given K sorted lists, merge them into one sorted list.

Example:

    List 0: [1, 4, 7]
    List 1: [2, 5, 8]
    List 2: [3, 6, 9]

Output:

    [1, 2, 3, 4, 5, 6, 7, 8, 9]

--------------------------------------------------------------------------------
Approach
--------------------------------------------------------------------------------

Use a min-heap.

Steps:

    1. Push the first element of every list into the min-heap.
    2. Pop the smallest element.
    3. Add it to the answer.
    4. From the same list, push the next element.
    5. Repeat until heap becomes empty.

--------------------------------------------------------------------------------
ASCII Diagram
--------------------------------------------------------------------------------

Initial lists:

    List 0:  1 -> 4 -> 7
             ^
    List 1:  2 -> 5 -> 8
             ^
    List 2:  3 -> 6 -> 9
             ^

Push first elements into heap:

    heap = [1, 2, 3]

Pop 1.
Now move pointer in List 0:

    List 0:  1 -> 4 -> 7
                  ^

Push 4:

    heap = [2, 3, 4]

Continue this process.

--------------------------------------------------------------------------------
Complexity
--------------------------------------------------------------------------------

Let:

    N = total number of elements
    K = number of lists

Time complexity:

    O(N log K)

Why?
    We process each element once.
    Each heap operation costs log K.

Space complexity:

    O(K)

Why?
    At most one current element from each list is kept in the heap.

================================================================================
6. EXAMPLE 2: K SMALLEST PAIRS
================================================================================

Problem:
    Given two sorted arrays, find K pairs with the smallest sums.

Example:

    nums1 = [1, 7, 11]
    nums2 = [2, 4, 6]
    k = 3

Possible pairs:

    (1, 2)  sum = 3
    (1, 4)  sum = 5
    (1, 6)  sum = 7
    (7, 2)  sum = 9
    ...

Answer:

    (1, 2), (1, 4), (1, 6)

--------------------------------------------------------------------------------
Brute Force Approach
--------------------------------------------------------------------------------

Generate all pairs:

    total pairs = nums1.size() * nums2.size()

Then sort them by sum.

This is slow when arrays are large.

--------------------------------------------------------------------------------
Heap Approach
--------------------------------------------------------------------------------

Start with the smallest possible pair:

    indices: (0, 0)
    pair:    (nums1[0], nums2[0])

From a state (i, j), possible next states are:

    (i + 1, j)
    (i, j + 1)

Why?

    nums1 and nums2 are sorted.
    Moving right or down gives a larger or equal sum.

--------------------------------------------------------------------------------
Grid View
--------------------------------------------------------------------------------

Rows represent nums1.
Columns represent nums2.

    nums1 = [1, 7, 11]
    nums2 = [2, 4, 6]

Pair sums grid:

              2    4    6
           +----+----+----+
      1    |  3 |  5 |  7 |
           +----+----+----+
      7    |  9 | 11 | 13 |
           +----+----+----+
      11   | 13 | 15 | 17 |
           +----+----+----+

Smallest starts at top-left:

    (0, 0)

From there, explore neighbors:

    right: (0, 1)
    down:  (1, 0)

--------------------------------------------------------------------------------
Visited Set
--------------------------------------------------------------------------------

The same index pair may be reached in multiple ways.

Example:

    (0,0) -> (1,0) -> (1,1)
    (0,0) -> (0,1) -> (1,1)

So (1,1) can be pushed twice.

To avoid this, use a visited set.

================================================================================
7. EXAMPLE 3: KTH SMALLEST IN A SORTED MATRIX
================================================================================

Problem:
    Given a matrix where rows and columns are sorted,
    find the kth smallest element.

Example:

    matrix =
        1   5   9
        10  11  13
        12  13  15

    k = 8

Sorted order:

    1, 5, 9, 10, 11, 12, 13, 13, 15

8th smallest = 13

--------------------------------------------------------------------------------
Method 1: Row-wise Heap
--------------------------------------------------------------------------------

Each row is sorted.

Steps:

    1. Push the first element of each row into the heap.
    2. Pop the smallest element.
    3. Push the next element from the same row.
    4. Repeat K times.

Initial heap:

    (1, row 0, col 0)
    (10, row 1, col 0)
    (12, row 2, col 0)

After popping 1, push 5.

--------------------------------------------------------------------------------
Method 2: Grid BFS Style
--------------------------------------------------------------------------------

Start from cell:

    (0, 0)

Push neighbors:

    (1, 0)
    (0, 1)

Use visited set to avoid duplicate cells.

This method uses the sorted matrix like a graph.

================================================================================
8. IMPORTANT RULE: DO NOT PUSH EVERYTHING
================================================================================

A common beginner mistake:

    Push all possible candidates into the heap.

This is usually wrong for this pattern.

Why?

    If you push everything, the heap may become huge.
    Then you lose the benefit of the sorted structure.

--------------------------------------------------------------------------------
Correct Idea
--------------------------------------------------------------------------------

Push only the frontier.

Frontier means:

    The next few candidates that can become the answer soon.

Examples:

    - For K sorted lists:
        frontier = current head of each list

    - For sorted matrix:
        frontier = first element of each row
        OR neighbors of visited cells

    - For K smallest pairs:
        frontier = nearby pairs from current smallest pair

--------------------------------------------------------------------------------
Simple Explanation
--------------------------------------------------------------------------------

Imagine you are standing at the smallest element.
You do not need to see the whole world.
You only need to check the next possible steps.

================================================================================
9. WHEN TO USE A VISITED SET
================================================================================

Use a visited set when the same state can be reached in multiple ways.

Example:

    From (0,0), we can reach (1,1) in two ways:

        Path 1:
            (0,0) -> (1,0) -> (1,1)

        Path 2:
            (0,0) -> (0,1) -> (1,1)

If we do not use visited, (1,1) may be pushed twice.

--------------------------------------------------------------------------------
When visited is usually needed
--------------------------------------------------------------------------------

Use visited when:

    - You move in multiple directions.
    - A cell or state can be reached from different parents.
    - You are using grid-style exploration.
    - You are pushing both (i + 1, j) and (i, j + 1).

--------------------------------------------------------------------------------
When visited may not be needed
--------------------------------------------------------------------------------

Visited may not be needed when:

    - Each candidate has only one source.
    - You push only the next element from the same list.
    - Example: merge K sorted lists.

================================================================================
10. COMMON C++ MIN-HEAP SYNTAX
================================================================================

By default, C++ priority_queue is a max-heap.

--------------------------------------------------------------------------------
Default Max-Heap
--------------------------------------------------------------------------------

    priority_queue<int> pq;

Example:

    pq.push(5);
    pq.push(2);
    pq.push(8);

    pq.top() is 8

--------------------------------------------------------------------------------
Min-Heap for Integers
--------------------------------------------------------------------------------

    priority_queue<int, vector<int>, greater<int>> pq;

Example:

    pq.push(5);
    pq.push(2);
    pq.push(8);

    pq.top() is 2

--------------------------------------------------------------------------------
Min-Heap for Tuples
--------------------------------------------------------------------------------

    using T = tuple<int, int, int>;

    priority_queue<T, vector<T>, greater<T>> pq;

Tuple comparison is lexicographical.

This means it compares:

    1. first value
    2. then second value
    3. then third value

Example tuple:

    (value, row, col)

The heap will first sort by value.

================================================================================
11. COMMON COMPLEXITY PATTERNS
================================================================================

If we need only K answers, complexity often looks like:

    O(K log K)
    O(K log N)
    O(K log M)
    O(N log K)

--------------------------------------------------------------------------------
Examples
--------------------------------------------------------------------------------

Merge K sorted lists:

    Time:  O(N log K)
    Space: O(K)

K smallest pairs:

    Time:  O(K log K)
    Space: O(K)

Kth smallest in sorted matrix using row-wise heap:

    Time:  O(K log R)

where:

    R = number of rows

--------------------------------------------------------------------------------
Why this is better than brute force
--------------------------------------------------------------------------------

Brute force may take:

    O(N * M log(N * M))

For pair problems, this can be too slow.

Heap approach avoids generating all pairs.

================================================================================
12. MAIN TAKEAWAY
================================================================================

The Top K from Sorted Structures pattern is about controlled exploration.

Instead of doing:

    generate everything -> sort -> take first K

Do this:

    start from smallest/largest candidate
    use heap to repeatedly get next best
    push only valid next candidates
    stop after K results

--------------------------------------------------------------------------------
Problems where this pattern is useful
--------------------------------------------------------------------------------

    - Merge K Sorted Lists
    - Merge K Sorted Arrays
    - Kth Smallest Element in a Sorted Matrix
    - Find K Pairs with Smallest Sums
    - Find K Largest Pair Sums
    - Top K from multiple sorted arrays or lists
    - Kth smallest or largest generated value from sorted structures

================================================================================
13. BEGINNER-FRIENDLY C++ EXAMPLES
================================================================================

Below are small examples outside comments.
They are intentionally simple.
They are written for learning and revision.

The code compiles and runs.

*/

#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
EXAMPLE A: Basic Min-Heap
================================================================================

Goal:
    Learn how to create a min-heap in C++.

Important syntax:

    priority_queue<int, vector<int>, greater<int>> pq;

This gives the smallest element first.
*/

void demoMinHeap() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    cout << "Min-Heap order: ";

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
}

/*
================================================================================
EXAMPLE B: Merge K Sorted Arrays
================================================================================

Problem:
    Given multiple sorted arrays, merge them into one sorted array.

Input:
    arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    }

Output:
    1 2 3 4 5 6 7 8 9

Idea:
    Store one current element from each array in the min-heap.

State stored in heap:
    (value, arrayIndex, elementIndex)

After popping one value:
    Push the next value from the same array.
*/

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    using State = tuple<int, int, int>;
    // State = {value, arrayIndex, elementIndex}

    priority_queue<State, vector<State>, greater<State>> pq;

    // Push first element of each non-empty array.
    for (int i = 0; i < (int)arrays.size(); i++) {
        if (!arrays[i].empty()) {
            pq.push({arrays[i][0], i, 0});
        }
    }

    vector<int> result;

    while (!pq.empty()) {
        auto [value, arrayIndex, elementIndex] = pq.top();
        pq.pop();

        result.push_back(value);

        int nextIndex = elementIndex + 1;

        if (nextIndex < (int)arrays[arrayIndex].size()) {
            pq.push({arrays[arrayIndex][nextIndex], arrayIndex, nextIndex});
        }
    }

    return result;
}

/*
================================================================================
EXAMPLE C: K Smallest Pairs
================================================================================

Problem:
    Given two sorted arrays, find K pairs with the smallest sums.

Input:
    nums1 = [1, 7, 11]
    nums2 = [2, 4, 6]
    k = 3

Output:
    (1, 2), (1, 4), (1, 6)

Idea:
    Treat pair sums like a sorted grid.

State:
    (sum, i, j)

From (i, j), push:
    (i + 1, j)
    (i, j + 1)

Use visited set to avoid duplicates.
*/

vector<pair<int, int>> kSmallestPairs(
    const vector<int>& nums1,
    const vector<int>& nums2,
    int k
) {
    vector<pair<int, int>> answer;

    if (nums1.empty() || nums2.empty() || k <= 0) {
        return answer;
    }

    using State = tuple<int, int, int>;
    // State = {sum, i, j}

    priority_queue<State, vector<State>, greater<State>> pq;
    set<pair<int, int>> visited;

    pq.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    while (!pq.empty() && (int)answer.size() < k) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        answer.push_back({nums1[i], nums2[j]});

        // Move down in the pair-sum grid.
        if (i + 1 < (int)nums1.size() && !visited.count({i + 1, j})) {
            pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        // Move right in the pair-sum grid.
        if (j + 1 < (int)nums2.size() && !visited.count({i, j + 1})) {
            pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }

    return answer;
}

/*
================================================================================
EXAMPLE D: Kth Smallest Element in a Sorted Matrix
================================================================================

Problem:
    Matrix rows are sorted.
    Find the kth smallest element.

Example matrix:
    1   5   9
    10  11  13
    12  13  15

For k = 8:
    Answer = 13

Idea:
    Push first element of each row.
    Then pop the smallest K times.
    After popping from a row, push next element from the same row.

State:
    (value, row, col)
*/

int kthSmallestInSortedMatrix(const vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || k <= 0) {
        return -1;
    }

    using State = tuple<int, int, int>;
    // State = {value, row, col}

    priority_queue<State, vector<State>, greater<State>> pq;

    int rows = matrix.size();

    // Push first element from each non-empty row.
    for (int r = 0; r < rows; r++) {
        if (!matrix[r].empty()) {
            pq.push({matrix[r][0], r, 0});
        }
    }

    int answer = -1;

    while (!pq.empty() && k > 0) {
        auto [value, row, col] = pq.top();
        pq.pop();

        answer = value;
        k--;

        int nextCol = col + 1;

        if (nextCol < (int)matrix[row].size()) {
            pq.push({matrix[row][nextCol], row, nextCol});
        }
    }

    return answer;
}

/*
================================================================================
14. main() FUNCTION
================================================================================

This main() function only runs small demos.

In competitive programming, you usually replace main() with the required input/output
format of the problem.

For revision, this main() helps you quickly see the pattern working.
*/

int main() {
    cout << "Top K from Sorted Structures Pattern - Demo\n";
    cout << "-------------------------------------------\n\n";

    // Demo A: Min-Heap
    demoMinHeap();
    cout << "\n";

    // Demo B: Merge K Sorted Arrays
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> merged = mergeKSortedArrays(arrays);

    cout << "Merged K sorted arrays: ";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << "\n\n";

    // Demo C: K Smallest Pairs
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int kPairs = 3;

    vector<pair<int, int>> pairs = kSmallestPairs(nums1, nums2, kPairs);

    cout << "K smallest pairs: ";
    for (auto [a, b] : pairs) {
        cout << "(" << a << ", " << b << ") ";
    }
    cout << "\n\n";

    // Demo D: Kth Smallest in Sorted Matrix
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;
    int kth = kthSmallestInSortedMatrix(matrix, k);

    cout << k << "th smallest element in sorted matrix: " << kth << "\n";

    return 0;
}