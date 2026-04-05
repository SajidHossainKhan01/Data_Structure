#include <stdio.h>

int main() {

    // QUESTION 1 — 2D array, 1-based indexing, find address formula
    // Array: int a[1..10][1..15], L0=100, W=1
    // Formula: L0 + (i-1)*N + (j-1) * W
    // = 100 + (i-1)*15 + (j-1)*1
    // = 100 + 15i - 15 + j - 1
    // = 15i + j + 84
    int i = 3, j = 5;
    int address_q1 = 15*i + j + 84;
    printf("Q1 Address of a[%d][%d] = %d\n", i, j, address_q1);


    // QUESTION 2 — pointer arithmetic on 2D array
    // int a[4][3], L0=2000, W=4
    int a[4][3] = {
        { 1,  2,  3},
        { 4,  5,  6},
        { 7,  8,  9},
        {10, 11, 12}
    };

    // x is pointer to rows
    int (*x)[3] = a;

    // x+3          → address of row 3 start
    // *(x+3)       → same address (not data)
    // *(x+2) + 3   → address of a[2][3]

    printf("\nQ2:\n");
    printf("x+3        = %u\n", (x+3));        // address of row 3
    printf("*(x+3)     = %u\n", *(x+3));       // same address
    printf("*(x+2)+3   = %u\n", *(x+2)+3);    // address of a[2][3]
    printf("**(x+2)    = %d\n", **(x+2));      // value at a[2][0] = 7
    printf("*(*(x+2)+1)= %d\n", *(*(x+2)+1)); // value at a[2][1] = 8


    // QUESTION 3 — Row major vs Column major for matrix multiplication
    // Answer: Both are equally efficient
    // Row major formula ops:  2 additions, 1 multiplication
    // Column major formula ops: 2 additions, 1 multiplication
    // Both have same number of operations → independent of representation
    printf("\nQ3: Both row major and column major are equally efficient\n");


    // QUESTION 4 — Find dimensions and data type from compiler steps
    // 3D array X[L][M][N], row major formula:
    // Address = L0 + (i*M*N + j*N + k) * W
    //
    // From compiler steps:
    // k * 4       → W = 4 (float)
    // j * 32      → N*W = 32 → N = 32/4 = 8
    // i * 1024    → M*N*W = 1024 → M = 1024/32 = 32
    //
    // Data type = float (W=4)
    // M = 32, N = 8, L = unknown

    float b[2][32][8];   // example with found dimensions
    printf("\nQ4:\n");
    printf("Data type = float (W=4)\n");
    printf("M = 32, N = 8, L = unknown\n");
    printf("Word size W = %lu\n", sizeof(float));

    return 0;
}

// 𝐐𝟏 — 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 (𝟏-𝐛𝐚𝐬𝐞𝐝 𝐢𝐧𝐝𝐞𝐱𝐢𝐧𝐠):

Given: a[1..10][1..15], L0=100, W=1, N=15

Formula: L0 + ((i-1)*N + (j-1)) * W
       = 100 + (i-1)*15 + (j-1)
       = 100 + 15i - 15 + j - 1
       = 15i + j + 84

// 𝐐𝟐 — 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐚𝐫𝐢𝐭𝐡𝐦𝐞𝐭𝐢𝐜 𝐨𝐧 𝐢𝐧𝐭 𝐚[𝟒][𝟑], 𝐋𝟎=𝟐𝟎𝟎𝟎, 𝐖=𝟒:

Memory layout (row major):
[1,2,3 | 4,5,6 | 7,8,9 | 10,11,12]
 2000    2012    2024    2036

x+3        → 2036  (address of row 3)
*(x+3)     → 2036  (same — not data)
*(x+2)+3   → 2036  (address of a[2][3])
**(x+2)    → 7     (value at a[2][0])
*(*(x+2)+1)→ 8     (value at a[2][1])

// 𝐐𝟑 — 𝐖𝐡𝐢𝐜𝐡 𝐦𝐚𝐩𝐩𝐢𝐧𝐠 𝐟𝐨𝐫 𝐦𝐚𝐭𝐫𝐢𝐱 𝐦𝐮𝐥𝐭𝐢𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧:

Row Major ops:    L0 + (i*N + j) * W  → 2 adds, 1 multiply
Column Major ops: L0 + (j*M + i) * W  → 2 adds, 1 multiply

Answer: BOTH equally efficient — independent of representation ✓

// 𝐐𝟒 — 𝐅𝐢𝐧𝐝 𝐝𝐢𝐦𝐞𝐧𝐬𝐢𝐨𝐧𝐬 𝐟𝐫𝐨𝐦 𝐜𝐨𝐦𝐩𝐢𝐥𝐞𝐫 𝐬𝐭𝐞𝐩𝐬:

Row major 3D formula expanded:
= (i * M*N*W) + (j * N*W) + (k * W) + L0

From compiler steps:
k * 4    → W    = 4     → float (not int, int=2)
j * 32   → N*W  = 32    → N = 32/4  = 8
i * 1024 → M*N*W= 1024  → M = 1024/32 = 32

Answer: Data type = float, M = 32, N = 8, L = unknown ✓