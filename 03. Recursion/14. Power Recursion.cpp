#include <stdio.h>

// VERSION 1 — Simple recursive power (n multiplications)
int power(int m, int n) {
    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}

// VERSION 2 — Efficient recursive power (fewer multiplications)
int power1(int m, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power1(m * m, n / 2);     // even: reduce faster
    else
        return m * power1(m * m, (n - 1) / 2);  // odd
}

int main() {
    int r;

    // Version 1
    r = power(2, 9);
    printf("%d\n", r);    // Output: 512

    r = power(3, 4);
    printf("%d\n", r);    // Output: 81

    // Version 2
    r = power1(3, 4);
    printf("%d\n", r);    // Output: 81

    r = power1(2, 9);
    printf("%d\n", r);    // Output: 512

    r = power1(2, 8);
    printf("%d\n", r);    // Output: 256

    r = power1(9, 3);
    printf("%d\n", r);    // Output: 729

    return 0;
}

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐩𝐨𝐰𝐞𝐫(𝟐, 𝟗) — 𝐕𝐞𝐫𝐬𝐢𝐨𝐧 𝟏:

power(2,9) = power(2,8) * 2
power(2,8) = power(2,7) * 2
... (9 multiplications total)
power(2,0) = 1

Result: 512

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐩𝐨𝐰𝐞𝐫𝟏(𝟐, 𝟗) — 𝐕𝐞𝐫𝐬𝐢𝐨𝐧 𝟐:

9 is odd  → 2 * power1(4, 4)
4 is even →     power1(16, 2)
2 is even →     power1(256, 1)
1 is odd  → 256 * power1(65536, 0)
0         → 1

Returning:
256 * 1 = 256
power1(16,2) = 256
power1(4,4)  = 256
2 * 256      = 512 ✓