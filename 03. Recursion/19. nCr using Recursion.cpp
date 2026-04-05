#include <stdio.h>

// HELPER — Factorial (recursive)
int fact(int n) {
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

// VERSION 1 — NCR using factorial formula
int ncr(int n, int r) {
    int numerator   = fact(n);
    int denominator = fact(r) * fact(n - r);
    return numerator / denominator;
}

// VERSION 2 — NCR using pure recursion (Pascal's Triangle)
int NCR(int n, int r) {
    if (n == r || r == 0)
        return 1;
    else
        return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main() {
    // Version 1 — using factorial
    printf("%d\n", ncr(5, 1));   // Output: 5
    printf("%d\n", ncr(5, 2));   // Output: 10
    printf("%d\n", ncr(5, 3));   // Output: 10
    printf("%d\n", ncr(4, 2));   // Output: 6

    // Version 2 — recursive
    printf("%d\n", NCR(4, 2));   // Output: 6
    printf("%d\n", NCR(5, 2));   // Output: 10
    printf("%d\n", NCR(5, 3));   // Output: 10

    return 0;
}

// 𝐍𝐂𝐑 𝐅𝐨𝐫𝐦𝐮𝐥𝐚:

n!
nCr = -------
      r!(n-r)!

// 𝐏𝐚𝐬𝐜𝐚𝐥'𝐬 𝐓𝐫𝐢𝐚𝐧𝐠𝐥𝐞 — 𝐡𝐨𝐰 𝐫𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐯𝐞𝐫𝐬𝐢𝐨𝐧 𝐰𝐨𝐫𝐤𝐬:

nCr = (n-1)C(r-1) + (n-1)C(r)

For NCR(4,2):
         NCR(4,2)
        /        \
   NCR(3,1)    NCR(3,2)
   /     \     /      \
NCR(2,0) NCR(2,1) NCR(2,1) NCR(2,2)
  1      /    \    /    \     1
      NCR(1,0) NCR(1,1) ...
         1       1

Result: 1+2+2+1 = 6 ✓

// 𝐁𝐚𝐬𝐞 𝐜𝐚𝐬𝐞𝐬 𝐟𝐨𝐫 𝐫𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐯𝐞𝐫𝐬𝐢𝐨𝐧:

n == r  → nCr = 1  (e.g. 3C3 = 1)
r == 0  → nCr = 1  (e.g. 3C0 = 1)