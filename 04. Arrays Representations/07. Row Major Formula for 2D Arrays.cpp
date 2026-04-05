#include <stdio.h>

int main() {

    // 2D array declaration — 3 rows, 4 columns
    int a[3][4] = {
        {1,  2,  3,  4},    // row 0: a[0][0] a[0][1] a[0][2] a[0][3]
        {5,  6,  7,  8},    // row 1: a[1][0] a[1][1] a[1][2] a[1][3]
        {9, 10, 11, 12}     // row 2: a[2][0] a[2][1] a[2][2] a[2][3]
    };

    // ROW MAJOR — elements stored row by row (C/C++ default)
    // Memory: [1,2,3,4, 5,6,7,8, 9,10,11,12]

    // Accessing element a[1][2]
    printf("a[1][2] = %d\n", a[1][2]);   // Output: 7

    // Accessing element a[2][3]
    printf("a[2][3] = %d\n", a[2][3]);   // Output: 12

    // Printing all addresses to verify row major storage
    printf("\nAddresses (row major order):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("a[%d][%d] = %u\n", i, j, &a[i][j]);
        }
    }

    // Word size
    printf("\nWord size W = %lu bytes\n", sizeof(int));

    return 0;
}

// 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐌𝐚𝐩𝐩𝐢𝐧𝐠 — 𝐡𝐨𝐰 𝟐𝐃 𝐦𝐚𝐩𝐬 𝐭𝐨 𝟏𝐃 𝐦𝐞𝐦𝐨𝐫𝐲:

2D view:          1D memory (row by row):
[1,  2,  3,  4]
[5,  6,  7,  8]  → [1,2,3,4, 5,6,7,8, 9,10,11,12]
[9, 10, 11, 12]

// 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 — 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 (𝟎-𝐛𝐚𝐬𝐞𝐝, 𝐂/𝐂++):

Address of a[i][j] = L0 + (i * n + j) * W

Where:
  L0 = Base address (address of a[0][0])
  i  = row index
  j  = column index
  n  = number of columns
  W  = word size (bytes per element)

// 𝐕𝐞𝐫𝐢𝐟𝐢𝐜𝐚𝐭𝐢𝐨𝐧 𝐰𝐢𝐭𝐡 𝐋𝟎=𝟐𝟎𝟎, 𝐧=𝟒, 𝐖=𝟐:

a[1][2]: 200 + (1*4 + 2) * 2 = 200 + 6*2 = 212 ✓
a[2][3]: 200 + (2*4 + 3) * 2 = 200 + 11*2 = 222 ✓

// 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐌𝐚𝐩𝐩𝐢𝐧𝐠 — 𝐡𝐨𝐰 𝟐𝐃 𝐦𝐚𝐩𝐬 𝐭𝐨 𝟏𝐃 𝐦𝐞𝐦𝐨𝐫𝐲:

Address of a[i][j] = L0 + ((i-1) * n + (j-1)) * W