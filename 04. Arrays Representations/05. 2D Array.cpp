#include <stdio.h>
#include <stdlib.h>

int main() {

    // METHOD 1 — 2D array in STACK (normal method)
    int a[3][4] = {
        {1,  2,  3,  4},    // row 0
        {2,  4,  6,  8},    // row 1
        {1,  3,  5,  7}     // row 2
    };

    // METHOD 2 — Array of pointers in STACK, rows in HEAP
    int *b[3];                              // array of 3 pointers in stack
    b[0] = (int *) malloc(4 * sizeof(int)); // row 0 in heap
    b[1] = (int *) malloc(4 * sizeof(int)); // row 1 in heap
    b[2] = (int *) malloc(4 * sizeof(int)); // row 2 in heap

    // METHOD 3 — Double pointer, everything in HEAP
    int **c;
    c = (int **) malloc(3 * sizeof(int *)); // array of pointers in heap
    c[0] = (int *) malloc(4 * sizeof(int)); // row 0 in heap
    c[1] = (int *) malloc(4 * sizeof(int)); // row 1 in heap
    c[2] = (int *) malloc(4 * sizeof(int)); // row 2 in heap

    // Print METHOD 1 — array a
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Print METHOD 2 — array b (garbage, not initialized)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Print METHOD 3 — array c (garbage, not initialized)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free heap memory
    free(b[0]); free(b[1]); free(b[2]);
    free(c[0]); free(c[1]); free(c[2]);
    free(c);

    return 0;
}

// 𝐌𝐞𝐦𝐨𝐫𝐲 𝐥𝐚𝐲𝐨𝐮𝐭 𝐨𝐟 𝐞𝐚𝐜𝐡 𝐦𝐞𝐭𝐡𝐨𝐝:

METHOD 1 — everything in STACK:
a → [ [1,2,3,4] | [2,4,6,8] | [1,3,5,7] ]
     all contiguous in stack

METHOD 2 — pointers in STACK, rows in HEAP:
STACK:          HEAP:
b[0] ────────→ [ ?, ?, ?, ? ]
b[1] ────────→ [ ?, ?, ?, ? ]
b[2] ────────→ [ ?, ?, ?, ? ]

METHOD 3 — everything in HEAP:
STACK:    HEAP (pointers):    HEAP (rows):
c ──────→ [ c[0] ]──────────→ [ ?, ?, ?, ? ]
          [ c[1] ]──────────→ [ ?, ?, ?, ? ]
          [ c[2] ]──────────→ [ ?, ?, ?, ? ]
