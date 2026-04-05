#include <stdio.h>

// HEAD RECURSION
void fun_head_recursive(int n) {
    if (n > 0) {
        fun_head_recursive(n - 1);  // recursive call is FIRST statement
        printf("%d ", n);           // processing at RETURNING time
    }
}

// ATTEMPTING direct conversion to loop (WRONG — gives wrong output)
void fun_loop_wrong(int n) {
    while (n > 0) {
        printf("%d ", n);   // prints 3 2 1, NOT 1 2 3
        n--;
    }
}

// CORRECT loop equivalent (different logic needed)
void fun_loop_correct(int n) {
    int i = 1;
    while (i <= n) {
        printf("%d ", i);   // prints 1 2 3 ✓
        i++;
    }
}

int main() {
    fun_head_recursive(3);   // Output: 1 2 3
    printf("\n");

    fun_loop_wrong(3);       // Output: 3 2 1  ✗ (wrong)
    printf("\n");

    fun_loop_correct(3);     // Output: 1 2 3  ✓
    printf("\n");

    return 0;
}

// 𝐖𝐡𝐚𝐭 𝐦𝐚𝐤𝐞𝐬 𝐢𝐭 𝐇𝐞𝐚𝐝 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐨𝐧:

void fun(int n) {
    if (n > 0) {
        fun(n - 1);         // ✅ HEAD — recursive call is the FIRST statement
        // ... all processing after ...
        printf("%d ", n);
    }
}
