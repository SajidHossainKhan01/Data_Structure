#include <stdio.h>

// TAIL RECURSION
void fun_tail_recursive(int n) {
    if (n > 0) {
        printf("%d ", n);   // processing at CALLING time
        fun_tail_recursive(n - 1);  // recursive call is LAST statement
    }
}

// SAME FUNCTION converted to a LOOP
void fun_tail_loop(int n) {
    while (n > 0) {
        printf("%d ", n);   // same processing
        n--;                // replaces recursive call with reduced n
    }
}

int main() {
    fun_tail_recursive(3);  // Output: 3 2 1
    printf("\n");
    fun_tail_loop(3);       // Output: 3 2 1
    return 0;
}

// 𝐖𝐡𝐚𝐭 𝐦𝐚𝐤𝐞𝐬 𝐢𝐭 𝐓𝐚𝐢𝐥 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐨𝐧:

void fun(int n) {
    if (n > 0) {
        // ... do all processing first ...
        fun(n - 1);       // ✅ TAIL — recursive call is the LAST statement
    }
}

void fun_NOT_tail(int n) {
    if (n > 0) {
        fun(n - 1) + n;   // ❌ NOT TAIL — addition happens at returning time
    }
}