#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
========================================
Pattern 1: Square Star Pattern
Output (N = 5):
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
========================================
*/
void pattern1(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 2: Right Angled Star Triangle
Output (N = 5):
*
* *
* * *
* * * *
* * * * *
========================================
*/
void pattern2(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 3: Right Angled Number Triangle
Output (N = 5):
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
========================================
*/
void pattern3(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 4: Right Angled Number Triangle
(each row prints row number)
Output (N = 5):
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
========================================
*/
void pattern4(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 5: Inverted Right Angled Star Triangle
Output (N = 5):
* * * * *
* * * *
* * *
* *
*
========================================
*/
void pattern5(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N; j > i; j--) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 6: Inverted Right Angled Number Triangle
Output (N = 5):
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
========================================
*/
void pattern6(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N; j > i; j--) {
            cout << N - j + 1 << " ";
        }
        cout << endl;
    }
}


/*
========================================
Pattern 7: Pyramid (Upright)
Output (N = 5):
    *
   ***
  *****
 *******
*********
========================================
*/
void pattern7(int N) {
    for (int i = 0; i < N; i++) {
        // Leading spaces
        for (int j = 0; j < N - i - 1; j++) {
            cout << " ";
        }
        // Stars
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 8: Inverted Pyramid
Output (N = 5):
*********
 *******
  *****
   ***
    *
========================================
*/
void pattern8(int N) {
    for (int i = 0; i < N; i++) {
        // Leading spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // Stars
        for (int j = 0; j < 2 * N - (2 * i + 1); j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 9: Diamond Pattern
(combination of pattern 7 & 8)

Output (N = 5):
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
========================================
*/
void pattern9(int N) {
    // Upper pyramid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }

    // Lower inverted pyramid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < 2 * N - (2 * i + 1); j++) cout << "*";
        cout << endl;
    }
}

/*
========================================
Pattern 10: Rotated Right Triangle
Output (N = 5):
*
**
***
****
*****
****
***
**
*
========================================
*/
void pattern10(int N) {
    for (int i = 1; i <= 2 * N - 1; i++) {
        int stars = i;
        if (i > N) stars = 2 * N - i;

        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}


/*
========================================
Pattern 11: Binary Right Triangle
Output (N = 5):
1
01
101
0101
10101
========================================
*/
void pattern11(int N) {
    for (int i = 0; i < N; i++) {
        int start = (i % 2 == 0) ? 1 : 0;
        for (int j = 0; j <= i; j++) {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

/*
========================================
Pattern 12: Number Crown Pattern
Output (N = 5):
1        1
12      21
123    321
1234  4321
1234554321
========================================
*/
void pattern12(int N) {
    int spaces = 2 * (N - 1);

    for (int i = 1; i <= N; i++) {
        // Increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Spaces
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // Decreasing numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
        spaces -= 2;
    }
}

/*
========================================
Pattern 13: Continuous Number Triangle
Output (N = 5):
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
========================================
*/
void pattern13(int N) {
    int num = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

/*
========================================
Pattern 14: Alphabet Triangle (Increasing)
Output (N = 5):
A
A B
A B C
A B C D
A B C D E
========================================
*/
void pattern14(int N) {
    for (int i = 0; i < N; i++) {
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 15: Alphabet Triangle (Decreasing)
Output (N = 5):
A B C D E
A B C D
A B C
A B
A
========================================
*/
void pattern15(int N) {
    for (int i = 0; i < N; i++) {
        for (char ch = 'A'; ch <= 'A' + (N - i - 1); ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}


/*
========================================
Pattern 16: Alphabet Triangle (Repeated)
Output (N = 5):
A
B B
C C C
D D D D
E E E E E
========================================
*/
void pattern16(int N) {
    for (int i = 0; i < N; i++) {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 17: Alphabet Pyramid
Output (N = 5):
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
========================================
*/
void pattern17(int N) {
    for (int i = 0; i < N; i++) {

        // Leading spaces
        for (int j = 0; j < N - i - 1; j++) {
            cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        // Characters
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << ch;
            if (j <= breakpoint) ch++;
            else ch--;
        }

        cout << endl;
    }
}

/*
========================================
Pattern 18: Alphabet Triangle (Reverse Start)
Output (N = 5):
E
D E
C D E
B C D E
A B C D E
========================================
*/
void pattern18(int N) {
    for (int i = 0; i < N; i++) {
        for (char ch = ('A' + N - 1) - i; ch <= ('A' + N - 1); ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 19: Double Star Hourglass
Output (N = 5):
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
========================================
*/
void pattern19(int N) {

    // Upper half
    int spaces = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N - i; j++) cout << "*";
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 1; j <= N - i; j++) cout << "*";
        spaces += 2;
        cout << endl;
    }

    // Lower half
    spaces = 2 * N - 2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        spaces -= 2;
        cout << endl;
    }
}



/*
========================================
Pattern 20: Double Star Pyramid
Output (N = 5):
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
========================================
*/
void pattern20(int N) {
    int spaces = 2 * N - 2;

    for (int i = 1; i <= 2 * N - 1; i++) {

        int stars = i;
        if (i > N) stars = 2 * N - i;

        // Left stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << endl;

        if (i < N) spaces -= 2;
        else spaces += 2;
    }
}

/*
========================================
Pattern 21: Hollow Square
Output (N = 5):
*****
*   *
*   *
*   *
*****
========================================
*/
void pattern21(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

/*
========================================
Pattern 22: Concentric Number Square
Output (N = 5):
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5
========================================
*/
void pattern22(int N) {
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {

            int top = i;
            int left = j;
            int bottom = (2 * N - 2) - i;
            int right = (2 * N - 2) - j;

            int minDist = min(min(top, bottom), min(left, right));
            cout << (N - minDist) << " ";
        }
        cout << endl;
    }
}




int main() {
    int N = 5;

    cout << "Pattern 1:\n";
    pattern1(N);

    cout << "\nPattern 2:\n";
    pattern2(N);

    cout << "\nPattern 3:\n";
    pattern3(N);

    cout << "\nPattern 4:\n";
    pattern4(N);

    cout << "\nPattern 5:\n";
    pattern5(N);

    cout << "\nPattern 6:\n";
    pattern6(N);


    cout << "Pattern 7:\n";
    pattern7(N);

    cout << "\nPattern 8:\n";
    pattern8(N);

    cout << "\nPattern 9:\n";
    pattern9(N);

    cout << "\nPattern 10:\n";
    pattern10(N);


    cout << "Pattern 11:\n";
    pattern11(N);

    cout << "\nPattern 12:\n";
    pattern12(N);

    cout << "\nPattern 13:\n";
    pattern13(N);

    cout << "\nPattern 14:\n";
    pattern14(N);

    cout << "\nPattern 15:\n";
    pattern15(N);


    cout << "Pattern 16:\n";
    pattern16(N);

    cout << "\nPattern 17:\n";
    pattern17(N);

    cout << "\nPattern 18:\n";
    pattern18(N);

    cout << "\nPattern 19:\n";
    pattern19(N);


    cout << "Pattern 20:\n";
    pattern20(N);

    cout << "\nPattern 21:\n";
    pattern21(N);

    cout << "\nPattern 22:\n";
    pattern22(N);


    return 0;
}
