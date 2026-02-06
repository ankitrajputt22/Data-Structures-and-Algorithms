#include <iostream>
using namespace std;

void pattern1(int N) {
    cout << "Pattern 1: " << endl;
    for (int i = 1; i <= N; i++) {  // This is the outer loop which will loop for the rows.
        for (int j = 0; j < N; j++) {  // This is the inner loop which here, loops for the columns as we have to print a rectangular pattern.
            cout << "* ";
        }
        cout << endl;  // As soon as N stars are printed, we move to the next row and give a line break otherwise all stars would get printed in 1 line.
    }
    cout << endl;
}

void pattern2(int n) {
    cout << "Pattern 2: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3(int n) {
    cout << "Pattern 3: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4(int n) {
    cout << "Pattern 4: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5(int n) {
    cout << "Pattern 5: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5_1(int n) {
    cout << "Pattern 5.1: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern6(int n) {
    cout << "Pattern 5: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            cout << n - j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern6_1(int n) {
    cout << "Pattern 6.1: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern7(int n) {
    cout << "Pattern 7: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
    
        for(int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
        
        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }

        cout << endl;
    }
}

void pattern8(int N) {
    cout << "Pattern 8: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * N - (2 * i + 1); j++) {
            cout << "*";
        }
        
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        cout << endl;
    }
}

void pattern9(int N) {
    cout << "Pattern 9: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
        for (int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * N - (2 * i + 1); j++) {
            cout << "*";
        }
        
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        cout << endl;
    }
}

void pattern10(int n) {   //may be correct or not
    cout << "Pattern 10: " << endl;
    for (int i = 0; i < (n+1)/2; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = (n+1)/2; i < n; i++) {
        int stars = 2*(n/2 + 1) - i - 1;
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10_1(int N) {
    cout << "Pattern 10_1: " << endl;
    for (int i = 1; i <= 2 * N - 1; i++) {
        int stars = i;
        if (i > N) stars = 2 * N - i;
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter no of rows: " << endl;
    // cin >> n;
    n = 4;
   
    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
    pattern5_1(n);
    pattern6(n);
    pattern6_1(n);
    pattern7(n);
    pattern8(n);
    pattern9(n);
    pattern10(n);
    pattern10_1(n);
    



    return 0;
}
