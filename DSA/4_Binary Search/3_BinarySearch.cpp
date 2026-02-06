// UPPER BOUND of BS.................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include <algorithm>
// #include <vector>
// #include <iostream>
// using namespace std;

// int main() {
//     vector<int> nums = {10, 20, 30, 30, 40, 50};
//     int target = 50;

//     auto it = upper_bound(nums.begin(), nums.end(), target);

//     if (it != nums.end()) {
//         cout << "First element > " << target << " is at index: " << (it - nums.begin());
//         // Output: Index 4 (40)
//     } else {
//         cout << "All elements are <= " << target;
//     }
//     return 0;
// }



// Ceil Function in cpp ...................................................................................................................
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main() {
//     cout << "ceil(7.0 / 2.0) = "  << ceil(7.0 / 2.0)  << endl;  // 4.0
//     cout << "ceil(7.0 / 3.0) = "  << ceil(7.0 / 3.0)  << endl;  // 3.0
//     cout << "ceil(-4.3) = "       << ceil(-4.3)       << endl;  // -4.0
//     cout << "Common Pitfall (Integer Division) " << ceil(7 / 2) << endl;  // 3 (WRONG! 7/2 = 3 in integer division)
//     cout << ceil(static_cast<double>(7) / 2) << endl;  // 4 (Correct)

//     return 0;
// }