#include <stdio.h>

int main() {

    // METHOD 1 — declare only, no initialization (garbage values)
    int a[5];

    // METHOD 2 — declare and initialize all elements
    int b[5] = {1, 2, 3, 4, 5};

    // METHOD 3 — declare size 10, initialize only 3 (rest become 0)
    int c[10] = {1, 2, 3};

    // METHOD 4 — initialize all to zero
    int d[5] = {0};

    // METHOD 5 — no size mentioned, inferred from elements (size = 6)
    int e[] = {1, 2, 3, 4, 5, 6};

    // PRINTING addresses to show contiguous memory
    for (int i = 0; i < 5; i++) {
        printf("%u\n", &a[i]);
    }

    return 0;
}

//  𝐎𝐮𝐭𝐩𝐮𝐭 𝐨𝐟 𝐚𝐝𝐝𝐫𝐞𝐬𝐬 𝐩𝐫𝐢𝐧𝐭𝐢𝐧𝐠 (𝐞𝐱𝐚𝐦𝐩𝐥𝐞):

56
60
64
68
72

//  𝐌𝐞𝐦𝐨𝐫𝐲 𝐥𝐚𝐲𝐨𝐮𝐭 𝐨𝐟 𝐞𝐚𝐜𝐡 𝐦𝐞𝐭𝐡𝐨𝐝:

a[5] — uninitialized:
[ garbage | garbage | garbage | garbage | garbage ]

b[5] = {1,2,3,4,5}:
[  1  |  2  |  3  |  4  |  5  ]

c[10] = {1,2,3}:
[  1  |  2  |  3  |  0  |  0  |  0  |  0  |  0  |  0  |  0  ]

d[5] = {0}:
[  0  |  0  |  0  |  0  |  0  ]

e[] = {1,2,3,4,5,6}:    ← size automatically = 6
[  1  |  2  |  3  |  4  |  5  |  6  ]

