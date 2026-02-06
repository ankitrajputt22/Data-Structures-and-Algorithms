// L1...Find Second Largest Element in Array | Remove duplicates from Sorted Array | Arrays Intro Video
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#include <iostream>
using namespace std;
#define newline1 cout<<"\n";
#define newline2 cout<<"\n \n";
#define newline3 cout<<"\n \n \n";

void printArray(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int Optimal_largestElement(vector<int> &arr, int n) {
    int lar = arr[0];
    for( int i = 0; i<n; i++){
        if(arr[i] > lar){
            lar = arr[i];
        }
    }
    return lar;
}

int Better_secondLarEl(vector<int> &arr, int n) {
    int lar = arr[0];
    int secLar = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > lar) {
            secLar = lar;
            lar = arr[i];
        } 
        else if (arr[i] > secLar && arr[i] != lar) {
            secLar = arr[i];
        }
    }

    return secLar;
}

bool checkSorted(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) {
            return false;
        }
    }
    return true;
} 

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


int arrG[6];
int main(){
    // //Global vs Local array.....................................

    int arr[6];
    cout << "All elements of local array are garbage values " << endl;
    for (int i=0; i<6 ; i++){
        cout << arr[i] << " ";  // all elements of local array are garbage values
    }
    cout<<endl;

    cout << "All elements of global array are zero" << endl;
    for (int i=0; i<6 ; i++){
        cout << arrG[i] << " ";  // all elements of global array are zero
    }
    cout << endl;

    vector<int> array = {1, 2};
    cout << "Printing array or vector" << endl;
    printArray(array, 2);


    return 0;
}



    

