// //L1___ Pairs and Vectors: @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Pairs....................................

#include <iostream>
using namespace std;

int main() {
    pair<int, string> p;
    //initializing a pair
    p = make_pair(2, "abc");
    cout << p.first << " " << p.second <<endl;

    p = {3, "pqr"};
    cout << p.first << " " << p.second <<endl;

    pair<int, string> p1 = p;  // p1 is copy of p 
    p1.first = 6;
    cout << p.first <<endl;

    pair<int, string> &p2 = p; // p2 is p itself as p is passed by reference in p2
    p2.first = 6;
    cout << p2.first <<endl;

    // why do we use pair? --> to maintain relation between two elements
    pair<int, int> p_array[3];
    p_array[0] = {1, 2};
    p_array[1] = {2, 4};
    int size = sizeof(p_array) / sizeof(p_array[0]);
    cout << size <<endl;

    for (int i = 0; i < std :: size(p_array); i++) {
        cout<< p_array[i].first << " " << p_array[i].second <<endl;
    }

    return 0;
}


// pair other notes.....................................
// #include <iostream>
// using namespace std;

// int main() {
//     // pair1.swap(pair2)........... The pairs must be of the same type. 
//     pair<char, int> pair1 = make_pair('A', 1);
//     pair<char, int> pair2 = make_pair('B', 2);
//     cout << pair1.first << " " << pair1.second <<endl;
//     cout << pair2.first << " " << pair2.second <<endl;

//     pair1.swap(pair2);
//     cout << pair1.first << " " << pair1.second <<endl;
//     cout << pair2.first << " " << pair2.second <<endl;


//     return 0;
// }

// more to be done from gfg ................


// vectors...........................................
// #include <iostream>
// using namespace std;

// void printVector(vector<int> &v) {
//     cout << "Vector is printed as following : " <<endl; 
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] <<" " ;
//     }
//     cout <<endl;
// }

// int main() {
//     // vector<int> v;
//     // int n;
//     // cout << "enter size : " ;
//     // cin >> n;
//     // for (int i = 0; i < n; i++) {
//     //     int x;
//     //     cin >> x;
//     //     v.push_back(x);
//     // }
       // for (auto i : v)     // printing a vector using iterators
       // cout << i << " ";

//     // printVector(v);


//     vector<int> v2(10, 3);
//     v2.pop_back();       // removes the last element with O(1) TC
//     v2.push_back(7);
//     printVector(v2);

//     vector<int> v3 = v2;  // v3 is copy of v2. It takes O(n) TC
//     // vector<int> &v3 = v2;     // v2 is passed by reference in v3
//     printVector(v3);
//     v3.push_back(5555);
//     cout << "vector v2 is : " <<endl;
//     printVector(v2);
//     cout << "vector v3 is : " <<endl;
//     printVector(v3);
    

//     return 0;
// }


// other notes on vectors..................
// #include <iostream>
// using namespace std;

// void printVector(vector<int> &v) {
//     cout << "Vector is printed as following : " <<endl; 
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] <<" " ;
//     }
//     cout <<endl;
// }

// int main() {
//     // vector<int> v1 = {1, 4, 2, 3, 5};
//     // // cout << v1.at(2) << endl;
//     // v1[2] = 1111111;
//     // v1.at(2) = 444444;
//     // printVector(v1);

//     // v1.insert(v1.begin() + 1, 222222);
//     // printVector(v1);

//     // v1.insert(v1.end() - 1, 99);
//     // printVector(v1);
   
//     // vector<int> v = {1, 2, 3, 4, 5};
//     // printVector(v);

//     // v.erase(v.begin() + v.size() - 1);
//     // printVector(v);

//     // v.erase(v.end() - 1);
//     // printVector(v);

//     // auto it = find(v.begin(), v.end(), 1);  // returns iterator pointing to the first occurrence of the value if found
//     // cout << "Index found by find function is : " << distance(v.begin(), it) << endl;
//     // printVector(v);


//     // Reverse a Vector.................
//     // vector<int> v = {1, 3, 5, 7, 9};
//     // // v.clear();   // it clears the whole vector.
//     // reverse(v.begin(), v.end());

//     // v = vector<int>(v.rbegin(), v.rend());
//     // printVector(v);

//     // vector<int> temp(v.size());
//     // reverse_copy(v.begin(), v.end(), temp.begin());
//     // v = temp;
//     // printVector(v);


//     // Sort Vector in Ascending Order...................................
//     // vector<int> v = {1, 4, 3, 2, 5};
//     // sort(v.begin(), v.end());
//     // printVector(v);

//     // // stable_sort(v.begin(), v.end());  // only difference being that the stable_sort() maintains the order of elements if the elements are equal.
    
//     // // other methods 1. using multiset   2. using bubble sort algorithm


//     // Sort a Vector in Descending Order.................
//     // vector<int> v = {6, 8, 2, 9};
//     // sort(v.begin(), v.end(), greater<>());
//     // printVector(v);

//     // // stable_sort(v.begin(), v.end(), greater<>());  // greater<>() is used as comparator to sort the vector in descending order.
//     // // other methods 1. Using multiset    2. Using sort() with reverse()


//     // Different Ways to Copy a Vector in C++..................
//     // vector<int> v1 = {2, 4, 1, 5, 3};
//     // vector<int> v2 = v1;

//     // // vector<int> v2(v1);
//     // printVector(v2);

//     // vector<int> v3;
//     // copy(v1.begin(), v1.end(), back_inserter(v3));
//     // printVector(v3);

//     // // v3.assign(v1.begin(), v1.end());
//     // // other methods 1. Using Vector insert()     2. Using Vector push_back()


//     // Using Vector push_back().................
//     // vector<int> v1 = {1, 2, 3};
//     // vector<int> v2 = {10, 20, 30};
//     // v1.swap(v2);


//     // Remove Duplicates from a Vector.......................
//     // vector<int> v = {1, 2, 2, 5, 4, 3, 5, 4};
//     // sort(v.begin(), v.end());
//     // printVector(v);
    
//     // // Move all duplicates to last of vector
//     // auto it = unique(v.begin(), v.end());    // Unique: {1, 2, 3, 4, 5, ?, ?, ?}  The unique() function returns an iterator pointing to the position after the last unique element (in this case, it points to the 5th position).
//     // printVector(v);

//     // v.erase(it, v.end());
//     // printVector(v);

//     // other methods 1. using unordered set    2. Using nested for loops

//     return 0;
// }



// more to be done from gfg 

