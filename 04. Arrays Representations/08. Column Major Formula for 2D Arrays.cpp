#include <stdio.h>

int main() {

    // 2D array — 3 rows (M=3), 4 columns (N=4)
    int a[3][4] = {
        {1,  2,  3,  4},    // row 0
        {5,  6,  7,  8},    // row 1
        {9, 10, 11, 12}     // row 2
    };

    // Accessing elements
    printf("a[1][2] = %d\n", a[1][2]);   // Output: 7
    printf("a[1][3] = %d\n", a[1][3]);   // Output: 8
    printf("a[2][3] = %d\n", a[2][3]);   // Output: 12

    // Printing all addresses
    printf("\nAddresses:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("a[%d][%d] = %u\n", i, j, &a[i][j]);
        }
    }

    printf("\nWord size W = %lu bytes\n", sizeof(int));

    return 0;
}

// 𝐂𝐨𝐥𝐮𝐦𝐧 𝐌𝐚𝐣𝐨𝐫 𝐌𝐚𝐩𝐩𝐢𝐧𝐠 — 𝐡𝐨𝐰 𝟐𝐃 𝐦𝐚𝐩𝐬 𝐭𝐨 𝟏𝐃 𝐦𝐞𝐦𝐨𝐫𝐲:

2D view:          1D memory (column by column):
[1,  2,  3,  4]
[5,  6,  7,  8]  → [1,5,9, 2,6,10, 3,7,11, 4,8,12]
[9, 10, 11, 12]   col0    col1     col2     col3

// 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 — 𝐂𝐨𝐥𝐮𝐦𝐧 𝐌𝐚𝐣𝐨𝐫 (𝟎-𝐛𝐚𝐬𝐞𝐝):

Address of a[i][j] = L0 + (j * M + i) * W

Where:
  L0 = Base address
  i  = row index
  j  = column index
  M  = number of ROWS
  W  = word size (bytes per element)

// 𝐕𝐞𝐫𝐢𝐟𝐢𝐜𝐚𝐭𝐢𝐨𝐧 𝐰𝐢𝐭𝐡 𝐋𝟎=𝟐𝟎𝟎, 𝐌=𝟑, 𝐖=𝟐:

a[1][2]: 200 + (2*3 + 1) * 2 = 200 + 7*2  = 214 ✓
a[1][3]: 200 + (3*3 + 1) * 2 = 200 + 10*2 = 220 ✓

// 𝐑𝐨𝐰 𝐌𝐚𝐣𝐨𝐫 𝐯𝐬 𝐂𝐨𝐥𝐮𝐦𝐧 𝐌𝐚𝐣𝐨𝐫 𝐟𝐨𝐫𝐦𝐮𝐥𝐚𝐬 𝐬𝐢𝐝𝐞 𝐛𝐲 𝐬𝐢𝐝𝐞:

Row Major:    L0 + (i*N + j) * W    → i first, then j (left to right)
Column Major: L0 + (j*M + i) * W    → j first, then i (right to left)

Where:
  M = number of rows
  N = number of columns

// 𝐅𝐨𝐫𝐦𝐮𝐥𝐚 𝐟𝐨𝐫 𝟏-𝐛𝐚𝐬𝐞𝐝 𝐢𝐧𝐝𝐞𝐱𝐢𝐧𝐠 (𝐨𝐥𝐝𝐞𝐫 𝐥𝐚𝐧𝐠𝐮𝐚𝐠𝐞𝐬):

Row Major:    L0 + ((i-1)*N + (j-1)) * W
Column Major: L0 + ((j-1)*M + (i-1)) * W


