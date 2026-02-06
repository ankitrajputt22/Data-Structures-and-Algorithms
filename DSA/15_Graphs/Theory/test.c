#include <stdio.h>

int func(int n) {
    printf("this is what I am testing\n");   

    return n+1;
}

int main() {
    int a = 6;
    int b = func(a);

    printf("Value of b is: %d\n", b);
    
    return 0;
}