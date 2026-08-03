#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: PARAMETERIZED vs FUNCTIONAL RECURSION
===========================================================

-----------------------------------------------------------
🔹 TWO TYPES OF RECURSION
-----------------------------------------------------------

1. Parameterized Recursion
2. Functional Recursion

These are FUNDAMENTAL patterns used in:
✔ Recursion problems
✔ Dynamic Programming
✔ Backtracking

===========================================================
🔴 1. PARAMETERIZED RECURSION
===========================================================

DEFINITION:
👉 We pass the answer (accumulator) as a parameter.

Instead of returning values, we "carry" the result.

-----------------------------------------------------------
🧠 KEY IDEA:
-----------------------------------------------------------

- Work is done while going DOWN
- Base case prints or finalizes answer

-----------------------------------------------------------
📌 EXAMPLE: SUM OF FIRST N NUMBERS
-----------------------------------------------------------

Logic:
f(i, sum)

Base Case:
if (i < 1) → print sum

Recursive Call:
f(i - 1, sum + i)

-----------------------------------------------------------
🧠 VISUALIZATION:
-----------------------------------------------------------

f(3,0)
→ f(2,3)
→ f(1,5)
→ f(0,6)

Final Answer = 6

===========================================================
*/

void sum_parameterized(int i, int sum) {
    if (i < 1) {
        cout << "Sum (Parameterized): " << sum << endl;
        return;
    }

    sum_parameterized(i - 1, sum + i);
}



/*
===========================================================
🟢 2. FUNCTIONAL RECURSION
===========================================================

DEFINITION:
👉 Function RETURNS value instead of passing it

-----------------------------------------------------------
🧠 KEY IDEA:
-----------------------------------------------------------

- Work is done while coming BACK (backtracking)
- Each function waits for result

-----------------------------------------------------------
📌 EXAMPLE: SUM OF FIRST N NUMBERS
-----------------------------------------------------------

f(n) = n + f(n-1)

Base Case:
if (n == 0) return 0

-----------------------------------------------------------
🧠 VISUALIZATION:
-----------------------------------------------------------

f(3)
= 3 + f(2)
= 3 + (2 + f(1))
= 3 + (2 + (1 + f(0)))
= 3 + 2 + 1 + 0
= 6

===========================================================
*/

int sum_functional(int n) {
    if (n == 0) return 0;

    return n + sum_functional(n - 1);
}



/*
===========================================================
🟡 FACTORIAL USING FUNCTIONAL RECURSION
===========================================================

DEFINITION:
n! = n × (n-1)!

-----------------------------------------------------------
IMPORTANT BASE CASE 🚨:
-----------------------------------------------------------

if (n == 0) return 1

WHY NOT 0?
Because:
Anything × 0 = 0 → destroys result

-----------------------------------------------------------
📌 EXAMPLE:
-----------------------------------------------------------

f(4)
= 4 × f(3)
= 4 × (3 × f(2))
= 4 × (3 × (2 × f(1)))
= 4 × 3 × 2 × 1 × f(0)
= 4 × 3 × 2 × 1 × 1 = 24

===========================================================
*/

int factorial(int n) {
    if (n == 0) return 1;

    return n * factorial(n - 1);
}



/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

TIME COMPLEXITY:
O(N) → N recursive calls

SPACE COMPLEXITY:
O(N) → due to recursion stack

===========================================================
*/


/*
===========================================================
🔥 PARAMETERIZED vs FUNCTIONAL (IMPORTANT)
===========================================================

| Feature            | Parameterized         | Functional        |
|--------------------|-----------------------|------------------|
| Return value       | No                    | Yes              |
| Work happens       | Going DOWN            | Coming UP        |
| Style              | Carry answer          | Build answer     |
| Use in DP          | Rare                  | Very common      |
| Code readability   | Medium                | Cleaner          |

-----------------------------------------------------------
🧠 INTERVIEW TIP:
-----------------------------------------------------------

✔ Functional recursion is preferred
✔ Easier to convert into DP

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 5;

    cout << "Using Parameterized Recursion:\n";
    sum_parameterized(n, 0);

    cout << "\nUsing Functional Recursion:\n";
    cout << "Sum (Functional): " << sum_functional(n) << endl;

    cout << "\nFactorial:\n";
    cout << "Factorial of " << n << " = " << factorial(n) << endl;

    return 0;
}