#include <stdio.h>

int main() {

    // Simple array — compiler uses formula to find addresses
    int a[5] = {10, 20, 30, 40, 50};

    // BASE ADDRESS formula (0-based index):
    // Address of a[i] = L0 + i * W
    // L0 = base address, W = size of data type (2 or 4 bytes)

    // Example: address of a[3]
    // = L0 + 3 * 2  (assuming 2 bytes per int)
    // = 200 + 6
    // = 206

    // Accessing elements using index (compiler uses formula internally)
    a[3] = 10;                       // stored at address L0 + 3*W
    printf("a[3] = %d\n", a[3]);    // Output: 10

    // Printing addresses to verify formula
    printf("Base address of a: %u\n", &a[0]);

    for (int i = 0; i < 5; i++) {
        printf("a[%d] address: %u\n", i, &a[i]);
    }

    // Difference between consecutive addresses = W (word size)
    printf("W (word size) = %lu bytes\n", sizeof(int));

    return 0;
}

// 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 — 𝐭𝐡𝐞 𝐜𝐨𝐫𝐞 𝐜𝐨𝐧𝐜𝐞𝐩𝐭:

0-based index (C/C++):
Address of a[i] = L0 + i * W

1-based index (older languages):
Address of a[i] = L0 + (i-1) * W

Where:
  L0 = Base address (address of first element)
  i  = Index being accessed
  W  = Word size (size of data type in bytes)

// 𝐄𝐱𝐚𝐦𝐩𝐥𝐞 𝐰𝐢𝐭𝐡 𝐋𝟎 = 𝟐𝟎𝟎, 𝐖 = 𝟐:

Index:    0     1     2     3     4
Address: 200   202   204   206   208
Value:    10    20    30    40    50

a[3] = L0 + 3*W = 200 + 3*2 = 206 ✓

// 𝐖𝐡𝐲 𝐂/𝐂++ 𝐮𝐬𝐞 𝟎-𝐛𝐚𝐬𝐞𝐝 𝐢𝐧𝐝𝐞𝐱𝐢𝐧𝐠:

0-based:  Address = L0 + i * W       → 2 operations (multiply, add)
1-based:  Address = L0 + (i-1) * W   → 3 operations (subtract, multiply, add)

For n elements accessed n times:
0-based → n fewer operations → FASTER ✓