// DP 42. Printing Longest Increasing Subsequence | Tabulation | Algorithm @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int longestIncreasingSubsequence(int arr[], int n){
    
//     vector<int> dp(n,1);
//     vector<int> hash(n,1);
    
//     for(int i=0; i<=n-1; i++){
        
//         hash[i] = i; // initializing with current index
//         for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
//             if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
//                 dp[i] = 1 + dp[prev_index];
//                 hash[i] = prev_index;
//             }
//         }
//     }

//     cout<<"hash array is : " ;
//     for (int i = 0; i < hash.size(); i++) {
//         cout << hash[i] << " ";
//     }
//     cout <<endl;
    
//     int ans = -1;
//     int lastIndex =-1;
    
//     for(int i=0; i<=n-1; i++){
//         if(dp[i]> ans){
//             ans = dp[i];
//             lastIndex = i;
//         }
//     }
    
//     vector<int> temp;
//     temp.push_back(arr[lastIndex]);
    
//     while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
//         lastIndex = hash[lastIndex];
//         temp.push_back(arr[lastIndex]);    
//     }
    
//     // reverse the array 
//     reverse(temp.begin(),temp.end());
    
//     cout<<"The subsequence elements are ";
    
//     for(int i=0; i<temp.size(); i++){
//         cout<<temp[i]<<" ";
//     }
//     cout<<endl;
    
//     return ans;
// }

// int main() {
	
// 	int arr[] = {5,4,11,1,16,8};
	
// 	int n = sizeof(arr)/sizeof(arr[0]);
// 	longestIncreasingSubsequence(arr,n);
// 	return 0;
// }





// DP 44. Largest Divisible Subset | Longest Increasing Subsequence @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// // Function to find the longest divisible subset
// vector<int> divisibleSet(vector<int>& arr) {
//     int n = arr.size();

//     // Sort the array in ascending order
//     sort(arr.begin(), arr.end());

//     vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
//     vector<int> hash(n, 1); // hash[i] stores the previous index in the divisible subset ending at arr[i]

//     for (int i = 0; i < n; i++) {
//         hash[i] = i; // Initialize with the current index
//         for (int prev_index = 0; prev_index < i; prev_index++) {
//             if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
//                 dp[i] = 1 + dp[prev_index];
//                 hash[i] = prev_index;
//             }
//         }
//     }

//     cout<<"hash array is : " ;
//     for (int i = 0; i < hash.size(); i++) {
//         cout << hash[i] << " ";
//     }
//     cout <<endl;

//     cout<<"dp array is : " ;
//     for (int i = 0; i < dp.size(); i++) {
//         cout << dp[i] << " ";
//     }
//     cout <<endl;

//     int ans = -1;
//     int lastIndex = -1;

//     for (int i = 0; i < n; i++) {
//         if (dp[i] > ans) {
//             ans = dp[i];
//             lastIndex = i;
//         }
//     }

//     vector<int> temp;
//     temp.push_back(arr[lastIndex]);

//     // Reconstruct the divisible subset using the hash table
//     while (hash[lastIndex] != lastIndex) {
//         lastIndex = hash[lastIndex];
//         temp.push_back(arr[lastIndex]);
//     }

//     // Reverse the array to get the correct order
//     reverse(temp.begin(), temp.end());

//     return temp;
// }

// int main() {
//     vector<int> arr = {1, 16, 7, 8, 4};

//     vector<int> ans = divisibleSet(arr);

//     cout << "The longest divisible subset elements are: ";

//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }

//     return 0;
// }




// DP 53. Palindrome Partitioning - II | Front Partition @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// // Function to check if a substring is a palindrome.
// bool isPalindrome(int i, int j, string &s) {
//     while (i < j) {
//         if (s[i] != s[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
// }

// // Recursive function to find the minimum number of partitions to make palindromes.
// int minPartitions(int i, int n, string &str) {
//     // Base case: If we've reached the end of the string.
//     if (i == n) return 0;

//     int minCost = INT_MAX;
//     // Consider all possible substrings starting from the current index.
//     for (int j = i; j < n; j++) {
//         if (isPalindrome(i, j, str)) {
//             // If the substring is a palindrome, calculate the cost and minimize it.
//             int cost = 1 + minPartitions(j + 1, n, str);
//             minCost = min(minCost, cost);
//         }
//     }
//     return minCost;
// }

// // Main function to find the minimum number of partitions for palindrome partitioning.
// int palindromePartitioning(string str) {
//     int n = str.size();
//     // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
//     return minPartitions(0, n, str) - 1;
// }

// int main() {
//     string str = "BABABCBADCEDE";
//     int partitions = palindromePartitioning(str);
//     cout << "The minimum number of partitions: " << partitions << "\n";
//     return 0;
// }




// DP 52. Evaluate Boolean Expression to True | Partition DP @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// recursive code

// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// #define ll long long
// const int mod = 1000000007;

// int f(int i, int j, int isTrue, string &exp) {
//     // Base case 1: If i > j, it's an invalid expression, return 0.
//     if (i > j) return 0;
    
//     // Base case 2: If i and j are the same, evaluate the single character.
//     if (i == j) {
//         if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
//         else return exp[i] == 'F' ? 1 : 0;
//     }
    
//     ll ways = 0;
    
//     // Iterate through the expression.
//     for (int ind = i + 1; ind <= j - 1; ind += 2) {
//         ll lT = f(i, ind - 1, 1, exp);  // Number of ways to make the left expression true.
//         ll lF = f(i, ind - 1, 0, exp);  // Number of ways to make the left expression false.
//         ll rT = f(ind + 1, j, 1, exp);  // Number of ways to make the right expression true.
//         ll rF = f(ind + 1, j, 0, exp);  // Number of ways to make the right expression false.

//         // Check the operator at the current index and update ways accordingly.
//         if (exp[ind] == '&') {
//             if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
//             else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
//         }
//         else if (exp[ind] == '|') {
//             if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
//             else ways = (ways + (lF * rF) % mod) % mod;
//         }
//         else {  // XOR operator
//             if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
//         }
//     }
//     return ways;
// }

// int evaluateExp(string &exp) {
//     int n = exp.size();
//     return f(0, n - 1, 1, exp);  // Start evaluation with isTrue set to true.
// }

// int main() {
//     string exp = "F|T^F|F|T^F";
//     int ways = evaluateExp(exp);
//     cout << "The total number of ways: " << ways << "\n";
//     return 0;
// }





