// L6. Recursion on Subsequences | Printing Subsequences____________________________________________
// _________________________________________________________________________________________________

// #include <iostream> 
// using namespace std;

// void print_subsequences(int ind, vector<int> ds, int arr[], int n) {
//     if (ind == n) {
//         for (auto it : ds) {
//             cout << it <<" " ;
//         }

//         if (ds.size() == 0) {
//             cout << "{}";
//         }
        
//         cout <<endl; 
//         return;
//     }

//     ds.push_back(arr[ind]);
//     print_subsequences(ind + 1, ds, arr, n);
    
//     ds.pop_back();

//     print_subsequences(ind + 1, ds, arr, n);
// }

// int main() {
//     int arr[3] = {3, 1, 2};
//     int n = 3;
//     vector<int> ds;

//     print_subsequences(0, ds, arr, 3);
// }




// #include <iostream>
// using namespace std;

// int main() {
//     vector<int> ds;
//     for(auto it : ds) {
//         cout<< it <<endl;
//     }

//     cout<< "my name is ankit rajput";
// }




// Power set algorithm of subsequences________________________..........................

// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;

// vector<string> AllPossibleStrings(string s) {
// 	int n = s.length();
// 	vector<string>ans;
// 	for (int num = 0; num < (1 << n); num++) {
// 		string sub = "";
// 		for (int i = 0; i < n; i++) {
// 			//check if the ith bit is set or not
// 			if (num & (1 << i)) {
// 				sub += s[i];
// 			}
// 		}
//         ans.push_back(sub);
// 		// if (sub.length() > 0) {
// 		// 	ans.push_back(sub);
// 		// }
// 	}
// 	sort(ans.begin(), ans.end());
// 	return ans;
// }
// int main()
// {


// 	string s="abc";
// 	vector<string>ans = AllPossibleStrings(s);
// 	// printint all the subsequence.
// 	cout <<"All possible subsequences are " <<endl;
// 	for (auto it : ans) {
// 		cout << it <<endl;
// 	}

// }




// L7. All Kind of Patterns in Recursion | Print All | Print one | Count______________________________
//___________________________________________________________________________________________________



// Ques1_sub with sum == k_____...........................................
// #include <iostream>
// using namespace std;

// void print_subsequences(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
//     if (ind == n) {
//         if (sum == s) {
//             for (auto it : ds){
//                 cout << it << " ";  
//             }
//             cout<<endl;
//         }
//         return;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     print_subsequences(ind+1, ds, s, sum, arr, n);
    
//     s -= arr[ind];
//     ds.pop_back();
//     print_subsequences(ind+1, ds, s, sum, arr, n);
// }

// int main(){
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;
//     print_subsequences(0, ds, 0, sum, arr, n);

// }



// count sub with sum == k
// #include <iostream>
// using namespace std;

// int print_subsequences(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
//     if (ind == n) {
//         if (sum == s) {
//             return 1;
//         }
//         return 0;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     int l = print_subsequences(ind+1, ds, s, sum, arr, n);
    
//     s -= arr[ind];
//     ds.pop_back();
//     int r = print_subsequences(ind+1, ds, s, sum, arr, n);

//     return l + r;
// }

// int main(){
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;
//     cout<< print_subsequences(0, ds, 0, sum, arr, n);

// }



// Print only one subsequence with sum = k________________________________....................
// #include <iostream>
// using namespace std;

// bool print_subsequences(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
//     if (ind == n) {
//         if (sum == s) {
//             for (auto it : ds){
//                 cout << it << " ";     
//             }
//             return true;
//         }
//         return false;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     if (print_subsequences(ind+1, ds, s, sum, arr, n) == true) {
//             return true;
//     }
    
//     s -= arr[ind];
//     ds.pop_back();
//     if (print_subsequences(ind+1, ds, s, sum, arr, n) == true) return true;

//     return false;
// }

// int main(){
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;
//     print_subsequences(0, ds, 0, sum, arr, n);

// }



// Count num of subsequences whose sum is k .....................................................
// #include <iostream>
// using namespace std;

// int print_subsequences(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
//     if (ind == n) {
//         if (sum == s) {
//             return 1;
//         }
//         return 0;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     int l = print_subsequences(ind+1, ds, s, sum, arr, n);
    
//     s -= arr[ind];
//     ds.pop_back();
//     int r = print_subsequences(ind+1, ds, s, sum, arr, n);

//     return l + r;
// }

// int main(){
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 4;
//     vector<int> ds;
//     cout << print_subsequences(0, ds, 0, sum, arr, n);

// }