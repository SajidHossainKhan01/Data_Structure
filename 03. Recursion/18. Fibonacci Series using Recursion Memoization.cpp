#include <stdio.h>

// VERSION 1 — ITERATIVE Fibonacci
int fib(int n) {
    int t0 = 0, t1 = 1, s = 0;

    if (n <= 1)
        return n;

    for (int i = 2; i <= n; i++) {
        s  = t0 + t1;   // sum of previous two terms
        t0 = t1;        // shift forward
        t1 = s;
    }
    return s;
}

// VERSION 2 — RECURSIVE Fibonacci
int rfib(int n) {
    if (n <= 1)
        return n;
    else
        return rfib(n - 2) + rfib(n - 1);
}

// VERSION 3 — RECURSIVE with MEMOIZATION
int F[10];   // global array, initialized to -1 in main

int mfib(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    } else {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);

        F[n] = F[n - 2] + F[n - 1];   // store result
        return F[n - 2] + F[n - 1];
    }
}

int main() {
    // Initialize memoization array with -1
    for (int i = 0; i < 10; i++)
        F[i] = -1;

    // Version 1 — Iterative
    printf("%d\n", fib(10));    // Output: 55
    printf("%d\n", fib(5));     // Output: 5
    printf("%d\n", fib(6));     // Output: 8

    // Version 2 — Recursive
    printf("%d\n", rfib(6));    // Output: 8

    // Version 3 — Memoization
    printf("%d\n", mfib(5));    // Output: 5
    printf("%d\n", mfib(6));    // Output: 8

    return 0;
}

// 𝐅𝐢𝐛𝐨𝐧𝐚𝐜𝐜𝐢 𝐒𝐞𝐫𝐢𝐞𝐬:

0  1  1  2  3  5  8  13  21  34  55
↑  ↑  ↑  ↑  ↑  ↑  ↑
0  1  2  3  4  5  6  ← term number (n)

// 𝐖𝐡𝐲 𝐦𝐞𝐦𝐨𝐢𝐳𝐚𝐭𝐢𝐨𝐧 — 𝐜𝐚𝐥𝐥 𝐜𝐨𝐮𝐧𝐭 𝐟𝐨𝐫 𝐫𝐟𝐢𝐛(𝟓) 𝐯𝐬 𝐦𝐟𝐢𝐛(𝟓):

rfib(5) — WITHOUT memoization:
rfib(5)→rfib(3)+rfib(4)
         rfib(1) rfib(2) rfib(2) rfib(3)  ← repeated calls!
Total: 15 calls

mfib(5) — WITH memoization:
Only 6 calls — already computed values
are looked up from array F, not recomputed

// 𝐆𝐥𝐨𝐛𝐚𝐥 𝐚𝐫𝐫𝐚𝐲 𝐅 𝐚𝐟𝐭𝐞𝐫 𝐦𝐟𝐢𝐛(𝟓):

Index:  0   1   2   3   4   5
F[]:    0   1   1   2   3   5