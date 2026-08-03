#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*--------------------------------------------------
  1️⃣ FUNCTION COMPARATOR (for pair<int,int>)
  Rule:
  - First element ascending
  - If first same → second descending
--------------------------------------------------*/
bool pairComparator(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

/*--------------------------------------------------
  2️⃣ FUNCTOR (Function Object)
  Used for sorting integers in DESCENDING order
--------------------------------------------------*/
class myComparator {
public:
    bool operator()(int a, int b) {
        return a > b;   // descending order
    }
};

/*--------------------------------------------------
  Print helpers
--------------------------------------------------*/
void printVector(const vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void printPairs(const vector<pair<int,int>>& v) {
    for (auto p : v)
        cout << p.first << " " << p.second << endl;
    cout << endl;
}

/*--------------------------------------------------
  MAIN FUNCTION
--------------------------------------------------*/
int main() {

    // ===============================
    // PART 1: SORT vector<pair<int,int>>
    // ===============================
    int n;
    cout << "Enter number of pairs: ";
    cin >> n;

    vector<pair<int,int>> vp(n);
    cout << "Enter pairs (first second):\n";
    for (int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }

    sort(vp.begin(), vp.end(), pairComparator);

    cout << "\nSorted pairs:\n";
    printPairs(vp);

    // ===============================
    // PART 2: SORT vector<int> USING FUNCTOR
    // ===============================
    vector<int> vec1 = {3, 5, 2, 8, 1};

    sort(begin(vec1), end(vec1), myComparator()); // Functor

    cout << "Sorted integers using FUNCTOR (descending):\n";
    printVector(vec1);

    // ===============================
    // PART 3: SORT vector<int> USING LAMBDA
    // ===============================
    vector<int> vec2 = {7, 4, 9, 1, 6};

    auto myLambda = [](int a, int b) {
        return a > b;   // descending order
    };

    sort(vec2.begin(), vec2.end(), myLambda);

    cout << "Sorted integers using LAMBDA (descending):\n";
    printVector(vec2);

    return 0;
}
