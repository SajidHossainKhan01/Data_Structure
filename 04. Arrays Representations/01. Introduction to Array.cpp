#include <stdio.h>

int main() {

    // SCALAR variable — stores single value
    int x = 10;
    printf("x = %d\n", x);

    // ARRAY declaration — stores multiple values of same type
    int a[5];   // array of 5 integers, indices 0 to 4

    // METHOD 1 — declare and initialize together
    int b[5] = {2, 4, 6, 8, 10};

    // METHOD 2 — partial initialization (rest become 0)
    int c[5] = {1, 2, 3};   // c = {1, 2, 3, 0, 0}

    // METHOD 3 — without size (size inferred from values)
    int d[] = {5, 10, 15, 20, 25};  // size automatically = 5

    // METHOD 4 — assign values individually
    a[0] = 10;
    a[1] = 20;
    a[2] = 15;   // store 15 at index 2
    a[3] = 40;
    a[4] = 50;

    // ACCESSING elements using index
    printf("a[2] = %d\n", a[2]);   // Output: 15

    // TRAVERSING array using loop
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // Printing array b
    for (int i = 0; i < 5; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}

// 𝐌𝐞𝐦𝐨𝐫𝐲 𝐥𝐚𝐲𝐨𝐮𝐭 𝐨𝐟 𝐢𝐧𝐭 𝐚[𝟓] (𝟐 𝐛𝐲𝐭𝐞𝐬 𝐩𝐞𝐫 𝐢𝐧𝐭):

Index:   [0]   [1]   [2]   [3]   [4]
Value:    10    20    15    40    50
Address: 200   202   204   206   208
         ↑
         contiguous memory block (10 bytes total)