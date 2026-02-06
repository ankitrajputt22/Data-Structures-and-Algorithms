#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout<<"\n"
#define newline2 cout<<"\n \n"
#define newline3 cout<<"\n \n \n"


void leftRotateBy1(vector<int> &arr) {
    int n = arr.size();
    int temp = arr[0];

    int j = 1;
    for (int i = 0; i < n-1; i++) {
        arr[i] = arr[j];
        j++;
    }
    arr[n-1] = temp;
}

void leftRotateByK(vector<int> &arr, int k) {
    int n = arr.size();
    k = k%n;

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    
    for (int i = k; i < n; i++) {
        arr[i-k] = arr[i];
    }

    // int j = 0;
    // for (int i = n-k; i < n; i++) {
    //     arr[i] = temp[j];
    //     j++;
    // }

    for (int i = n-k; i < n; i++) {
        arr[i] = temp[i - (n-k)];
    }
}

void leftRotateByK_2(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where k > n

    // Step 1: Store first k elements
    vector<int> temp(arr.begin(), arr.begin() + k);

    // Step 2: Shift remaining elements to the front
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // Step 3: Copy temp elements to the end
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

void Optimal_leftRotatebyK(vector<int> &arr, int k) {
    int n = arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.begin() + n);
    reverse(arr.begin(), arr.end());
}

int linearSearch(vector<int> &arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

vector<int> unionOf2Arrays(vector<int>& a, vector<int>& b) {
    set<int> s;

    for (int val : a) s.insert(val);
    for (int val : b) s.insert(val);

    vector<int> result;
    for (int val : s) result.push_back(val);

    return result;
}

vector<int> unionOf2SortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> res;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            if (res.empty() || res.back() != arr1[i])
                res.push_back(arr1[i]);
            i++;
        } 
        else if (arr2[j] < arr1[i]) {
            if (res.empty() || res.back() != arr2[j])
                res.push_back(arr2[j]);
            j++;
        } 
        else {
            // Both are equal
            if (res.empty() || res.back() != arr1[i])
                res.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Handle remaining elements of arr1
    while (i < n1) {
        if (res.empty() || res.back() != arr1[i]) res.push_back(arr1[i]);
        i++;
    }

    // Handle remaining elements of arr2
    while (j < n2) {
        if (res.empty() || res.back() != arr2[j]) res.push_back(arr2[j]);
        j++;
    }

    return res;
}

vector<int> intersectionOf2Arrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> visited(n2, 0);
    vector<int> res;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j] && visited[j] == 0) {
                res.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }

            // if (arr2[j] > arr1[i]) break; // in case both arrays are sorted
        }
    }
    return res;
}

vector<int> intersectionSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> res;

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return res;
}


void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}


int main() {
    newline1;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original Array: " << endl;
    printArray(nums);

    newline2;

    leftRotateBy1(nums);
    cout << "Left shift by 1 place: " << endl;
    printArray(nums);

    newline2;

    cout << "Left shift by k places: " << endl;
    leftRotateByK(nums, 3);
    printArray(nums);

    newline2;

    Optimal_leftRotatebyK(nums, 3);
    cout << "Result of Left rotate Optimal code: " << endl;
    printArray(nums);

    newline2;

    vector<int> arr3 = {1, 2, 4, 4, 5, 6};
    vector<int> arr4 = {1, 3, 4, 4, 6, 8};
    vector<int> Union = unionOf2Arrays(arr3, arr4);
    cout << "Union of above arrays is: " << endl;
    printArray(Union);

    newline2;

    vector<int> intersection = intersectionSortedArrays(arr3, arr4);
    cout << "Intesection of two sorted arrays: " << endl;
    printArray(intersection);

    newline2;
    
}